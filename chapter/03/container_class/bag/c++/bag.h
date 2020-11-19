#ifndef CONTAINER_BAG_H
#define CONTAINER_BAG_H
#include <cstdlib>

namespace container_bag {
    class bag {
    public:
        typedef int value_type;
        typedef size_t size_type;
        static const size_type CAPACITY = 30;
        //CONSTRUCTOR
        bag(){ used = 0; }
        //Copy Constructor goes here
        //...
        //----------------- MODIFICATION MEMBER FUNCTIONS -------------------
        size_type erase(const value_type& target);
        bool erase_one(const value_type& target);
        void insert(const value_type& entry);
        void operator +=(const bag& addend);
        //------------------- CONSTANT MEMBER FUNCTIONS ---------------------
        size_type size() const { return used; }
        size_type count(const value_type& target) const;
    private:
        value_type data[CAPACITY];
        size_type used;
    };

    //----------------------- NON MEMBER FUNCTIONS --------------------------
    bag operator +(const bag& b1, const bag& b2);
}

#endif
