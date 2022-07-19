#include<iostream>
#include<cstring>
#include <algorithm>
using namespace std;
int cal_num(int num);
int cache[1001];
int arr[1001];
int n;
int main(){
	cin >> n;
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << cal_num(-1);


}
int cal_num(int num) {
	if (num == n)
		return 0;
	int& ref = cache[num+1];
	
	if (ref != -1)
		return ref;
	ref = 0;
	for (int next = num + 1; next < n; next++) {
		if (num == -1 || arr[num] > arr[next]) {
			ref = max(ref, cal_num(next)+1);

