#include "compare.h" 
#include <iostream>
#include <vector>
using namespace std ;
std::vector < EVAL_BLOCK > vlb ;
int main ( int argc, char *argv[] )
{
  if( argc < 3 ) return -1 ;
  char *regex = argv[ 1 ], *string = argv[ 2 ];
  vlb = move(break_ops( regex + ( *regex == '^' ) ) ) ;
  for( EVAL_BLOCK op: vlb ) cout << op.MIN << ", " << op.MAX << "|";
  char *itr = string ;
  char *end = 0 ;
  if( *regex != '^' )
  {
    for( ; *itr ; itr++ )
    {
      end = rec( 0, itr, vlb ) ;
      if( end ) break ;
    }
  }
  else end = rec( 0, itr, vlb ) ;
  if( end )
  {
    while( itr != end ) cout << *itr++ ;
  }
  else cout << "NULL";
  cout << "\n" ;
  return 0;

}
