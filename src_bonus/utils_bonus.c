#include "pipex_bonus.h"

void    exit_error(void)
{
    perror("zsh");
	exit(1);
}

int     length_array(int **array)
{
	int count;

	count = 0;
	while (array[count])
		count++;
	return (count);
}

int     length_array_char(char **array)
{
	int count;

	count = 0;
	while (array[count])
		count++;
	return (count);
}

void	free_tab(int **array)
{
	int	i;

	i = length_array(array);
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
}
void	free_tab_char(char **array)
{
		int	i;

	i = length_array_char(array);
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
}