<?php
    /*
     * FILE: mystring.h
// CLASS PROVIDED: string (a simple version of the Standard Library string class) DONE
//
// CONSTRUCTOR for the string class:
// -- default argument is the empty string.
// Precondition: str is an ordinary null-terminated string.
// Postcondition: The string contains the sequence of chars from str.
//
// CONSTANT MEMBER FUNCTIONS for the string class:
//
// Postcondition: The return value is the number of characters in the string.
//
//
// Precondition: position < length( ).
// Postcondition: The value returned is the character at the specified position of the
// string. A string’s positions start from 0 at the start of the sequence and go up to
// length( ) – 1 at the right end.
//
// MODIFICATION MEMBER FUNCTIONS for the string class:
//
// Postcondition: addend has been catenated to the end of the string.
//
//
// Precondition: addend is an ordinary null-terminated string.
// Postcondition: addend has been catenated to the end of the string.
//
//
// Postcondition: The single character addend has been catenated to the end of the string.
//
//
// Postcondition: All functions will now work efficiently (without allocating new memory)
// until n characters are in the string.
     */
    class StlString {
        function __construct($str){
            $this->$str = $str;
        }
    }

    function main() {
        StlString $test = new StlString("Hello World");
    }
    echo main();
