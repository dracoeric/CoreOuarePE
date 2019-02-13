/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_match_tag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:26:03 by erli              #+#    #+#             */
/*   Updated: 2019/02/13 17:54:59 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

/*
** line[data->col] doit pointer sur un tag,
** retourne le opcode si ca match,
** retourne -1 ou 20 si erreur avec message d'erreur LEXICAL ERROR pointant
** au debut du mot
** gere les ligne vide
*/

int		asm_match_tag(t_asm_data *data, char *line)
{
	unsigned int	i;
	int				j;

	if (line[data->col] == '\0' || line[data->col] == '#')
		return (0);
	i = data->col;
	while (line[i] != ' ' && line[i] != '\t' && line[i] != '\0'
		&& line[i] != '#')
		i++;
	if (line[i] == '\0' || line[i] == '#')
		return (asm_error_msg(data, MISSING_ARGUMENT));
	line[i++] = '\0';
	j = 0;
	while (asm_op_tab(j).tag != 0)
	{
		if (ft_strcmp(line + data->col, asm_op_tab(j).tag) == 0)
		{
			data->col = i;
			return (j);
		}
		j++;
	}
	return ((char)asm_error_msg(data, UNKNOWN_INSTRUCTION));
}
