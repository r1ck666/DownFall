#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// WaitingRoomManager
struct WaitingRoomManager_t1781439173;

#include "AssemblyU2DCSharp_Photon_PunBehaviour692890556.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// SingletonPhotonMonoBehaviour`1<WaitingRoomManager>
struct  SingletonPhotonMonoBehaviour_1_t2677728322  : public PunBehaviour_t692890556
{
public:

public:
};

struct SingletonPhotonMonoBehaviour_1_t2677728322_StaticFields
{
public:
	// T SingletonPhotonMonoBehaviour`1::instance
	WaitingRoomManager_t1781439173 * ___instance_3;

public:
	inline static int32_t get_offset_of_instance_3() { return static_cast<int32_t>(offsetof(SingletonPhotonMonoBehaviour_1_t2677728322_StaticFields, ___instance_3)); }
	inline WaitingRoomManager_t1781439173 * get_instance_3() const { return ___instance_3; }
	inline WaitingRoomManager_t1781439173 ** get_address_of_instance_3() { return &___instance_3; }
	inline void set_instance_3(WaitingRoomManager_t1781439173 * value)
	{
		___instance_3 = value;
		Il2CppCodeGenWriteBarrier(&___instance_3, value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
