#include "List.hpp"

int main()
{

    List students;
    students.addStudent();
    students.addStudent();
    students.addStudent();
    students.addStudent();

    std::cout<<students;

    students.sortStudents();

    std::cout<<students;

    return 0;
}

