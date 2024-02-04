#pragma once

#ifdef ORANGE_PLATFORM_WINDOWS
	#ifdef ORANGE_BUILD_DLL
		#define ORANGE_API_ _declspec(dllexport)
	#else
		#define ORANGE_API_ _declspec(dllimport)
	#endif
#else
	#error Orange only supports Windows!
#endif