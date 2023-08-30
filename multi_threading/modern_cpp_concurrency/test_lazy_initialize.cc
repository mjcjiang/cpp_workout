#include <string_view>
#include <iostream>
#include <mutex>
#include <memory>
#include <thread>
#include <random>

class File
{
public:
    File(std::string_view fileName)
    {
        std::cout << "Opening file " << fileName << std::endl;
    }
    ~File()
    {
        std::cout << "Closing file" << std::endl;
    }
    File(const File&) = delete;
    File(File&&) = default;
    File& operator=(const File&) = delete;
    File& operator=(File&&) = default;

    void write(std::string_view str)
    {
        std::cout << "Writing to file: " << str << std::endl;
    }
};

class Config
{
    File file;
public:
    Config() : file{"config.txt"}
    {
        std::cout << "Config object created" << std::endl;
    }

    void addOption(std::string_view name, std::string_view value)
    {
        file.write(name);
        file.write(" = ");
        file.write(value);
        file.write("\n");
    }
};

class SomeResource {
};

class IntUniRdGen {
public:
    IntUniRdGen(int start, int end) : start(start), end(end) {
        dis = std::uniform_int_distribution<>(start, end);
    }

    int gen_random() {
        return dis(gen);
    }
private:
    int start = 0;
    int end = 0;
    std::random_device rd;
    std::mt19937 gen{rd()};
    std::uniform_int_distribution<> dis;
};

std::shared_ptr<SomeResource> resource_ptr;
std::once_flag resource_flag;

void init_resource(std::string_view name) {
    std::cout << "------------------------------" << std::endl;
    std::cout << "Init by: " << name << std::endl;
    resource_ptr.reset(new SomeResource);
    std::cout << "------------------------------" << std::endl;
}

void thread_function(std::string_view thread_name) {
    auto sleep_time = IntUniRdGen(1, 10).gen_random();
    std::this_thread::sleep_for(std::chrono::seconds(sleep_time));
    std::call_once(resource_flag, init_resource, thread_name);
    std::cout << "Do something else in: " << thread_name << std::endl;
}

int main(int argc, char *argv[])
{
    /*
    Config c;
    std::cout << "Some operations..." << std::endl;
    c.addOption("dark_mode", "true");
    c.addOption("font", "DejaVu Sans Mono");
    */

    std::thread th1(thread_function, "thread1");
    std::thread th2(thread_function, "thread2");
    std::thread th3(thread_function, "thread3");
    th1.join();
    th2.join();
    th3.join();
    return 0;
}
