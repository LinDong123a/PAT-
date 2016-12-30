#include<iostream>
using namespace std;


int main() {
	double arr[3][3];
	double temp;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> temp;
			arr[i][j] = temp;
		}
	}

	int largest_number = 0; 
	double max_odd = 1;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (arr[i][largest_number] < arr[i][j])
				largest_number = j;
		}
		switch (largest_number) {
		case 0:		cout << 'W' << ' '; break;
		case 1:		cout << 'T' << ' ';	break;
		case 2:		cout << 'L' << ' ';	break;
		}
		max_odd *= arr[i][largest_number];
		largest_number = 0;
	}
	
	int output = (max_odd * 0.65 - 1) * 2 * 100;
	if (output % 10 >= 5)
		output += 1;
	printf("%.2lf", (double)output/100);

	system("pause");
	return 0;
}