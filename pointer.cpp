#include <iostream>
using namespace std;

int main(){
    int a = 3;
    int b = 6;

    int* paa = &a;
    int** ppaa = &paa;
    
    printf("%d\n",a);
    printf("%d\n",b);
    printf("%d\n",paa);//a 주소값 - 성신k
    printf("%d\n",*paa);//a 주소값이 저장되어 있음 
    
    printf("%d\n",ppaa);//a 주소값이 저장되어 있음 
    printf("%d\n",*ppaa);//a 주소값이 저장되어 있음 
    printf("%d\n",**ppaa);//a 주소값이 저장되어 있음 
    return 0;
}
