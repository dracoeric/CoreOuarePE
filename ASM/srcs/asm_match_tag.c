/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_match_tag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:26:03 by erli              #+#    #+#             */
/*   Updated: 2019/02/12 18:27:25 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		asm_match_tag(t_asm_data *data, char *line)
{
	if (data == 0 || line == 0)
		return (-1);
	return (0);
	/* 
	** line[data->col] doit pointer sur un tag,
	** retourne le opcode si ca match,
	** retourne -1 ou 20 si erreur avec message d'erreur LEXICAL ERROR pointant
	** au debut du mot
	** gere les ligne vide
	*/
}
