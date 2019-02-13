/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_verif_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:26:30 by erli              #+#    #+#             */
/*   Updated: 2019/02/13 17:34:09 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Verify that there is the right amout of argument, of the right type for 
** the instruction by looking in g_op_tab[opcode]
*/

int				asm_verif_arg(t_asm_data *data, int opcode, char **strip)
{
	if (data == 0 || opcode == -1 || strip == 0)
		return (-1);
	return (1);
}
