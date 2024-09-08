#ifndef LOG_FUNCTION_H
#define LOG_FUNCTION_H

#include <TGlobal>
#include <iostream>
#include <ctime>

#define LOG_FUNC_NAME                                                                              \
  {                                                                                                \
    std::time_t now = std::time(nullptr);                                                          \
    tInfo("Function: %s | DateTime: %s", __PRETTY_FUNCTION__, std::asctime(std::localtime(&now))); \
  }
#endif // LOG_FUNCTION_H