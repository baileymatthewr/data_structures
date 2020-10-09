#ifndef BAG_H
#define BAG_H
#include <cstdlib>

namespace bag_h {
    class bag {
    public:
        typedef double value_type;
        typedef std::size_t size_type;
        static const size_type DEFAULT_CAPACITY = 30;
        // constructors & destructor
        bag(size_type initial_capacity=DEFAULT_CAPACITY);
        bag(const bag& source);
        ~bag();

        // modification member functions
        void fill();
        void reserve(size_type new_capacity);
        bool erase_one(const value_type& target);
        size_type erase(const value_type& target);
        void insert(const value_type& entry);
        void operator +=(const bag& addend);
        void operator =(const bag& source);

        // const member functions
        size_type size() const { return used; }
        size_type count(const value_type& target) const;

        // public library functions
        void print_final_sequence();
    private:
        value_type *data;
        size_type used;
        size_type capacity;
        // const member private functions
        double average() const;
        void compare(double mean) const;
    };
    // nonmember functions
    bag operator +(const bag& b1, const bag& b2);
}
#endif
