#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
int n;
ll h[100001];
ll max_rect(int left, int right);
int main(){
    cin >> n;
    memset(h,-1,sizeof(h));
    for(int i=0; i<n; i++)
    {
        cin >> h[i];
    }
    cout << max_rect(0,n-1) << endl;
    return 0;
}
ll max_rect(int left, int right){
    if(left == right)
        return h[left];
    int mid = (left + right) / 2;
    ll ret = max(max_rect(left,mid), max_rect(mid+1,right));
    int lo = mid, hi = mid+1;
    ll height = min(h[lo],h[hi]);
    ret = max(ret, height*2);

    while(left < lo || hi < right){
        if( hi < right && (left == lo || h[lo-1] < h[hi+1])){
            hi++;
            height = min(height,h[hi]);
        }else{
            lo--;
            height = min(height,h[lo]);
        }
        ret = max(ret, height*(hi - lo + 1));
    }
    return ret;
}
