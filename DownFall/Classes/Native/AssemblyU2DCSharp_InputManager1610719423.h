#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// InputManager/InputDelegate[]
struct InputDelegateU5BU5D_t556171692;

#include "AssemblyU2DCSharp_SingletonMonoBehaviour_1_gen307395758.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// InputManager
struct  InputManager_t1610719423  : public SingletonMonoBehaviour_1_t307395758
{
public:
	// InputManager/InputDelegate[] InputManager::InputKeyDown
	InputDelegateU5BU5D_t556171692* ___InputKeyDown_3;

public:
	inline static int32_t get_offset_of_InputKeyDown_3() { return static_cast<int32_t>(offsetof(InputManager_t1610719423, ___InputKeyDown_3)); }
	inline InputDelegateU5BU5D_t556171692* get_InputKeyDown_3() const { return ___InputKeyDown_3; }
	inline InputDelegateU5BU5D_t556171692** get_address_of_InputKeyDown_3() { return &___InputKeyDown_3; }
	inline void set_InputKeyDown_3(InputDelegateU5BU5D_t556171692* value)
	{
		___InputKeyDown_3 = value;
		Il2CppCodeGenWriteBarrier(&___InputKeyDown_3, value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
