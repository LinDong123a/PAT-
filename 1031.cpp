#include<iostream>
#include<string>
using namespace std;
int main() {
	string input;
	cin >> input;
	int n1, n2, n3;
	n1 = n3 = (input.size() + 2) / 3;
	n2 = input.size() + 2 - n1 * 2;
	int middle_start = n1 - 1;
	for (int i = 0; i < n1 - 1; ++i) {
		cout << input[i];
		for (int j = 0; j < n2 - 2; ++j)
			cout << ' ';
		cout << input[input.size() - 1 - i] << endl;
	}

	cout << input.substr(middle_start, n2);

	system("pause");
	return 0;
}