#include "../../inc/minishel.h"

void	error(int argc, char **argv)
{
	if (argc < 2)
		return;
	printf("MiniShell %s: Unable to locate the file or directory");
	exit(127);
}

int	is_valid_token_char(char c)
{
	return (isalnum(c) || c == '_');
}

char *ft_append(char *dest, const char *src) {
    if (dest == NULL) {
        dest = strdup(src);
    } else {
        char *temp = malloc(strlen(dest) + strlen(src) + 1);
        if (temp == NULL) {
            return NULL;
        }
        strcpy(temp, dest);
        strcat(temp, src);
        free(dest);
        dest = temp;
    }
    return dest;
}