#include <iostream>
#include <cstring>
using namespace std;
string s1,s2,s3;
int cache[101][101][101];
int num_lcs(int p1,int p2,int p3);
int main(){
    cin >> s1 >> s2 >> s3;
    memset(cache,-1, sizeof(cache));
    cout << num_lcs(0,0,0) << endl;
    return 0;
}
int num_lcs(int p1,int p2,int p3){
    if( p1 == s1.length() || p2 == s2.length() || p3 == s3.length()){
        return 0;
    }
    int& ref = cache[p1][p2][p3];
    if(ref != -1)
        return ref;
    ref = 0;
    if(s1[p1] == s2[p2] && s2[p2] == s3[p3])
        ref = max(ref, num_lcs(p1+1, p2+1,p3+1)+1);
    ref = max(ref, num_lcs(p1+1, p2,p3));
    ref = max(ref, num_lcs(p1, p2+1,p3));
    ref = max(ref, num_lcs(p1, p2,p3+1));
    ref = max(ref, num_lcs(p1+1, p2+1,p3));
    ref = max(ref, num_lcs(p1, p2+1,p3+1));
    return ref;
}
