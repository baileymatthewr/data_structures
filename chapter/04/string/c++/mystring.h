#ifndef MYSTRING_H
#define MYSTRING_H
#include <cstdlib>

namespace mystring_h {
    class string {
    public:
        string(const char str[] = "");
        size_t length() const;
        char operator [](size_t position) const;
        void operator +=(const string& addend);
        void operator +=(const char addend);
        void operator +=(char addend);
        void reserve(size_t n);
        string operator +(const string& s1, const string& s2);
        istream& operator >>(istream& ins, string& target);
        ostream& operator <<(ostream& outs, const string& source);
        istream& getline(istream& ins, string& target, char delimiter = '\n');
    private:
        char *characters;
        std::size_t allocated;
        std::size_t current_length;
    };
}
#endif
