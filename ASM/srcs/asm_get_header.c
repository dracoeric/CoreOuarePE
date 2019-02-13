/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_header.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:33:28 by erli              #+#    #+#             */
/*   Updated: 2019/02/13 11:54:07 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <stdlib.h>

int		asm_match_name_or_comment(t_asm_data *data, char *line)
{
	int				flags;
	unsigned int	i;
	char			*cmd_name;
	char			*cmd_com;

	cmd_name = NAME_CMD_STRING;
	cmd_com = COMMENT_CMD_STRING;
	flags = 3;
	i = data->col;
	while (flags != 0 && line[i] != ' ' && line[i] != '\t' && line[i] != '\0')
	{
		if ((flags & 1) == 1 && line[i] != cmd_name[i] && cmd_name[i] != '\0')
			flags -= 1;
		if ((flags & 2) == 2 && line[i] != cmd_com[i] && cmd_com[i] != '\0')
			flags -= 2;
		i++;
	}
	if ((flags == 0) || (line[i] != ' ' && line[i] != '\t' && line[i] != '\0')
		|| (!(i == ft_strlen(cmd_name) || i == ft_strlen(cmd_com))))
		return (asm_error_msg(data, LEXICAL_ERROR));
	data->col = i + 1;
	return (flags);
}

static	int		asm_get_string(t_asm_data *data, char *line)
{
	while (line[data->col] != '"' && line[data->col] != '\0')
		data->col++;
	if (line[data->col] != '"')
		return (asm_error_msg(data, SYNTAX_ERROR));
	if (line[data->col] != '\0')
	{
		line[data->col] = '\0';
		data->col++;
	}
	return (1);
}

static	int		asm_strip_line(t_asm_data *data, char *line, char **strip)
{
	int	name_or_com;

	data->col = 0;
	while (line[data->col] != '\0' && (line[data->col] == ' '
		|| line[data->col] == '\t'))
		data->col++;
	if (line[data->col] == '\0')
		return (0);
	if ((name_or_com = asm_match_name_or_comment(data, line)) < 0)
		return (-1);
	while (line[data->col] != '\0' && (line[data->col] == ' '
		|| line[data->col] == '\t'))
		data->col++;
	if (line[data->col] != '"')
		return (asm_error_msg(data, SYNTAX_ERROR));
	data->col++;
	*strip = line + (data->col);
	if (asm_get_string(data, line) < 0)
		return (-1);
	while (line[data->col] != '\0' && (line[data->col] == ' '
		|| line[data->col] == '\t'))
		data->col++;
	if (!(line[data->col] != '\0' || line[data->col] != '#'))
		return (asm_error_msg(data, SYNTAX_ERROR));
	return (name_or_com);
}

static	int		asm_header_read(t_asm_data *data, char *line, t_header *header,
					int *completed)
{
	char	*strip;
	int		name_or_com;

	strip = NULL; 
	if ((name_or_com = asm_strip_line(data, line, &strip)) < 0)
		return (-1);
	if (name_or_com == 0)
		return (1);
	if (name_or_com == 1 && (*completed & 1) == 0)
	{
		ft_strncpy(header->prog_name, strip, PROG_NAME_LENGTH + 1);
		*completed += 1;
		free(line);
	}
	else if (name_or_com == 2 && (*completed & 2) == 0)
	{
		ft_strncpy(header->comment, strip, COMMENT_LENGTH + 1);
		*completed += 2;
		free(line);
	}
	else if (name_or_com == 1 && (*completed & 1) == 1)
		return (ft_msg_int(2, "Error, two name command line.\n", -1));
	else if (name_or_com == 2 && (*completed & 2) == 1)
		return (ft_msg_int(2, "Error, two comment command line.\n", -1));
	return (1);
}

int				asm_get_header(t_asm_data *data)
{
	char		*line;
	int			completed;
	t_header	header[1];
	int			ret;

	if (data == 0)
		return (-1);
	completed = 0;
	line = NULL;
	ret = 1;
	while (completed != 3 && ret > 0)
	{
		ret = asm_next_line(data->fd, &line);
		if (ret > 0)
		{
			ret = asm_header_read(data, line, header, &completed);
			ft_printf("ret = %d, comp = %d\n", ret, completed);
		}
		else if (ret == -1)
			return (ft_msg_int(2, "Failed GNL\n", -2));
		else
			return (ft_msg_int(2, "Missing name and/or comment\n", -1));
	}
	if (ret < 0)
		return (-1);
	return (1);
}
