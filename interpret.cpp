#include "compare.h" 
#include <iostream>
#include <vector>
using namespace std ;
std::vector < EVAL_BLOCK > vlb ;
char *rec( int op_id, char *bg )
{
  if( op_id == vlb.size() ) return bg ;
  unsigned int lmx = 0 ;
  while( eval_chr( &vlb[ op_id ], *( bg + lmx ) ) && lmx < vlb[ op_id ].MAX ) lmx++ ;
  for( long long len = lmx ; len >= vlb[ op_id ].MIN ; len-- )
  {
    char *eom = rec( op_id + 1, bg + len ) ;
    if( eom ) return eom ;
  }
  return 0 ;
}
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
      end = rec( 0, itr ) ;
      if( end ) break ;
    }
  }
  else end = rec( 0, itr ) ; 
  if( end )
  {
    while( itr != end ) cout << *itr++ ;
  }
  else cout << "NULL";
  cout << "\n" ;
  return 0;

}
