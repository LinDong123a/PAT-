#include<iostream>
using namespace std;

static int k = 0;

void merge(int *arr, int begin, int mid, int end) {
	//create the initial array
	int L_length = mid - begin + 1;
	int R_length = end - mid;
	int *L = (int *)malloc(L_length * sizeof(int)),
		*R = (int *)malloc(R_length * sizeof(int));

	//initiliate the array
	for (int i = 0; i < L_length; ++i)
		L[i] = arr[begin + i];
	for (int i = 0; i < R_length; ++i)
		R[i] = arr[mid + i + 1];

	// merge
	int L_count = 0, R_count = 0;
	while (L_count != L_length && R_count != R_length) {
		if (L[L_count] > R[R_count])
			arr[begin++] = R[R_count++];
		else
			arr[begin++] = L[L_count++];
	}
	// the fullfill the array
	if (L_count != L_length)
		for (int i = L_count; i < L_length; ++i)
			arr[begin++] = L[i];
	if (R_count != R_length)
		for (int i = R_count; i < R_length; ++i)
			arr[begin++] = R[i];

	free(L);
	free(R);
}

void merge_sort(int *arr, int begin, int end) {
	int middle = (begin + end) / 2;
	if (begin < end) {
		merge_sort(arr, begin, middle);
		merge_sort(arr, middle + 1, end);
		merge(arr, begin, middle, end);
	}
}

void build_cbt(int *input, int *output, int pos, int N) {
	if (pos > N - 1)
		return;
	else {
		build_cbt(input, output, 2 * pos + 1, N);
		output[pos] = input[k++];
		build_cbt(input, output, 2 * pos + 2, N);
	}
}

int main() {
	int count;
	cin >> count;
	int *arr = (int *)malloc(count * sizeof(int));
	int *output = (int *)malloc(count * sizeof(int));
	int input;
	//initilate
	for (int i = 0; i < count; ++i) {
		cin >> input;
		arr[i] = input;
	}
	//sort the array
	merge_sort(arr, 0, count - 1);

	//find the hierachy
	build_cbt(arr, output, 0, count);

	//print
	for (int i = 0; i < count; ++i) {
		if (i != 0)
			cout << ' ';
		cout << output[i];
	}

	system("pause");
	return 0;
}