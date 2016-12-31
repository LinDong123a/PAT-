#include<iostream>
#include<set>
#include<string>
#include<vector>

using namespace std;

int main() {
	set<char> input_record, origin_record;
	string input, origin;
	cin >> origin >> input;
	
	for (int i = 0; i < input.size(); ++i) {
		if (input[i] >= 'a' && input[i] <= 'z')
			input[i] = toupper(input[i]);
		input_record.insert(input[i]);
	}

	for (int i = 0; i < origin.size(); ++i) {
		if (origin[i] >= 'a' && origin[i] <= 'z')
			origin[i] = toupper(origin[i]);
		if (input_record.find(origin[i]) == input_record.end() && origin_record.find(origin[i]) == origin_record.end()) {
			cout << origin[i];
			origin_record.insert(origin[i]);
		}
	}

	system("pause");
	return 0;
}