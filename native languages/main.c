#include <stdio.h>

void get_cpuid(int code, unsigned int *a, unsigned int *b, unsigned int *c, unsigned int *d) {
    __asm__ volatile("cpuid"
                     : "=a"(*a), "=b"(*b), "=c"(*c), "=d"(*d)
                     : "a"(code));
}

int main() {
    unsigned int eax, ebx, ecx, edx;

    // Method 1: Check the 31st bit of ECX with EAX=1
    get_cpuid(1, &eax, &ebx, &ecx, &edx);
    int hypervisor_present = (ecx >> 31) & 1;
    if (hypervisor_present) {
        printf("Hypervisor detected using Method 1 (ECX bit 31 is set).\n");
    } else {
        printf("No hypervisor detected using Method 1 (ECX bit 31 is not set).\n");
    }

    // Method 2: Retrieve hypervisor brand with EAX=0x40000000
    get_cpuid(0x40000000, &eax, &ebx, &ecx, &edx);
    if (eax != 0) { // Check if there’s any hypervisor information
        char hypervisor_brand[13];
        snprintf(hypervisor_brand, 13, "%s%s%s", (char *)&ebx, (char *)&ecx, (char *)&edx);
        printf("Hypervisor brand: %s\n", hypervisor_brand);
    } else {
        printf("No hypervisor brand detected using Method 2.\n");
    }

    return 0;
}
