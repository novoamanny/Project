#include "mainwin.h"
#include <exception>
#include <stdexcept>
#include <iostream>

void Mainwin::on_log_in_click() {

    // /////////////////////////////
    // Select Item Type
    Gtk::Dialog dialog_type{"Select Log In Type", *this};
    //Gtk::Dialog dialog_type;
    //dialog_type.set_title("Select Item Type");
    const int WIDTH = 15;

    // Type
    Gtk::HBox b_type;

    Gtk::Label l_type{"Log In:"};
    l_type.set_width_chars(WIDTH);
    b_type.pack_start(l_type, Gtk::PACK_SHRINK);

    // TODO: Replace this with 3 large, colorful buttons
    Gtk::ComboBoxText c_type;
    c_type.set_size_request(WIDTH*10);
    const int SERVER = 0;
    c_type.append("Server");
    const int MANAGER = 1;
    c_type.append("Manager");
    const int CUSTOMER = 2;
    c_type.append("Customer");
    b_type.pack_start(c_type, Gtk::PACK_SHRINK);
    dialog_type.get_vbox()->pack_start(b_type, Gtk::PACK_SHRINK);

    // Show dialog_type
    dialog_type.add_button("Cancel", 0);
    dialog_type.add_button("OK", 1);
    dialog_type.show_all();
    if (dialog_type.run() != 1) {
        dialog_type.close();
        return;
    }

    int type = c_type.get_active_row_number();

    dialog_type.close();

    // //////////////////////////////
    // Define Item

    Gtk::Dialog dialog;
    if (type == SERVER) on_server_log_in_click();
    //else if (type == MANAGER) dialog.set_title("Create Manager");
    else on_customer_log_in_click();
    dialog.set_transient_for(*this);

   
    
    dialog.close();
}
