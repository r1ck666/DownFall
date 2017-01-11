﻿#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.ComponentModel.AsyncOperation
struct AsyncOperation_t1185541675;
// System.ComponentModel.DoWorkEventHandler
struct DoWorkEventHandler_t941110040;
// System.ComponentModel.ProgressChangedEventHandler
struct ProgressChangedEventHandler_t839864825;
// System.ComponentModel.RunWorkerCompletedEventHandler
struct RunWorkerCompletedEventHandler_t2492476920;

#include "mscorlib_System_Object2689449295.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.ComponentModel.BackgroundWorker
struct  BackgroundWorker_t4230068110  : public Il2CppObject
{
public:
	// System.ComponentModel.AsyncOperation System.ComponentModel.BackgroundWorker::async
	AsyncOperation_t1185541675 * ___async_0;
	// System.Boolean System.ComponentModel.BackgroundWorker::cancel_pending
	bool ___cancel_pending_1;
	// System.Boolean System.ComponentModel.BackgroundWorker::report_progress
	bool ___report_progress_2;
	// System.Boolean System.ComponentModel.BackgroundWorker::support_cancel
	bool ___support_cancel_3;
	// System.ComponentModel.DoWorkEventHandler System.ComponentModel.BackgroundWorker::DoWork
	DoWorkEventHandler_t941110040 * ___DoWork_4;
	// System.ComponentModel.ProgressChangedEventHandler System.ComponentModel.BackgroundWorker::ProgressChanged
	ProgressChangedEventHandler_t839864825 * ___ProgressChanged_5;
	// System.ComponentModel.RunWorkerCompletedEventHandler System.ComponentModel.BackgroundWorker::RunWorkerCompleted
	RunWorkerCompletedEventHandler_t2492476920 * ___RunWorkerCompleted_6;

public:
	inline static int32_t get_offset_of_async_0() { return static_cast<int32_t>(offsetof(BackgroundWorker_t4230068110, ___async_0)); }
	inline AsyncOperation_t1185541675 * get_async_0() const { return ___async_0; }
	inline AsyncOperation_t1185541675 ** get_address_of_async_0() { return &___async_0; }
	inline void set_async_0(AsyncOperation_t1185541675 * value)
	{
		___async_0 = value;
		Il2CppCodeGenWriteBarrier(&___async_0, value);
	}

	inline static int32_t get_offset_of_cancel_pending_1() { return static_cast<int32_t>(offsetof(BackgroundWorker_t4230068110, ___cancel_pending_1)); }
	inline bool get_cancel_pending_1() const { return ___cancel_pending_1; }
	inline bool* get_address_of_cancel_pending_1() { return &___cancel_pending_1; }
	inline void set_cancel_pending_1(bool value)
	{
		___cancel_pending_1 = value;
	}

	inline static int32_t get_offset_of_report_progress_2() { return static_cast<int32_t>(offsetof(BackgroundWorker_t4230068110, ___report_progress_2)); }
	inline bool get_report_progress_2() const { return ___report_progress_2; }
	inline bool* get_address_of_report_progress_2() { return &___report_progress_2; }
	inline void set_report_progress_2(bool value)
	{
		___report_progress_2 = value;
	}

	inline static int32_t get_offset_of_support_cancel_3() { return static_cast<int32_t>(offsetof(BackgroundWorker_t4230068110, ___support_cancel_3)); }
	inline bool get_support_cancel_3() const { return ___support_cancel_3; }
	inline bool* get_address_of_support_cancel_3() { return &___support_cancel_3; }
	inline void set_support_cancel_3(bool value)
	{
		___support_cancel_3 = value;
	}

	inline static int32_t get_offset_of_DoWork_4() { return static_cast<int32_t>(offsetof(BackgroundWorker_t4230068110, ___DoWork_4)); }
	inline DoWorkEventHandler_t941110040 * get_DoWork_4() const { return ___DoWork_4; }
	inline DoWorkEventHandler_t941110040 ** get_address_of_DoWork_4() { return &___DoWork_4; }
	inline void set_DoWork_4(DoWorkEventHandler_t941110040 * value)
	{
		___DoWork_4 = value;
		Il2CppCodeGenWriteBarrier(&___DoWork_4, value);
	}

	inline static int32_t get_offset_of_ProgressChanged_5() { return static_cast<int32_t>(offsetof(BackgroundWorker_t4230068110, ___ProgressChanged_5)); }
	inline ProgressChangedEventHandler_t839864825 * get_ProgressChanged_5() const { return ___ProgressChanged_5; }
	inline ProgressChangedEventHandler_t839864825 ** get_address_of_ProgressChanged_5() { return &___ProgressChanged_5; }
	inline void set_ProgressChanged_5(ProgressChangedEventHandler_t839864825 * value)
	{
		___ProgressChanged_5 = value;
		Il2CppCodeGenWriteBarrier(&___ProgressChanged_5, value);
	}

	inline static int32_t get_offset_of_RunWorkerCompleted_6() { return static_cast<int32_t>(offsetof(BackgroundWorker_t4230068110, ___RunWorkerCompleted_6)); }
	inline RunWorkerCompletedEventHandler_t2492476920 * get_RunWorkerCompleted_6() const { return ___RunWorkerCompleted_6; }
	inline RunWorkerCompletedEventHandler_t2492476920 ** get_address_of_RunWorkerCompleted_6() { return &___RunWorkerCompleted_6; }
	inline void set_RunWorkerCompleted_6(RunWorkerCompletedEventHandler_t2492476920 * value)
	{
		___RunWorkerCompleted_6 = value;
		Il2CppCodeGenWriteBarrier(&___RunWorkerCompleted_6, value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
