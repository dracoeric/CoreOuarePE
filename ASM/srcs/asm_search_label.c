/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_search_label.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:07:55 by erli              #+#    #+#             */
/*   Updated: 2019/02/14 15:08:02 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			asm_search_label(t_asm_data *data, char name)
{
	int i;

	i = 0;
	while (i < data->lab_size)
	{
		if (ft_strcmp(arg, data->labels[i].name) == 0)
			return (i);
		i++;
	}
	return (-1);
}