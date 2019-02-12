/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_match_name_or_comment.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 12:19:57 by erli              #+#    #+#             */
/*   Updated: 2019/02/12 14:04:32 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			asm_match_name_or_comment(t_asm_data *data, char *line)
{
	/* parcour line a partir de line[data->col]
	** qui est le premier character non ' ' ou '\t'
	** jusqu'au premier charactere different de .name et de .comment,
	** ou du premier ' ' ou '\t'.
	** retourne 1 si match .name et ecrit '\0' sur le premier whitespace
	** qui le suit.
	** retourne 2 pour .comment et ecrit '\0' sur le premier whitespace
	** qui le suit si il y en a un.
	** update data->col.
	** retourne asm_error_message(data, LEXICAL ERROR) si match pas
	*/
	if (data == 0 || line == 0)
		return (-1);
	return (0);
}
