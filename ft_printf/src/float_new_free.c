/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_new_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 16:51:09 by emaveric          #+#    #+#             */
/*   Updated: 2020/07/30 11:54:23 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		free_t_float(t_float *fl)
{
	if (fl->first)
		fl->first = 0;
	if (fl->second)
		fl->second = 0;
	if (fl->flag)
		fl->flag = 0;
	if (fl->i)
		fl->i = 0;
	if (fl->frst)
		free(fl->frst);
	fl->frst = NULL;
	if (fl->scnd)
		free(fl->scnd);
	fl->scnd = NULL;
	if (fl->tmp)
		free(fl->tmp);
	fl->tmp = NULL;
	if (fl->res)
		free(fl->res);
	fl->res = NULL;
	if (fl->not_f)
		fl->not_f = 0;
	free(fl);
}

t_float		*init_t_float(void)
{
	t_float *fl;

	if (!(fl = (t_float*)malloc(sizeof(t_float))))
		return (NULL);
	fl->first = 0;
	fl->second = 0;
	fl->scnd = NULL;
	fl->frst = NULL;
	fl->i = 0;
	fl->pos = 0;
	fl->tmp = NULL;
	fl->res = NULL;
	fl->not_f = 2;
	fl->flag = 0;
	return (fl);
}

char		*init_memory_for_decimal(t_pf *pf, t_float *fl)
{
	if (pf->precision > 0)
	{
		if (!(fl->scnd = ft_memalloc(pf->precision + 1)))
			return (NULL);
	}
	else if (pf->precision == 0)
	{
		if (!(fl->scnd = ft_memalloc(pf->precision + 2)))
			return (NULL);
	}
	return (fl->scnd);
}
