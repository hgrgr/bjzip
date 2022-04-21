#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n;
int arr[101];
int main()
{
    int tcase;
    int temp;
    cin >> tcase;
    priority_queue<int, vector<int>, greater<int> > my_queue;
    for(int i=0; i < tcase;i++)
    {
        cin >> n;
        for(int j=0; j < n;j++)
        {
            cin >> temp;
            my_queue.push(temp);
        }
        int result = 0;
        int addstr=0;
        while(my_queue.size() > 1)
        {
            int min1 = my_queue.top(); my_queue.pop();
            int min2 = my_queue.top(); my_queue.pop();
            my_queue.push(min1+min2);
            result += min1 + min2;
        }
        cout << result << endl;
        while(!my_queue.empty()) my_queue.pop();
    }
    return 0;
}
