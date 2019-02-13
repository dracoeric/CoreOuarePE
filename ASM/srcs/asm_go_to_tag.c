/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_go_to_tag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:52:53 by erli              #+#    #+#             */
/*   Updated: 2019/02/13 15:01:06 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	asm_labels_cpy(t_asm_data *data, t_labels *new)
{
	int i;

	i = 0;
	while (i < data->lab_curs)
	{
		new[i].name = data->labels[i].name;
		new[i].size = data->labels[i].size;
		new[i].buff_position = data->labels[i].buff_position;
		new[i].line = data->labels[i].line;
		new[i].col = data->labels[i].col;
		new[i].state = data->labels[i].state;
		i++;
	}
}

int		asm_malloc_labels(t_asm_data *data)
{
	t_label	*new;

	new = NULL;
	if ((data->lab_size + B_SIZE / 2) > 1000000)
		return (ft_msg_int(2, "fail, lab_size too big.\n", -1));
	if (data->mallocked & 1)
	{
		if (!((t_label *)realloc(data->labels,
				sizeof(t_label) * (data->lab_size + B_SIZE / 2))))
			return (ft_msg_int(2, "failed realloc labels.\n", -1));
		data->lab_size = data->lab_size + B_SIZE / 2;
	}
	else
	{
		if (!(new = (t_label *)malloc(sizeof(t_label) * B_SIZE)))
			return (ft_msg_int(2, "failed malloc labels.\n", -1));
		data->mallocked = (data->mallocked | 1);
		data->lab_size = B_SIZE;
		asm_labels_cpy(data, new);
	}
	return (1);
}

int		asm_create_lab(t_asm_data *data, char *line, int i)
{
	data->lab_curs++;
	if (lab->curs >= data->lab_size)
	{
		if (asm_malloc_labels(data) < 0)
			return (-1);
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
		if (asm_create_lab(data, line, i) < 0)
			return (-1);
		data->col = data->col + i + 1;
		while (line[data->col] == ' ' || line[data->col] == '\t')
			data->col++;
	}
	else if (line[data->col] == ':')
		return (asm_error_msg(data, 2));
	if (line[data->col] == '\0')
		return (0);
	return (1);
}
