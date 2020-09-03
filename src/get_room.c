/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 21:21:10 by emaveric          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/07/27 16:23:50 by emaveric         ###   ########.fr       */
=======
/*   Updated: 2020/08/10 18:01:01 by emaveric         ###   ########.fr       */
>>>>>>> lexa
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		get_end_or_start_room(t_lem_in *l_i, char **str, int i)
{
	int		j;

	if (ft_strcmp(l_i->line[i - 1], "##start") == 0)
		j = 0;
	else
		j = l_i->room_num - 1;
<<<<<<< HEAD
	if (!(l_i->rooms[j]->name = ft_memalloc(ft_strlen(str[0]) + 1)))//(char*)malloc(sizeof(char) * ft_strlen(str[0]))))
=======
	if (!(l_i->rooms[j]->name = ft_memalloc(ft_strlen(str[0]) + 1)))
>>>>>>> lexa
		return (ERROR);
	ft_strcpy(l_i->rooms[j]->name, str[0]);
	if (l_i->rooms[j]->name[0] == 'L' || l_i->rooms[j]->name[0] == '#')
		return (ERROR);
	if (coord_valid(l_i, str, j) == ERROR)
		return (ERROR);
	l_i->rooms[j]->num = j;
<<<<<<< HEAD
=======
	return (0);
}

int		get_out_room(t_lem_in *l_i, char **str)
{
	if (!(l_i->rooms[l_i->i]->name = ft_strjoin(str[0], "'")))
		return (error(-1, str));
	if (l_i->rooms[l_i->i]->name[0] == 'L' ||
		l_i->rooms[l_i->i]->name[0] == '#')
		return (error(7, str));
	if (coord_valid(l_i, str, l_i->i) == ERROR)
		return (error(8, str));
	l_i->rooms[l_i->i]->num = l_i->i;
	l_i->rooms[l_i->i]->d_flag = l_i->i - 1;
	l_i->link_arr[l_i->i][l_i->i - 1] = 4;
	l_i->link_arr[l_i->i - 1][l_i->i] = 3;
	l_i->i++;
>>>>>>> lexa
	return (0);
}

int		get_room(t_lem_in *l_i, char *line, int i, int j)
{
<<<<<<< HEAD
	char 	**str;

	//printf("%s\n", line);
	if (ft_check_space(line) == ERROR)
		return (ERROR);
=======
	char	**str;

	if (ft_check_space(line) == ERROR)
		return (error(7, NULL));
>>>>>>> lexa
	str = ft_strsplit(line, ' ');
	while (str[j])
		j++;
	if (j != 3)
<<<<<<< HEAD
	{
		printf ("j = %d\n", j);
		return (ERROR);
	}
	j = start_end_room_check(l_i, i - 1, str);
	if (j == ERROR)
=======
		return (error(7, str));
	if ((j = start_end_room_check(l_i, i - 1, str)) == ERROR)
>>>>>>> lexa
		return (ERROR);
	else if (j == 0)
		return (0);
	if (!(l_i->rooms[l_i->i]->name = ft_memalloc(ft_strlen(str[0]) + 1)))
<<<<<<< HEAD
		return (ERROR);
=======
		return (error(-1, str));
>>>>>>> lexa
	ft_strcpy(l_i->rooms[l_i->i]->name, str[0]);
	if (coord_valid(l_i, str, l_i->i) == ERROR)
		return (error(8, str));
	l_i->rooms[l_i->i]->num = l_i->i;
	l_i->i++;
	l_i->rooms[l_i->i - 1]->d_flag = l_i->i;
	if (get_out_room(l_i, str) == ERROR)
		return (ERROR);
	str_free(str, 0);
	return (0);
}
