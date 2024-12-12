#include "../../inc/minishell.h"

void	ft_plus_one(int value1, int value2)
{
	value1 += 1;
	value2 += 1;
}

int	strlen_pipe(const char *s, int i, char c)
{
	int len;
	int j;

	len = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0' && s[i] != c)
	{
		j = 1;
		if (s[i] == '\'' || s[i] == '\"')
		{
			i = ft_locate_next_quote(i + 1, (char *)s, s[i]) + 1;
			if (j != i)
				len += i - j;
		}
		else
			ft_plus_one(i++, len++);
	}
	return (len);
}

char *strlcpy_pipe(char *s, char c, int *new_start, int size)
{
	char	*ptr;
	int		i;
	int		start;

	i = 0;
	start = *new_start;
	ptr = (char *)ft_calloc((size_t)size + 1, sizeof(char));
	if (ptr == NULL)
		return(NULL);
	while(s[start] == c && s[start] != '\0')
		start++;
	while(s[start] != '\0' && j < size)
		ptr[j++] = s[start++];
	*new_start = start;
	return(ptr);
}

void  *free_pipe_memory(int a, char **arr)
{
	int	f;

	f = 0;
	while(f < a)
		free(arr[f++]);z
	free(arr);
	return(NULL);
}

char	**ft_split_pipe(const char *s, char c)
{
	int		i;
	int		a;
	int		len_mod;
	char	**arr;
	char	*cpy_mod;

	i = 0;
	a = 0;
	len_mod = 0;
	arr = (char **)ft_calloc((size_t)(error_pipe((char *)s,
					0, 0, 0) + 2), sizeof(char *));
	if (arr == NULL)
		return (NULL);
	while (a < (error_pipe((char *)s, 0, 0, 0) + 1))
	{
		len_mod = strlen_pipe(s, i, c);
		cpy_mod = strlcpy_pipe((char *)s, c, &i, len_mod);
		if (cpy_mod == NULL)
			return (free_memory_pipe(a, arr));
		arr[a++] = cpy_mod;
	}
	return (arr);
}