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

#ifdef MT_ENABLE_ASSERTS
	#define MT_ASSERT(x, ...) { if(!(x)) { MT_CLIENT_ERROR("Asserrtion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define MT_CORE_ASSERT(x, ...) { if(!(x)) { MT_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define MT_ASSERT(x, ...)
	#define MT_CORE_ASSERT(x, ...)
#endif

// Bit shift 1, x number of places to the left
#define BIT(x) (1 << x)
