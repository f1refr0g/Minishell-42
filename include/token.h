#ifndef TOKEN_H
# define TOKEN_H

#include "minishell.h"

typedef enum    e_token_type
{
    ERROR,
    PIPE,
    ALPHA,
    OUTFILE,
    INFILE,
    APPEND,
    HEREDOC,
}               t_token_type;

typedef struct s_token
{
    char *value;
    int     len;
    t_token_type        type;

} t_token ;

typedef struct s_token_list
{
    t_token     token;
    struct t_token_list *next;
    struct t_token_list *prev;
    int          len;
    
}   t_token_list;

typedef struct  t_tokenizer
{
    int             i;
    int             len;
    char            *prompt;
    t_token_list    *head;
    t_token_list    *current;

}   t_tokenizer;

#endif