#include<iostream>
#include<cstdlib>
#include "bag.h"

using namespace std;
using namespace container_bag;

void get_ages(bag& ages);
void check_ages(bag& ages);

int main(int argc, char* argv[]){
    bag ages;
    get_ages(ages);
    check_ages(ages);
    cout << "May your family live long and prosper." << endl;
    return EXIT_SUCCESS;
}


void get_ages(bag& ages){
    int user_input;
    cout << "Type the ages in your family." << endl;
    cout << "Type a negative number when you are done:" << endl;
    do {
        cin >> user_input;
        if(user_input >= 0)
            ages.insert(user_input);
    } while(user_input >= 0 && ages.size() < ages.CAPACITY);
}

void check_ages(bag& ages){
    int user_input;
    cout << "Type those ages again. Press return after each age:" << endl;
    do {
        cin >> user_input;
        if(user_input >= 0){
            if(ages.erase_one(user_input))
                cout << "Yes, I've found that age and removed it." << endl;
            else
                cout << "No, that age does not occur!" << endl;
        }
    } while(user_input >= 0 && ages.size() > 0);
}
