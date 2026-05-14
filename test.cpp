#include <iostream>
#include "compare.h"
using namespace std ;
char a ;
int main()
{
  cout << "is_alnum: " ; cin >> noskipws >> a ; cout << is_alnum( a ) << "\n" ;
  cout << "is_alpha: " ; cin >> noskipws >> a ; cout << is_alpha( a ) << "\n" ;
  cout << "is_blank: " ; cin >> noskipws >> a ; cout << is_blank( a ) << "\n" ;
  cout << "is_cntrl: " ; cin >> noskipws >> a ; cout << is_cntrl( a ) << "\n" ;
  cout << "is_digit: " ; cin >> noskipws >> a ; cout << is_digit( a ) << "\n" ;
  cout << "is_graph: " ; cin >> noskipws >> a ; cout << is_graph( a ) << "\n" ;
  cout << "is_lower: " ; cin >> noskipws >> a ; cout << is_lower( a ) << "\n" ;
  cout << "is_print: " ; cin >> noskipws >> a ; cout << is_print( a ) << "\n" ;
  cout << "is_punct: " ; cin >> noskipws >> a ; cout << is_punct( a ) << "\n" ;
  cout << "is_space: " ; cin >> noskipws >> a ; cout << is_space( a ) << "\n" ;
  cout << "is_upper: " ; cin >> noskipws >> a ; cout << is_upper( a ) << "\n" ;
  cout << "is_xdigit: " ; cin >> noskipws >> a ; cout << is_xdigit( a ) << "\n" ;
}
