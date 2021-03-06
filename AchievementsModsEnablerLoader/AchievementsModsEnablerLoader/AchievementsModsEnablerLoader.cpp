#include "stdafx.h"

////// F4SE //////
#ifdef _F4SE_
#include "common\IPrefix.h"
#include "F4SE\F4SE\PluginAPI.h"
extern "C" __declspec(dllexport) bool F4SEPlugin_Query(const F4SEInterface * skse, PluginInfo * info)
{
	info->infoVersion = PluginInfo::kInfoVersion;
	info->name = "AchievementsModsEnabler";
	info->version = 1;

	return TRUE;
}

extern "C" __declspec(dllexport) bool F4SEPlugin_Load(const F4SEInterface * skse)
{
	// Get dll path.
	TCHAR DllFilePath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, DllFilePath);
	_tcscat_s(DllFilePath, MAX_PATH, L"\\Data\\Plugins\\Sumwunn\\AchievementsModsEnabler.dll");

	// Return if already loaded.
	if (GetModuleHandle(DllFilePath) != 0) return 0;

	// Load it.
	HMODULE hModule = LoadLibrary(DllFilePath);
	FARPROC Function01 = GetProcAddress(hModule, "SetF4SEMode");
	FARPROC Function02 = GetProcAddress(hModule, "Setup");

	// Call stuff.
	Function01();
	Function02();

	return TRUE;
}
#endif

#ifdef _SKSE64_
////// SKSE64 //////
#include "common\IPrefix.h"
#include "SKSE64\SKSE64\PluginAPI.h"
extern "C" __declspec(dllexport) bool SKSEPlugin_Query(const SKSEInterface * skse, PluginInfo * info)
{
	info->infoVersion = PluginInfo::kInfoVersion;
	info->name = "AchievementsModsEnabler";
	info->version = 1;

	return TRUE;
}

extern "C" __declspec(dllexport) bool SKSEPlugin_Load(const SKSEInterface * skse)
{
	// Get dll path.
	TCHAR DllFilePath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, DllFilePath);
	_tcscat_s(DllFilePath, MAX_PATH, L"\\Data\\Plugins\\Sumwunn\\AchievementsModsEnabler.dll");

	// Return if already loaded.
	if (GetModuleHandle(DllFilePath) != 0) return 0;

	// Load it.
	HMODULE hModule = LoadLibrary(DllFilePath);
	FARPROC Function01 = GetProcAddress(hModule, "SetSKSEMode");
	FARPROC Function02 = GetProcAddress(hModule, "Setup");

	// Call stuff.
	Function01();
	Function02();

	return TRUE;
}
#endif