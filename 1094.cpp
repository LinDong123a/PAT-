#include<iostream>
#include<vector>
#include<map>

using namespace std;

static map<int, std::vector<int>> generation_count;

void generation_loop(std::vector<int>& generation, int *generation_arr, int count) {
	generation_arr[count++] += generation.size();
	for (auto beg = generation.begin(); beg != generation.end(); ++beg) {
		generation_loop(generation_count[*beg], generation_arr, count);
	}
}

int main() {
	int family_total, family_with_child;
	cin >> family_total >> family_with_child;
	int child_count, family_number, child_number;
	for (int i = 0; i < family_with_child; ++i) {
		cin >> family_number >> child_count;
		for (int j = 0; j < child_count; ++j) {
			cin >> child_number;
			generation_count[family_number].push_back(child_number);
		}
	}

	int *generation_arr = (int*)malloc((family_with_child + 1) * sizeof(int));

	generation_arr[0] = 1;
	for (int i = 1; i < family_with_child; ++i)
		generation_arr[i] = 0;
	
	generation_loop(generation_count[1], generation_arr, 1);

	int largest = 0;

	for (int i = 1; i <= family_with_child; ++i) {
		if (generation_arr[i] > generation_arr[largest])
			largest = i;
	}

	cout << generation_arr[largest] << ' ' << largest + 1;
	system("pause");
	return 0;
}