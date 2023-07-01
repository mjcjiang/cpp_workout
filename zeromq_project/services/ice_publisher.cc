#include "topic_data.h"

#include "iceoryx_dust/posix_wrapper/signal_watcher.hpp"
#include "iceoryx_posh/popo/publisher.hpp"
#include "iceoryx_posh/runtime/posh_runtime.hpp"
#include <iostream>

int main()
{
    constexpr char APP_NAME[] = "iox-cpp-publisher-helloworld";
    iox::runtime::PoshRuntime::initRuntime(APP_NAME);
 
    iox::popo::Publisher<RadarObject> publisher({"Radar", "FrontLeft", "Object"});
 
    double ct = 0.0;
    while (!iox::posix::hasTerminationRequested())
    {
        ++ct;

        // Retrieve a sample from shared memory
        auto loanResult = publisher.loan();
        if (!loanResult.has_error())
        {
            auto& sample = loanResult.value();
            sample->x = ct;
            sample->y = ct;
            sample->z = ct;
            sample.publish();
        }
        else
        {
            auto error = loanResult.error();
            std::cerr << "Unable to loan sample, error code: " << error << std::endl;
        }

        std::cout << APP_NAME << " sent value: " << ct << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        //! [msg]
    }

    return 0;
}
