#pragma once
#include "DirectXWrapper.h"

#define out [Runtime::InteropServices::Out]


#define DECLARE_WRAPPED_INSTANCE(WRAPPER_CLASS,ORIGIN_CLASS)\
private:\
ORIGIN_CLASS* origin = nullptr;\
public:\
WRAPPER_CLASS(){}\
WRAPPER_CLASS(IntPtr unmanagedObject)\
{\
  origin = (ORIGIN_CLASS*)unmanagedObject.ToPointer();\
}\
~WRAPPER_CLASS()\
{\
  if(origin == nullptr) return;\
  origin->Release();\
  origin = nullptr;\
}\
ORIGIN_CLASS* ToOrigin()\
{\
  return origin;\
}\
IntPtr ToPointer()\
{\
  return (IntPtr)origin;\
}\
