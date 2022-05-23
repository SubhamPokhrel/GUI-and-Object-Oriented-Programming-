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
#include "Sxp9653_dialog.h"

void Dialogs::message(std::string msg, std::string title)
{
    Gtk::MessageDialog *dialog = new Gtk::MessageDialog(title);
    dialog->set_secondary_text(msg, true);
    dialog->run();
    
    dialog->close();
    while (Gtk::Main::events_pending())
        Gtk::Main::iteration();
    
    delete dialog;
}

std::string Dialogs::input(std::string msg, 
                        std::string title, 
                        std::string default_text,
                        std::string cancel_text)
{
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title(title);
    
    Gtk::Label *label = new Gtk::Label(msg);
    dialog->get_content_area()->pack_start(*label);
    label->show();
    
    dialog->add_button("Cancel", 0);
    dialog->add_button("OK",1);
    dialog->set_default_response(1);
    
    Gtk::Entry *entry = new Gtk::Entry();
    entry->set_text(default_text);
    entry->set_max_length(50);
    entry->show();
    dialog->get_vbox()->pack_start(*entry);
    
    int result = dialog->run();
    std::string text = entry->get_text();
        
    
    dialog->close();
    while (Gtk::Main::events_pending())
        Gtk::Main::iteration();
    
    delete dialog;
    delete label;
    delete entry;
    
    if(result == 1)
    return text;
    else
        return  cancel_text;
}

int Dialogs::question(std::string msg, 
                        std::string title, 
                        std::vector<std::string> buttons)
{
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title(title);
    
    Gtk::Label *label = new Gtk::Label(msg);
    dialog->get_content_area()->pack_start(*label);
    label->show();
    
    for( int i = 0; i < buttons.size(); i++)
        dialog->add_button(buttons[i], i);
        
    int result = dialog->run();
    
    dialog->close();
    while (Gtk::Main::events_pending())
        Gtk::Main::iteration();
    
    delete dialog;
    delete label;
    return result;
}
