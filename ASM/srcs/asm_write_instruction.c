/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_write_instruction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:10:17 by erli              #+#    #+#             */
/*   Updated: 2019/02/14 14:39:08 by erli             ###   ########.fr       */
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

/*
** asm_manage_register does an atoi (4) on arg + 1, then calls write_in_buf.
** return -1 if write_in_buf_fails.
*/

static	int	asm_manage_register(t_asm_data *data, int opcode, char *arg)
{
	int nb;

	nb = ft_atoi(arg + 1);
	nb = nb & 255;
	if (asm_write_in_buf(data, nb, 1) < 0)
		return (-1);
	return (1);
}

int			asm_write_instruction(t_asm_data *data, int opcode, char **strip,
				int *cols)
{
	char	ocp;
	int		i;
	int		ret;

	ocp = asm_verif_arg(data, opcode, strip);
	if ((ocp & 3) != 0)
		return (-1);
	data->buf[data->cursor++] = asm_op_tab(opcode).opcode;
	if (ocp != 0)
		data->buf[data->cursor++] = ocp;
	i = 0;
	ret = 1;
	while (ret > 1 && i < asm_op_tab(opcode).nb_arg)
	{
		data->col = cols[i];
		if ((ocp >> (6 - (2 * i)) & 3) == 1)
			ret = asm_manage_register(data, opcode, strip[i]);
		else if ((ocp >> (6 - (2 * i)) & 3) == 2)
			ret = asm_manage_direct(data, opcode, strip[i]);
		else if ((ocp >> (6 - (2 * i)) & 3) == 3)
			ret = asm_manage_indirect(data, opcode, strip[i]);
		i++;
	}
	if (ret < 0)
		return (-1);
	return (1);
}
