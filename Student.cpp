#include "Student.hpp"

Student:: Student(std::string fname,std::string lname,int index)
    :fname_(fname)
    ,lname_(lname)
    ,index_(index)
{}

int Student:: getIndex() const
{
    return index_;
}
std::string Student:: getFname() const
{
    return fname_;
}

std::string Student:: getLname() const
{
    return lname_;
}

bool Student:: operator < (const Student& s)
{
    return index_ < s.index_;
}

std::ostream& operator << (std::ostream& Strm, const Student& s)
{
    Strm<<s.getFname();
    Strm<<"\t";
    Strm<<s.getLname();
    Strm<<"\t";
    Strm<<s.getIndex();
    Strm<<std::endl;

    return Strm;
}
