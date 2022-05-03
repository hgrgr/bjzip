#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string s1,s2;
int cache[1002][1002];
int l_cache[1002];
int start = 0;
int num_lcs(int p1, int p2);
void print_str(int p1,int p2);
int main(){
    cin >> s1 >> s2;
    memset(cache,-1,sizeof(cache));
    memset(l_cache,-1,sizeof(l_cache));
    int ret;
    if( !(ret = num_lcs(0,0))){
        cout << ret<<endl;
        return 0;
    }else
    {
        cout << ret << endl;
        print_str(0,0);
        return 0; 
    }
    return 0;
}
int num_lcs(int p1, int p2){
    if(p1 == s1.length() || p2 == s2.length())
        return 0;
    int& ref = cache[p1][p2];
    if( ref != -1 )
        return ref;
    ref = 0;
    int tmp;
    if(s1[p1] == s2[p2]){
        return ref= num_lcs(p1+1,p2+1)+1;
    }
    else 
        return ref = max(num_lcs(p1+1,p2),num_lcs(p1,p2+1));
}
void print_str(int p1,int p2){
    if(p1 == s1.length() || p2 == s2.length())
        return;
    if(s1[p1] == s2[p2]){
        cout << s1[p1];
        print_str(p1+1,p2+1);
    }else if(cache[p1+1][p2] >= cache[p1][p2+1]){
        print_str(p1+1,p2);
    }else
        print_str(p1,p2+1);
    
}
