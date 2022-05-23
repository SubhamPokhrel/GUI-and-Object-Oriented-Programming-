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
#include "Sxp9653_Main_Window.h"

Main_Window :: Main_Window()
{
	view = new View(schedule);
	//setting up default size
	set_default_size(400,200);
	
	Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL,0));
	add(*vbox);
	
	//menu bar
	Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
	vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
	
	//file menu
	Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
	menubar->append(*menuitem_file);
	Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
	menuitem_file->set_submenu(*filemenu);
	
	//quit
	Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
	menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_quit_click));
	filemenu->append(*menuitem_quit);
	
	//courses
	Gtk::MenuItem *menuitem_courses = Gtk::manage(new Gtk::MenuItem("_Courses", true));
	menubar->append(*menuitem_courses);
	Gtk::Menu *coursesmenu = Gtk::manage(new Gtk::Menu());
	menuitem_courses->set_submenu(*coursesmenu);
	
	//view
	Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
	menubar->append(*menuitem_view);
	Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
	menuitem_view->set_submenu(*viewmenu);
	
	//add course -. course
	Gtk::MenuItem *menuitem_add_cr = Gtk::manage(new Gtk::MenuItem("_Add Course", true));
	menuitem_add_cr->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_add_course_click));
	coursesmenu->append(*menuitem_add_cr);
	
	// remove course -. course
	Gtk::MenuItem *menuitem_rm_cr = Gtk::manage(new Gtk::MenuItem("_Remove Course", true));
	menuitem_rm_cr->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_rm_course_click));
	coursesmenu->append(*menuitem_rm_cr);
	
	//change an instructor -.course
	Gtk::MenuItem *menuitem_changeins = Gtk::manage(new Gtk::MenuItem("_Change an instructor", true));
	menuitem_changeins->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_change_ins_click));
	coursesmenu->append(*menuitem_changeins);
	
	//add student to a course -. course
	Gtk::MenuItem *menuitem_add_std = Gtk::manage(new Gtk::MenuItem("_Add student to a course", true));
	menuitem_add_std->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_add_std_click));
	coursesmenu->append(*menuitem_add_std);
	//remove student from a course -. course
	Gtk::MenuItem *menuitem_rm_std = Gtk::manage(new Gtk::MenuItem("_Remove student to a course", true));
	menuitem_rm_std->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_rm_std_click));
	coursesmenu->append(*menuitem_rm_std);
	// view all courses -. view
	Gtk::MenuItem *menuitem_view_all = Gtk::manage(new Gtk::MenuItem("_View all courses", true));
	menuitem_view_all->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_view_all_click));
	viewmenu->append(*menuitem_view_all);
	// view sections of one course -. view
	Gtk::MenuItem *menuitem_view_sec = Gtk::manage(new Gtk::MenuItem("_View sections of a course", true));
	menuitem_view_sec->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_view_sec_click));
	viewmenu->append(*menuitem_view_sec);
	// view all courses with a prefix
	Gtk::MenuItem *menuitem_view_pre = Gtk::manage(new Gtk::MenuItem("_View all courses of a prefix", true));
	menuitem_view_pre->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_view_pre_click));
	viewmenu->append(*menuitem_view_pre);
	vbox->show_all();
	
}

void Main_Window :: on_quit_click()
{
	hide();
}
void Main_Window :: on_change_ins_click()
{
	// change instructor
	string i;
	std::string p = view->prompt_for_string("the prefix");
	int c = view->prompt_for_int("the course number");
	int s = view->prompt_for_int("the section number");
	std::string n = view->prompt_for_string("the name of the course");
	std::string in = view->prompt_for_string("the name of the new instructor");
    schedule.change_instructor(Course (p,c,s,n,i), in); //course prefix, course number, section number, name, instructor
}
void Main_Window :: on_add_std_click()
{
	// add student 
	string i;
	std::string p = view->prompt_for_string("the prefix");
	int c = view->prompt_for_int("the course number");
	int s = view->prompt_for_int("the section number");
	std::string n = view->prompt_for_string("the name of the course");
	int std = view->prompt_for_int("the student number to add");
    schedule.add_student(Course (p,c,s,n,i), std); //course prefix, course number, section number, name, instructor
}
void Main_Window :: on_rm_std_click()
{
	//remove student
	string i;
	std::string p = view->prompt_for_string("the prefix");
	int c = view->prompt_for_int("the course number");
	int s = view->prompt_for_int("the section number");
	std::string n;// = view->prompt_for_string("the name of the course");
	int std = view->prompt_for_int("the student number to remove");
    schedule.remove_student(Course (p,c,s,n,i), std); //course prefix, course number, section number, name, instructor

}
void Main_Window :: on_view_all_click()
{
     //view all
    schedule.view_all_courses(); //course prefix, course number, section number, name, instructor
}
void Main_Window :: on_view_pre_click() 
{
	//view  all course of prefix
	//string i;
	std::string p = view->prompt_for_string("the prefix");
	//int c = view->prompt_for_int("the course number");
    schedule.view_all_courses_of_prefix(p); //course prefix, course number, section number, name, instructor
}
void Main_Window :: on_view_sec_click() 
{
	//view  sections
	//string i;
	std::string p = view->prompt_for_string("the prefix");
	int c = view->prompt_for_int("the course number");
    schedule.view_all_sections_of_course(p,c); //course prefix, course number, section number, name, instructor
}
void Main_Window :: on_add_course_click()
{
   // add course
   string i;
	std::string p = view->prompt_for_string("the prefix");
	int c = view->prompt_for_int("the course number");
	int s = view->prompt_for_int("the section number");
	std::string n = view->prompt_for_string("the name of the course");
    schedule.add_course(Course (p,c,s,n,i)); //course prefix, course number, section number, name, instructor   
}
void Main_Window :: on_rm_course_click()
{
	// remove course
	string i;
	std::string p = view->prompt_for_string("the prefix");
	int c = view->prompt_for_int("the course number");
	int s = view->prompt_for_int("the section number");
	std::string n;// = view->prompt_for_string("the name of the course");
    schedule.remove_course(Course (p,c,s,n,i)); //course prefix, course number, section number, name, instructor
}
Main_Window::~Main_Window()
{
	
}
