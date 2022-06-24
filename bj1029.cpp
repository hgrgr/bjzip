#include <iostream>
#include <cstring>
using namespace std;
int n;
int cache[1<<16][15][10];
int arr[16][16];
int cal_people(int state, int pos, int cost);
int main(){
    cin >> n;
    char tmp;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin >> tmp;
            arr[i][j] = (int)tmp - (int)'0';
        }
    memset(cache,-1,sizeof(cache)); 
    cout << cal_people(1,0,0) + 1; 
    return 0;
}
int cal_people(int state, int pos, int cost){
    int& ref = cache[state][pos][cost];
    if(ref != -1)
        return ref;
    ref = 0;
    for(int i=0;i<n; i++){
        if(i == pos)
            continue;
        if( !(state & (1<<i)) && (arr[pos][i] >= cost)){
            ref = max(ref, cal_people((state | (1<<i)),i,arr[pos][i])+1);
        }
    }
    return ref;
}
