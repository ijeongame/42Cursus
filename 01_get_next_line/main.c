/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 22:19:32 by hkwon             #+#    #+#             */
/*   Updated: 2021/01/15 22:13:23 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    char    *line;
    int     fd = open("file.txt", O_RDONLY);
    int     n;
    while ((n = get_next_line(fd, &line)) > 0)
    {
        printf("line : %s\n", line);
        printf("n : %d\n", n);
        free(line);
    }
    printf("line : %s\n", line);
    printf("n : %d\n", n);
    free(line);
}