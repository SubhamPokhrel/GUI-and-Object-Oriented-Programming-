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

#ifndef _SXP9653_CATALOG_H_
#define _SXP9653_CATALOG_H_

#include "Sxp9653_Course.h"
#include "Sxp9653_dialog.h"

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <sstream>


using namespace std;

class Catalog
{
	public:
		Catalog();
		void add_course(Course course);
		void remove_course(Course course);
		void view_all_courses();
		void view_all_courses_of_prefix(string prefix);
		void view_all_sections_of_course(string prefix, int number);
		void change_instructor(Course course, string instructor);
		void add_student(Course course, int student_id);
		void remove_student(Course course, int student_id);
	private:
	    // vector of course where course is an object
		vector <Course> courses;
};

#endif