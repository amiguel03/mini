#include "../../inc/minishell.h"

char	*get_val(t_list *node)
{
	int	i;

	i = 0;
	if (node == NULL || node->content == NULL)
	{
		return ("");
	}
	while (node->content[i] != '\0' && node->content[i] != '=')
	{
		i++;
	} 
	if (node->content[i] == '\0')
	{
		return ("");
	}
	return (node->content + i + 1);
}

t_list	*find_var(t_list *vars, char *to_find)
{
	int	i;

	i = 0;
	while (vars != NULL)
	{
		while (vars->content[i] != '\0' && vars->content[i] != '=')
		{
			i++;
		}
		if (vars->content[i] == '=')
		{
			if (strncmp(vars->content, to_find, i) == 0 && to_find[i] == '\0')
			{
				return (vars);
			}
		}
		vars = vars->next;
	}
	return (NULL);
}

char	*access_var(t_data *data, char *name)
{
	t_list	*node;

	static char exit_value_str[12];
	if (name == NULL)
	{
		return ("");
	}
	if (name[0] == '?')
	{
		printf("%d", data->exit_value);
		return (exit_value_str);
	}
	node = find_var(data->env_vars, name);
	if (node == NULL)
	{
		return ("");
	}
	return (get_val(node));
}
