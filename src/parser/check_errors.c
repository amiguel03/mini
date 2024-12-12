#include "../../inc/minishell.h"

int	ft_locate_next_quote(int i, char *input, char quote)
{
	while (input && input[i] && input[i] != quote)
		i++;
	return (i);
}

int	ft_nothing_r(char *input, int i)
{
	while (i >= 0 && input[i] && input[i] == ' ')
		i--;
	if (i == -1)
		return (1);
	return (0);
}

int	ft_nothing(char *input, int i)
{
	while (input[i] && input[i] == ' ')
		i++;
	if (input[i] == '\0')
		return (1);
	return (0);
}

int	valid_pipe(char *input, int i)
{
	bool	character;

	if (i - 1 == -1)
		return (-1);
	i--;
	while (input[i])
	{
		if (input[i] == '|' && character == false)
			return (-1);
		if (input[i] == '|' && character == true)
			return (0);
		if (input[i] != '|' && input[i] != ' ')
			character = true;
		i--;
	}
	return (0);
}

int	error_pipe(char *input)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '"' || input[i] == '\'')
		{
			i = ft_locate_next_quote(i + 1, input, input[i]);
			if (input[i] == '\0')
				return (-1);
		}
		if (input[i] == '|' && (ft_nothing_r(input, i - 1) == 1 || ft_nothing(input, i + 1) == 1))
			return (-1);
		if (input[i] == '|' && valid_pipe(input, i) == -1)
			return (-1);
		i++;
	}
	return (0);
}
