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
bool is_any( char c ) { return ( c != '\0' ) ; }
bool is_inlist( char c, std::vector < char > &chrps )
{
  for( char p: chrps ) if( c == p ) return !( 0 ) ;
  return 0 ;
}

char *match_alnum( char *c )
{
  const char *str = "[[:alnum:]]", *shr = "\\w" ;
  char *d = c ;
  for( ; *shr && *shr == *d ; shr++, d++ ) ;
  if( ! *shr ) return d ;
  for( ; *str && *str == *c ; str++, c++ ) ;
  return ( ! *str ? c : 0 ) ;
}
char *match_alpha( char *c )
{
  const char *str = "[[:alpha:]]" ;
  for( ; *str && *str == *c ; str++, c++ ) ;
  return ( ! *str ? c : 0 ) ;
}
char *match_blank( char *c )
{
  const char *str = "[[:blank:]]" ;
  for( ; *str && *str == *c ; str++, c++ ) ;
  return ( ! *str ? c : 0 ) ;
}
char *match_cntrl( char *c )
{
  const char *str = "[[:cntrl:]]" ;
  for( ; *str && *str == *c ; str++, c++ ) ;
  return ( ! *str ? c : 0 ) ;
}
char *match_digit( char *c )
{
  const char *str = "[[:digit:]]", *shr = "\\d" ;
  char *d = c ;
  for( ; *shr && *shr == *d ; shr++, d++ ) ;
  if( ! *shr ) return d ;
  for( ; *str && *str == *c ; str++, c++ ) ;
  return ( ! *str ? c : 0 ) ;
}
char *match_graph( char *c )
{
  const char *str = "[[:graph:]]" ;
  for( ; *str && *str == *c ; str++, c++ ) ;
  return ( ! *str ? c : 0 ) ;
}
char *match_lower( char *c )
{
  const char *str = "[[:lower:]]" ;
  for( ; *str && *str == *c ; str++, c++ ) ;
  return ( ! *str ? c : 0 ) ;
}
char *match_print( char *c )
{
  const char *str = "[[:print:]]" ;
  for( ; *str && *str == *c ; str++, c++ ) ;
  return ( ! *str ? c : 0 ) ;
}
char *match_punct( char *c )
{
  const char *str = "[[:punct:]]" ;
  for( ; *str && *str == *c ; str++, c++ ) ;
  return ( ! *str ? c : 0 ) ;
}
char *match_space( char *c )
{
  const char *str = "[[:space:]]", *shr = "\\s" ;
  char *d = c ;
  for( ; *shr && *shr == *d ; shr++, d++ ) ;
  if( ! *shr ) return d ;
  for( ; *str && *str == *c ; str++, c++ ) ;
  return ( ! *str ? c : 0 ) ;
}
char *match_upper( char *c )
{
  const char *str = "[[:upper:]]" ;
  for( ; *str && *str == *c ; str++, c++ ) ;
  return ( ! *str ? c : 0 ) ;
}
char *match_xdigit( char *c )
{
  const char *str = "[[:xdigit:]]" ;
  for( ; *str && *str == *c ; str++, c++ ) ;
  return ( ! *str ? c : 0 ) ;
}
char *match_any( char *c )
{
  const char *str = "[[:any:]]", *shr = "." ;
  char *d = c ;
  for( ; *shr && *shr == *d ; shr++, d++ ) ;
  if( ! *shr ) return d ;
  for( ; *str && *str == *c ; str++, c++ ) ;
  return ( ! *str ? c : 0 ) ;
}

check_pair check_fns[] = {
  { match_alnum, is_alnum },
  { match_alpha, is_alpha },
  { match_blank, is_blank },
  { match_cntrl, is_cntrl },
  { match_digit, is_digit },
  { match_graph, is_graph },
  { match_lower, is_lower },
  { match_print, is_print },
  { match_punct, is_punct },
  { match_space, is_space },
  { match_upper, is_upper },
  { match_xdigit, is_xdigit },
  { match_any, is_any }
} ;

int matcher_count = sizeof( check_fns ) / sizeof( check_fns[ 0 ] ) ;

#include <vector>
std::vector < EVAL_BLOCK > break_ops( char *rgx )
{
  std::vector < EVAL_BLOCK > vlp ;
  EVAL_BLOCK tcr ;
  while ( *rgx )
  {
    char *p = 0 ;
    tcr = { 0 } ;
    
    for( int i = 0 ; i < matcher_count && ! p ; i++ )
    {
      p = check_fns[ i ].rgx_chk( rgx ) ;
      if( p ) tcr.chk = check_fns[ i ].str_chk ;
    }
    if( ! p )
    {
      tcr.chk = 0 ;
      if( *rgx == '\\' ) tcr.charps.push_back( *( ++rgx ) );
      else tcr.charps.push_back( *rgx ) ;
      p = ( rgx + 1 ) ;
    }
    if( *p == '+' ) tcr.MIN = 1, tcr.MAX = -1, p++ ;
    else if( *p == '*' ) tcr.MIN = 0, tcr.MAX = -1, p++ ;
    else if( *p == '?' ) tcr.MIN = 0, tcr.MAX = 1, p++ ;
    else if( *p == '{' ) // we consider no spacing, for now only n exact
    {
      p++ ;
      int nr = 0 ;
      while( is_digit( *p ) ) nr = nr * 10 + ( *p - '0' ), p++ ;
      tcr.MIN = tcr.MAX = nr ;
      if( *p ) p++ ;
    }
    else tcr.MIN = tcr.MAX = 1 ;

    rgx = p ;
    vlp.push_back( tcr ) ;
  }
  return vlp ;
}

char *rec( int op_id, char *bg, std::vector < EVAL_BLOCK > &vlb)
{
  if( op_id == vlb.size() ) return bg ;
  unsigned int lmx = 0 ;
  if( vlb[ op_id ].chk )
  {
    while( vlb[ op_id ].chk( *( bg + lmx ) ) && lmx < vlb[ op_id ].MAX ) lmx++ ;
  }
  else
  {
    char cp = 0 ; if( is_inlist( *bg, vlb[ op_id ].charps ) ) cp = *bg ;
    while( *( bg + lmx ) == cp && lmx < vlb[ op_id ].MAX ) lmx++ ;
  }
  for( long long len = lmx ; len >= vlb[ op_id ].MIN ; len-- )
  {
    char *eom = rec( op_id + 1, bg + len, vlb) ;
    if( eom ) return eom ;
  }
  return 0 ;
}
