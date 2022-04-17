#include <iostream>
using namespace std;

int n,d,p;
int t,q;
int town[51][51];
int town_num[51];
int dig[51];
double cache[51][101];

double find_docter(int here,int days){

    if(days == d){
        return (here == q ? 1.0 : 0.0);
    }
    double& ref = cache[here][days];

    if(ref > -0.9)
        return ref;

    ref = 0.0;
    for(int i=0; i < n; i++)
    {
        if(town[here][i] == 1)//find spot
        {
            ref += find_docter(i,days+1) / dig[here];
        }    
    }
    return ref;
}
int main()
{
    int tcase;
    cin >> tcase;
    for(int i=0; i < tcase; i++)
    {
        cin >> n >> d >> p;
        
        memset(cache,-1,sizeof(double)*51*101);
        memset(town,-1,sizeof(int)*51*51);
        memset(town_num,-1,sizeof(int)*51);
        memset(dig,0,sizeof(int)*51);

        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                cin >> town[j][k];
        cin >> t;

        for(int j=0; j<t;j++)
            cin >> town_num[j];
        
        for(int j=0;j<n;j++){
            for(int k=0; k<n;k++){
                if((town[j][k]) == 1)
                    dig[j] += 1;
            }
        }
        double result =0;
        for(int j=0; j <t; j++)
        {
            q = town_num[j];
            memset(cache,-1,sizeof(double)*51*101);
            result = find_docter(p,0);
            cout << result << " ";
        }
        cout << endl;
    }
}
