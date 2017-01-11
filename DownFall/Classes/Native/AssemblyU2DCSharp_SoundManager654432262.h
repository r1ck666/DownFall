#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// UnityEngine.AudioSource
struct AudioSource_t1135106623;

#include "AssemblyU2DCSharp_SingletonMonoBehaviour_1_gen3646075893.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// SoundManager
struct  SoundManager_t654432262  : public SingletonMonoBehaviour_1_t3646075893
{
public:
	// UnityEngine.AudioSource SoundManager::seSource
	AudioSource_t1135106623 * ___seSource_3;
	// UnityEngine.AudioSource SoundManager::bgmSource
	AudioSource_t1135106623 * ___bgmSource_4;

public:
	inline static int32_t get_offset_of_seSource_3() { return static_cast<int32_t>(offsetof(SoundManager_t654432262, ___seSource_3)); }
	inline AudioSource_t1135106623 * get_seSource_3() const { return ___seSource_3; }
	inline AudioSource_t1135106623 ** get_address_of_seSource_3() { return &___seSource_3; }
	inline void set_seSource_3(AudioSource_t1135106623 * value)
	{
		___seSource_3 = value;
		Il2CppCodeGenWriteBarrier(&___seSource_3, value);
	}

	inline static int32_t get_offset_of_bgmSource_4() { return static_cast<int32_t>(offsetof(SoundManager_t654432262, ___bgmSource_4)); }
	inline AudioSource_t1135106623 * get_bgmSource_4() const { return ___bgmSource_4; }
	inline AudioSource_t1135106623 ** get_address_of_bgmSource_4() { return &___bgmSource_4; }
	inline void set_bgmSource_4(AudioSource_t1135106623 * value)
	{
		___bgmSource_4 = value;
		Il2CppCodeGenWriteBarrier(&___bgmSource_4, value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
