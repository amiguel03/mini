#include "../../inc/minishell.h"

int	locate_next_quote(int i, char *input, char quote)
{
	while (input && input[i] && input[i] != quote)
		i++;
	return (i);
}

int	pairs_check(char *input, int *i, char quote)
{
	int count;

	count = 1;
	while (input[*i + 1] && input[*i + 1] != quote)
		(*i)++;
	if (input[*i + 1] == quote)
		count++;
	(*i)++;
	return (count);
}

int	quotes_check(char *input, int simp, int doub, t_mini *mini)
{
	int	i;
	int	tmp;

	i = -1;
	while (input[++i])
	{
		tmp = i;
		if (input[i] == 39)
			simp += pairs_check(input, &i, input[i]);
		if (input[i] == 34)
			doub += pairs_check(input, &i, input[i]);
		if (simp % 2 == 1 || doub % 2 == 1)
		{
			mini->flags->quote = 1;
			mini->error = -2;
			return ((tmp + 1) * -1);
		}
		if (input[i] == '\0')
			break ;
	}
	return (1);
}
