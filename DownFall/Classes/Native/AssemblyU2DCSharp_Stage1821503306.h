#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.String
struct String_t;
// System.UInt32[0...,0...,0...]
struct UInt32U5BU2CU2CU5D_t59386218;

#include "mscorlib_System_Object2689449295.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// Stage
struct  Stage_t1821503306  : public Il2CppObject
{
public:
	// System.String Stage::stageName
	String_t* ___stageName_0;
	// System.UInt32 Stage::x
	uint32_t ___x_1;
	// System.UInt32 Stage::y
	uint32_t ___y_2;
	// System.UInt32 Stage::z
	uint32_t ___z_3;
	// System.UInt32[0...,0...,0...] Stage::blocks
	UInt32U5BU2CU2CU5D_t59386218* ___blocks_4;

public:
	inline static int32_t get_offset_of_stageName_0() { return static_cast<int32_t>(offsetof(Stage_t1821503306, ___stageName_0)); }
	inline String_t* get_stageName_0() const { return ___stageName_0; }
	inline String_t** get_address_of_stageName_0() { return &___stageName_0; }
	inline void set_stageName_0(String_t* value)
	{
		___stageName_0 = value;
		Il2CppCodeGenWriteBarrier(&___stageName_0, value);
	}

	inline static int32_t get_offset_of_x_1() { return static_cast<int32_t>(offsetof(Stage_t1821503306, ___x_1)); }
	inline uint32_t get_x_1() const { return ___x_1; }
	inline uint32_t* get_address_of_x_1() { return &___x_1; }
	inline void set_x_1(uint32_t value)
	{
		___x_1 = value;
	}

	inline static int32_t get_offset_of_y_2() { return static_cast<int32_t>(offsetof(Stage_t1821503306, ___y_2)); }
	inline uint32_t get_y_2() const { return ___y_2; }
	inline uint32_t* get_address_of_y_2() { return &___y_2; }
	inline void set_y_2(uint32_t value)
	{
		___y_2 = value;
	}

	inline static int32_t get_offset_of_z_3() { return static_cast<int32_t>(offsetof(Stage_t1821503306, ___z_3)); }
	inline uint32_t get_z_3() const { return ___z_3; }
	inline uint32_t* get_address_of_z_3() { return &___z_3; }
	inline void set_z_3(uint32_t value)
	{
		___z_3 = value;
	}

	inline static int32_t get_offset_of_blocks_4() { return static_cast<int32_t>(offsetof(Stage_t1821503306, ___blocks_4)); }
	inline UInt32U5BU2CU2CU5D_t59386218* get_blocks_4() const { return ___blocks_4; }
	inline UInt32U5BU2CU2CU5D_t59386218** get_address_of_blocks_4() { return &___blocks_4; }
	inline void set_blocks_4(UInt32U5BU2CU2CU5D_t59386218* value)
	{
		___blocks_4 = value;
		Il2CppCodeGenWriteBarrier(&___blocks_4, value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
