#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 987654321
using namespace std;
int n;
map<int,int> m_map;
map<int,int>::iterator it;
vector<int> m_vec;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int tmp;
    double avg =0;
    for(int i=0;i<n;i++){
        cin >> tmp;
        avg +=tmp;
        m_map[tmp]++;
        m_vec.push_back(tmp);
    }
    int max_value = 0;
    for(it = m_map.begin();it != m_map.end(); it++){
        max_value = max(max_value, it->second);
    //    cout << it->first << " " << it->second << endl;  
    }
    int ck =0;
    int many;
    for(it = m_map.begin();it != m_map.end(); it++){
        if(it->second == max_value && ck <= 1){
            many = it->first;
            ck++; 
        }
    }
    sort(m_vec.begin(),m_vec.end());
    cout << floor(avg/n + 0.5)<< endl;
    cout << m_vec[m_vec.size()/2] << endl;
    cout << many << endl;
    cout << m_vec[m_vec.size()-1] - m_vec[0] << endl;

    

    return 0;
}
