#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int arr[100];
int pSum[101];
int pSqSum[101];
int n,s;
int cache[101][11];
void precalc(){
    sort(arr,arr+n);
    pSum[0] = arr[0];
    pSqSum[0] = arr[0] *arr[0];
    for(int i=1;i<n;i++)
    {
        pSum[i] = pSum[i-1] + arr[i];
        pSqSum[i] = pSqSum[i-1] + arr[i]*arr[i];
    }
}
int cal_err(int lo, int hi){
    int sum = pSum[hi] - (lo ==0 ? 0 : pSum[lo-1]);
    int sqSum =pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo-1]);

    int m = int(0.5 + (double)sum / (hi -lo +1));
    int ret = sqSum -2*m*sum + m*m*(hi -lo +1);
    return ret;
    /*
    int sum =0;
    for(int i=begin; i<=end;i++)
    {
        sum += arr[i];
    }
    sum = sum / end - begin +1;
    int total;
    for(int i=begin; i<end; i++)
    {
        total += abs(arr[i] - sum) * abs(arr[i] - sum);
    }
    return total;
    */
}
int min_err(int begin, int num){

    if(begin == n)
        return 0;
    if(num == 0)
        return 98765421;
   
    int& ref = cache[begin][num];
    if(ref != -1)
        return ref;

    ref = 987654321;

    for(int i=1; begin+i<=n;i++)
    {
       ref = min(ref, min_err(begin+i,num -1) + cal_err(begin,begin + i -1)); 
    }
    return ref;
}
int main()
{
    int tcase;
    cin >> tcase;
    int result = 0;
    for(int i=0; i<tcase; i++)
    {
        cin >> n >> s;
        memset(cache,-1,sizeof(int)*100);
        for(int j=0; j<n;j++)
            cin >> arr[j];
        precalc();
        for(int j=0; j < n; j++)
        {
            cout << arr[j]<< " ";
        }
        cout << endl;
        result = min_err(0,s);

        cout << result << endl;

    }
}
