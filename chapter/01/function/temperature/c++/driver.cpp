#include<iostream>
#include<iomanip>
#include<string>

#define START   -50
#define END 60
#define INCREMENT   10
#define WIDTH   15
using namespace std;

double cToF(double c){
    return (c * 9.0 / 5.0) + 32.0;
}

double cToK(double c){
    return c + 273.15;
}

double convert(bool isF, double c){
    return (isF) ? cToF(c) : cToK(c);
}

void displayTable(bool isF){
    string type = (isF) ? "Fahrenheit" : "Kelvin";
    cout << setw(WIDTH) << "Celsius" << setw(WIDTH) << type << endl;
    for(int c = START; c < END; c += INCREMENT){
        double temp = convert(isF, c);
        cout << setw(WIDTH) << c;
        cout << setw(WIDTH) << temp << endl;
    }
}

int main(int argc, char* argv[]){
    string input;
    bool isF;
    cout << "Do you use Fahrenheit or Kelvin?" << endl;
    cin >> input;
    isF = (input != "Kelvin");
    displayTable(isF);
}
