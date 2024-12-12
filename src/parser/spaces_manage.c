#include "../../inc/minishell.h"

void	split_space_join(char ***result, char *tmp)
{
	char **copy;
	char **str;

	str = ft_split(tmp, ' ');
	if (*result == NULL)
		*result = strstr_join(str, NULL);
	else
	{
		copy = strstr_join(*result, str);
		strstr_free(*result);
		*result = copy;
	}
	strstr_free(str);
}

void	quit_spaces(t_cmd **cmd)
{
	char	**result;
	char	**copy;
	char	**tmp;
	int		i;

	i = -1;
	result = NULL;
	tmp = strstr_dup((*cmd)-> args);
	while (tmp[++i])
	{
		if (has_quotes(tmp[i], 0) == 0 && ft_strchr(tmp[i], ' '))
			split_space_join(&result, tmp[i]);
		else
		{
			copy = sindub_join(result, tmp[i]);
			strstr_free(result);
			result = copy;
		}	
	}
	strstr_free(tmp);
	strstr_free((*cmd)->args);
	(*cmd)->args = result;
}
