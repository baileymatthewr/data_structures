#include<iostream>
#include<cstdlib>
#include<cassert>
#include "bag.h"

using namespace std;
using namespace bag_h;


int main(int argc, char* argv[]){
    size_t array_size;
    double mean_value;

    cout << "This program will compute the average of some numbers. The\n";
    cout << "numbers will be stored in an array of doubles that I allocate.\n";
    cout << "How many doubles should I allocate?" << endl;
    cout << "Please type a positive integer answer: ";
    cin >> array_size;
    bag* numbers = new bag(array_size);

    numbers->fill(array_size);

    numbers->print_final_sequence();
    return EXIT_SUCCESS;
}

