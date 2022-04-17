#include <iostream>
#include <string.h>
using namespace std;

int main(){

    char a = 0x12;
    short c = 0x5678;
    char b=0x34;
    int t;
    char temp[4];
    printf("%d %d %d\n", &a, &c, &b);
    int *ta = (int*)&b;
    printf("0x%x \n", *ta);

    temp[3] = a;
    temp[2] = b;
    memcpy(&temp[0],&c,sizeof(short));
    memcpy(&t,temp,sizeof(int));
    printf("0x%x\n",t);
}
