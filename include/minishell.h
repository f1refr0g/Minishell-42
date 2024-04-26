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
# define PROMPT "Minishell-42$ "
# define HEREDOC "heredoc > "
# define EMPTY 0
# define CMD 1
# define ARGS 2
# define PIPE 3
# define REDIR_IN 4
# define REDIR_OUT 5
# define ABS 6
# define FILE_OUT 7
# define REDIR_DBL 9
# define REDIR_DBL2 10
# define HEREDOC_T 10
# define INTERACTIVE 11
# define CHILD 12
# define HERE_DOC_SIG 13

int			g_errno;

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

typedef struct s_token
{
	int					token_no;
	int					type;
	char				**cmd;
	char				*next_sep;
	pid_t				child_pid;
	pid_t				pid;
	int					p_fd[2];
	int					fd_in;
	int					fd_out;
	int					fd_hd;
	struct s_environ	*env;
	struct s_mini		*mini;
	struct s_token		*next;
}					t_token;

typedef struct s_mini
{
	char				*input;
	char				**cmds;
	char				**new_cmds;
	char				**env;
	char				no_wrds;
	char				*shlvl;
	int					env_len;
	int					nb_of_words;
	t_token				*heredoc_temp;
	struct s_environ	*env_test;
	struct s_export		*_export;
	struct s_token		*tokens;
	int					no_of_tokens;
}					t_mini;

typedef struct s_environ
{
	char				**temp;
	char				*env_var;
	char				*env_val;
	struct s_environ	*next;
}					t_environ;

typedef struct s_export
{
	char				**temp;
	char				*env_var;
	char				*env_val;
	struct s_export		next;
}					t_export;

typedef struct s_data
{
	char				**env;
	char				***cmd_array;
	char				*prompt;
	char				**array;
	char				*expended;
	int					len;
	int					nlen;
	int					state;
}					t_data;

//absolute.c
char			**build_cmd(t_token *token);
void			exec_abs_path(char *path, t_token *token);
void			abs_error(t_token *token);
void			absolute_path(t_token *token);

//init_minishell.c
void			ft_init_minishell(t_data *data, char **env);
void			ft_init_env(t_data *data, char **env);
void			ft_set_env(t_mini *mini, char **env);
t_environ		*init_item(char *to_split);

//set_shlvl
int				set_shlvl(void);

//env2.c

int				update_env_part3(t_mini *mini, char *part, char *_new);
char			*get_env_part(t_mini *mini, char *part);

//clean.c
void			ft_clean(t_data *data);
int				launch_fail(char **env);

//Built-in.c
void			ft_exit(t_data *data);
int				check_exit(char *prompt);
void			ft_env(t_data *data);
int				check_env(char *prompt);

//Built-in2.c
int				check_pwd(char *prompt);
void			ft_pwd(t_data *data);
int				check_cd(char *prompt);

//Built-in3.c

void			ft_export(t_data *data, char **cmd);
void			ft_echo2(int i, int n_option, t_token *token);
int				ft_unset(t_token *token);
int				ft_echo(t_token *token);
void			ft_unset2(t_mini *mini);

//Builtins4.c
char			*get_env_line(char *var, t_data *data);
void			ft_cd(t_data *data, char **cmdarray);
void			ft_cd_export(t_data *data, char **cmd, char *pwd);

//token.c

int				ft_parse(t_mini	*mini);
int				ft_count(char *str);
char			*ft_expend(t_data *data);
char			***ft_commandarray(t_data *data);

//quote.c

bool			valid_quote(char *str, int len, int quote);
bool			contain_cash(char *str);
char			*ft_dollar_switch(char *str, t_data *data);

//execution.c

char			*get_command_path(char *argv, char **envp);
void			get_command(char **argv, char **envp, int argval);

//exec utils.c
void			ft_execute(t_data *data);
void			parent(char **argv, char **envp, int *fd);
void			child(char **argv, char **envp, int *fd);

//mini_split.c
int				nb_of_words(char *s, int trigger, int i, int nb_wrds);
int				mini_len(char *s, int start, int trigger, int len);
int				word_len(char *s, int start);
char			**no_name(char *s, int wrd_nb, int nb_wrds, char **split);
char			**small_split(char *s);

//utils.c
int				ft_isonlyspace(int c);
t_mini			*get_data(void);
void			*ft_other_free(void *p);
int				is_empty(char *prompt);

//utils2.c
int				check_valid_quotes(char *input);

//strtok.c
char			**ft_tok(char *src, char sep);

void			ft_cd_home(t_data *data, char **cmdarray, char *home);

//prompt.c
char			*get_prompt(char *ptr);

//Signal.c
void			ft_signal_handler_parent(int mode);
extern void		rl_replace_line(const char *, int);

//Parsing.c
char			**parse_mini_cmds(void);
void			set_mini_no_wrds(void);

#endif
