/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 09:40:26 by erli              #+#    #+#             */
/*   Updated: 2019/02/13 16:35:27 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <stdlib.h>

void				asm_convert(t_asm_data *data)
{
	char	*line;
	int		ret;
	char	opcode;

	if (data == 0)
		return ;
	ft_putstr("asm_convert to do\n");
	line = NULL;
	while ((ret = get_next_line(data->fd, &line)) > 0)
	{
		data->line++;
		data->col = 0;
		if (asm_go_to_tag(data, line) < 0)
			return ;
		if ((opcode = asm_match_tag(data, line)) < 0)
			return ;
		if (asm_manage_arg(data, opcode, line) < 0)
			return ;
		free(line);
	}
	if (ret < 0)
	{
		ft_putstr_fd("Failed GNL\n", 2);
		return ;
	}
	if (ret == 0 && data->cursor == 0)
		ft_putstr_fd("Error, missing instructions\n", 2);
	/* 
	** parcour le fichier .s ligne par ligne en decodant les instructions,
	** en stockant les label et les trous, et en remplissant les trou.
	** retourne le bon message d'erreur si erreur.
	*/
}
