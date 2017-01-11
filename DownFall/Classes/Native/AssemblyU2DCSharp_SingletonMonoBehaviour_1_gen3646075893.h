#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// SoundManager
struct SoundManager_t654432262;

#include "UnityEngine_UnityEngine_MonoBehaviour1158329972.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// SingletonMonoBehaviour`1<SoundManager>
struct  SingletonMonoBehaviour_1_t3646075893  : public MonoBehaviour_t1158329972
{
public:

public:
};

struct SingletonMonoBehaviour_1_t3646075893_StaticFields
{
public:
	// T SingletonMonoBehaviour`1::instance
	SoundManager_t654432262 * ___instance_2;

public:
	inline static int32_t get_offset_of_instance_2() { return static_cast<int32_t>(offsetof(SingletonMonoBehaviour_1_t3646075893_StaticFields, ___instance_2)); }
	inline SoundManager_t654432262 * get_instance_2() const { return ___instance_2; }
	inline SoundManager_t654432262 ** get_address_of_instance_2() { return &___instance_2; }
	inline void set_instance_2(SoundManager_t654432262 * value)
	{
		___instance_2 = value;
		Il2CppCodeGenWriteBarrier(&___instance_2, value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
