#include <iostream>
#include <cstring>
using namespace std;
int n,m;
int s,e;
int arr[2001];
int cache[2001][2001];
int judge(int start, int end);
int main(){
    cin >> n;
    memset(arr,-1,sizeof(int)*2001);
    memset(cache,-1,sizeof(int)*2001*2001);
    for(int i=1; i <= n; i++)
        scanf("%d",&arr[i]);
    cin >> m;
    for(int i=0; i< m; i++ ){
        scanf("%d %d",&s,&e);
        printf("%d\n",judge(s,e));
    }
    return 0;
}
int judge(int start, int end){
    if(start == end)
        return true;
    else if(arr[start] != arr[end])
        return false;
    int& ref = cache[start][end];
    if(ref != -1)
        return ref;
    ref = true;
    int mid = (start + end)/2;
    for(int next=start+1;next<=mid;next++){
        if(judge(next,end+start-next) == false)
            ref = false;
    }
    return ref;
}
