#include "../../inc/minishell.h"

char	*get_env_value(const char *var_name, t_data *data)
{
	int		i;
	char	*entry;
	char	*delimiter;
	size_t	key_len;

	i = 0;
	while (data->env[i] != NULL)
	{
		entry = data->env[i];
		delimiter = strchr(entry, '=');
		if (delimiter != NULL)
		{
			key_len = delimiter - entry;
			if (strncmp(entry, var_name, key_len) == 0
				&& var_name[key_len] == '\0')
			{
				return (delimiter + 1);
			}
		}
		i++;
	}
	return ("");
}

void	replace_variable(char **temp_strings, t_data *data)
{
	int		i;
	char	*var_name;
	char	*replacement;

	i = 0;
	while (temp_strings[i] != NULL)
	{
		if (temp_strings[i][0] == '$')
		{
			var_name = temp_strings[i] + 1;
			replacement = get_env_value(var_name, data);
			free(temp_strings[i]);
			temp_strings[i] = strdup(replacement);
		}
		i++;
	}
}

void	process_line(char *line, t_data *data, char **temp_strings,
		int *indexes)
{
	reset(temp_strings, indexes);
	break_down(line, indexes, temp_strings);
	replace_variable(temp_strings, data);
}

void	replace_dollar(t_data *data)
{
	int		i;
	char	*temp_store;
	char	**temp_strings;
	int		*indexes;

	i = 0;
	temp_store = NULL;
	temp_strings = malloc(sizeof(char *) * 1024);
	indexes = malloc(sizeof(int) * 1024);
	while (data->commands[i] != NULL)
	{
		prepare_indexes(data->commands[i], indexes);
		process_line(data->commands[i], data, temp_strings, indexes);
		reset(&temp_store, NULL);
		recombine_parts(&temp_store, temp_strings);
		free(data->commands[i]);
		data->commands[i] = temp_store;
		i++;
	}
	free(temp_strings);
	free(indexes);
}

void	prepare_indexes(char *line, int *indexes)
{
	int	j = 0, idx;
	int	stop;

	j = 0, idx = 0;
	while (line[j] != '\0')
	{
		if (line[j] == '$')
		{
			stop = get_keyword(line, strlen(line));
			if (stop != -1)
			{
				indexes[idx++] = j;
				indexes[idx++] = stop + 1;
			}
		}
		j++;
	}
	indexes[idx] = -1;
}
