/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error_msg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:24:40 by erli              #+#    #+#             */
/*   Updated: 2019/02/13 19:44:36 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "asm_error_msg.h"

int			asm_error_msg(t_asm_data *data, int error_code)
{
	int	code;

	if (data == 0)
		return (-1);
	if (data->error_code != 0)
		code = error_code;
	else
		code = error_code;
	ft_putstr_fd(g_error_msg[code].msg, 2);
	ft_putstr_fd("line ", 2);
	ft_putnbr_fd(data->line, 2);
	ft_putstr_fd(", col  ", 2);
	ft_putnbr_fd(data->col, 2);
	ft_putstr_fd(".\n", 2);
	return (-1);
}
