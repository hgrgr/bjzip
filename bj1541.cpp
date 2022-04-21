#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#include <stdlib.h>
using namespace std;
string n;
int op_num;
vector<pair<int,int> > sub_op;
int main(){
    cin >> n;
    int tmp = 0;
    vector<int> number;
    int j = 0;
    int pre_sub = 0;
    int cur_sub = 0;

    for(int i=0;i<n.length();i++){
        if(i == n.length()-1){//last
            tmp *= 10;
            tmp += n[i] - '0';
            number.push_back(tmp);
        }
        else if(n[i] == '-'){
            number.push_back(tmp);
            j++;
            tmp = 0;
            pre_sub = cur_sub;
            cur_sub = j;
            sub_op.push_back(make_pair(pre_sub,cur_sub));
        }  
        else if(n[i] == '+'){
            number.push_back(tmp);
            j++;
            tmp = 0;
        }else{
           tmp *= 10;
           tmp += n[i] - '0';
        }
    }/*
    cout << endl;
    for(int i=0; i<number.size();i++)
        cout << number[i]<< " ";
    cout << endl;
    */
    int result = 0;
    if(sub_op.empty()){
        for(int i=0; i<number.size();i++)
            result +=number[i];
    }else{
        int start = sub_op[0].first;
        int end = sub_op[0].second;
        for(int i=0; i<end;i++)
            result +=number[i];
        for(int i=end; i<number.size();i++)
            result -=number[i];
    }
    cout << result << endl;
    return 0;
}
