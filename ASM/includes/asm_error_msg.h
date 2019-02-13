/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error_msg.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:19:01 by erli              #+#    #+#             */
/*   Updated: 2019/02/13 14:02:10 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_ERROR_MSG_H
# define ASM_ERROR_MSG_H

typedef	struct	s_error_msg
{
	char	*msg;
	int		len;
}				t_error_msg;

t_error_msg		g_error_msg[4] =
{
	{"No error message has been selected.\n", 36},
	{"Lexical error at ", 17},
	{"Syntax error at ", 16},
	{"Error, end of file before first instruction at ", 47}
};

#endif
