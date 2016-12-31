#include<iostream>
#include<string>
#include<set>

using namespace std;

int main() {
	string input, exclude;
	set<char> _exclude;
	getline(cin, input);
	getline(cin, exclude);
	for (int i = 0; i < exclude.size(); ++i)
		_exclude.insert(exclude[i]);

	for (int i = 0; i < input.size(); ++i) {
		if (_exclude.find(input[i]) == _exclude.end())
			cout << input[i];
	}
	system("pause");
	return 0;
}