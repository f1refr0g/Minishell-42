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
# include <signal.h>

//ERROR MESSAGE

# define MALLOC_ERROR "Error : Memory allocation\n"
# define QUOTE_ERROR "Error : Invalid quote\n"

//Quote handling

# define QUOTE 0
# define SINGLE_QUOTE 1
# define DOUBLE_QUOTE 2
# define INTERACTIVE 11
# define CHILD 12
# define HERE_DOC_SIG 13

enum e_builtin
{
	E_CD,
	E_UNSET,
	E_EXPORT,
	E_PWD,
	E_ECHO,
	E_ENV,
	E_EXIT
};

typedef struct	s_data
{
	char			**env;
	char			***cmd_array;
	char			*prompt;
	char			**array;
	char			*expended;
	int				len;
	int				nlen;

	// struct termios  term;
	int				state;
	// int				exit_code;
}	t_data ;

//init_minishell.c

void		ft_init_minishell(t_data *data, char **env);
void		ft_init_env(t_data *data, char **env);

//cean.c

void		ft_clean(t_data *data);
int			launch_fail(char **env);

//Built-in.c

void		ft_exit(t_data *data);
int			check_exit(char *prompt);
void		ft_env(t_data *data);
int			check_env(char *prompt);

//Built-in2.c

int			check_pwd(char *prompt);
void		ft_pwd(t_data *data);
int			check_cd(char *prompt);

//Built-in3.c

void		ft_export(t_data *data, char **cmd);
int			verify_double(t_data *data, char *cmd);
void		ft_unset(t_data *data, char *cmd);
void		ft_echo(char **cmd);

//Builtins4.c
char		*get_env_line(char *var, t_data *data);
void		ft_cd(t_data *data, char **cmdarray);
void		ft_cd_export(t_data *data, char **cmd, char *pwd);

//token.c

char		**ft_parse(t_data *data);
int			ft_count(char *str);
char		*ft_expend(t_data *data);
char		***ft_commandarray(t_data *data);

//quote.c

bool		valid_quote(char *str, int len, int quote);
bool		contain_cash(char *str);
char		*ft_dollar_switch(char *str, t_data *data);

//execution.c

char		*get_command_path(char *argv, char **envp);
void		get_command(char **argv, char **envp, int argval);

//exec utils.c

void		ft_execute(t_data *data);
void		parent(char **argv, char **envp, int *fd);
void		child(char **argv, char **envp, int *fd);

//utils.c
int			ft_isonlyspace(char *prompt);

//REMOVE BEFORE PUSH
void		print_cmd_array(char ***cmd_array);

//strtok.c
char		**ft_tok(char *src, char sep);

void		ft_cd_home(t_data *data, char **cmdarray, char *home);

//Signal.c
void		ft_signal_handler_parent(int mode);
extern void	rl_replace_line(const char *, int);

#endif
