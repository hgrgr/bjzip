#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int n;
int counter;
vector<int> stu;
vector<int> discover;
vector<int> finish;
vector<int> cyclic;
void dfs2(int here);
void ck_cyc(int here, int target);
int main(){
    int tcase;
    cin >> tcase;
    for(int t=0;t<tcase;t++){
        cin >> n;
        stu.clear();
        discover.clear();
        finish.clear();
        cyclic.clear();

        cyclic.resize(n+1,0);
        stu.resize(n+1,0);
        discover.resize(n+1,-1);
        finish.resize(n+1,0);
        for(int i=1;i<=n;i++)
            cin >> stu[i];
        for(int i=1;i<=n;i++){
            if(discover[i]==-1)
                dfs2(i);
        }
        int a_num=0;
        for(int i=1;i<=n;i++)
            if(cyclic[i] == 0)
                a_num++;
        cout << a_num<<endl;
    }
    return 0;
}
void dfs2(int here){
    discover[here] = counter++;
    int next = stu[here];
    if(discover[next] == -1){
        dfs2(next);
    }
    else{
        if(discover[next] > discover[here]){//forword

        }else if(finish[next] == 0){//back
            ck_cyc(next,here);
            
        }else {//edge
        }
    }
    finish[here] = 1;
}
void ck_cyc(int here, int target){
    cyclic[here] = 1;
    if(here == target)
        return;
    ck_cyc(stu[here],target);
}
