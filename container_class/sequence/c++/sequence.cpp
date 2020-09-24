#include <algorithm>
#include <cassert>
#include "sequence.h"
using namespace std;

namespace container_sequence {
    const sequence::size_type sequence::CAPACITY;

    sequence::sequence(const sequence& seq){
        used = seq.used;
        current_index = seq.current_index;
        for(sequence::size_type i = 0; i < CAPACITY; ++i){
            data[i] = seq.data[i];
        }
    }

    void sequence::advance(){
        if(is_item())
            ++current_index;
    }

    void sequence::shift(
        const sequence::size_type& first,
        const sequence::size_type& last,
        bool expand
    ){
        if(expand){
            for(sequence::size_type i = last; i > first; --i){
                data[i] = data[i - 1];
            }
        } else {
            for(sequence::size_type i = first; i < last; ++i){
                data[i] = data[i + 1];
            }
        }
    }

    void sequence::insert(const sequence::value_type& entry){
        assert(size() < CAPACITY);
        if(current_index != used)
            shift((current_index - 1), used++);
        data[current_index] = entry;
    }

    void sequence::attach(const sequence::value_type& entry){
        assert(size() < CAPACITY);
        if(current_index != used)
            shift(current_index, used++);
        data[current_index] = entry;
    }

    void sequence::remove_current(){
        if(is_item())
            shift(current_index, used--, false);
    }


    bool sequence::is_item() const {
        return (current_index >= 0 && current_index < used);
    }

    sequence::value_type sequence::current() const {
        return data[current_index];
    }
}
