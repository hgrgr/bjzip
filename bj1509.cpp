#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string str;
int cache[2501][2501];
char temp[2501];
int min_cache[2501];
int juge(int start, int end);
int cal_min();
int main(){
    cin >> str;
    for(int i=0;i<str.length();i++)
        temp[i+1] = str[i];
    memset(cache,-1,sizeof(cache));
    memset(min_cache,-1,sizeof(min_cache));
    cout << cal_min();
    /*
    cout << endl;
    for(int i=0; i<= str.length();i++)
        cout << min_cache[i]<< " ";
    cout << endl;
    */
    return 0;
}

int juge(int start, int end){
    if(start >= end)
        return true;

    int& ref = cache[start][end];
    if(ref !=-1)
        return ref;
    if(temp[start] != temp[end])
        return ref=false;
    
    return ref = juge(start +1, end -1);
}
int cal_min(){
    min_cache[0] = 0;
    for(int end = 1;end <= str.length();end++){
        min_cache[end] = 987654321;
        for(int start = 1; start <= end; start++)
        {
            if(juge(start,end))
                min_cache[end] = min(min_cache[end], min_cache[start -1]+1);
        }
    }
    return min_cache[str.length()];
}
