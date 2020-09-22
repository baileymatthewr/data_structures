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
            //shift everything over
            sequence::size_type last = used++;
            sequence::size_type start = current_index;
            while(last != start){
                data[last--] = data[last - 1];
            }
        }
        data[current_index] = entry;
    }

    void sequence::attach(const sequence::value_type& entry){
        assert(size() < CAPACITY);
        if(current_index != used){
            //shift everything over
            sequence::size_type last = used++;
            sequence::size_type start = current_index + 1;
            while(last != start){
                data[last--] = data[last - 1];
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
