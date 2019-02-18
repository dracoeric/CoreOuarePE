/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_dest_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:51:15 by erli              #+#    #+#             */
/*   Updated: 2019/02/18 12:33:19 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

static	int		asm_fuse_other(char *file, char *output_path, int len)
{
	int		fd;
	char	path[len + 3];

	ft_strcpy(path, output_path);
	ft_strncpy(path + ft_strlen(output_path), filename,
		ft_strlen(filename) - 2);
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
	ft_putstr("Writing output program to ");
	ft_putstr(path);
	ft_putstr(".\n");
	return (fd);
}


static	int		asm_dest_other_path(char *file, char *output_path)
{
	char *filename;

	filename = ft_strrchr(file, '/');
	if (filename == 0)
		filename = file;
	return (asm_fuse_other(filename, output_path,
		ft_strlen(filename) + ft_strlen(output_path)));
}

int				asm_dest_path(char *file, int len, char *output_path)
{
	int		fd;
	char	path[len + 3];

	if (output_path != NULL)
		return (asm_dest_other_path(file, output_path));
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
	ft_putstr("Writing output program to ");
	ft_putstr(path);
	ft_putstr(".\n");
	return (fd);
}
