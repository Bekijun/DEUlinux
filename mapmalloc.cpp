#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	int max;
	map<int, string> student_map;

	cout << "입력할 학생의 수는? ";
	cin >> max;

	cout << max << "명의 학생의 학번과 이름을 입력하세요." << endl;
	for (int i = 0; i < max; i++) {
		int id;
		string name;
		cout << "학번과 이름을 입력하세요: ";
		cin >> id >> name;
		student_map[id] = name;
}

	cout << "\n학생 리스트:" << endl;
	for(const auto &pair : student_map) {
		cout << "학번: " << pair.first << ", 이름: " << pair.second << endl;
	}
	return 0;
}
