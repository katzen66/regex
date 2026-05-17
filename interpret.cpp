#include "compare.h" 
#include <iostream>
#include <vector>
using namespace std ;
std::vector < EVAL_BLOCK > vlb ;
char *rec( int op_id, char *bg )
{
  if( op_id == vlb.size() ) return bg ;
  
  for( unsigned int len = vlb[ op_id ].MIN ; len <= vlb[ op_id ].MAX ; len++ )
  {
    for( unsigned int cl = 0 ; cl < len ; cl++ )
    {
      if( vlb[ op_id ].chk )
      {
        if( ! vlb[ op_id ].chk( *( bg + cl ) ) )
          return 0 ;
      }
      else if( vlb[ op_id ].chrq != *( bg + cl ) ) return 0 ;
    }
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
