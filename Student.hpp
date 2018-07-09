#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <iostream>

class Student
{
    std::string fname_;
    std::string lname_;
    int index_;

public:
    Student(std::string fname,std::string lname,int index);
    ~Student() {}
    std::string getFname() const;
    std::string getLname() const;
    int getIndex() const;
    bool operator < (const Student& s);
};

std ::ostream& operator << (std::ostream& Strm, const Student& s);

#endif
