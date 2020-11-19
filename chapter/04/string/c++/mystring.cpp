#include <algorithm>
#include <iostream>
#include <cassert>
#include "mystring.h"

using namespace std;

namespace mystring_h {

    string::string(const char str[]){
        current_length = strlen(str);
        allocated = current_length + 1;
        characters = new char[allocated];
        strcpy(characters, str);
    }

    bool operator ==(const string& s1, const string& s2){
        return (strcmp(s1.characters, s2.characters) == 0);
    }

}
