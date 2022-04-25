#include <iostream>
#include <cstring>
#include <string>
#include <deque>
using namespace std;
int k,n;
string str;
deque<char> dq;
int main(){
    cin >> k >> n;
    cin >> str;
    for(int i=0;i<k;i++)
    {
        while(n && !dq.empty() && dq.back() < str[i])
        {
            dq.pop_back();
            n--;
        }
        dq.push_back(str[i]);
    }
    for(int i=0; i < dq.size()-n;i++)
        cout << dq[i];
    return 0;
}
