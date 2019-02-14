/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_assemble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:01:28 by erli              #+#    #+#             */
/*   Updated: 2019/02/14 19:45:41 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static	void		asm_init_labels(t_asm_data *data)
{
	int i;

	i = 0;
	while (i < B_SIZE / 2)
	{
		data->labels[i].state = 0;
		data->holes[i].state = 0;
		i++;
	}
}

static	int			asm_init_data(t_asm_data *data, int fd, char options)
{
	data->fd = fd;
	data->dest_fd = -1;
	data->max_arg = asm_max_arg();
	if (data->max_arg > 3)
		return (0);
	data->cursor = 0;
	data->instruction_cursor = 0;
	data->lab_curs = 0;
	data->hol_curs = 0;
	data->line = 0;
	data->col = 0;
	data->mallocked = 0;
	data->lab_size = B_SIZE / 2;
	data->holes_size = B_SIZE / 2;
	data->buf_size = B_SIZE + 1;
	data->options = options;
	ft_bzero(data->buf, B_SIZE + 1);
	asm_init_labels(data);
	return (0);
}

void				asm_finish(t_asm_data *data, t_header *header, char *file)
{
	if (asm_fill_holes(data) < 0)
	{
		asm_free_data(data);
		return ;
	}
	if ((data->dest_fd = asm_dest_path(file, ft_strlen(file))) < 0)
	{
		asm_free_data(data);
		return ;
	}
	asm_write_header(data, header);
	write(data->dest_fd, data->buf, data->cursor);
	close(data->dest_fd);
	asm_free_data(data);
}

void				asm_assemble(int fd, char *file, char options)
{
	t_asm_data	data[1];
	t_header	header[1];
	char		buf[B_SIZE + 1];
	t_label		labels[B_SIZE / 2];
	t_label		holes[B_SIZE / 2];

	data->buf = buf;
	data->labels = labels;
	data->holes = holes;
	header->magic = COREWAR_EXEC_MAGIC;
	if (asm_init_data(data, fd, options) < 0)
		exit(ft_msg_int(2, "Max number of arg over 100\n", 0));
	if (asm_get_header(data, header) < 0)
		return ;
	if (asm_convert(data) < 0)
	{
		asm_free_data(data);
		return ;
	}
	header->prog_size = data->cursor;
	if (data->cursor > CHAMP_MAX_SIZE)
		ft_putstr("Warning : Champion size exceed maximum size authorized.\n");
	asm_finish(data, header, file);
}
