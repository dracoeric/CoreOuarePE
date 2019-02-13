/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_assemble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:01:28 by erli              #+#    #+#             */
/*   Updated: 2019/02/13 11:06:19 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

void				asm_init_data(t_asm_data *data, int fd, int dest_fd)
{
	int i;

	data->fd = fd;
	data->dest_fd = dest_fd;
	data->cursor = 0;
	data->file_offset = 0;
	data->lab_curs = 0;
	data->hol_curs = 0;
	data->line = 0;
	data->col = 0;
	data->error_code = 0;
	i = 0;
	ft_bzero(data->buf, B_SIZE + 1);
	while (i < B_SIZE / 2)
	{
		data->labels[i].state = 0;
		data->holes[i].state = 0;
		i++;
	}
}

void				asm_assemble(int fd, int dest_fd)
{
	t_asm_data data[1];

	asm_init_data(data, fd, dest_fd);
	if (asm_get_header(data) < 0)
		return ;
//	asm_convert(data);      
}
