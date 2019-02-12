/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_go_to_tag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:52:53 by erli              #+#    #+#             */
/*   Updated: 2019/02/12 14:55:28 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			asm_go_to_tag(t_asm_data *data, char *line)
{
	if (data == 0 || line == 0)
		return ;
	/* 
	** Amene data->col au premier character non ' ' ou '\t', gere le label si il y
	** en a un;
	*/
}
