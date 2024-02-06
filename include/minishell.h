#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h> 	
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "./readline/readline.h"
# include "./readline/history.h"	
# include <termios.h>
# include "libft/libft.h"
# include "token.h"


//ERROR MESSAGE
# define MALLOC_ERROR "Error : Memory allocation\n"

//Quote handling
# define QUOTE 0
# define SINGLE_QUOTE 1
# define DOUBLE_QUOTE 2



typedef struct s_data 
{
    char             **env;
    char             *prompt;
    char             **array;
    char             *expended;
    int                 len;
    int                 nlen;

    // struct termios  term;
    int             state;
	// int				exit_code;

} t_data ;





//init_minishell.c

void    ft_init_minishell(t_data *data, char **env);
void    ft_init_env(t_data *data, char **env);

//cean.c

void    ft_clean(t_data *data);

//Built-in.c
void    ft_exit(t_data *data);
int     check_exit(char *prompt);
void    ft_env(t_data *data);
int     check_env(char *prompt);

//Built-in2.c
int     check_pwd(char *prompt);
void    ft_pwd(t_data *data);

//token.c
char    **ft_parse(t_data *data);
int     ft_count(char *str);
char    *ft_expend(t_data *data);

//quote.c
bool    valid_quote(char *str, int len, int quote);
bool    contain_cash(char *str);
#endif
