/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_match_tag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:26:03 by erli              #+#    #+#             */
/*   Updated: 2019/02/13 14:12:52 by erli             ###   ########.fr       */
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

static	void	asm_cmp_tag(char *line, int i, int *flags)
{
	int i;
	int	flag;

	i = data->col;
	flag = 0;
	while (line[i] != ' ' && line[i] != '\t' && line[i] != '\0')
		i++;
	
	return ;

}

char			asm_match_tag(t_asm_data *data, char *line)
{
	int i;
	int	flags;
	
	i = data->col;
	if (line[i] == '\0')
		return (0);
	flags = 65535;
	while (flags != 0 && line[i] != ' ' && line[i] != '\t' && line[i] != '\0')
	{
		asm_cmp_tag(line, i, &flags);
		i++;
	}
	if ((flags == 0) || (line[i] != ' ' && line[i] != '\t' && line[i] == '\0')
		|| !(asm_match_tag_check_length(i)))
		return (asm_error-msg(data, LEXICAL_ERROR));
	data->col = i + 1;
	return (asm_get_opcode(flags));
}
