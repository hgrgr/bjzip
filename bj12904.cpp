#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
string s,t;
int main()
{
    cin >> s >> t;
    for(int i=t.length()-1;i>=0;i--)
    {
        if(t.length() == s.length()){
            if(s == t)
            {
                cout <<"1";
            }
            else{
                cout <<"0";
            }
            break;
        }
        else{
            if(t[i] == 'A')
            {
                t.erase(i);
            }
            else if(t[i] == 'B')
            {
                t.erase(i);
                reverse(t.begin(),t.end());
            }
        }
    }
    return 0;
}
