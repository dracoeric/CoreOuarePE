/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_write_in_buf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:20:54 by erli              #+#    #+#             */
/*   Updated: 2019/02/14 13:28:36 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** write nb_byte of arg in data->buf and update data->cursor.
** if buf is too small, malloc, then realloc it, setting data->malloced
** as needed.
** return -1 if malloc fails, 1 otherwise.
*/

int			asm_write_in_buf(t_asm_data *data, int arg, int nb_bytes)
{



} 
