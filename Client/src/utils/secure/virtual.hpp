#pragma once
#include "stdafx.hpp"

namespace Utils::Secure {
	LPVOID VirtualAlloc(LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect);
	BOOL VirtualFree(LPVOID lpAddress, SIZE_T dwSize, DWORD dwFreeType);
	BOOL VirtualProtect(LPVOID lpAddress, SIZE_T dwSize, DWORD flNewProtect, PDWORD lpflOldProtect);
}