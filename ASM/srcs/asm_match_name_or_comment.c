/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_match_name_or_comment.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:59:31 by erli              #+#    #+#             */
/*   Updated: 2019/02/15 16:18:06 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

int		asm_match_name_or_comment(t_asm_data *data, char *line,
					int *param)
{
	unsigned int	i;

	i = data->col;
	if (line[i] == '\0')
		return (0);
	while (line[i] != ' ' && line[i] != '\t' && line[i] != '\0'
		   && ((int)i - data->col) < data->tag_max_size)
		i++;
	if (line[i] == '\0')
		return (asm_error_msg(data, SYNTAX_ERROR));
	line[i++] = '\0';
	if (ft_strcmp(line + data->col, NAME_CMD_STRING) == 0)
		*param = 1;
	if (ft_strcmp(line + data->col, COMMENT_CMD_STRING) == 0)
		*param = 2;
	if (*param != 0)
	{
		data->col = i;
		return (1);
	}
	return (asm_error_msg(data, LEXICAL_ERROR));
}
