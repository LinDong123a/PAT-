#include<iostream>
#include<string>
using namespace std;

int main() {
	string input;
	getline(cin, input);
	int count_odd = 0, count_even = 0;
	int temp_count;
	for (int i = 0; i < input.size(); ++i) {
		for (int j = 0; i - j >= 0 && i + j < input.size(); ++j) {
			if (input[i - j] != input[i + j])
				break;
			else {
				temp_count = 2 * j + 1;
				if (count_odd < temp_count)
					count_odd = temp_count;
			}
		}
		for (int j = 0; i - j >= 0 && i + j + 1 < input.size(); ++j) {
			if (input[i - j] != input[i + j + 1])
				break;
			else {
				temp_count = 2 * j + 2;
				if (count_even < temp_count)
					count_even = temp_count;
			}
		}
	}

	if (count_even > count_odd)
		count_odd = count_even;
	
	cout << count_odd;
	system("pause");
	return 0;
}