/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:50:33 by erli              #+#    #+#             */
/*   Updated: 2019/02/15 09:28:06 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

static	int	asm_check_file(char *file, int *fd)
{
	int	len;

	if (file == 0)
		return (-1);
	len = ft_strlen(file);
	if (len < 3 || ft_strcmp(file + len - 2, ".s") != 0)
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
		perror("asm");
		return (-1);
	}
	return (1);
}

void		asm_get_options(char *options, int *i, char **argv)
{
	if (argv[1][0] == '-')
	{
		if (argv[1][1] == 'c')
		{
			*options = 1;
			*i = *i + 1;
		}
	}
}

int			main(int argc, char **argv)
{
	int 	i;
	int		fd;
	char	options;

	if (argc == 1)
		return (ft_msg_int(1, "Usage : ./asm <sourcefile.s>\n", 0));
	i = 1;
	asm_get_options(&options, &i, argv);
	if (i == argc)
		return (ft_msg_int(1, "Usage : ./asm -opt <sourcefile.s>\n", 0));
	while (i < argc)
	{
		if (asm_check_file(argv[i], &fd) > 0)
		{
			asm_assemble(fd, argv[i], options);
			close(fd);
		}
		i++;
	}
	return (0);
}
