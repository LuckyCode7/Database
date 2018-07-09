#include "List.hpp"

void List:: addStudent()
{
    std::string fname,lname;
    int index;

    std::cout<<"First Name: ";
    std::cin>>fname;
    std::cout<<"Last Name: ";
    std::cin>>lname;
    std::cout<<"Index number: ";
    std::cin>>index;

    Student s(fname,lname,index);
    list_.push_back(s);

}

void List:: sortStudents()
{
    list_.sort();
}

std ::ostream& operator << (std::ostream& Strm, List& l)
{
    std::list<Student>::iterator i;
    for(i=l.list_.begin(); i!=l.list_.end(); i++)
    {
        Strm<<*i;
    }
    Strm<<std::endl;
    return Strm;
}


