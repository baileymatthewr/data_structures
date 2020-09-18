#include <algorithm>
#include <cassert>
#include "bag.h"
using namespace std;

namespace container_bag {
    const bag::size_type bag::CAPACITY;

    bag::size_type bag::erase(const value_type& target){
        size_type many_removed = 0;
        for(int i = 0; i < used; ++i){
            if(data[i] == target){
                data[i--] = data[used--];
                ++many_removed;
            }
        }
        return many_removed;
    }

    bool bag::erase_one(const value_type& target){
        for(int i = 0; i < used; ++i){
            if(data[i] == target){
                data[i] = data[--used];
                return true;
            }
        }
        return false; //index >= used
    }

    void bag::insert(const value_type& entry){
        assert(size() < CAPACITY);
        data[used++] = entry;
    }

    void bag::operator +=(const bag& addend){
        assert(&addend != this); //This only works when it's not itself
        assert(size() + addend.size() <= CAPACITY);
        copy(addend.data, addend.data + addend.used, data + used);
        used += addend.used;
    }

    bag::size_type bag::count(const value_type& target) const {
        size_type answer = 0;
        for(int i = 0; i < used; ++i){
            if(target == data[i])
                ++answer;
        }
        return answer;
    }

    bag operator +(const bag& b1, const bag& b2){
        bag answer;
        assert(b1.size() + b2.size() <= bag::CAPACITY);
        answer += b1;
        answer += b2;
        return answer;
    }
}
