/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_go_to_tag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:52:53 by erli              #+#    #+#             */
/*   Updated: 2019/02/13 11:53:52 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		asm_create_lab(t_asm_data *data, char *line, int i)
{
	data->lab_curs++;
	if (lab->curs >= B_SIZE / 2)
	{
		//malloc
	}
	if (!(data->labels[data->lab_curs].name = ft_strndup(line, data->col, i - 1)))
		return(ft_msg_int(2, "failed malloc label.name\n", -1));
	data->labels[data->lab_curs].size = i;
	data->labels[data->lab_curs].buff_position = data->cursor;
	data->labels[data->lab_curs].line = data->line;
	data->labels[data->lab_curs].col = data->col;
	data->labels[data->lab_curs].state = 1;
	return (1);
}

int		asm_go_to_tag(t_asm_data *data, char *line)
{
	char	*str_lab;
	int		i;

	if (data == 0 || line == 0)
		return ;
	while (line[data->col] != '\0' && line[data->col] == ' '
			&& line[data->col] == '\t')
		data->col++;
	str_lab = LABEL_CHARS;
	i = 0;
	while (ft_char_in_str(line[data->col + i], str_lab) == 1)
			i++;
	if (i > 0 && line[data->col + i] == ':')
	{
		asm_create_lab(data, line, i);
		data->col = data->col + i + 1;
		while (line[data->col] == ' ' || line[data->col] == '\t')
			data->col++;
	}
	else if (line[data->col] == ':')
		return (asm_error_msg(data, 2));
	if (line[data->col] == '\0')
		return (0);
	return (1);
	/* 
	** Amene data->col au premier character non ' ' ou '\t', gere le label si il y
	** en a un; Gere aussi les fin de lignes
	*/
}
