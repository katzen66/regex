#include "compare.h"
#include <cctype>
bool is_alnum( char c ) { return ( is_alpha( c ) || is_digit( c ) ) ; }
bool is_alpha( char c ) { return ( is_lower( c ) || is_upper( c ) ) ; } 
bool is_blank( char c ) { return ( c == ' ' || c == '\t' ) ; } 
bool is_cntrl( char c ) { return ( ( 0 <= c && c <= 31 ) || c == 127) ; } 
bool is_digit( char c ) { return std::isdigit( c ) ; } 
bool is_graph( char c ) { return is_print( c ) && ( ! is_space( c ) ) ; } 
bool is_lower( char c ) { return std::islower( c ) ; } 
bool is_print( char c ) { return( ! is_cntrl( c ) ) ; } 
bool is_punct( char c ) { return is_graph( c ) && ( ! is_alnum( c ) ) ; } ; 
bool is_space( char c ) { return ( is_blank( c ) || c == '\n' || c == '\r' || c == '\f' || c == '\v' ) ; } 
bool is_upper( char c ) { return std::isupper( c ) ; }
bool is_xdigit( char c ) { return ( is_digit( c ) || ( 'a' <= c && c <= 'f' ) || ( 'A' <= c && c <= 'F' ) ) ; }
