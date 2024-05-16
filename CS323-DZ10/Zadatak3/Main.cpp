#include <iostream>
#include "BachlorStudent.h"

int main() {
    Student student("Bogdan", "Petrovic", "4382");
    student.info();

    BachelorStudent bachelorStudent("Test", "Test", "4381", "Informatika");
    bachelorStudent.info(); 

    return 0;
}