<?php

require_once __DIR__."/sequence.php";




function print_menu(){
    echo "\n";
    echo "The following choices are available:\n";
    echo " !     Activate the start() function\n";
    echo " +     Activate the advance() function\n";
    echo " ?     Print the result from the is_item() function\n";
    echo " C     Print the result from the current() function\n";
    echo " P     Print a copy of the entire sequence\n";
    echo " S     Print the result form the size() function\n";
    echo " I     Insert a new number with the insert(...) function\n";
    echo " A     Attach a new number with the attach(...) function\n";
    echo " R     Activate the remove_current() function\n";
    echo " Q     Quit this test program\n";
}

function get_user_command(){
    $command = 'q';
    echo "Enter choice: ";
    //cin >> command;
    return $command;
}

function show_sequence(sequence $display){
    for($display->start(); $display->is_item(); $display->advance())
        echo $display->current()."\n";;
}

function get_number(){
    $result = 0;
    do {
        echo "\nPlease enter a real number for the sequence: ";
        //cin >> result;
    } while(!is_numeric($result));
    echo $result." has been read.\n";
    return result;
}



//------------------------- script ---------------------------
int main(int argc, char* argv[]){
    string tmp = "";
    sequence test;
    char choice;
    echo "I have initialized an empty sequence of real numbers.\n";
    do {
        print_menu();
        choice = toupper(get_user_command());
        switch(choice){
            case '!':
                test.start();
                break;
            case '+':
                test.advance();
                break;
            case '?':
                tmp = (test.is_item()) ? "There is an item." : NO_CURRENT;
                cout << tmp << endl;
                break;
            case 'C':
                if(test.is_item())
                    cout << "Current item is: " << test.current() << endl;
                else
                    cout << NO_CURRENT << endl;
                break;
            case 'P':
                show_sequence(test);
                break;
            case 'S':
                cout << "Size is " << test.size() << endl;;
                break;
            case 'I':
                test.insert(get_number());
                break;
            case 'A':
                test.attach(get_number());
                break;
            case 'R':
                test.remove_current();
                break;
            case 'Q':
                cout << "Ridicule is the best test of truth." << endl;;
                break;
            default:
                cout << choice << " is invalid." << endl;
        }
    } while(choice != 'Q');
    return EXIT_SUCCESS;
}
