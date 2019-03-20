#ifndef COMMUNICATION_GLOBAL_H
#define COMMUNICATION_GLOBAL_H

#ifdef _WIN32
#   if defined(COMMUNICATION_LIBRARY)
#       define COMMUNICATION_EXPORT __declspec(dllexport)
#   else
#       define COMMUNICATION_EXPORT __declspec(dllimport)
#   endif
#else
#   define COMMUNICATION_EXPORT
#endif

#endif // COMMUNICATION_GLOBAL_H
