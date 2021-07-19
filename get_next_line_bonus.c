#include "get_next_line_bonus.h"

static	char	*ft_newsubstr(char *s, unsigned int start, size_t len, int f)
{
	unsigned int	i;
	unsigned int	end;
	char			*p;

	p = (char *)malloc(sizeof(char) * len + 1);
	if (!p)
		return (NULL);
	if (start >= ft_strlen(s))
		ft_bzero(p, len + 1);
	else
	{
		i = 0;
		end = start + len - 1;
		while (start <= end && len > 0)
		{
			p[i] = s[start];
			i++;
			start++;
		}
		p[i] = '\0';
		if (f == 1 && *s)
			free(s);
	}
	return (p);
}

char	*get_line(char **save)
{
	size_t	i;
	char	*line;
	char	*tmp_save;

	tmp_save = *save;
	if (!tmp_save)
		return (NULL);
	i = 0;
	while (tmp_save[i] && tmp_save[i] != '\n')
		i++;
	line = ft_newsubstr(*save, 0, ++i, 0);
	if (i + 1 > ft_strlen(*save))
	{
		free(*save);
		*save = NULL;
	}
	else
		*save = ft_newsubstr(*save, i, ft_strlen(*save) - i, 1);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*buf;
	int			rd;

	rd = 1;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!(ft_strchr(save[fd], '\n')) && rd != 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[rd] = '\0';
		if (rd != 0)
			save[fd] = ft_strjoin(save[fd], buf);
	}
	free(buf);
	return (get_line(&save[fd]));
}
