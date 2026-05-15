#include "compare.h" 
#include <iostream>
#include <vector>
using namespace std ;
int main ( int argc, char *argv[] )
{
  if( argc < 3 ) return -1 ;
  std::vector< int > vlp = move( break_ops( argv[ 1 ] ) );
  char *sr = argv[ 2 ] ;
  while( *sr )
  {
    char *nw = sr ;
    int op_index = 0 ;
    bool ok = 1 ;
    for( ; ok && *nw && op_index < vlp.size() ; op_index++ )
      if( ! check_fns[ vlp[ op_index ] ].str_chk( *( nw++ ) ) )
        ok = 0 ;
    if( op_index != vlp.size() ) ok = 0 ;
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
