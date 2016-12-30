#include<iostream>
using namespace std;
int main() {
	int count;
	int first, second, times = 0;
	bool is_first = true;
	cin >> count;
	while (count--) {
		cin >> second;
		if (is_first) {
			is_first = false;
			times += second * 6 + 5;
			first = second;
			continue;
		}
		else {
			if (second > first) {
				times += (second - first) * 6 + 5;
			}
			else if (second < first)
				times += (first - second) * 4 + 5;
			else
				times += 5;
			first = second;
		}
	}
	cout << times;
	system("pause");
	return 0;
}