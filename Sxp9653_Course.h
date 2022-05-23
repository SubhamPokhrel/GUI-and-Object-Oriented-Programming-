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
#ifndef _SXP9653_COURSE_H_
#define _SXP9653_COURSE_H_

#include <iostream>
#include <vector>
#include <fstream>

class Course
{
	public:
		Course();
		Course(std::string cp, int cn, int sn, std::string nam, std::string ins); // course prefix, course number, section number, name, instructor
		std::string get_course_prefix() const; // get prefix
		int get_course_number() const; // get course
		int get_section_number() const; // sectiion
		std::string get_name() const; // name
		std::string get_instructor() const; // instructor

		
		void set_course_prefix(std::string prefix); // set prefix
		void set_course_number(int cn); // course
		void set_section_number(int num); // section
		void set_name(std::string); // set name
		void set_instructor(std::string); //set instructor
		
		void add_student(int); // 
		void remove_student(int); //
		
		std::string to_string(std::string);//
 		friend std::ostream& operator<<(std::ostream&, const Course&);
		bool operator<(const Course&);
		bool operator==(const Course&);
	protected:
		std::string course_prefix; 
		int course_number;
		int section_number; 
		std::string name;
		std::string instructor;
		std::vector <int> student_ids;
};

#endif

