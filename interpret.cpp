#include "compare.h" 
#include <iostream>
#include <vector>
using namespace std ;
std::vector < EVAL_BLOCK > vlb ;
char *rec( int op_id, char *bg )
{
  if( op_id == vlb.size() ) return bg ;
  unsigned int lmx = 0 ;
  while( eval_chr( &vlb[ op_id ], *( bg + lmx ) ) && lmx <= vlb[ op_id ].MAX ) lmx++ ;
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
  vlb = move(break_ops( argv[ 1 ] ) ) ;
  for( EVAL_BLOCK op: vlb ) cout << op.MIN << ", " << op.MAX << "|";
  char *end = rec( 0, argv[ 2 ] ) ;
  if( end )
  {
    char *itr = argv[ 2 ] ;
    while( itr != end ) cout << *itr++ ;
  }
  else cout << "NULL";
  cout << "\n" ;
  return 0;

}
