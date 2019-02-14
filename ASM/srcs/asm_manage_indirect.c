/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_manage_indirect.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:10:01 by erli              #+#    #+#             */
/*   Updated: 2019/02/14 14:40:27 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** if argument is a value, does atoi (2 byte) then calls write_in_buf
** if argument is a hole, calls manage hole
** return -1 if write_in_buf or manage hole fails (failed malloc) fails.
*/

int			asm_manage_indirect(t_asm_data *data, int opcode, char *arg,
				int col)
{
	int		content;

	content = 0;
	if (arg[0] == ':' && asm_manage_hole(data, arg + 1, 2, opcode) < 0)
		return (-1);
	else
	{
		content = (int)asm_atoi_short(arg);
		if (asm_op_tab(opcode).opcode < 13
			&& asm_op_tab(opcode).opcode > 15)
			content = content % IDX_MOD;
		if (asm_write_to_buf(data, content, 2) < 0)
			return (-1);
	}
	return (1);
}
