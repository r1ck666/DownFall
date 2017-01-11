#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// PlayerController
struct PlayerController_t4148409433;
// UnityEngine.UI.Text
struct Text_t356221433;

#include "AssemblyU2DCSharp_SingletonMonoBehaviour_1_gen1215859820.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// UIManager
struct  UIManager_t2519183485  : public SingletonMonoBehaviour_1_t1215859820
{
public:
	// PlayerController UIManager::playerController
	PlayerController_t4148409433 * ___playerController_3;
	// UnityEngine.UI.Text UIManager::limitTimeText
	Text_t356221433 * ___limitTimeText_4;

public:
	inline static int32_t get_offset_of_playerController_3() { return static_cast<int32_t>(offsetof(UIManager_t2519183485, ___playerController_3)); }
	inline PlayerController_t4148409433 * get_playerController_3() const { return ___playerController_3; }
	inline PlayerController_t4148409433 ** get_address_of_playerController_3() { return &___playerController_3; }
	inline void set_playerController_3(PlayerController_t4148409433 * value)
	{
		___playerController_3 = value;
		Il2CppCodeGenWriteBarrier(&___playerController_3, value);
	}

	inline static int32_t get_offset_of_limitTimeText_4() { return static_cast<int32_t>(offsetof(UIManager_t2519183485, ___limitTimeText_4)); }
	inline Text_t356221433 * get_limitTimeText_4() const { return ___limitTimeText_4; }
	inline Text_t356221433 ** get_address_of_limitTimeText_4() { return &___limitTimeText_4; }
	inline void set_limitTimeText_4(Text_t356221433 * value)
	{
		___limitTimeText_4 = value;
		Il2CppCodeGenWriteBarrier(&___limitTimeText_4, value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
