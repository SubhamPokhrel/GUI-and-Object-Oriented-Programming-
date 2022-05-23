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

#include "Sxp9653_View.h" 

class Controller
{
    public:
        Controller(Catalog& c, View& v) : catalog(c), view(v) {}; // constructor with assignments in definition
        void gui(); //function that starts the CLI based application
        void execute_cmd(int); //function that decides what operation to perfrom based on user input
        void add_Course(); //get information necessary and adds course
        void remove_course(); // remove course
		void view_all_courses(); // view all courses
		void view_sections_of_one_course(); // view sections of the course the prefix and course number are same but different sections
		void change_an_instructor(); // chcange instructor
		void add_student_to_a_course(); // add student 
		void remove_student_from_a_course(); // remove student
    private:
        Catalog& catalog; //reference to a catalog object
        View& view; //reference to a view object
};
