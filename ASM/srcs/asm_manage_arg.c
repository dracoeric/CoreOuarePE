/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_manage_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:56:06 by erli              #+#    #+#             */
/*   Updated: 2019/02/13 15:30:36 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** gere les parametres de l'instructions et les ecris dans buf
** retourne 1 si tout va bien, un message d'erreur correspondant sinon
** gere aussi les commentaires en fin de ligne
*/

int			asm_manage_arg(t_asm_data *data, int opcode, char *line)
{
	char	*strip[3];
	int		cols[3];

	while (line[data->code] == ' ' || line[data->code] == '\t'
		|| line[data->code] == '\0')
		data->col++;
	if (line[data->code] == '\0')
		return (asm_error_msg(data, MISSING_ARGUMENT));
	ft_bzero(cols, sizeof(int) * 3);
	strip[0] = 0;
	strip[1] = 0;
	strip[2] = 0;
	if (asm_strip_arg(data, line, strip, cols) < 0)
		return (-1);
	if (asm_verif_arg(data, opcode, strip) < 0)
		return (-1);
	if (asm_write_instruction(data, opcode, strip, cols) < 0)
		return (-2);
	return (1);
}
