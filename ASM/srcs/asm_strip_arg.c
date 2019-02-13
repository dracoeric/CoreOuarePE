/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_strip_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:21:00 by erli              #+#    #+#             */
/*   Updated: 2019/02/13 18:05:24 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** fill strip with the argument. argument are separated with SEPARATOR_CHAR
** and then cleaned (no whitespace before nor after.
** if there is a 4th arg, or a non whitespace characater != COMMENT_CHAR
** return an asm_error_msg.
** Also fills cols, which contains the number of col before each arg.
*/

static	int	asm_get_arg(t_asm_data *data, char *line, int *nb_arg, int i)
{
	while (line[data->col] != ' ' && line[data->col] != '\t'
		&& line[data->col] != ',' && line[data->col] != '\0'
		&& line[data->col] != '#')
		data->col++;
	if (line[data->col] == '\0' || line[data->col] == '#')
		return (0);
	*nb_arg += (line[data->col] == ',' ? 1 : 0);
	line[data->col++] = '\0';
	while ((line[data->col] == ' ' || line[data->col] == '\t')
		&& line[data->col] != '\0' && line[data->col] != '#')
		data->col++;
	if ((line[data->col] == '\0' || line[data->col] == '#')
		&& *nb_arg == i + 1)
		return (asm_error_msg(data, SYNTAX_ERROR));
	else if (*nb_arg == i)
		return (0);
	if ((line[data->col] == ',' && *nb_arg == i + 1) || (line[data->col] != '\0'
		&& line[data->col] != ',' && *nb_arg == i))
		return (asm_error_msg(data, SYNTAX_ERROR));
	while (line[data->col] == ' ' || line[data->col] == '\t')
		data->col++;
	return (1);
}

int			asm_strip_arg(t_asm_data *data, char *line, char **strip,
				int *cols)
{
	int	nb_arg;
	int i;
	int	ret;

	i = 0;
	nb_arg = 0;
	while (i < data->max_arg)
	{
		cols[i] = data->col;
		strip[i] = line + data->col;
		if ((ret = asm_get_arg(data, line, &nb_arg, 0)) < 0)
			return (-1);
		if (ret == 0)
			i = data->max_arg;
		i++;
	}
	return (1);
}
