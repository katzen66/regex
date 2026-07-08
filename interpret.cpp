#include "compare.h" 
#include <iostream>
#include <vector>
using namespace std ;
std::vector < EVAL_BLOCK > vlb ;
int main ( int argc, char *argv[] )
{
  if( argc < 3 ) return -1 ;
  char *regex = argv[ 1 ], *string = argv[ 2 ];

  bool match_end = 0 ; char *rpe = regex ;
  while( *( rpe + 1 ) ) rpe++ ;
  if( *rpe == '$' && *( rpe - 1) != '\\' )
  {
    match_end = !( 0 ) ;
    *rpe = 0 ;
  }

  vlb = move(break_ops( regex + ( *regex == '^' ) ) ) ;
  for( EVAL_BLOCK op: vlb ) cout << op.MIN << ", " << op.MAX << " ^ " << op.neg << "|" ; cout << match_end << "| " ;
  char *itr = string ;
  char *end = 0 ;
  unsigned int op_begin = 0 | ( boffset * match_end ) ;
  if( *regex != '^' )
  {
    for( ; *itr ; itr++ )
    {
      end = rec( op_begin, itr, vlb ) ;
      if( end ) break ;
    }
  }
  else end = rec( op_begin, itr, vlb ) ;
  if( end )
  {
    while( itr != end ) cout << *itr++ ;
  }
  else cout << "NULL";
  cout << "\n" ;
  return 0;

}
