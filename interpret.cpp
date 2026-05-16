#include "compare.h" 
#include <iostream>
#include <vector>
using namespace std ;
std::vector < EVAL_BLOCK > vlb ;
bool rec( int op_id, char *bg )
{
  if( op_id == vlb.size() ) return 1 ;
  
  for( unsigned int len = vlb[ op_id ].MIN ; len <= vlb[ op_id ].MAX ; len++ )
  {
    for( unsigned int cl = 0 ; cl < len ; cl++ )
      if( ! vlb[ op_id ].chk( *( bg + cl ) ) )
        return 0 ;
    if( rec( op_id + 1, bg + len ) ) return 1 ;
  }
  return 0 ;
}
int main ( int argc, char *argv[] )
{
  if( argc < 3 ) return -1 ;
  vlb = move(break_ops( argv[ 1 ] ) ) ;
  for( EVAL_BLOCK op: vlb ) cout << op.MIN << ", " << op.MAX << "|";
  cout << "\n\n" << rec( 0, argv[ 2 ] ) << "\n" ;
  return 0;

}
