#include <iostream>
#include<unordered_map>
#include<string>
using namespace std;

class Student {
public:
	string firstname;
	string lastname;
	string rollno;

	Student(string f, string l, string no) {
		firstname  = f;
		lastname = l;
		rollno = no;
	}

	bool operator==(const Student &s) const {
		return rollno == s.rollno ? true : false;
	}
};

class HashFn {
public:
	size_t operator()(const Student &s) const {
		return s.firstname.length() + s.lastname.length();
	}
};

int main() {

	unordered_map<Student, int, HashFn> student_map;

	Student s1("Girish", "Garg", "17");
	Student s2("Rohan", "Gujrathi", "54");
	Student s3("Jai", "Gujrathi", "65");
	Student s4("Girish", "Garg", "71");


	student_map[s1] = 95;
	student_map[s2] = 65;
	student_map[s3] = 73;
	student_map[s4] = 55;

	for (auto s : student_map) {
		cout << s.first.firstname << " " << s.first.rollno << " Marks:" << s.second << endl;
	}


}