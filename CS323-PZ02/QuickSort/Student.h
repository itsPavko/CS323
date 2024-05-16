#pragma once
#include <string>
#include <iostream>

using namespace std;

class Student {
public:
	int id;
	string name;
	int studentNumber;
public:
	Student(int id, string name, int studentNumber) : id(id), name(name), studentNumber(studentNumber) {};
	int getId();
	string getName();
	int getStudentNumber();
};

