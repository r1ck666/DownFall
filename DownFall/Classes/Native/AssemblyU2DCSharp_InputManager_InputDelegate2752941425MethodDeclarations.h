#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>
#include <assert.h>
#include <exception>

// InputManager/InputDelegate
struct InputDelegate_t2752941425;
// System.Object
struct Il2CppObject;
// System.IAsyncResult
struct IAsyncResult_t1999651008;
// System.AsyncCallback
struct AsyncCallback_t163412349;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Object2689449295.h"
#include "mscorlib_System_IntPtr2504060609.h"
#include "mscorlib_System_AsyncCallback163412349.h"

// System.Void InputManager/InputDelegate::.ctor(System.Object,System.IntPtr)
extern "C"  void InputDelegate__ctor_m3583457546 (InputDelegate_t2752941425 * __this, Il2CppObject * ___object0, IntPtr_t ___method1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void InputManager/InputDelegate::Invoke()
extern "C"  void InputDelegate_Invoke_m1905123440 (InputDelegate_t2752941425 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.IAsyncResult InputManager/InputDelegate::BeginInvoke(System.AsyncCallback,System.Object)
extern "C"  Il2CppObject * InputDelegate_BeginInvoke_m2044484391 (InputDelegate_t2752941425 * __this, AsyncCallback_t163412349 * ___callback0, Il2CppObject * ___object1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void InputManager/InputDelegate::EndInvoke(System.IAsyncResult)
extern "C"  void InputDelegate_EndInvoke_m354430760 (InputDelegate_t2752941425 * __this, Il2CppObject * ___result0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
