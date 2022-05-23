/* 
   DISCLAIMER:
      This file I wrote is a part of a larger program I wrote
	as a University course assignment. While I have asked permission
	from said instructors for permission to post my code. If any
	instructor or professor use this assignment or similar
	for their classes and find this code or part of this code submitted, they can request
    me to remove this from my public respository. The code I post 
	in my public repository in github is for purely showcasing my skills and interest.
   
   liability conditions:
    In no event shall the authors or copyright holders
	be liable for damages, claim or other liability, whether in 
	an action of contract, tort or otherwise, arising from,
	out of or in connection with the software or the use or
	other dealings in the software.
*/

#include <cstdlib>
#include "Sxp9653_Controller.h"
#include "Sxp9653_dialog.h"
#include <sstream>
void Controller::gui()
{
    int cmd = 1;
    while(cmd != 7) //while loop that runs till the user puts in a 0
    {
        cmd = view.show_menu(); //show user options available
        execute_cmd(cmd);
    }
}

void Controller::execute_cmd(int cmd)
{
    switch(cmd) //switch to decide what function to call based on user input
    {
        case 0: //add event
            Controller::add_Course();
            break;
        case 1:
            Controller::remove_course();
            break;
        case 2:
            Controller::view_all_courses();
            break;
        case 3:
            Controller::view_sections_of_one_course();
            break;
        case 4:
            Controller::change_an_instructor();
            break;
        case 5:
			Controller::add_student_to_a_course();
            break;
        case 6:
            Controller::remove_student_from_a_course();
            break;    
        default:
			exit(0);//quit
            break;     
    }
}
void Controller::add_Course()
{
	int c,s;
	std::string p, n, i, tc, ts;
	p = Dialogs::input("Please input the prefix", "Input Prefix", "CSE");
	tc = Dialogs::input("Please input the course number", "Input Course number", "1970");
	std::stringstream iss;
	iss<<tc;
	iss >> c;
	ts = Dialogs::input("Please input the section number", "Input section number", "001");
	iss<<ts;
	iss >> s;
	n = Dialogs::input("Please input the name of the class", "Input name", "Intro");
	i = Dialogs::input("Please input the name of the instructor", "Input name", "John Doe");
    catalog.add_course(Course (p,c,s,n,i)); //course prefix, course number, section number, name, instructor
}
void Controller::remove_course()
{
	int c,s;
	std::string p, n, i,tc, ts;
	std::stringstream iss;
    p = Dialogs::input("Please input the prefix", "Input Prefix", "CSE");
	tc = Dialogs::input("Please input the course number", "Input Course number", "1970");
	iss<<tc;
	iss >> c;
	ts = Dialogs::input("Please input the section number", "Input section number", "001");
	iss<<ts;
	iss >> s;
    //view.prompt_for_input("the name of the class");
	//std::cin.ignore();
	//std::getline(std::cin, n);
	Course cr (p,c,s,n,i);
	catalog.remove_course(cr);
}
void Controller::view_all_courses()
{
	string iss;
	catalog.view_all_courses();
	
}
void Controller::view_sections_of_one_course()
{
	int c,s;
	std::string p, n, i,tc, ts;
    p = Dialogs::input("Please input the prefix", "Input Prefix", "CSE");
	tc = Dialogs::input("Please input the course number", "Input Course number", "1970");
	std::stringstream iss;
	iss<<tc;
	iss >> c;
	catalog.view_all_sections_of_course(p,c);
	
}
void Controller::change_an_instructor()
{
	int c,s;
	std::string p, n, i,tc, ts;
	std::stringstream iss;
	p = Dialogs::input("Please input the prefix", "Input Prefix", "CSE");
	tc = Dialogs::input("Please input the course number", "Input Course number", "1970");
	 iss<<tc;
	iss >> c;
	ts = Dialogs::input("Please input the section number", "Input section number", "001");
	 iss<<ts;
	iss >> s;
	n = Dialogs::input("Please input the name of the class", "Input name", "Intro");
	i = Dialogs::input("Please input the name of the instructor", "Input name", "John Doe");
	Course cr (p,c,s,n,i);
	catalog.change_instructor(cr, i);
}
void Controller::add_student_to_a_course()
{
	int c,s, id;
	std::string p, n, i,tc, ts, td;
	p = Dialogs::input("Please input the prefix", "Input Prefix", "CSE");
	tc = Dialogs::input("Please input the course number", "Input Course number", "1970");
	std::stringstream iss;
	iss<<tc;
	iss >> c;
	ts = Dialogs::input("Please input the section number", "Input section number", "001");
	iss<<ts;
	iss >> s;
	td = Dialogs::input("Please input the student id", "Input student id", "1001");
	iss<<td;
	iss >> id;
	
	Course cr (p,c,s,n,i);
	catalog.add_student(cr, id);
}
void Controller::remove_student_from_a_course()
{
	int c,s, id;
	std::string p, n, i,tc, ts;
	std::stringstream iss;
	iss<<tc;
	p = Dialogs::input("Please input the prefix", "Input Prefix", "CSE");
	tc = Dialogs::input("Please input the course number", "Input Course number", "1970");
	iss<<tc;
	iss >> c;
	ts = Dialogs::input("Please input the section number", "Input section number", "001");
	iss<<ts;
	iss >> s;
	Course cr (p,c,s,n,i);
	catalog.remove_student(cr, id);
}
