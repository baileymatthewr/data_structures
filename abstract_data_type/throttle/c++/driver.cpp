#include<iostream>
#include<cstdlib>

using namespace std;

class throttle {
public:
    void shut_off(){
        position = 0;
    }

    void shift(int amount){
        position += amount;
        if(position < 0)
            position = 0;
        else if(position > 6)
            position = 6;
    }

    double flow() const {
        return (position / 6.0);
    }

    bool is_on() const {
        return (flow() > 0);
    }
private:
    int position;
};

int main(int argc, char* argv[]){
    throttle sample;
    int user_input;
    cout << "I have a throttle with 6 positions." << endl;
    cout << "Where would you like to set the throttle?" << endl;
    cout << "Please type a number from 0 to 6: ";
    cin >> user_input;
    sample.shut_off();
    sample.shift(user_input);
    while(sample.is_on()){
        cout << "The flow is now " << sample.flow() << endl;
        sample.shift(-1);
    }
    cout << "The flow is now off" << endl;
    return EXIT_SUCCESS;
}

