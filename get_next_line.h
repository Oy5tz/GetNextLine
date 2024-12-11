#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 444
#endif
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


char *get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char *ft_strjoin(const char *s, const char *);
size_t ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char *ft_next_line(char *save);


#endif