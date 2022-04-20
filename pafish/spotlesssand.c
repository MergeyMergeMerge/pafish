#include <string.h>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <psapi.h>
#include <winevt.h>
#include <sddl.h>

#pragma comment(lib, "wevtapi.lib")

#include "spotlesssand.h"
#include "utils.h"

DWORD PrintResults(EVT_HANDLE);

int spotlesssand_clscount(){
	HKEY regkey;
	LONG ret;
	int count = 0;
	FILETIME ftLastWriteTime;
	if (pafish_iswow64()){
		ret = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Enum\\USB", 0, KEY_READ | KEY_WOW64_64KEY, &regkey);
	} else {

		ret = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Enum\\USB", 0, KEY_READ, &regkey);
	}
	if (ret == ERROR_SUCCESS){
		for (int i = 0; i < 200; i++){
			DWORD subkeyLength = 255;
			TCHAR subkeyName[255];
			ret = RegEnumKeyExA(regkey, i, subkeyName, &subkeyLength, NULL, NULL, NULL, &ftLastWriteTime);
			if (ret == 259){
				count = i;
				break;
			}
		}
	}
	printf("%i subkeys\n", count);
	return count < 60;
}

int spotlesssand_totalproc(){
	DWORD buf[4096];
	DWORD numBytes;
	BOOL ret;
	ret = EnumProcesses(buf, 4096, &numBytes);
	int numProc = numBytes / sizeof(DWORD);
	printf("%i processes\n", numProc);
	return numProc < 41;
}

int spotlesssand_browsernum(){
	int count = 0;
	if (pafish_exists_regkey(HKEY_LOCAL_MACHINE, "SOFTWARE\\Google\\Chrome")) {
			count++;
	}
	if (pafish_exists_regkey(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Edge")) {
			count++;
	}
	if (pafish_exists_regkey(HKEY_LOCAL_MACHINE, "SOFTWARE\\Mozilla\\Firefox")) {
			count++;
	}
	return count <= 1;
}

int spotlesssand_syssrc(){
	DWORD ret = ERROR_SUCCESS;
	LPWSTR channelName = L"SYSTEM";
	LPWSTR query = L"*";
	//EVT_HANDLE results = EvtQuery(NULL, channelName, query, EvtQueryChannelPath | EvtQueryReverseDirection);
	return 0;
}

int spotlesssand_autorun(){
	HKEY regkey;
	LONG ret;
	int count = 0;
	FILETIME ftLastWriteTime;

	//HKLM
	if (pafish_iswow64()){
		ret = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_READ | KEY_WOW64_64KEY, &regkey);
	} else {

		ret = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_READ, &regkey);
	}
	if (ret == ERROR_SUCCESS){
		for (int i = 0; i < 200; i++){
			DWORD subkeyLength = 255;
			TCHAR subkeyName[255];
			ret = RegEnumValueA(regkey, i, subkeyName, &subkeyLength, NULL, NULL, NULL, NULL);
			if (ret == 259){
				count = i;
				break;
			}
		}
	}

	//HKCU
	if (pafish_iswow64()){
		ret = RegOpenKeyEx(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_READ | KEY_WOW64_64KEY, &regkey);
	} else {

		ret = RegOpenKeyEx(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_READ, &regkey);
	}
	if (ret == ERROR_SUCCESS){
		for (int i = 0; i < 200; i++){
			DWORD subkeyLength = 255;
			TCHAR subkeyName[255];
			ret = RegEnumValueA(regkey, i, subkeyName, &subkeyLength, NULL, NULL, NULL, NULL);
			if (ret == 259){
				count += i;
				break;
			}
		}
	}
	printf("%i autorun apps!", count);
	return count < 2;
}
