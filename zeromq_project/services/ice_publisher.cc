#include "topic_data.h"
#include "iceoryx_posh/popo/publisher.hpp"
#include "iceoryx_posh/runtime/posh_runtime.hpp"
#include "iceoryx_dust/posix_wrapper/signal_watcher.hpp"

int main() {
    constexpr char APP_NAME[] = "iox-cpp-publisher-helloworld";
    iox::runtime::PoshRuntime::initRuntime(APP_NAME);

    double ct = 1.0;
    
    iox::popo::Publisher<RadarObject> publisher({"Radar", "FrontLeft", "Object"});
    while(!iox::posix::hasTerminationRequested()) {
        auto loanResult = publisher.loan();
        if (!loanResult.has_error()) {
            auto& sample = loanResult.value();
            sample->x = ct;
            sample->y = ct;
            sample->z = ct;
            sample.publish();
        } else {
            auto error = loanResult.get_error();
            std::cerr << "unable to loan sample, error code: " << error << std::endl;
        }

        std::cout << APP_NAME << " sent value: " << ct << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
