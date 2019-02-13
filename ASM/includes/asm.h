/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 10:57:30 by erli              #+#    #+#             */
/*   Updated: 2019/02/13 12:58:49 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"

# define B_SIZE MEM_SIZE / 6
# define BUFF_SIZE 2048
# define HEADER_SIZE 10 + PROG_NAME_LENGTH + COMMENT_LENGTH

# define LEXICAL_ERROR 1
# define SYNTAX_ERROR 2
# define NO_INSTRUCTION	3

typedef struct	s_op
{
	char		*tag;
	int			nb_arg;
	int			arg_type[3];
	char		opcode;
	int			duration;
	char		*description;
	char		ocp;
	char		direct_is_short;
}				t_op;

typedef	struct	s_label
{
	char			*name;
	int				size;
	int				buf_position;
	int				file_offset;
	int				line;
	int				col;
	char			state;
}				t_label;

typedef struct	s_asm_data
{
	int		fd;
	int		dest_fd;
	int		buf_header[HEADER_SIZE + 1];
	char	buf[B_SIZE + 1];
	int		cursor;
	int		file_offset;
	t_label	labels[B_SIZE / 2];
	char	malloced;
	int		lab_curs;
	t_label	holes[B_SIZE / 2];
	int		hol_curs;
	int		line;
	int		col;
	int		error_code;
}				t_asm_data;

int				asm_error_msg(t_asm_data *data, int error_code);
void			asm_assemble(int fd, int dest_fd);
int				asm_get_header(t_asm_data *data, t_header *header);
int				asm_next_line(int fd, char **line);
void			asm_convert(t_asm_data *data);
void			asm_free_data(t_asm_data **data);
int				asm_match_name_or_comment(t_asm_data *data, char *line);
void			asm_write_header(t_asm_data *data, t_header *header);
#endif
