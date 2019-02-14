/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_dest_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:51:15 by erli              #+#    #+#             */
/*   Updated: 2019/02/14 17:31:47 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

int	asm_dest_path(char *file, int len)
{
	int		fd;
	char	path[len + 3];

	ft_strncpy(path, file, len - 2);
	ft_strncpy(path + len - 2, ".cor", 5);
	fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		ft_putstr_fd("Cannot write output file ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(".\n", 2);
		perror("asm");
		return (-1);
	}
	return (fd);
}
