
#include <windows.h>
#include <stdio.h>

#include "types.h"
#include "cpu.h"

static inline int rdtsc_diff() {
	unsigned long long ret, ret2;
	unsigned eax, edx;

	__asm__ volatile("rdtsc" : "=a" (eax), "=d" (edx));
	ret  = ((unsigned long long)eax) | (((unsigned long long)edx) << 32);
	__asm__ volatile("rdtsc" : "=a" (eax), "=d" (edx));
	ret2  = ((unsigned long long)eax) | (((unsigned long long)edx) << 32);

	return ret2 - ret;
}

static inline void cpuid_vendor_00(char * vendor) {
	int eax, ebx, ecx, edx;

	__asm__ volatile("cpuid" \
			: "=b"(ebx), \
			  "=c"(ecx), \
			  "=d"(edx) \
			: "a"(0x00));
	sprintf(vendor  , "%c%c%c%c", ebx, (ebx >> 8), (ebx >> 16), (ebx >> 24));
	sprintf(vendor+4, "%c%c%c%c", edx, (edx >> 8), (edx >> 16), (edx >> 24));
	sprintf(vendor+8, "%c%c%c%c", ecx, (ecx >> 8), (ecx >> 16), (ecx >> 24));
	vendor[12] = 0x00;
}

static inline int cpuid_hv_bit() {
	int ecx;
	__asm__ volatile("cpuid" \
			: "=c"(ecx) \
			: "a"(0x01));
	return (ecx >> 31) & 0x1;
}

int cpu_rdtsc() {
	int i, avg = 0, diff;
	for (i = 0; i < 10; i++) {
		diff = rdtsc_diff();
		avg = avg + diff;
		Sleep(500);
	}
	return (avg / 10) > 750 ? TRUE : FALSE;
}

int cpu_hv() {
	return cpuid_hv_bit() ? TRUE : FALSE;
}

void cpu_write_vendor(char * vendor) {
	cpuid_vendor_00(vendor);
}
