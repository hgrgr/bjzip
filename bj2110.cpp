#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n,c;
vector<int> house;
bool find_gap(int gap);
int main(){
    cin >> n >> c;
    int tmp;
    for(int i=0;i<n;i++){
        scanf("%d",&tmp);
        house.push_back(tmp);
    }
    sort(house.begin(),house.end());
    double lo, hi,mid;
    lo = 0;
    hi = 1000000000;
    for(int i=0;i<100;i++){
        mid = (hi + lo) /2.0;
        if(find_gap(mid)){
            lo = mid;
        }
        else{
            hi = mid;
        }
    }
    cout << lo -1;
    return 0;
}
bool find_gap(int gap){
    int num=0;
    int start = -1;
    for(int i=0;i<n;i++){
        if(start <= house[i]){
            start = house[i] + gap;
            num++;
        }
    }
    if(num < c)
        return false;
    else 
        return true;
}
