#include<iostream>
#include<cstdlib>
#include<cassert>
#include "mystring.h"

using namespace std;

void match(
    const string& variety,
    const string& mine,
    const string& yours
);



int main(int argc, char* argv[]){
    const string BLANK(" ");
    string me_first("Demo");
    string me_last("Program");
    string you_first, you_last, you;
    cout << "What is your first name?";
    cin >> you_first;
    match("first name", me_first, you_first);
    cout << "What is your last name?";
    cin >> you_last;
    match("last name", me_last, you_last);

    you = you_first + BLANK + you_last;
    cout << "I am happy to meet you, " << you << "." << endl;
    return EXIT_SUCCESS;
}



void match(
    const string& variety,
    const string& mine,
    const string& yours
){
    if(mine == yours)
        cout << "That is the same as my " << variety << '!' << endl;
    else
        cout << "My " << variety << " is " << mine << '.' << endl;
}
