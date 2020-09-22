#include <algorithm>
#include <cassert>
#include "sequence.h"
using namespace std;

namespace container_sequence {
    const sequence::size_type sequence::CAPACITY;

    void sequence::advance(){
        assert(is_item());
        if(current_index != used - 1)
            ++current_index;
    }

    void sequence::insert(const sequence::value_type& entry){
        assert(size() < CAPACITY);
        if(current_index != used){
            //FIXME: There's a bug here
            for(sequence::size_type i = ++used; i >= current_index; --i){
                data[i] = data[i - 1];
            }
        }
        data[current_index] = entry;
    }

    void sequence::attach(const sequence::value_type& entry){
        assert(size() < CAPACITY);
        if(current_index != used){
            //FIXME: There's a bug here
            for(sequence::size_type i = ++used; i > current_index; --i){
                data[i] = data[i - 1];
            }
        }
        data[++current_index] = entry;
    }

    void sequence::remove_current(){
        data[current_index] = data[used--];
    }

    bool sequence::is_item() const {
        return (current_index >= 0 && current_index < used);
    }

    sequence::value_type sequence::current() const {
        return data[current_index];
    }
}
