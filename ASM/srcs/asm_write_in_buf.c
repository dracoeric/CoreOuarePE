/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_write_in_buf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:20:54 by erli              #+#    #+#             */
/*   Updated: 2019/02/14 17:37:15 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <stdlib.h>

/*
** write nb_byte of arg in data->buf and update data->cursor.
** if buf is too small, malloc, then realloc it, setting data->mallocked
** as needed.
** return -1 if malloc fails, 1 otherwise.
*/

int			asm_malloc_buff(t_asm_data *data)
{
	char	*new;

	if (data->buf_size + B_SIZE > 10000000 && (data->options & 1) == 0)
		return (ft_msg_int(1,
		"Warning, abort champ too big, rerun with -c to force\n", -1));
	if ((data->mallocked & 3) == 0)
	{
		if (!(new = (char *)malloc(sizeof(char) * (data->buf_size + B_SIZE))))
			return (ft_msg_int(2, "failed malloc buff.\n", -1));
		new = ft_strncpy(new, data->buf, data->cursor);
		data->mallocked = (data->mallocked | 3);
		data->buf_size = data->buf_size + B_SIZE;
		data->buf = new;
	}
	else
	{
		if (!(realloc(data->buf, sizeof(char) * (data->buf_size + B_SIZE))))
			return (ft_msg_int(2, "failed realloc buff.\n", -1));
		data->buf_size = data->buf_size + B_SIZE;
	}
	return (1);
}

int			asm_write_in_buf(t_asm_data *data, int arg, int nb_bytes)
{
	int				i;
	unsigned char	*str;

	i = 0;
	if (data == 0 || arg == -1 || nb_bytes == -1)
		return (-1);
	if (data->cursor + nb_bytes >= data->buf_size)
	{
		if (asm_malloc_buff(data) < 0)
			return (-1);
	}
	str = (unsigned char *)&arg;
	while (i < nb_bytes)
	{
		data->buf[data->cursor + nb_bytes - i] = str[i];
		i++;
	}
	data->cursor = data->cursor + nb_bytes;
	return (1);
} 
