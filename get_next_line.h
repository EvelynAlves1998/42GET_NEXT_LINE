#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define OPEN_MAX 1024
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*get_line(char **save);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);

#endif