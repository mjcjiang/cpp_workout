#include "topic_data.h"
#include "iceoryx_posh/popo/subscriber.hpp"
#include "iceoryx_posh/runtime/posh_runtime.hpp"
#include "iceoryx_dust/posix_wrapper/signal_watcher.hpp"

int main() {
    constexpr char APP_NAME[] = "iox-cpp-subcriber-helloworld";
    iox::runtime::PoshRuntime::initRuntime(APP_NAME);

    iox::popo::Subscriber<RadarObject> subscriber({"Radar", "FrontLeft", "Object"});

    // run until interrupted by Ctrl-C
    while (!iox::posix::hasTerminationRequested())
    {
        auto takeResult = subscriber.take();
        if (!takeResult.has_error())
        {
            std::cout << APP_NAME << " got value: " << takeResult.value()->x << std::endl;
        }
        else
        {
            if (takeResult.error() == iox::popo::ChunkReceiveResult::NO_CHUNK_AVAILABLE)
            {
                std::cout << "No chunk available." << std::endl;
            }
            else
            {
                std::cout << "Error receiving chunk." << std::endl;
            }
        }
        
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return (EXIT_SUCCESS);
    return 0;
}
