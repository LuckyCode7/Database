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

    int index;
    std::cout<<"podaj numer: ";
    std::cin>>index;
    students.eraseStudent(index);
    std::cout<<students;
    students.addStudent();
    students.addStudent();
    std::cout<<students;
    students.sortStudents();
    std::cout<<students;
    return 0;
}

