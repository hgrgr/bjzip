#include <iostream>
#include <string>
using namespace std;

char arr[10000];
int arr_len;
int cache[10000][3];
int cache2[10000];
int cal_com(int begin, int len)
{
    int result = -1;
    int ck_bit = 1;
    for(int i=0; i<len-1; i++)
    {
        if(arr[begin+i] != arr[begin+i+1]){
            ck_bit = 0;
            break;
        }
    }
    if(ck_bit == 1)
        return 1;
    
    for(int i=0; i<len-1; i++)
    {
       if(arr[begin+i] - arr[begin+i+1] != 1)
       {
           ck_bit = 0;
           break;
       }
    }
    if(ck_bit == 1)
        return 2;

    for(int i=0; i<len-2; i++)
    {
        if(arr[begin+i] != arr[begin+i+2])
        {
            ck_bit =0;
            break;
        }

    }
    if(ck_bit ==1)
        return 4;

    for(int i=0; i<len-2; i++)
    {
       if(arr[begin+i] - arr[begin+i+1] != arr[begin+i+1] - arr[begin+i+2])
       {
           ck_bit = 0;
           break;
       }
    }
    if(ck_bit == 1)
        return 5;

    return 10;

}

int min_complex(int begin){
    
    if(begin == arr_len)
        return 0;
    int& ret = cache2[begin];
    if(ret != -1)
        return ret;

    int ck_bit =0;
    ret = 987654321;

    for(int i=3; i<=5;i++){
        if(i + begin < arr_len)
            ret = min(ret, min_complex(begin+i) + cal_com(begin, i));
    }
    return ret;
}
int main(){
    int tcase;
    cin >> tcase;

    for(int i=0; i < tcase; i++)
    {
        cin >> arr;
        arr_len = strlen(arr);
        memset(cache,-1,sizeof(int)*10000*3);
        memset(cache2,-1,sizeof(int)*10000);
        int result = min_complex(0);
        cout << result<<endl;
    }
    return 0;
}
