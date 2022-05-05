#include <iostream>
#include <cstring>
#define TYPE1 3
#define TYPE2 6
#define TYPE3 12
#define TYPE4 9
#define TYPE5 0
#define FULL 15
using namespace std;
typedef long long ll;
int n;
ll cache[100000][1<<4];
ll cal_tile(int size,int state); 
int main(){
    int tcase;
    cin >> tcase;
    memset(cache,-1,sizeof(cache));
    for(int i=0; i< tcase; i++){
        cin >> n;
        cout << cal_tile(n,0)<<endl;
    }

    return 0;
}
ll cal_tile(int size,int state){
    if(size < 0)
        return  0;
    if(size == 0)
        return state == TYPE5;

    ll& ref = cache[size][state];
    if(ref != -1)
        return ref;
    ref = 0;
    switch(state){
        case TYPE1:
            ref +=cal_tile(size-1,TYPE3);
            ref +=cal_tile(size-1,TYPE5);
            break;
        case TYPE2:
            ref += cal_tile(size-1,TYPE4);
            break;
        case TYPE3:
            ref += cal_tile(size-1,TYPE5);
            ref += cal_tile(size-1,TYPE1);
            break;
        case TYPE4:
            ref += cal_tile(size-1,TYPE2);
            ref += cal_tile(size-1,TYPE5);
            break;
        case TYPE5:
            ref += cal_tile(size-1,TYPE4);
            ref += cal_tile(size-1,TYPE3);
            ref += cal_tile(size-1,TYPE1);
            ref += cal_tile(size-1,TYPE5);
            ref += cal_tile(size-2,TYPE5);
            break;
    }
    return ref;
    
}
