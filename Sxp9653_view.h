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

class View
{
    public:
        View(Catalog& c) : catalog(c) {};
		// view class inheirts from catalog class
		// args: a pointer to the catalog class 
		int show_menu();
		// show menu put all the names of the buttons in a vector
		int prompt_for_int(std::string);
		// a simple input dialog that takes in an integer from user
		std::string prompt_for_string(std::string);
		// a simple input dialog that takes in a string from user
		
    private:
        Catalog& catalog; 
};
