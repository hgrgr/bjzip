#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define INF -987654321
using namespace std;
typedef long long ll;
int n;
vector<int> arr;
priority_queue<int,vector<int>,less<int> > p_pq;
priority_queue<int,vector<int>,greater<int> > m_pq;
ll total;
int main(){
    cin >> n;
    arr.resize(n+1);
    int temp = 0;
    for(int i=0;i<n;i++)
    {
        cin >> temp;
        if(temp > 0)
            p_pq.push(temp);
        else
            m_pq.push(temp);
    }
    
    while(1){
        if(p_pq.size() <= 1)
            break;
        int first = p_pq.top();
        p_pq.pop();
        int second = p_pq.top();
        p_pq.pop();
        total += max(first * second, first+second);
    }
    while(1){
        if(m_pq.size() <= 1)
            break;
        int first = m_pq.top();
        m_pq.pop();
        int second = m_pq.top();
        m_pq.pop();
        total += max(first * second, first+second);
    }
    int m_tmp = INF;
    if(p_pq.size() == 1 && m_pq.size() == 1)
    {
        m_tmp = max(m_tmp, p_pq.top() * m_pq.top());
        m_tmp = max(m_tmp, p_pq.top() + m_pq.top());
    }else if(p_pq.size() == 1){
        m_tmp = p_pq.top();
    }else if(m_pq.size() == 1){
        m_tmp = m_pq.top();
    }
    if(p_pq.empty() && m_pq.empty())
        m_tmp = 0;
    cout << total + m_tmp;
    return 0;
}
