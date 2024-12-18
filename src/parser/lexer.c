#include "../../inc/minishell.h"

static void	free_per_comm(t_mini *mini, char *input)
{
	if (mini->input)
	{
		free(mini->input);
		mini->input = NULL;
	}
	if (mini->flags->redirect && input != NULL)
	{
		mini->flags->locate_red = 0;
		free(mini->flags->redirects);
		mini->flags->redirects = NULL;
	}
	if (mini->proc && mini->error != -2 && ft_nothing(input, 0) != 1)
		free(mini->proc);
	if (input)
		free(input);
	if (mini->files)
	{
		strstr_free(mini->files);
		mini->files = NULL;
	}
	mini->here_doc_index = 0;
	mini->files = NULL;
}

unlink_hd(t_mini *mini)
{
	int dup_fd;
	int fd;
	int i;

	i = 0;
	fd = 2;
	while(++fd < 1024)
	{
		dup_fd = -1;
		if (fd != mini->fd_history)
			dup_fd = dup(fd);
		if(dup_fd != -1)
		{
			close(fd);
			close(dup_fd);
		}
	}
	if (mini->files)
	{
		while(mini->files[i])
			unlink(mini->files[i++]);
	}
}

static char *ft_tty(void)
{
	char *input;
	char *input2;

	input2 = get_next_line(STDIN_FILENO);
	input = ft_strtrim(input2, "\n");
	if(input2)
		free(input2);
	return(input);
}

void	recive_input(t_mini *mini)
{
	char	*input;

	mini->fd_history = history();
	while(1)
	{
		if (mini->tty == 0)
			input = readline(B_PR_0"MINISHELL"RESET"->");
		else if (mini->tty >= 1 && mini->tty++ >= 1)
			input = ft_tty();
		if (handle_input(mini, input) == 0)
			break;
		else if (handle_input(mini, input) == 2)
		{
			mini->input = ft_strdup(input);
			add_history(input);
			if(mini->fd_history != -1)
				if(write(mini->fd_history, input, ft_strlen(input)) == -1
					|| write(mini->fd_history, "\n", 1) == -1)
					return;
			strtok(mini, &(mini->cmd), input);
			unlink_hd(mini);
		}
		free_per_comm(mini, input);
		free_t_cmd(&(mini->cmd));
	}
}
