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
#include <vector>
#include <iostream>
#include <gtkmm.h>

class Dialogs
{
public:
    static void message(std::string msg, std::string title);
    static std::string input(std::string msg, 
                        std::string title, 
                        std::string default_text = "",
                        std::string cancel_text = "CANCEL");
   static int question(std::string msg, 
                        std::string title, 
                        std::vector<std::string> buttons);
private:
};
