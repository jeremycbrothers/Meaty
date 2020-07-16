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

// Bit shift 1 x number of places to the left
#define BIT(x) (1 << x)
