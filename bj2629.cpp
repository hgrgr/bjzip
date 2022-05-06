#include <iostream>
#include <cstring>
using namespace std;
int n,k;
int arr[31];
int cache[15001+40000];
void print_table(int size);
int main(){
    cin >> n;
    memset(cache,0,sizeof(cache));
    int total =0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        total +=arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=total;j-arr[i]>=0;j--){
            if(j == arr[i])
                cache[arr[i]] = true;
            else if(cache[j-arr[i]] == true)
                cache[j] = true;
        } 
    }
    cin >> k;
    int tmp;
    bool ck=false;
    for(int i=0;i<k;i++){
        ck = false;
        cin >> tmp;
        for(int j=0;j+tmp<=total;j++){
            if(cache[j] == true)
            {
                if(cache[j+tmp] == true){
                    ck = true;
                    break;
                }
            }
        }
        if(ck || cache[tmp])
            cout <<"Y ";
        else
            cout <<"N ";
    }
    return 0;
}
