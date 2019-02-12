/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 09:40:26 by erli              #+#    #+#             */
/*   Updated: 2019/02/12 12:26:29 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

void				asm_convert(t_asm_data *data)
{
	if (data == 0)
		return ;
	ft_putstr("asm_convert to do\n");
	/* 
	** parcour le fichier .s ligne par ligne en decodant les instructions,
	** en stockant les label et les trous, et en remplissant les trou.
	** retourne le bon message d'erreur si erreur.
	*/
}
