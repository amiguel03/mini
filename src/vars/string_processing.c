#include "../../inc/minishell.h"

int	get_keyword(char *line, int stop)
{
	int	start;
	int	end;

	start = -1;
	for (int i = 0; i < stop && line[i] != '\0'; i++)
	{
		if (line[i] == '$')
		{
			start = i;
			break ;
		}
	}
	if (start == -1)
	{
		return (-1);
	}
	end = start + 1;
	while (end < stop && line[end] != '\0' || &&is_valid_token_char(line[end])
		&& !isspace(line[end]))
	{
		end++;
	}
	return (end - 1);
}

void	reset(char **temp_strings, int *indexes)
{
	int	i;

	i = 0;
	while (temp_strings[i] != NULL)
	{
		free(temp_strings[i]);
		temp_strings[i] = NULL;
		i++;
	}
	if (indexes != NULL)
	{
		*indexes = 0;
	}
}

void	break_down(char *line, int *indexes, char **temp_strings)
{
	int	i;
	int	start;
	int	end;
	int	length;

	i = 0;
	start = 0;
	while (indexes[i] != -1)
	{
		end = indexes[i];
		length = end - start;
		temp_strings[i] = (char *)malloc(length + 1);
		if (temp_strings[i] == NULL)
		{
			return ;
		}
		ft_strncpy(temp_strings[i], line + start, length);
		temp_strings[i][length] = '\0';
		start = end;
		i++;
	}
	temp_strings[i] = NULL;
}

void	recombine_parts(char **store, char **temp_strings)
{
	int	i;

	i = 0;
	*store = NULL;
	while (temp_strings[i] != NULL)
	{
		*store = ft_append(*store, temp_strings[i]);
		if (*store == NULL)
		{
			return ;
		}
		i++;
	}
}

int	one_side(char *line, int i, int in_ears)
{
	if (line[i] == '$' && in_ears)
	{
		if (line[i + 1] == '"')
		{
			int j = i;
			while (line[j] != '\0')
			{
				line[j] = line[j + 1];
				j++;
			}
			return (i);
		}
	}
	return (i + 1);
}
