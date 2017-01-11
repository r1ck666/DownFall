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
// UnityEngine.GameObject
struct GameObject_t1756533147;
// UnityEngine.UI.Text
struct Text_t356221433;
// UnityEngine.UI.Text[]
struct TextU5BU5D_t4216439300;
// RoomInfo[]
struct RoomInfoU5BU5D_t3672612454;

#include "AssemblyU2DCSharp_SingletonPhotonMonoBehaviour_1_g1885725658.h"
#include "AssemblyU2DCSharp_PhotonLogLevel1525257006.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// TitleManager
struct  TitleManager_t989436509  : public SingletonPhotonMonoBehaviour_1_t1885725658
{
public:
	// System.String TitleManager::_gameVersion
	String_t* ____gameVersion_4;
	// PhotonLogLevel TitleManager::Loglevel
	int32_t ___Loglevel_5;
	// UnityEngine.GameObject TitleManager::playStart
	GameObject_t1756533147 * ___playStart_6;
	// System.Boolean TitleManager::isPlay
	bool ___isPlay_7;
	// UnityEngine.GameObject TitleManager::progressLabel
	GameObject_t1756533147 * ___progressLabel_8;
	// UnityEngine.UI.Text TitleManager::gameVersionLabel
	Text_t356221433 * ___gameVersionLabel_9;
	// UnityEngine.UI.Text TitleManager::errorDialog
	Text_t356221433 * ___errorDialog_10;
	// UnityEngine.GameObject TitleManager::menu
	GameObject_t1756533147 * ___menu_11;
	// UnityEngine.UI.Text[] TitleManager::menuText
	TextU5BU5D_t4216439300* ___menuText_12;
	// System.Int32 TitleManager::sceneNum
	int32_t ___sceneNum_13;
	// RoomInfo[] TitleManager::roomInfo
	RoomInfoU5BU5D_t3672612454* ___roomInfo_14;

public:
	inline static int32_t get_offset_of__gameVersion_4() { return static_cast<int32_t>(offsetof(TitleManager_t989436509, ____gameVersion_4)); }
	inline String_t* get__gameVersion_4() const { return ____gameVersion_4; }
	inline String_t** get_address_of__gameVersion_4() { return &____gameVersion_4; }
	inline void set__gameVersion_4(String_t* value)
	{
		____gameVersion_4 = value;
		Il2CppCodeGenWriteBarrier(&____gameVersion_4, value);
	}

	inline static int32_t get_offset_of_Loglevel_5() { return static_cast<int32_t>(offsetof(TitleManager_t989436509, ___Loglevel_5)); }
	inline int32_t get_Loglevel_5() const { return ___Loglevel_5; }
	inline int32_t* get_address_of_Loglevel_5() { return &___Loglevel_5; }
	inline void set_Loglevel_5(int32_t value)
	{
		___Loglevel_5 = value;
	}

	inline static int32_t get_offset_of_playStart_6() { return static_cast<int32_t>(offsetof(TitleManager_t989436509, ___playStart_6)); }
	inline GameObject_t1756533147 * get_playStart_6() const { return ___playStart_6; }
	inline GameObject_t1756533147 ** get_address_of_playStart_6() { return &___playStart_6; }
	inline void set_playStart_6(GameObject_t1756533147 * value)
	{
		___playStart_6 = value;
		Il2CppCodeGenWriteBarrier(&___playStart_6, value);
	}

	inline static int32_t get_offset_of_isPlay_7() { return static_cast<int32_t>(offsetof(TitleManager_t989436509, ___isPlay_7)); }
	inline bool get_isPlay_7() const { return ___isPlay_7; }
	inline bool* get_address_of_isPlay_7() { return &___isPlay_7; }
	inline void set_isPlay_7(bool value)
	{
		___isPlay_7 = value;
	}

	inline static int32_t get_offset_of_progressLabel_8() { return static_cast<int32_t>(offsetof(TitleManager_t989436509, ___progressLabel_8)); }
	inline GameObject_t1756533147 * get_progressLabel_8() const { return ___progressLabel_8; }
	inline GameObject_t1756533147 ** get_address_of_progressLabel_8() { return &___progressLabel_8; }
	inline void set_progressLabel_8(GameObject_t1756533147 * value)
	{
		___progressLabel_8 = value;
		Il2CppCodeGenWriteBarrier(&___progressLabel_8, value);
	}

	inline static int32_t get_offset_of_gameVersionLabel_9() { return static_cast<int32_t>(offsetof(TitleManager_t989436509, ___gameVersionLabel_9)); }
	inline Text_t356221433 * get_gameVersionLabel_9() const { return ___gameVersionLabel_9; }
	inline Text_t356221433 ** get_address_of_gameVersionLabel_9() { return &___gameVersionLabel_9; }
	inline void set_gameVersionLabel_9(Text_t356221433 * value)
	{
		___gameVersionLabel_9 = value;
		Il2CppCodeGenWriteBarrier(&___gameVersionLabel_9, value);
	}

	inline static int32_t get_offset_of_errorDialog_10() { return static_cast<int32_t>(offsetof(TitleManager_t989436509, ___errorDialog_10)); }
	inline Text_t356221433 * get_errorDialog_10() const { return ___errorDialog_10; }
	inline Text_t356221433 ** get_address_of_errorDialog_10() { return &___errorDialog_10; }
	inline void set_errorDialog_10(Text_t356221433 * value)
	{
		___errorDialog_10 = value;
		Il2CppCodeGenWriteBarrier(&___errorDialog_10, value);
	}

	inline static int32_t get_offset_of_menu_11() { return static_cast<int32_t>(offsetof(TitleManager_t989436509, ___menu_11)); }
	inline GameObject_t1756533147 * get_menu_11() const { return ___menu_11; }
	inline GameObject_t1756533147 ** get_address_of_menu_11() { return &___menu_11; }
	inline void set_menu_11(GameObject_t1756533147 * value)
	{
		___menu_11 = value;
		Il2CppCodeGenWriteBarrier(&___menu_11, value);
	}

	inline static int32_t get_offset_of_menuText_12() { return static_cast<int32_t>(offsetof(TitleManager_t989436509, ___menuText_12)); }
	inline TextU5BU5D_t4216439300* get_menuText_12() const { return ___menuText_12; }
	inline TextU5BU5D_t4216439300** get_address_of_menuText_12() { return &___menuText_12; }
	inline void set_menuText_12(TextU5BU5D_t4216439300* value)
	{
		___menuText_12 = value;
		Il2CppCodeGenWriteBarrier(&___menuText_12, value);
	}

	inline static int32_t get_offset_of_sceneNum_13() { return static_cast<int32_t>(offsetof(TitleManager_t989436509, ___sceneNum_13)); }
	inline int32_t get_sceneNum_13() const { return ___sceneNum_13; }
	inline int32_t* get_address_of_sceneNum_13() { return &___sceneNum_13; }
	inline void set_sceneNum_13(int32_t value)
	{
		___sceneNum_13 = value;
	}

	inline static int32_t get_offset_of_roomInfo_14() { return static_cast<int32_t>(offsetof(TitleManager_t989436509, ___roomInfo_14)); }
	inline RoomInfoU5BU5D_t3672612454* get_roomInfo_14() const { return ___roomInfo_14; }
	inline RoomInfoU5BU5D_t3672612454** get_address_of_roomInfo_14() { return &___roomInfo_14; }
	inline void set_roomInfo_14(RoomInfoU5BU5D_t3672612454* value)
	{
		___roomInfo_14 = value;
		Il2CppCodeGenWriteBarrier(&___roomInfo_14, value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
