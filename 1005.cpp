#include<iostream>
#include<vector>
#include<string>
using namespace std;

int sum;
vector<string> English = { "zero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

void print(int number) {
	if (number == 0)
		;
	else {
		print(number / 10);
		cout << English[number % 10];
		if (number != sum)
			cout << ' ';
	}
}

int main() {
	char input;
	while ((input = getchar()) != '\n') {
		sum += (input - '0');
	}

	if (sum == 0) {
		cout << "zero";
		return 0;
	}
	print(sum);

	system("pause");
	return 0;
	
}