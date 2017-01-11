#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// StageManager
struct StageManager_t1309287873;

#include "UnityEngine_UnityEngine_MonoBehaviour1158329972.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// SingletonMonoBehaviour`1<StageManager>
struct  SingletonMonoBehaviour_1_t5964208  : public MonoBehaviour_t1158329972
{
public:

public:
};

struct SingletonMonoBehaviour_1_t5964208_StaticFields
{
public:
	// T SingletonMonoBehaviour`1::instance
	StageManager_t1309287873 * ___instance_2;

public:
	inline static int32_t get_offset_of_instance_2() { return static_cast<int32_t>(offsetof(SingletonMonoBehaviour_1_t5964208_StaticFields, ___instance_2)); }
	inline StageManager_t1309287873 * get_instance_2() const { return ___instance_2; }
	inline StageManager_t1309287873 ** get_address_of_instance_2() { return &___instance_2; }
	inline void set_instance_2(StageManager_t1309287873 * value)
	{
		___instance_2 = value;
		Il2CppCodeGenWriteBarrier(&___instance_2, value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
