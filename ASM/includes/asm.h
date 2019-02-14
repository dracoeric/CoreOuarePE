/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 10:57:30 by erli              #+#    #+#             */
/*   Updated: 2019/02/14 17:35:13 by erli             ###   ########.fr       */
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
# define MISSING_ARGUMENT 4
# define UNKNOWN_INSTRUCTION 5
# define WRONG_NB_OF_ARG 6
# define WRONG_REG_NUMBER 7
# define WRONG_ARG_TYPE 8

typedef struct	s_op
{
	char		*tag;
	int			nb_arg;
	int			arg_type[3];
	char		opcode;
	int			duration;
	char		*description;
	char		ocp;
	char		direct_is_half;
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
	int		max_arg;
	int		buf_header[HEADER_SIZE + 1];
	char	*buf;
	int		buf_size;
	int		cursor;
	int		file_offset;
	t_label	*labels;
	int		lab_size;
	char	mallocked;
	int		lab_curs;
	t_label	*holes;
	int		holes_size;
	int		hol_curs;
	char	options;	
	int		line;
	int		col;
	int		error_code;
}				t_asm_data;

int				asm_error_msg(t_asm_data *data, int error_code);
void			asm_assemble(int fd, char *file, char options);
int				asm_get_header(t_asm_data *data, t_header *header);
int				asm_next_line(int fd, char **line);
int				asm_convert(t_asm_data *data);
void			asm_free_data(t_asm_data *data);
void			asm_write_header(t_asm_data *data, t_header *header);
int				asm_go_to_tag(t_asm_data *data, char *line);
int				asm_match_tag(t_asm_data *data, char *line);
int				asm_manage_arg(t_asm_data *data, int opcode, char *line);
int				asm_strip_arg(t_asm_data *data, char *line, char **strip,
					int *cols);
char			asm_verif_arg(t_asm_data *data, int opcode, char **strip,
					int *cols);
int				asm_write_instruction(t_asm_data *data, int opcode,
					char **strip, int *cols);
t_op			asm_op_tab(int i);
int				asm_max_arg(void);
void			asm_create_ocp(char *ocp, int tr, int i);
int				asm_write_instruction(t_asm_data *data, int opcode,
					char **Strip, int *cols);
int				asm_manage_hole(t_asm_data *data, char *arg, int nb_byte,
					int opcode);
int				asm_write_in_buf(t_asm_data *data, int content, int nb_byte);
short			asm_atoi_short(char *str);
int				asm_search_label(t_asm_data *data, char *name);
int				asm_dest_path(char *file, int len);
#endif
