#include <thread>
#include <mutex>

#include <spdlog/spdlog.h>

extern std::mutex gmutex;
bool gstarted = false;

std::unique_lock<std::mutex> gguard(gmutex);

std::thread gstartup([](int){
    gstarted = true; 
    gguard.unlock();
    spdlog::info("gstartup unblocked");
}, (spdlog::info("gstartup construct"), 0));
