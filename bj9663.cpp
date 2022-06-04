#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int n;
int pan[16][16];
int moving[3][2] = {
    {-1,1},
    {0,1},
    {1,1}
};
int num_case;
void find_q(int line);
void print_pan();
int main(){
    cin >> n;
    memset(pan,0,sizeof(pan));
    find_q(0); 
    cout << num_case;
    return 0;
}
void find_q(int line){
    if(line == n){
        num_case++;
        return;
    }

    int t_pan[16][16];
    memcpy(t_pan,pan,sizeof(pan));
    int ck_bit = 0;
    for(int tup=0;tup<n;tup++)
    {
        if(pan[tup][line] == 0){
            ck_bit = 1;
            pan[tup][line] = 2;
            for(int k=0;k<3;k++){
                int t_y = tup;
                int t_x = line;
                while(1){
                    if(t_y+moving[k][0] >=0 && t_y+moving[k][0] < n &&
                            t_x+moving[k][1] >= 0 && t_x+moving[k][1] < n)
                    {
                        pan[t_y+moving[k][0]][t_x+moving[k][1]] = 1;
                        t_y += moving[k][0];
                        t_x += moving[k][1];
                        continue;
                    }
                    break;
                }
            }
            find_q(line+1);
            memcpy(pan,t_pan,sizeof(t_pan));
        }
    }
}
