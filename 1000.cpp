#include<iostream>
#include<string>
using namespace std;

void add_pathesis(string &input, int number) {
	while (number--)
		input += '(';
	input += ')';
}

int main() {
	int count, input_count, input;
	cin >> count;
	while (count--) {
		bool is_first = true;
		string pathesis_record;
		cin >> input_count;
		int *arr = (int *)malloc(sizeof(int) * input_count);
		for (int i = 0; i < input_count; ++i) {
			cin >> input;
			arr[i] = input;
		}
		for (int i = 0; i < input_count; ++i) {
			if (i == 0)
				add_pathesis(pathesis_record, arr[i]);
			else {
				add_pathesis(pathesis_record, arr[i] - arr[i - 1]);
			}
		}
		cout << pathesis_record;
		int R_pathesis_count = 0, index = 0;
		for (int i = 0; i < pathesis_record.size(); ++i) {
			if (pathesis_record[i] == ')') {
				++R_pathesis_count;
				if (i == 0)
					arr[index++] = 1;
				else {
					if (pathesis_record[i - 1] == '(')
						arr[index++] = 1;
					else {
						arr[index++] = R_pathesis_count;
					}
				}
			}
		}
		for (int i = 0; i < input_count; ++i) {
			if (i != 0)
				cout << ' ';
			cout << arr[i];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}