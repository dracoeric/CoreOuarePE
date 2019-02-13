/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_match_name_or_comment.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 12:19:57 by erli              #+#    #+#             */
/*   Updated: 2019/02/13 10:57:59 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			asm_match_name_or_comment(t_asm_data *data, char *line)
{
	int		flags;
	int		i;
	char	*cmd_name;
	char	*cmd_com;
//	char	cmd_name[ft_strlen(NAME_CMD_STRING) + 1];
//	char	cmd_com[ft_strlen(COMMENT_CMD_STRING) + 1];

	cmd_name = NAME_CMD_STRING;
	cmd_com = COMMENT_CMD_STRING;
	flags = 3;
//	ft_strncpy(cmd_name, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING) + 1);
//	ft_strncpy(cmd_com, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING) + 1);
	i = data->col;
	while (flags != 0 && line[i] != ' ' && line[i] != '\t' && line[i] != '\0')
	{
		if (line[i] != cmd_name[i] && cmd_name[i] != '\0' && (flags & 1) == 1)
			flags -= 1;
		if (line[i] != cmd_com[i] && cmd_com[i] != '\0' && (flags & 2) == 1)
			flags -= 2;
		i++;
	}
	if ((flags == 0) || (line[i] != ' ' && line[i] != '\t' && line[i] != '\0')
		|| (!(i == ft_strlen(cmd_name) || i == ft_strlen(cmd_comment))))
		return (asm_error_msg(data, LEXICAL_ERROR));
	data->col = i + 1;
	return (flags);
}
