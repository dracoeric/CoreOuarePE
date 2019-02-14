/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_manage_direct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:00:15 by erli              #+#    #+#             */
/*   Updated: 2019/02/14 14:40:11 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Checks if argument is D4 of D2
** If the arguement si a direct value, does the atoi (D4 or D2)
** does modulo 65536 if D2, doe modulo IDX_MOD
** then calls write_in_buf.
** If argument is a hole, calls manage hole.
** returns -1 if write_to_buf or manage hole fails (failed malloc).
*/

int		asm_manage_direct(t_asm_data *data, int opcode, char *arg)
{
	int		half_size;
	int		content;

	content = 0;
	half_size = asm_op_tab(opcode).direct_is_half;
	if (arg[1] == ':' && asm_manage_holes(data, arg + 2,
		(half_size == 1 ? 2 : 4), opcode) < 0)
		return (-1);
	else
	{
		content = (half_size == 1 ? (int)asm_atoi_short(arg + 1)
			: ft_atoi(arg + 1));
		if (half_size == 1)
			content = content % 65536;
		if (asm_op_tab(opcode).opcode < 13
			&& asm_op_tab(opcode).opcode > 15)
			content = content % IDX_MOD;
		if (asm_write_to_buf(data, content, (half_size == 1 ? 2 : 4)) < 0)
			return (-1);
	}
	return (1);
}
