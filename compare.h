#ifndef REGEX_H

#define REGEX_H

bool is_alnum( char c ); // all letters and digits
bool is_alpha( char c ); // all letters
bool is_blank( char c ); // all horizontal whitespace
bool is_cntrl( char c ); // all control characters
bool is_digit( char c ); // all digits
bool is_graph( char c ); // all printable characters, not including space
bool is_lower( char c ); // all lower case letters
bool is_print( char c ); // all printable characters, including space
bool is_punct( char c ); // all punctuation characters
bool is_space( char c ); // all horizontal or vertical whitespace
bool is_upper( char c ); // all upper case letters
bool is_xdigit( char c ); // all hexadecimal digits
bool is_any( char c ); // any character

char *match_alnum( char *c ); // match [[:alnum:]]
char *match_alpha( char *c ); // match [[:alpha:]]
char *match_blank( char *c ); // match [[:blank:]]
char *match_cntrl( char *c ); // match [[:cntrl:]]
char *match_digit( char *c ); // match [[:digit:]]
char *match_graph( char *c ); // match [[:graph:]]
char *match_lower( char *c ); // match [[:lower:]]
char *match_print( char *c ); // match [[:print:]]
char *match_punct( char *c ); // match [[:punct:]]
char *match_space( char *c ); // match [[:space:]]
char *match_upper( char *c ); // match [[:upper:]]
char *match_xdigit( char *c ); // match [[:xdigit:]]
char *match_any( char *c ); // match [[:any:]]

typedef char *( *match_fn )( char * );
typedef bool ( *check_fn )( char );
typedef struct
{
  match_fn rgx_chk;
  check_fn str_chk;
} check_pair;

extern int matcher_count;
extern check_pair check_fns[];

struct EVAL_BLOCK
{
  check_fn chk = 0;
  unsigned int MIN, MAX;
  char chrq = 0 ;
};
#include <vector>
std::vector < EVAL_BLOCK > break_ops( char *rgx );
bool eval_chr( EVAL_BLOCK *blk, char chr );

#endif
