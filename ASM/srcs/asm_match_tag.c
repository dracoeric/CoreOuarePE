/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_match_tag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:26:03 by erli              #+#    #+#             */
/*   Updated: 2019/02/13 14:46:48 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/* 
** line[data->col] doit pointer sur un tag,
** retourne le opcode si ca match,
** retourne -1 ou 20 si erreur avec message d'erreur LEXICAL ERROR pointant
** au debut du mot
** gere les ligne vide
*/

char			asm_match_tag(t_asm_data *data, char *line)
{
	unsigned int	i;
	int				j;

	if (line[data->col] == '\0')
		return (0);
	i = data->col;
	while (line[i] != ' ' && line[i] != '\t' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (asm_error_msg(data, MISSING_ARGUMENT));
	line[i++] = '\0';
	j = 0;
	while (g_op_tab[j].tag != 0)
	{
		if (ft_strcmp(line + data->col, g_op_tab[j].tag) == 0)
		{
			data->col = i;
			return (g_op_tab[j].opcode);
		}
		j++;
	}
	return ((char)asm_error_msg(data, LEXICAL_ERROR));
}
