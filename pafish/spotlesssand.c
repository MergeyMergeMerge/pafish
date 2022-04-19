#include <string.h>
#include <windows.h>

#include "spotlesssand.h"

int spotlesssand_clscount(){
	HKEY regkey;
	LONG ret;
	int count = 0;
	if(pafish_iswow64()){
		ret = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SYSTEM/CurrentControlSet/Enum/USB", 0, KEY_READ | KEY_WOW64_64KEY, &regkey);
	} else {

		ret = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SYSTEM/CurrentControlSet/Enum/USB", 0, KEY_READ, &regkey);
	}
	if (ret == ERROR_SUCCESS){
		for (int i = 0; i < 200; i++){
			ret = RegEnumKeyExA(regkey, i, NULL, 0, NULL, NULL);
			if (ret != ERROR_SUCCESS){
				count = i;
				break;
			}
		}
	}
	printf("%s", count)	
	return 0;
}

int spotlesssand_totalproc(){
	return 0;
}

int spotlesssand_uniqueurl(){
	return 0;
}

int spotlesssand_dnscache(){
	return 0;
}

int spotlesssand_totalcookies(){
	return 0;
}
