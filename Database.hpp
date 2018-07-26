#ifndef LIST_HPP
#define LIST_HPP

#include "Student.hpp"
#include <list>


class List
{
    std:: list<Student> list_; 
public:

    List() {}
    ~List() {}
    void addStudent();
    void eraseStudent(int index);
    void sortStudents();
    std::list<Student> getList() const;
};

std ::ostream& operator << (std::ostream& Strm, List& l);


#endif
