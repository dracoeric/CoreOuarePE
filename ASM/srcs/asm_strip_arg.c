/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_strip_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:21:00 by erli              #+#    #+#             */
/*   Updated: 2019/02/15 12:42:34 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

/*
** fill strip with the argument. argument are separated with SEPARATOR_CHAR
** and then cleaned (no whitespace before nor after.
** if there is a 4th arg, or a non whitespace characater != COMMENT_CHAR
** return an asm_error_msg.
** Also fills cols, which contains the number of col before each arg.
*/

static	int	asm_get_arg(t_asm_data *data, char *line, int *nb_sep, int i)
{
	while (line[data->col] != ' ' && line[data->col] != '\t'
		&& line[data->col] != '\0' && line[data->col] != COMMENT_CHAR
		&& line[data->col] != SEPARATOR_CHAR)
		data->col++;
	if (line[data->col] == '\0' || line[data->col] == COMMENT_CHAR)
		return (0);
	*nb_sep += (line[data->col] == SEPARATOR_CHAR ? 1 : 0);
	line[data->col++] = '\0';
	while (line[data->col] == ' ' || line[data->col] == '\t')
		data->col++;
	if (line[data->col] == '\0' || line[data->col] == COMMENT_CHAR)
		return (0);
	if ((line[data->col] != SEPARATOR_CHAR && *nb_sep == i)
		|| (line[data->col] == SEPARATOR_CHAR && *nb_sep == i + 1))
		return (asm_error_msg(data, SYNTAX_ERROR));
	*nb_sep += (line[data->col] == SEPARATOR_CHAR ? 1 : 0);
	data->col += (line[data->col] == SEPARATOR_CHAR ? 1 : 0);
	while (line[data->col] == ' ' || line[data->col] == '\t')
		data->col++;
	return (1);
}

int			asm_strip_arg(t_asm_data *data, char *line, char **strip,
				int *cols)
{
	int	nb_sep;
	int i;
	int	ret;

	i = 0;
	nb_sep = 0;
	while (i < data->max_arg)
	{
		cols[i] = data->col;
		if (line[data->col] != '\0' && line[data->col] != COMMENT_CHAR)
			strip[i] = line + data->col;
		if ((ret = asm_get_arg(data, line, &nb_sep, i)) < 0)
			return (-1);
		if (ret == 0)
			i = data->max_arg;
		i++;
	}
	if (nb_sep >= data->max_arg || (strip[nb_sep] == 0))
		return (asm_error_msg(data, WRONG_NB_OF_ARG));
	if (line[data->col] != '\0' && line[data->col] != COMMENT_CHAR)
		return (asm_error_msg(data, SYNTAX_ERROR));
	return (1);
}
