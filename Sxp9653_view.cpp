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
int View::show_menu()
{
	// args: void
	// return: user selection
	// summary: shows the main menu 

	std::vector<string> buttons{"Add Course",
"remove course",
"view all courses",
"view sections of one course", 
"change an instructor", 
"add student to a course", 
"remove student from a course", 
"view students in a course", 
"Exit"};
	int result = Dialogs::question("Please select an option","Course Catalog", buttons);
	return result;
}
   
int View::prompt_for_int(std::string prompt)
{
	// args: string prompt/question for the user
	// return: user provided int
	// summary: shows the main menu 
	std::string year_str = Dialogs::input("Please enter " + prompt," Input Number", "0");
	
	std::istringstream iss (year_str);
	int year;
	iss >> year;
	return year;
}

std::string View::prompt_for_string(std::string prompt)
{
	// args: string prompt/question for the user
	// return: user provided string
	// summary: pop up input box for taking string input  
	std::string input = Dialogs::input("Please enter " + prompt," Input Answer ", "0");
	return input;
}


   