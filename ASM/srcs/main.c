/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:50:33 by erli              #+#    #+#             */
/*   Updated: 2019/02/12 12:48:14 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

static	int	asm_dest_path(char *file, int len)
{
	int		fd;
	char	path[len + 3];

	ft_strncpy(path, file, len - 2);
	ft_strncpy(path + len - 2, ".cor", 5);
	fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("asm");
		return (-1);
	}
	return (fd);		
}

static	int	asm_check_file(char *file, int *fd, int *dest_fd)
{
	int	len;

	if (file == 0)
		return (-1);
	len = ft_strlen(file);
	if (len < 3 || ft_strcmp(file + len - 3, ".s") != 0)
	{
		ft_putstr_fd(file, 2);
		ft_putstr_fd(" has an incorrect format,", 2);
		return (ft_msg_int(2, " <sourcefile.s> format needed.\n", -1));
	}
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
	{
		ft_putstr_fd("Cannot read source file ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(".\n", 2);
		return (-1);
	}
	*dest_fd = asm_dest_path(file, len);
	if (*dest_fd < 0)
		return (-1);
	return (1);	
}

int			main(int argc, char **argv)
{
	int i;
	int	fd;
	int	dest_fd;

	if (argc == 1)
		return (ft_msg_int(1, "Usage : ./asm <sourcefile.s>\n", 0));
	i = 1;
	while (i < argc)
	{
		if (asm_check_file(argv[i], &fd, &dest_fd) > 0)
			asm_assemble(fd, dest_fd);
		i++;
	}
	return (0);
}
