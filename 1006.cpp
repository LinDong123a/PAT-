#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
#include<cmath>
#pragma warning(disable:4996)
using namespace std;

unsigned timeToUInt(const string &s) {
	int first = 0, count = 2;
	string temp;
	int sum = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == ':') {
			temp = s.substr(first, i - first);
			first = i + 1;
			sum += stoi(temp) * pow(60, count--);
		}
	}
	temp = s.substr(first, s.size() - first);
	sum += stoi(temp);
	return sum;
}

int main() {
	int count;
	cin >> count;
	char ID[16];
	string sign_in_time, sign_out_time;

	//read the first one
	char earliest_ID[16], latest_ID[16];
	cin >> ID >> sign_in_time >> sign_out_time;

	//initiliate the earliest and latest
	strcpy(earliest_ID, ID);
	strcpy(latest_ID, ID);
	int earliest_sign_in_time = timeToUInt(sign_in_time);
	int latest_sign_out_time = timeToUInt(sign_out_time);

	//find the larget and the smallest
	while (--count) {
		cin >> ID >> sign_in_time >> sign_out_time;
		if (timeToUInt(sign_in_time) < earliest_sign_in_time) {
			strcpy(earliest_ID, ID);
			earliest_sign_in_time = timeToUInt(sign_in_time);
		}
		if (timeToUInt(sign_out_time) > latest_sign_out_time) {
			strcpy(latest_ID, ID);
			latest_sign_out_time = timeToUInt(sign_out_time);
		}
	}
	
	if (earliest_ID == latest_ID) {
		cout << earliest_ID;
		return 0;
	}
	cout << earliest_ID << ' ' << latest_ID;



	system("pause");
	return 0;
}