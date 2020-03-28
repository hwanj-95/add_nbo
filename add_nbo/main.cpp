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

void add_nbo() {
    uint32_t total; //file1 + file2 value
    uint32_t num1; //file1 value 16
    uint32_t num2; //file2 value 16
    uint32_t change1; //LE > BE
    uint32_t change2; //LE > BE
    FILE* file1; // file1 open pointer
    FILE* file2; // file2 open pointer
    file1 = fopen("./thousand.bin","rb"); // file1 open
    file2 = fopen("./five-hundred.bin","rb");// file2 open

    if(file1 == NULL || file2 == NULL) {
        printf("error\n");
        exit(1);
    }

    fread(&num1, sizeof(uint32_t), 1, file1); //read file1
    fread(&num2, sizeof(uint32_t), 1, file2); //read file2

    change1 = ntohl(num1); //LE > BE
    change2 = ntohl(num2); //LE > BE

    total = change1+change2; // total
    printf("%d(0x%04x) + %d(0x%04x) = %d(0x%04x)\n",change1, change1, change2, change2, total,total);

    fclose(file1);
    fclose(file2);

}

int main() {
    add_nbo();
}





//    if(ntohl(num1) == 0 ){
//        printf("error1\n");
//        exit(1);
//    }
//    printf("0x%04x\n", ntohl(num1));
//    fclose(file1);

//    file2 = fopen("/home/hwan95/add_nbo/add_nbo/five-hundred.bin","rb");
//    if(file2 == NULL){
//        printf("error2\n");
//        exit(1);
//    }
//    fread(&num2, 4, 1, file2);
//    printf("0x%04x\n", ntohl(num2));
//    fclose(file2);

//    total = ntohl(num1)+ntohl(num2); // total
//    printf("%d(0x%04x) + %d(0x%04x) = %d(0x%04x)\n",ntohl(num1), ntohl(num1),ntohl(num2), ntohl(num2), total,total);
//}
