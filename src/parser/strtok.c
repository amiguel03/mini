#include "../../inc/minishell.h"

int strtok(t_mini *mini, t_cmd **cmd, char *input)
{
	char **lines;

	mini->error = 0;
	lines = check_input(mini, input);
	if (error_rqp(mini, input) == 1)
		return (-1);
	if (order_all(mini, cmd, lines, input) == -1)
		return (-1);
	if (do_comm(*cmd, mini) == -1)
		return (-1);
	return (0);
}
