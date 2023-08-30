/*
* Author: hjiang
* Created: 2023-08-24
*
* Posix write file test
*/

#include <iostream>
#include <fstream>
#include <string>
#include <fcntl.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>
#include <thread>
#include <chrono>

class FileWrapper {
public:
    FileWrapper(const std::string &file_path) {
        fileDesc = open(file_path.c_str(), O_RDWR | O_CREAT | O_APPEND, 0644);
        if (fileDesc == -1)
            std::cerr << "Error opening file: " << std::strerror(errno) << std::endl;

        fl.l_whence = SEEK_SET;
        fl.l_start = 0;
        fl.l_len = 0;
    }

    /**
     * @brief lock the opened file
     *
     * @return -1 stand for lock error, 0 stand for get lock success
     */
    int lock() {
        fl.l_type = F_WRLCK;
        if (fileDesc != -1 && fcntl(fileDesc, F_SETLK, &fl) != -1)
            return 0;

        std::cerr << "Failed to get lock on file: " << std::strerror(errno)
                  << std::endl;
        return -1;
    }

    /**
     * @brief unlock the opened file
     *
     * @return -1 stand for unlock error, 0 stand for unlock success
     */
    int unlock() {
        fl.l_type = F_ULOCK;
        if (fileDesc != -1 && fcntl(fileDesc, F_SETLK, &fl) != -1)
            return 0;

        std::cerr << "Failed to release lock on file: " << std::strerror(errno)
                  << std::endl;
        return -1;
    }

    /**
     * @brief write content to file
     *
     * @return -1 failed to write, 0 stand for write success
     */
    int write_file(const std::string &content) {
        ssize_t bytes_written = write(fileDesc, content.c_str(), content.length());
        if (bytes_written == -1) {
            std::cerr << "Failed to write file..." << std::strerror(errno) << std::endl;
            return -1;
        }
        return 0;
    }
private:
    int fileDesc;
    struct flock fl;
};

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cout << "Usage: prog \"your content\"" << std::endl;
        return 1;
    }

    FileWrapper fw("test_posix.txt");
    while (fw.lock() == -1) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    for (int i = 0; i < 10; i++) {
        fw.write_file(argv[1]);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    fw.unlock();
    return 0;
}
