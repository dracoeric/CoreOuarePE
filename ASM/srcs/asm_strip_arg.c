/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_strip_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:21:00 by erli              #+#    #+#             */
/*   Updated: 2019/02/13 15:39:10 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** fill strip with the argument. argument are separated with SEPARATOR_CHAR
** and then cleaned (no whitespace before nor after.
** if there is a 4th arg, or a non whitespace characater != COMMENT_CHAR
** return an asm_error_msg.
** Also fills cols, which contains the number of col before each arg.
*/

int			asm_strip_arg(t_asm_data *data, char *line, char **strip,
				int *cols)
{
	if (data == 0 || line == 0 || strip == 0 || cols == 0)
		return (-1);
	return (1);
}
