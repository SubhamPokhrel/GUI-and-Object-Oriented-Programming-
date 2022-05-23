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
#include "Sxp9653_Course.h"
#include <string>
#include <bits/stdc++.h>

using namespace std;

Course :: Course()
{
	course_prefix = "";
	course_number = 0;
	section_number = 0;
	instructor = "";
	name = "";
	student_ids.push_back(0);
}
Course :: Course (string cp, int cn, int sn, string n, string i): course_prefix{cp}, course_number{cn}, section_number{sn}, instructor{i}, name{n} // course prefix, course number, section number, name, instructor
{
	student_ids.push_back(0);
}
string Course :: get_course_prefix() const
{
	return course_prefix;
}
int Course :: get_course_number() const
{
	return course_number;
}
int Course :: get_section_number() const
{	
	return section_number;
}
string Course::get_name() const
{
	return name;
}
string Course::get_instructor() const
{
	return instructor;
}
void Course::set_course_number(int cn)
{
	course_number = cn;
}
void Course::set_course_prefix(string prefix)
{
	course_prefix = prefix;
}
void Course::set_section_number(int num)
{
	if(num >= 0)
	{
		section_number = num;
	}
}
void Course::set_name(string nam)
{
	name = nam;
}
void Course::set_instructor(string ins)
{
	instructor = ins;
}
void Course::add_student(int std)
{
	bool already = false;
	if(student_ids.at(0) == 0)
	{
		student_ids.clear();
	}
	
	for(int i=0; i<student_ids.size(); ++i)
	{
		if(student_ids.at(i) == std)
		{
			already = true;
			cerr<<"The student is already enrolled\n\n"<<endl;
		}
	}
	if(already == false)
	{
		student_ids.push_back(std);
		sort(student_ids.begin(), student_ids.end());
	}
}
void Course::remove_student(int std)
{
	int element = 0;
	bool already = false;
	int e = 0;
	for(int i=0; i<student_ids.size(); ++i)
	{
		if(student_ids.at(i) == std)
		{
			element = e;
			already = true;
			cerr<<"Cannot remove student -> The student is not enrolled\n\n"<<endl;
		}
		e = e++;
	}
	if(already == false)
	{
		student_ids.erase(student_ids.begin()+element);
	}
	
}

std::string Course::to_string(string allvalues)
{
	/* using to string to convert every private member into a string and assigning it to a return string
	   only course number, student ids and section number are to_string()ed since name, prefix and instructor are already strings
	*/
	allvalues+="Class name: "+get_name() +"\nCourse prefix: " +get_course_prefix();
	allvalues+="\nCourse number: "+std::to_string(get_course_number());
	allvalues+= "\nSection number: "+std::to_string(get_section_number());
	allvalues+= "\nTaught by: " + get_instructor();
	return allvalues;
}
ostream& operator<<(ostream& ost, const Course& C)
{
	ost<<"Class name: "<<C.get_name() <<"\nCourse prefix: " <<C.get_course_prefix();
	ost<<"\nCourse number: "<<C.get_course_number()<<"\nSection number: "<<C.get_section_number();
	ost << "\nTaught by: " << C.get_instructor();
	return ost;
}
bool Course :: operator<(const Course& rhs)
{
	// operator overloading to implement 
	// course a < course b
	// it will check in priority 
	// the prefix if same then 
	// check the course number
	// if same then check section 
	// if section number is same returns error
	bool same = false;
	if(this->get_course_prefix() < rhs.get_course_prefix())
	{
		same = true;
	}
	else if(this->get_course_prefix() == rhs.get_course_prefix())
	{
		if(this->get_course_number() < rhs.get_course_number())
		{
			same  = true;
		}
		else if(this->get_course_number() == rhs.get_course_number())
		{
			if(this->get_section_number() == rhs.get_section_number())
			{
				cerr<<"There must be something wrong: both classes are the exact same"<<endl;
			}
			else if(this->get_section_number() < rhs.get_section_number())
			{
				same = true;
			}
			else
				same = false;
		}
	}
	return same;
}
bool Course :: operator==(const Course& rhs)
{
	// similiar to overloaded , function
	// only it checks if the courses are same
	// returns a bool 
	bool same = false;
	if(this->get_course_prefix() == rhs.get_course_prefix())
	{
		if(this->get_course_number() == rhs.get_course_number())
		{
			if(this->get_section_number() == rhs.get_section_number())
			{
				same = true;
			}
		}
	}
	return same;
}