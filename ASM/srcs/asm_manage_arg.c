/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_manage_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:56:06 by erli              #+#    #+#             */
/*   Updated: 2019/02/12 18:26:52 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ams.h"

int			asm_manage_arg(t_asm_data *data, char opcode, char *line)
{
	if (data == 0 || opcode == 0 || line == 0)
		return (-1);
	/* 
	** gere les parametres de l'instructions et les ecris dans buf
	** retourne 1 si tout va bien, un message d'erreur correspondant sinon
	** gere aussi les commentaires en fin de ligne
	*/
}
