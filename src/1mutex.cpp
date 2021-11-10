#include <thread>
#include <mutex>

#include <spdlog/spdlog.h>

std::mutex gmutex;
extern bool gstarted;

extern std::thread gstartup;

std::thread gstarting([](int){
    spdlog::info("gstarting unblocked gstarted={}", gstarted);
  }, 
  (spdlog::info("gstarting waits.."), 
  []{
      try{
        gstartup.join();
      }catch(...){
        spdlog::info("gstartup join failed");
        std::terminate();
      }
    }(), 
  0));
