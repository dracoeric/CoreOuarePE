/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_atoi_short.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:35:37 by erli              #+#    #+#             */
/*   Updated: 2019/02/14 13:41:26 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

short			asm_atoi_short(char *str)
{
	short	nb;
	short	sign;
	int		nb;

	nb = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		sign = (short)(44 - str[i++]);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = 10 * nb + (short)(str[i] - '0');
		i++;
	}
	return (nb *sign);
}
