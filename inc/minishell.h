#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "colors.h"
# include "struct.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>
#include <ctype.h>

// headline.c
int			headline(void);

// main.c
int			main(void);

// check_errors.c
int			ft_locate_next_quote(int i, char *input, char quote);
int			ft_nothing_r(char *input, int i);
int			ft_nothing(char *input, int i);
int			valid_pipe(char *input, int i);
int			error_pipe(char *input);

// quotes_check.c
int			pairs_check(char *input, int *i, char quote);
int			quotes_check(char *input, int simp, int doub, t_mini *mini);

// spaces_manage.c
void		split_space_join(char ***result, char *tmp);
void		quit_spaces(t_cmd **cmd);

// split_pipes.c
void		ft_plus_one(int value1, int value2);
int			strlen_pipe(const char *s, int i, char c);
char		*strlcpy_pipe(char *s, char c, int *new_start, int size);
void		*free_pipe_memory(int a, char **arr);
char		**ft_split_pipe(const char *s, char c);

// error.c
void		error(int argc, char **argv);

// free.c
static void	free_sim(void *ptr, char *str, char *str1);
static void	free_dou(void *ptr, char **str, char **str1);
void		free_t_cmd(t_cmd **cmd);
void		free_t_mini(t_mini *mini);

// utils_str.c
int			strstr_len(char **str);
void		strstr_free(char **str);
char		**strstr_dup(char **str);
int			strnstrstr(char **str, char *locate);
char		**strstr_join(char **str, char **str1);

#endif