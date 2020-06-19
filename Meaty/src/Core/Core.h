#pragma once

#ifdef MT_WINDOWS_PLATFORM
	#ifdef MT_BUILD_DLL
		#define MEATY_API __declspec(dllexport)
	#else
		#define MEATY_API __declspec(dllimport)
	#endif
#else
	#error This engine only supports Windows for now. Sorry.
#endif

