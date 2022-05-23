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

#include "Sxp9653_Catalog.h"
#include <string>

using namespace std;

// default constructor
Catalog :: Catalog()
{
	
}
void Catalog :: add_course(Course course)
{
	//args: course 
	//return: void
	// summary: checks if the course given already exists in catalog.
	//          if it does exist it shows an error message to the user
	//          if it does not it it added to the catalog
	bool already = false;
	for(int i = 0; i < courses.size();++i)
	{ 
		already = (course==courses.at(i));
	}
	if(already == false)
	{
		courses.push_back(course);
	}
	else
	{
		Dialogs::message("Course already added", "ERROR");
	}
}
void Catalog :: remove_course (Course course)
{
	//args: course 
	//return: void
	// summary: checks if the course given already exists in catalog.
	//          if it course exists remove it from catalog
	bool already = false;
	for(int i = 0; i < courses.size();++i)
	{ 
		already = (course==courses.at(i));
		if(already == true)
		{
			courses.erase(courses.begin()+i);
		}
	}

}
void Catalog :: view_all_courses ()
{
	//args: void 
	//return: void
	// summary: view all courses in the catalog
	stringstream output;
	output<<"\nAll courses in the Catalog\n";
	output<<"Name\tCourse prefix\tCourse Number\tCourse Section";
	for(int i = 0; i < courses.size(); i++)
	{
		output<<"\n"<<(courses.at(i)).get_name();
		output<<"\t"<<(courses.at(i)).get_course_prefix();
		output<<"\t\t\t\t"<<(courses.at(i)).get_course_number();
		output<<"\t\t\t\t"<<(courses.at(i)).get_section_number();
	}
	output<<"\n";
	Dialogs::message(output.str(),"View all courses");
	
}
void Catalog :: view_all_courses_of_prefix (string prefix)
{
	//args: course 
	//return: void
	//summary: view all courses with the same prefix
	//         CaSe SeNeSiTive as well as white space senesitive
	//     example:    prefix:  CS != cS
	stringstream output;
	output<<"\nThe courses offered with the prefix " + prefix + " are";
	for(int i = 0; i < courses.size(); ++i)
	{
		if(courses.at(i).get_course_prefix() == prefix)
		{
			output<<" " <<(courses.at(i)).get_course_number();
			output<< " " <<(courses.at(i)).get_section_number()<<endl;
		}
	}
	Dialogs::message(output.str(),"View all course of prefix");
	
}
void Catalog :: view_all_sections_of_course (string prefix, int number)
{
	//args: course 
	//return: void
	//summary: view all courses with the same prefix and course number
	//         CaSe SeNeSiTive as well as white space senesitive
	//      example:    prefix:  Cs != CS
	stringstream oss;
	oss<<"\nAll the sections of the course"<<prefix<<" "<<number<<" in the catalog are ";
	for(int i = 0; i < courses.size(); ++i)
	{
		if((courses.at(i)).get_course_prefix() == prefix)
		{
			if((courses.at(i).get_course_number() == number))
			{
				oss<<" " <<(courses.at(i)).get_section_number()<<endl;
			}
		}
	}
	Dialogs::message(oss.str(),"View all sections in course");
	
}
// change instructor, add student, remove student
// simple calls to functions of the course class which then implement
// the functionality of these function
void Catalog :: change_instructor (Course course, string instructor)
{
	course.set_instructor(instructor);
}
void Catalog :: add_student (Course course, int student_id)
{
	course.add_student(student_id);
}
void Catalog :: remove_student (Course course, int student_id)
{
	course.remove_student(student_id);
}


