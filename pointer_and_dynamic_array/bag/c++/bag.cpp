#include <algorithm>
#include <iostream>
#include <cassert>
#include "bag.h"

using namespace std;

namespace bag_h {
    const bag::size_type bag::DEFAULT_CAPACITY;

    bag::bag(size_type initial_capacity){
        data = new value_type[initial_capacity];
        capacity = initial_capacity;
        used = 0;
    }

    bag::bag(const bag& source){
        data = new value_type[source.capacity];
        capacity = source.capacity;
        used = source.used;
        copy(source.data, source.data + used, data);
    }

    bag::~bag(){
        delete[] data;
    }

    void bag::reserve(size_type new_capacity){
        value_type *larger_array;
        if(new_capacity == capacity)
            return; //The allocated memory is already the right size
        if(new_capacity < used)
            new_capacity = used; //can't allocate less than what we're using.
        larger_array = new value_type[new_capacity];
        copy(data, data + used, larger_array);
        delete[] data;
        data = larger_array;
        capacity = new_capacity;
    }

    bag::size_type bag::erase(const value_type& target){
        size_type many_removed = 0;
        for(size_type i = 0; i < used; ++i){
            if(data[i] == target){
                data[i--] = data[--used];
                ++many_removed;
            }
        }
        return many_removed;
    }

    bool bag::erase_one(const value_type& target){
        for(size_type i = 0; i < used; ++i){
            if(data[i] == target){
                data[i] = data[--used];
                return true;
            }
        }
        return false;
    }

    void bag::insert(const value_type& entry){
        if(used == capacity)
            reserve(used+1);
        data[used] = entry;
        ++used;
    }

    void bag::operator +=(const bag& addend){
        if(used + addend.used > capacity)
            reserve(used + addend.used);
        copy(addend.data, addend.data + addend.used, data + used);
        used += addend.used;
    }

    void bag::operator =(const bag& source){
        value_type *new_data;
        if(this == &source)
            return;

        if(capacity != source.capacity){
            new_data = new value_type[source.capacity];
            delete[] data;
            data = new_data;
            capacity = source.capacity;
        }

        used = source.used;
        copy(source.data, source.data + used, data);
    }

    bag::size_type bag::count(const value_type& target) const {
        size_type answer = 0;
        for(size_type i = 0; i < used; ++i)
            if(target == data[i])
                ++answer;
        return answer;
    }

    bag operator +(const bag& b1, const bag& b2){
        bag answer(b1.size() + b2.size());
        answer += b1;
        answer += b2;
        return answer;
    }

    double bag::average() const {
        double sum = 0;
        assert(this->size() > 0);
        for(bag::size_type i = 0; i < used; ++i)
            sum += data[i];
        return (sum/this->size());
    }

    void bag::compare(double mean) const {
        for(bag::size_type i = 0; i < used; ++i){
            cout << data[i];
            if(data[i] < mean)
                cout << " is less than ";
            else if(data[i] > mean)
                cout << " is more tahn ";
            else
                cout << " is equal to ";
            cout << mean << endl;
        }
    }

    void bag::print_final_sequence() const {
        double mean = this->average();
        cout << "The average is: " << mean << endl;
        this->compare(mean);
        cout << "This was a mean program." << endl;
    }

    void bag::fill(bag::size_type n){
        cout << "Please type " << n << "double numbers: " << endl;
        size_type entry;
        for(size_type i = 0; i < n; ++i){
            cin >> entry;
            this->insert(entry);
        }
    }

}
