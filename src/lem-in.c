/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 20:07:30 by emaveric          #+#    #+#             */
/*   Updated: 2020/07/30 14:09:52 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

int		map_reading(int fd, t_lem_in *l_i)
{
	char *buff;
//    char 	buff[B_SIZE + 1];
    int 	data;

    buff = (char*)malloc(B_SIZE);
    if ((data = read(fd, buff, B_SIZE)) < 32)
	{
//    	printf("\n%s\n%d\n", buff, data);
    	return (ERROR); // минимально возможное кол-во символов на валидной карте - 32
	}
    buff[data] = '\0';
    if (empty_line_check(buff) == ERROR)
	{
    	printf("\nempty line\n");
    	return (ERROR);
	}
    l_i->line = ft_strsplit(buff, '\n');
    if (room_num_check(l_i) == ERROR)
	{
    	printf("error in map reading\n");
    	return (ERROR);
	}
    if (get_map(l_i, 0) == ERROR)
    	return (ERROR);
//    printf("\nOK\n");
    free(buff);
    return (0);
}

int		main(int ac, char **av)
{
	t_lem_in	*l_i;
	char 		tmp;
	char *str;

	if (!(l_i = init_l_i()))
		return (0);
	if (ac == 1 && av[1] == NULL)
	{
		if (read(0, &tmp, 0) == 0)
		{
			if (map_reading(0, l_i) == ERROR)
				return (ERROR);
		}
		else
			return (ERROR);
	}
	else
		return (ERROR);
	start_algo(l_i);
	//sleep(500);
	exit(0);
}
