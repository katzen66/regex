#include "compare.h" 
#include <iostream>
#include <vector>
using namespace std ;
int main ( int argc, char *argv[] )
{
  if( argc < 3 ) return -1 ;
  std::vector < EVAL_BLOCK > vlb = move( break_ops( argv[ 1 ] ) ) ;
  for( EVAL_BLOCK op: vlb ) cout << op.MIN << ", " << op.MAX << "|";
  char *sr = argv[ 2 ] ;
  while( *sr )
  {
    char *nw = sr ;
    int op_index = 0 ;
    bool ok = 1 ;
    for( ; ok && *nw && op_index < vlb.size() ; op_index++ )
      if( ! vlb[ op_index ].chk( *( nw++ ) ) )
        ok = 0 ;
    if( op_index != vlb.size() ) ok = 0 ;
    if( ok )
    {
      cout << "matches\n" ;
      return 1 ;
    }
    sr++ ;
  }
  cout << "nope\n" ;
  return 0;

}
