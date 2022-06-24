#include <iostream>
#include <cstring>
using namespace std;
//(100+1+ | 01)+
int grah[8][2];
int s1,s2;
bool ck_state(string& s_tmp, int pos, int state);
int main(){
    grah[0][0] = 2;
    grah[0][1] = 1;
    grah[1][0] = 3;
    grah[1][1] = 7;
    grah[2][0] = 7;
    grah[2][1] = 4;
    grah[3][0] = 5;
    grah[3][1] = 7;
    grah[4][0] = 2;
    grah[4][1] = 1;
    grah[5][0] = 5;
    grah[5][1] = 6;
    grah[6][0] = 2;
    grah[6][1] = 6;
    grah[7][0] = 7;
    grah[7][1] = 7;
    int tcase;
    cin >> tcase;
    for(int t=0;t<tcase;t++)
    {
        string temp;
        cin >> temp;
        if(ck_state(temp,0,0))
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}
bool ck_state(string& s_tmp, int pos, int state){
    if(state == 7)
        return false;
    if(state == 6)
        s1 = 1;
    if(state ==4)
        s2 = 1;
    if(pos == s_tmp.length() && (s1 == 1 || s2 == 1) && (state == 4 || state == 6))
        return true;
    else if (pos == s_tmp.length())
        return false;
    if(state == 6 && s_tmp[pos] == '1')
        return (ck_state(s_tmp,pos+1,1) || ck_state(s_tmp,pos+1,6));
    else
        return ck_state(s_tmp,pos+1,grah[state][(int)s_tmp[pos]-(int)'0']);
}
