#ifndef LIST_HPP
#define LIST_HPP

#include "Student.hpp"
#include <list>


class List
{

public:

    std:: list<Student> list_; ///trzeba shermetyzować
    List() {}
    ~List() {}
    void addStudent();
    void eraseStudent(int index);
    void sortStudents();

};

std ::ostream& operator << (std::ostream& Strm, List& l);


#endif
