/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_write_instruction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:10:17 by erli              #+#    #+#             */
/*   Updated: 2019/02/13 19:47:02 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** opcode is in fact the index in g_op_tab, the instruction is at
** g_op_tab[opcode].
** cols contains the column right before each arg.
** write the opcode, the OCP and argument in strip (eg opcode = 1,
** strip[0] = "%10", strip[1] = "r2") in buf.
** if buf isn't big enough, malloc, then realloc it, setting malloced as needed
** also add holes if encountered. if holes isn't big enough, malloc then realloc
** it, then set data->malloced as needed.
** Also search in data->label if holes can be filled.
*/

int			asm_write_instruction(t_asm_data *data, int opcode, char **strip,
				int *cols)
{
	if (data == 0 || opcode == -1 || strip == 0 || cols == 0)
		return (-1);
	return (1);
}
