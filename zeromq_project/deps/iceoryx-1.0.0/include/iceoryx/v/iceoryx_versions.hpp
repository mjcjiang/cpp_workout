#ifndef __ICEORYXVERSIONS__
#define __ICEORYXVERSIONS__

#define ICEORYX_VERSION_MAJOR    2
#define ICEORYX_VERSION_MINOR    90
#define ICEORYX_VERSION_PATCH    0
#define ICEORYX_VERSION_TWEAK    0

#define ICEORYX_LATEST_RELEASE_VERSION    "2.90.0"
#define ICEORYX_BUILDDATE                 "2023-06-14T22:41:59Z"
#define ICEORYX_SHA1                      "9e795aac7393711bfbca6f4c56539939c1cbd294"

#include "iox/logging.hpp"

#define ICEORYX_PRINT_BUILDINFO()     IOX_LOG(INFO) << "Built: " << ICEORYX_BUILDDATE;


#endif
