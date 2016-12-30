#include<iostream>
#include<algorithm>
#pragma warning(disable:4996)

using namespace std;

struct Student{
	char name[11];
	char ID[11];
	unsigned grade;
};

bool is_smaller(const Student &a, const Student &b) {
	return a.grade >= b.grade;
}

int main() {
	// input the student and sort it
	int count;
	cin >> count;
	
	Student* student_collect = (Student*)malloc(count * sizeof(Student));
	for (int i = 0; i < count; ++i)
		scanf("%s %s %d", student_collect[i].name, student_collect[i].ID, &student_collect[i].grade);
	sort(student_collect, student_collect + count, is_smaller);
	
	int range_begin, range_end;
	cin >> range_begin >> range_end;

	bool is_exist = false;
	for (int i = 0; i < count; ++i) {
		if (student_collect[i].grade >= range_begin && student_collect[i].grade <= range_end) {
			is_exist = true;
			cout << student_collect[i].name << ' ' << student_collect[i].ID;
			if (i != count - 1 && student_collect[i + 1].grade >= range_begin && student_collect[i].grade <= range_end)
				cout << endl;
		}
	}

	if (!is_exist)
		cout << "None";

	system("pause");
	return 0;
}