#ifndef REGEX_H

#define REGEX_H

bool is_alnum( char c ); // all letters and digits
bool is_alpha( char c ); // all letters
bool is_blank( char c ); // all horizontal whitespace
bool is_cntrl( char c ); // all control characters
bool is_digit( char c ); // all digits
bool is_graph( char c ); // all printable characters, not including space
bool is_lower( char c ); // all lower case letters
bool is_print( char c ); // all printable characters, including space
bool is_punct( char c ); // all punctuation characters
bool is_space( char c ); // all horizontal or vertical whitespace
bool is_upper( char c ); // all upper case letters
bool is_xdigit( char c ); // all hexadecimal digits

#endif
