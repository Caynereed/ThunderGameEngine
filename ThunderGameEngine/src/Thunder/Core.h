#pragma once

#ifdef TD_Platform_Windows
	#ifdef TD_Build_DLL
		#define TD_API __declspec(dllexport)
	#else
		#define TD_API __declspec(dllimport)
	#endif
#else
	#error Thunder only supports Windows!
#endif