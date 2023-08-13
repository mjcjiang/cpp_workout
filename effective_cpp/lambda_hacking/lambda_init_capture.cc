#include <iostream>
#include <memory>
#include <vector>
#include <functional>

enum class status {
    SLEEP,
    READY,
    RUNNING,
    FINISH
};

class Widget {
public:
    bool is_sleep() { return sts == status::SLEEP; }
    bool is_ready() { return sts == status::READY; }
    bool is_running() { return sts == status::RUNNING; }
    bool is_finish() { return sts == status::FINISH; }
    void set_status(status s) { sts = s; }
    status get_status() { return sts; }
private:
    status sts;
};

int main(int argc, char *argv[])
{
    auto pw = std::make_unique<Widget>();
    pw->set_status(status::RUNNING);

    auto is_sleep_or_finish = [pw = std::move(pw)] {
        return pw->is_sleep() || pw->is_finish();
    };
    std::cout << std::boolalpha << is_sleep_or_finish() << std::endl;

    auto is_ready_or_running = [pw = std::make_unique<Widget>()] {
        return pw->is_ready() || pw->is_running();
    };
    std::cout << std::boolalpha << is_ready_or_running() << std::endl;

    std::vector<int> data = {1, 2, 3};
    auto func = std::bind([](std::vector<int> &data) mutable {
        data.emplace_back(4);
        for (auto &elem : data) {
            std::cout << elem << std::endl;
        }
    }, std::move(data));

    func();
    return 0;
}
