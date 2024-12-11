/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:52:47 by marvin            #+#    #+#             */
/*   Updated: 2024/11/29 19:52:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char*    ft_free(char *save, char *buff)
{
    free(save);
    free(buff);
    return(NULL);
}

static char *ft_save(char *save)
{
    char *new_save;
    int i;
    int j;

    i = 0;
    j = 0;
    while(save[i] && save[i] != '\n')
        i++;
    if(!save[i])
    {
        free(save);
        return(NULL);
    }
    i++;
    new_save = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
    if(!new_save)
        return(NULL);
    while(save[i] && save[i] != '\n')
        new_save[j++] = save[i++];
    new_save[j] = '\0';
    free(save);
    return(new_save);
}

char *ft_next_line(char *save)
{
    char *line;
    int i;
    int j;  //for save and line

    i = 0;
    j = 0;
    if(!save[i] || !save)
        return(NULL);
    while(save[i] && save[i] != '\n')
        i++;
    if(save[i] == '\n')
    line = malloc(sizeof(char) * (i + 2));
    if (save[i] == '\0')
    line = malloc(sizeof(char) * (i + 1));
    if(!line)
        return(NULL);
    i = 0;
    while(save[i] && save[i] != '\n')
        line[j++] = save[i++];
    if(save[i] == '\n')
        line[j++] = save[i];
    line[j] = '\0';
    return(line);
}

static char* readbuff(char *buff, char *save, int fd)
{
    ssize_t n;
    char *temp;
    while(!ft_strchr(save, '\n'))
    {
        n = read(fd, buff, BUFFER_SIZE);
        if(n == -1)
            return(ft_free(save, buff));
        else if(n == 0)
            break;
        buff[n] = '\0';
        temp = ft_strjoin(save, buff);
        if(!temp)
            return(ft_free(save, buff));
        free(save);
        save = temp;        
    }
    free(buff);
    return(save);
}

char *get_next_line(int fd)
{
    static char        *save;
    char                *line;
    char                *buff;

    if(fd < 0 || BUFFER_SIZE == 0) //-1 if fd has an error
        return (NULL);
    if(!save)
        save = ft_strdup("");
    buff = malloc(sizeof(char)* (BUFFER_SIZE + 1)); //for null terminator
    if(!buff)
        return(NULL);
    save =  readbuff(buff, save, fd);
    if(!save)
    {
        free(save);
        return(NULL);
    }
line = ft_next_line(save);
save = ft_save(save);
return(line);
}