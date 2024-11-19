#ifndef QUIETDRIVER__VISIBILITY_CONTROL_H_
#define QUIETDRIVER__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define QUIETDRIVER_EXPORT __attribute__ ((dllexport))
    #define QUIETDRIVER_IMPORT __attribute__ ((dllimport))
  #else
    #define QUIETDRIVER_EXPORT __declspec(dllexport)
    #define QUIETDRIVER_IMPORT __declspec(dllimport)
  #endif
  #ifdef QUIETDRIVER_BUILDING_LIBRARY
    #define QUIETDRIVER_PUBLIC QUIETDRIVER_EXPORT
  #else
    #define QUIETDRIVER_PUBLIC QUIETDRIVER_IMPORT
  #endif
  #define QUIETDRIVER_PUBLIC_TYPE QUIETDRIVER_PUBLIC
  #define QUIETDRIVER_LOCAL
#else
  #define QUIETDRIVER_EXPORT __attribute__ ((visibility("default")))
  #define QUIETDRIVER_IMPORT
  #if __GNUC__ >= 4
    #define QUIETDRIVER_PUBLIC __attribute__ ((visibility("default")))
    #define QUIETDRIVER_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define QUIETDRIVER_PUBLIC
    #define QUIETDRIVER_LOCAL
  #endif
  #define QUIETDRIVER_PUBLIC_TYPE
#endif
#endif  // QUIETDRIVER__VISIBILITY_CONTROL_H_
// Generated 19-Nov-2024 01:06:50
// Copyright 2019-2020 The MathWorks, Inc.
