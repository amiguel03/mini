#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <stdbool.h>
# include <limits.h>
# include <errno.h>
# include <signal.h>
# include "colors.h"
# include "struct.h"

int	headline(void);
int main();
int	ft_locate_next_quote(int i, char *input, char quote);
int	ft_nothing_r(char *input, int i);
int	ft_nothing(char *input, int i);
int valid_pipe(char *input, int i);
int	error_pipe(char *input);
int	strstr_len(char **str);
void	strstr_free(char **str);
char	**strstr_dup(char **str);
int	strnstrstr(char **str, char *locate);
char **strstr_join(char **str, char **str1);


#endif