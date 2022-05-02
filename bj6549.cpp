#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
int rect[100001];
ll hig[100001];
ll max_rect(int left, int right);
int main(){
    while(1){
        memset(rect,-1,sizeof(rect));
        memset(hig,-1,sizeof(hig));
        cin >> n;
        if(n == 0)
            break;
        for(int i=0; i<n; i++)
        {
            cin >> hig[i];
        }
        cout << max_rect(0,n-1) << endl;
    }
    

    return 0;
}
ll max_rect(int left, int right){
    if(left == right)
        return hig[left];
    int mid = (left + right)/2;
    ll ret = max(max_rect(left,mid), max_rect(mid+1,right));
    int lo =mid, hi=mid+1;
    ll height = min(hig[lo],hig[hi]);
    ret = max(ret,height*2);
    while(left < lo || hi < right){
        if(hi < right && (left == lo || hig[lo-1] < hig[hi+1]))
        {
            hi++;
            height = min(height,hig[hi]);
        }
        else {
            lo--;
            height = min(height,hig[lo]);
        }
        ret = max(ret, (ll)height*(hi - lo + 1));
        
    }
    return ret;
}
