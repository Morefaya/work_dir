#include "test.h"

int		match(char *s1, char *s2)
{
	if (!ft_strcmp(s2, "*") || !ft_strcmp(s1, s2))
		return (1);
	else if (!ft_strlen(s1))
		return (0);
	if (*s1 == *s2)
		return (match(s1 + 1, s2 + 1));
	else if (*s2 == '*')
		return (match(s1 + 1, s2) || match(s1, s2 + 1));
	return (0);
}

/*int		main(int ac, char **av)
{
	char	*s1;
	char	*s2;
	if (ac != 3)
		return (1);
	s1 = av[1];
	s2 = av[2];
	ft_printf("match: %d\n", match(s1, s2));
	return (0);
}*/



int		main(int ac, char **av)
{
	char			buff[PATH_MAX];
	int				i;
	DIR				*fd;
	struct dirent	*data;
	char			*tmp;

	if (ac != 2)
	{
		ft_printf("1 arg plz\n");
		return (1);
	}
	if ()
	i = 0;
	ft_bzero(buff, PATH_MAX);
	if (!(getcwd(buff, PATH_MAX)))
	{
		ft_putendl(strerror(errno));
		return (1);
	}
	if (!(fd = opendir(buff)))
	{
		ft_putendl(strerror(errno));
		return (2);	
	}
	while ((data = readdir(fd)))
	{
		if (!(tmp = ft_strjoin(buff, data->d_name)))
			return (3);
		ft_printf("%s, %d\n", data->d_name, match(tmp, "*.c"));
		free(tmp);
	}
	closedir(fd);
	return (0);
}
