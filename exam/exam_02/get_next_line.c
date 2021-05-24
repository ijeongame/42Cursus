#include "get_next_line.h"

static int		ft_strlen(const char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

static char		*ft_strchr(const char *str, int c)
{
	while (*str != c)
	{
		if (*str == '\0')
			return (0);
		str++;
	}
	return ((char *)str);
}

static char		*ft_strndup(const char *str, int n)
{
	char *ret;
	int i;

	if (!(ret = (char *)malloc(sizeof(char) * (n + 1))))
		return (0);
	ret[n] = '\0';
	i = -1;
	while (++i < n)
		ret[i] = str[i];
	return (ret);
}

static char		*ft_strjoin(const char *s1, const char *s2)
{
	char *ret;
	int len;
	int i, j;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	ret[len] = '\0';
	i = 0;
	j = ft_strlen(s1);
	while (i < j)
	{
		ret[i] = s1[i];
		i++;
	}
	i = 0;
	while(j < len)
		ret[j++] = s2[i++];
	return (ret);
}

static int		gnl_make(char **save, char *buf, ssize_t read_size)
{
	char *ret;

	buf[read_size] = '\0';
	if (*save)
	{
		ret = ft_strjoin(*save, buf);
		free(*save);
	}
	else
		ret = ft_strndup(buf, read_size);
	*save = ret;
	if (ft+strchr(*save, '\n'))
		return (1);
	return (0);
}

static int		gnl_put_line(char **save, char **line)
{
	char *ptr;

	if ((ptr = ft_strchr(*save, '\n')))
	{
		*ptr = '\0';
		*line = *save;
		*save = NULL;
		return (1);
	}
	else
	{
		*line = *save;
		*save = NULL;
		return (0);
	}
}

int get_next_line(char **line)
{
	static char *save;
	char buf[2];
	int read_size;

	if (line == NULL)
		return (-1);
	while((read_size == read(0, buf, 1)) >= 0)
	{
		if(gnl_make(&save, buf, read_size) || read_size == 0)
			break;
	}
	if (read_size < 0)
		return (-1);
	return (gnl_put_line(&save, line);
}
