#include <iostream>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
using namespace std;

void dump(void* p, size_t n) {
    uint8_t* u8 = static_cast<uint8_t*>(p);
    size_t i = 0;
    while (true) {
        printf("%02X ", *u8++);
        if (++i >= n) break;
        if (i % 8 == 0)
            printf("\n");
    }
    printf("\n");
}

void write_0x12345678() {
    uint32_t total;
    uint32_t num1;
    FILE* file1;
    file1 = fopen("/tmp/qt-ex/add_nbo/thousand.bin","rb");
    if(file1 == NULL){
        printf("error");
    }
    fread(&num1, 4, 1, file1);
//    printf("0x%04x\n", ntohl(num1));
    fclose(file1);

    uint32_t num2;
    FILE* file2;
    file2 = fopen("/tmp/qt-ex/add_nbo/five-hundred.bin","rb");
    if(file2 == NULL){
        printf("error");
    }
    fread(&num2, 4, 1, file2);
//    printf("0x%04x\n", ntohl(num2));
    fclose(file2);

    total = ntohl(num1)+ntohl(num2); // total
    printf("%d(0x%04x) + %d(0x%04x) = %d(0x%04x)\n",ntohl(num1), ntohl(num1),ntohl(num2), ntohl(num2), total,total);
}

int main() {
    write_0x12345678();
}
