#include<iostream>
#include<cstring>
using namespace std;
int cal_num(int num);
int cache[11];
int main(){

	int tcase;
	cin >> tcase;
	for (int t = 0; t < tcase; t++) {
		int n;
		cin >> n;
		memset(cache, -1, sizeof(cache));
		cout << cal_num(n)<<endl;
	}
}
int cal_num(int num) {
	if (num < 0)
		return 0;
	if (num == 0)
		return 1;
	int& ref = cache[num];
	if (ref != -1)
		return ref;
	ref = 0;
	ref = cal_num(num - 1) + cal_num(num - 2) + cal_num(num-3);
	return ref;
}
