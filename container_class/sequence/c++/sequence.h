#ifndef CONTAINER_SEQUENCE_H
#define CONTAINER_SEQUENCE_H
#include <cstdlib>

namespace container_sequence {
    class sequence {
    public:
        typedef double value_type;
        typedef size_t size_type;
        static const size_type CAPACITY = 30;
        //CONSTRUCTOR
        sequence(){ used = 0; }
        //Copy Constructor goes here
        //...
        //----------------- MODIFICATION MEMBER FUNCTIONS -------------------
        void start(){ current_index = 0; }
        void advance();
        void insert(const value_type& entry);
        void attach(const value_type& entry);
        void remove_current();
        //------------------- CONSTANT MEMBER FUNCTIONS ---------------------
        size_type size() const { return used; }
        bool is_item() const;
        value_type current() const;
    private:
        value_type data[CAPACITY];
        size_type used;
        size_type current_index;
    };
}

#endif
