#include "List.hpp"
#include <string>

void menu()
{
    std::cout<<"---------------------------------------"<<std::endl;
    std::cout<<"         DATABASE - STUDENTS           "<<std::endl;
    std::cout<<"---------------------------------------"<<std::endl;
    std::cout<<"MENU:"<<std::endl<<std::endl;
    std::cout<<"0 - quit"<<std::endl;
    std::cout<<"1 - add student"<<std::endl;
    std::cout<<"2 - delete student by index number"<<std::endl;
    std::cout<<"3 - sort students by index number"<<std::endl;
    std::cout<<"4 - print database"<<std::endl<<std::endl;
}

int main()
{   
    List students;
    int choice=0;
    int index=0;
    menu();

    do
    {
        std::cout<<"(to show menu chose 5)"<<std::endl;
        std::cout<<"YOUR CHOICE: "; std::cin>>choice;
        std::cout<<std::endl;

        switch(choice)
        {
            case 0:
                {
                    std::cout<<"END"<<std::endl;
                    break;
                }
        case 1:
                        {
                            std::cout<<"ADD STUDENT"<<std::endl;
                            std::string yesno = "yes";
                            std::string yes = "yes";
                            while(yesno == yes )
                            {
                            std::cin.clear();
                            std::cin.sync();
                            students.addStudent();
                            std::cout<<"STUDENT ADDED"<<std::endl<<std::endl;
                            std::cout<<"Want to add another student? Type yes. want to stop adding students? Type no" <<std::endl;
                            std::cin>> yesno;
                            if (yesno == "no") break;
                            }
                            break;
                        }
            case 2:
                {
                    std::cout<<"DELETE STUDENT BY INDEX NUMBER"<<std::endl;
                    std::cout<<"INDEX: "; std::cin>>index;
                    students.eraseStudent(index);
                    std::cout<<"STUDENT DELETED"<<std::endl<<std::endl;

                    break;
                }
            case 3:
                {
                    students.sortStudents();
                    std::cout<<"STUDENTS SORTED BY INDEX NUMBER"<<std::endl<<std::endl;

                    break;
                }
            case 4:
                {
                    std::cout<<students;
                    break;
                }
            case 5:
                {
                    menu();
                    break;
                }
            default:
                {
                    std::cout<<"YOU CHOSE WRONG OPTION, CHOSE AGAIN"<<std::endl;
                    break;
                }
        }
    }while(choice != 0);

    return 0;
}

