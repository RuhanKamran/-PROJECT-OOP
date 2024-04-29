#include "Shop.h"
#include <iostream>
using namespace std;
Shop::Shop(const Shop& other) {
    start = nullptr;
    Container* prevlink = nullptr;
    Container* currentcptr = other.start;
    while (currentcptr != nullptr) {
         Container* xc = new Container;
        int namel = 0;
        const char* temp = currentcptr->name;
        while (*temp++ != '\0') {
            namel++;
        }
        xc->name = new char[namel + 1];
        for (int i = 0; i < namel; ++i) {
            xc->name[i] = currentcptr->name[i];
        }
        xc->name[namel] = '\0';
        xc->containerno = currentcptr->containerno;
        xc->link = nullptr;
        if (start == nullptr) {
            start = xc;
        }
        else {
            prevlink->link = xc; 
        }
        prevlink = xc;
        currentcptr = currentcptr->link;

    }
}
void Shop::add_Container(char* name, int containerindex) {
    Container* xc = new Container;
    int namel = 0;
    const char* temp = name;
    while (*temp++ != '\0') {
        namel++;
    }
    xc->name = new char[namel + 1];
    for (int i = 0; i < namel; ++i) {
        xc->name[i] = name[i];
    }
    xc->name[namel] = '\0';
    xc->containerno = containerindex;
    xc->link = nullptr;
    if (start == nullptr) {
        start = xc;  
    }
    else {
        Container* currentlink = start;
        while (currentlink->link != nullptr) {
            currentlink = currentlink->link;
        }
        currentlink->link = xc;
    }
    }

void Shop::print_Shop() {
    if (start == nullptr) {
        return;
    }
    Container* currentlink = start;
    while (currentlink != nullptr) {
        cout << currentlink->name << "-" << currentlink->containerno << "\n";
        currentlink = currentlink->link;
    }
}
void Shop::delete_Chain(int containerindex) {
    if (start == nullptr) {
        return;
    }
    else {
        Container* currentlink = start;
        Container* prevlink = nullptr;
        while (currentlink->containerno != containerindex) {
            prevlink = currentlink;
            currentlink = currentlink->link;
        }
        if (prevlink == nullptr) {
            //then delete the one block that exists
            start = nullptr;
            currentlink = nullptr;
        }
        //else delete the other block and connect the rest 
        else {
            prevlink->link = currentlink->link;
            currentlink = currentlink->link;
        }
    }
}
void Shop::Sort_Chain() {
    if (start == nullptr) {
        return;
    }
        //check size of shop
        Container* prevlink = start;
        Container* currentlink = start;
        /////////////////////////
        // loop to access each array element
        while (prevlink != nullptr) {
            currentlink = prevlink->link;
            // loop to compare two elements
            while (currentlink != nullptr) {
                if (prevlink->containerno > currentlink->containerno) {
                    Container temp;
                    temp.name = prevlink->name;
                    temp.containerno = prevlink->containerno;
                    prevlink->name = currentlink->name;
                    prevlink->containerno = currentlink->containerno;
                    currentlink->name = temp.name;
                    currentlink->containerno = temp.containerno;
                    
                }
                currentlink = currentlink->link;
               
            }
            prevlink = prevlink->link;

        }
    }

void Shop::update_name_at_containerNumber(int containerindex, char* name) {
    if (start == nullptr) {
        return;
    }
    //find container
    Container* currentlink = start;
    Container* prevlink = nullptr;
    while (currentlink->containerno != containerindex) {
        prevlink = currentlink;
        currentlink = currentlink->link;
    }

    //copy name
        // Determine the length of the name
    int namel = 0;
    int i = 0;
    while (name[i] != '\0') {
        namel++;
        i++;
    }


    // Allocate memory for the name in the new Container
    char* tempname = new char[namel + 1];

    // Copy characters from temp->name to tempname
    for (int i = 0; i <= namel; i++) {
        tempname[i] = name[i];
    }
    // Assign copied values
    currentlink->name = tempname;
}
void Shop::remove_Duplicate() {
    if (start == nullptr) {
        return;
    }
    else {
        Container* currentlink = start;
        Container* temp = start;
        Container* prevlink = start;
        while (currentlink != nullptr) {
            temp = currentlink->link;
            prevlink = currentlink;
            while (temp != nullptr) {
                // Compare names and container numbers
                bool same = true;
                int x = 0;
                while (currentlink->name[x] != '\0' && temp->name[x] != '\0' && currentlink->name[x] == temp->name[x]) {

                    if (currentlink->name[x] == temp->name[x]) {
                        same = true;
                    }
                    else {
                        same = false;
                    }
                    x++;
                }
                if (same && currentlink->containerno == temp->containerno) {
                    prevlink->link = temp->link;
                    temp = prevlink->link;
                }
                else {
                    prevlink = temp;
                    temp = temp->link;
                }

            }
            currentlink = currentlink->link;
        }
    }
}



void Shop::findContainer(int containerindex) {
    if (start == nullptr) {
        return;
    }
    else {
        bool found = true;
        Container* currentlink = start;
        while (currentlink != nullptr) {
            if (currentlink->containerno == containerindex) {
                cout << currentlink->name << "\n";
                found = true;
                break;
            }
            else {
                currentlink = currentlink->link;
            }
            
        }
        if (found == false) {
            cout << "not found";
        }
    }
}
void Shop::findContainer(int containerindex1, int containerindex2) {
    if (start == nullptr) {
        return;
    }
    else {
        Container* currentlink = start;
        while (currentlink != nullptr) {
            if (currentlink->containerno >= containerindex1 && currentlink->containerno <= containerindex2) {
                cout << currentlink->name << "\n";
            }
            currentlink = currentlink->link;
        }
    }
}

 Shop::~Shop() {
    }


