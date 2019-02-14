/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_write_header.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 12:43:58 by erli              #+#    #+#             */
/*   Updated: 2019/02/13 19:46:49 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <unistd.h>

/*
** ecrit le contenut de header dans le fichier pointe par data->dest_fd
*/

void			asm_write_header(t_asm_data *data, t_header *header)
{
	unsigned char	*ptr;

	if (data == 0 || header == 0)
		return ;
	ptr = (unsigned char *)header;
	write(data->dest_fd, ptr, HEADER_SIZE);
}
