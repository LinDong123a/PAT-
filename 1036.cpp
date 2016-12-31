#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

struct Student{
    char name[11];
    char ID[11];
    int grade;
};

bool cmp(Student &a, Student &b) {
	return a.grade <= b.grade;
}

int main(){
    int count;
    cin >> count;
    vector<Student> M_record, F_record;
    char gender, name[11], ID[11];
    int grade;
    Student student;
    while(count--){
        scanf("%s %c %s %d",student.name, &gender, student.ID, &student.grade);
        switch(gender){
        case 'M':
            M_record.push_back(student);
            break;
        case 'F':
            F_record.push_back(student);
        }
    }

    sort(M_record.begin(), M_record.end(), cmp);
    sort(F_record.begin(), F_record.end(), cmp);
    
    int difference = 0;
	if (!F_record.empty()) {
		cout << (*(--F_record.end())).name << ' ' << (*(--F_record.end())).ID << endl;
	}
	else
		cout << "Absent" << endl;

	if (!M_record.empty()) {
		cout << (*(M_record.begin())).name << ' ' << (*(M_record.begin())).ID << endl;
	}
	else
		cout << "Absent" << endl;
    
    if(F_record.empty() || M_record.empty())
        cout << "NA";
    else
        cout << (*(--F_record.end())).grade - (*(M_record.begin())).grade;
    return 0;
}
