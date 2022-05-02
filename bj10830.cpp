#include <iostream>
#include <cstring>
#define MOD 1000
using namespace std;
typedef long long ll;
typedef struct {
    int mat[6][6];
}MT;
int n;
ll b;
MT temp;
MT make_mat(ll size);
MT mul_mat(MT& a,MT& b);
int main(){
    cin >> n >> b;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> temp.mat[i][j] ;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            temp.mat[i][j] %= 1000;
    MT t = make_mat(b);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << t.mat[i][j]<< " ";
        }
        cout << endl;
    }
    return 0;
}
MT make_mat(ll size){
    if(size == 1)
        return temp;
    ll mid;
    MT c,a;
    if((size % 2) == 1){// odd
        mid = (size-1) / 2;
        a = make_mat(mid);
        c = mul_mat(a,a);
        c = mul_mat(c,temp);
    }else{
        mid = size/2;
        a = make_mat(mid);
        c = mul_mat(a,a);
    }
    return c;
}
MT mul_mat(MT& a,MT& b){
    ll t=0;
    MT c;
    for(int i=0; i<n; i++)
    {
        for(int j=0;j<n;j++){
            t=0;
            for(int k=0;k<n;k++)
            {
                t += (a.mat[i][k] * b.mat[k][j]) % MOD;
            }
            c.mat[i][j] = t % MOD;
        }
    }
    return c;
}
