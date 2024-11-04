#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Student {
	int id;
	string name;
};

int main() {
	int max;
	map<int, string> student_map;

	cout << "입력할 학생의 수는? ";
	cin >> max;

	cout << max << "명의 학생의 학번과 이름을 입력하세요." << endl;
	for (int i = 0; i < max; i++) {
	Student student;
	cout << "학번과 이름을 입력하세요: ";
	cin >> student.id >> student.name;
	student_map[student.id] = student.name;
}

	cout << "\n학생 리스트:" << endl;
	for(const auto &pair : student_map) {
		cout << "학번: " << pair.first << ", 이름: " << pair.second << endl;
}
	return 0;
}
