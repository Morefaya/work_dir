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

char	*create_path(struct dirent *data, char *dir)
{
	char	*tmp;
	char	*ret;

	if (!(tmp = ft_strjoin(dir, "/")))
		return (NULL);
	ret = ft_strjoin(tmp, data->d_name);
	free(tmp);
	return (ret);
}

void	search(DIR *fd, char *buff, char *dir)
{
	struct dirent	*data;
	char			*tmp_1;
	char			*tmp_2;

	while ((data = readdir(fd)))
	{
		tmp_1 = NULL;
		tmp_2 = NULL;
		if (!(tmp_1 = create_path(data, dir))
			|| !(tmp_2 = ft_strjoin(buff, "*")))
		{
			free(tmp_1);
			free(tmp_2);
			return ;
		}
		ft_printf("%s, match: %d\n", data->d_name, match(tmp_1, tmp_2));
	}
}

char	*deal_path(char *str)
{
	int		i;

	i = 0;
	if (!str || !ft_strchr(str, '/'))
		return (NULL);
	while (str[i])
		i++;
	while (i >= 0 && str[i] != '/')
		i--;
	return (ft_strsub(str, 0, i));
}

int		main(int ac, char **av)
{
	char			*buff;
	char			*dir;
	int				i;
	DIR				*fd;

	if (ac != 2)
	{
		ft_printf("1 arg plz\n");
		return (1);
	}
	if (!(buff = ft_strtrim(av[1])) || !(i = ft_strlen(buff)) || i > PATH_MAX)
	{
		ft_printf("not good format\n");
		return (2);
	}
	if (!(dir = deal_path(buff)))
	{
		ft_printf("error\n");
		return (3);
	}
	if (!(fd = opendir(dir)))
	{
		ft_printf("%s, %s\n", strerror(errno), buff);
		return (2);	
	}
	search(fd, buff, dir);
	closedir(fd);
	return (0);
}
