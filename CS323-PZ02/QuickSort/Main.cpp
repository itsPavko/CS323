#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <fstream>

#include "Student.h"
#include "QuickSort.h"

using namespace std;

// Učitavanje podataka iz fajla u vektor
vector<Student> loadStudentsFromFile(const string& filename) {
	vector<Student> students;
	ifstream file(filename);

	if (!file.is_open()) {
		throw runtime_error("Unable to open file: " + filename);
	}

	int id, studentNumber;
	string name;

	while (file >> id >> name >> studentNumber) {
		students.emplace_back(id, name, studentNumber);
	}

	file.close();
	return students;
}

// Upisivanje sortiranog niza u fajl
void writeStudentsToFile(const vector<Student>& students, const string& filename) {
	ofstream file(filename);

	if (!file.is_open()) {
		throw runtime_error("Unable to open file: " + filename);
	}

	for (const auto& student : students) {
		file << student.id << " " << student.name << " " << student.studentNumber << endl;
	}

	file.close();
}

void printVector(const vector<Student>& array) {
	for (const auto& item : array) {
		cout << item.id << " " << item.name << " " << item.studentNumber << endl;
	}
}

int main() {

	try {
		using Compare = function<bool(const Student&, const Student&)>;
		vector<Student> students = loadStudentsFromFile("students.txt");

		cout << "Original array:" << endl;
		printVector(students);

		int number;
		cout << "Type number by which attribute you want to sort array" << endl;
		cout << "1. ID" << " 2. Name" << " 3. Student number" << endl;
		cin >> number;

		QuickSort<Student> sort;
		switch (number) {
		case 1:
			sort.quickSort(students, 0, students.size() - 1, Compare([](const Student& a, const Student& b) {
				return a.id < b.id;
			}));
			break;
		case 2:
			sort.quickSort(students, 0, students.size() - 1, Compare([](const Student& a, const Student& b) {
				return a.name < b.name;
			}));
			break;
		case 3:
			sort.quickSort(students, 0, students.size() - 1, Compare([](const Student& a, const Student& b) {
				return a.studentNumber < b.studentNumber;
			}));
			break;
		default:
			throw runtime_error("You type wrong number!");
		}

		cout << "Sorted array:" << endl;
		printVector(students);

		writeStudentsToFile(students, "sortedStudents.txt");

		cout << "Sorted array has been written to sortedStudents.txt." << endl;
	}
	catch (const exception& ex) {
		cout << "Error: " << ex.what() << endl;
	}

	return 0;
}