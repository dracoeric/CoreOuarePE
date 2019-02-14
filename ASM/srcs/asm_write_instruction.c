/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_write_instruction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:10:17 by erli              #+#    #+#             */
/*   Updated: 2019/02/14 19:05:48 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

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

static	int	asm_manage_register(t_asm_data *data, char *arg)
{
	int nb;

	nb = ft_atoi(arg + 1);
	nb = nb & 255;
	if (asm_write_in_buf(data, nb, 1) < 0)
		return (-1);
	return (1);
}

/*
** Checks if argument is D4 of D2
** If the arguement si a direct value, does the atoi (D4 or D2)
** does modulo 65536 if D2, doe modulo IDX_MOD
** then calls write_in_buf.
** If argument is a hole, calls manage hole.
** returns -1 if write_to_buf or manage hole fails (failed malloc).
*/

static	int	asm_manage_direct(t_asm_data *data, int opcode, char *arg)
{
	int		half_size;
	int		content;

	content = 0;
	half_size = asm_op_tab(opcode).direct_is_half;
	if (arg[1] == LABEL_CHAR && asm_manage_hole(data, arg + 2,
		(half_size == 1 ? 2 : 4), opcode) < 0)
		return (-1);
	else if (arg[1] != LABEL_CHAR)
	{
		content = (half_size == 1 ? (int)asm_atoi_short(arg + 1)
			: ft_atoi(arg + 1));
		if (half_size == 1)
			content = content % 65536;
		if (asm_op_tab(opcode).opcode < 13
			&& asm_op_tab(opcode).opcode > 15)
			content = content % IDX_MOD;
		if (asm_write_in_buf(data, content, (half_size == 1 ? 2 : 4)) < 0)
			return (-1);
	}
	return (1);
}

/*
** if argument is a value, does atoi (2 byte) then calls write_in_buf
** if argument is a hole, calls manage hole
** return -1 if write_in_buf or manage hole fails (failed malloc) fails.
*/

static	int	asm_manage_indirect(t_asm_data *data, int opcode, char *arg)
{
	int		content;

	content = 0;
	if (arg[0] == LABEL_CHAR && asm_manage_hole(data, arg + 1, 2, opcode) < 0)
		return (-1);
	else if (arg[0] != LABEL_CHAR)
	{
		content = (int)asm_atoi_short(arg);
		if (asm_op_tab(opcode).opcode < 13
			&& asm_op_tab(opcode).opcode > 15)
			content = content % IDX_MOD;
		if (asm_write_in_buf(data, content, 2) < 0)
			return (-1);
	}
	return (1);
}

int			asm_write_instruction(t_asm_data *data, int opcode, char **strip,
				int *cols)
{
	char	ocp;
	int		i;
	int		ret;

	ocp = asm_verif_arg(data, opcode, strip, cols);
	if ((ocp & 3) != 0)
		return (-1);
	data->buf[data->cursor++] = asm_op_tab(opcode).opcode;
	if (asm_op_tab(opcode).ocp == 1)
		data->buf[data->cursor++] = ocp;
	i = 0;
	ret = 1;
	while (ret > 0 && i < asm_op_tab(opcode).nb_arg)
	{
		data->col = cols[i];
		if ((ocp >> (6 - (2 * i)) & 3) == 1)
			ret = asm_manage_register(data, strip[i]);
		else if ((ocp >> (6 - (2 * i)) & 3) == 2)
			ret = asm_manage_direct(data, opcode, strip[i]);
		else if ((ocp >> (6 - (2 * i)) & 3) == 3)
			ret = asm_manage_indirect(data, opcode, strip[i]);
		i++;
	}
	return (ret < 0 ? -1 : 1);
}
