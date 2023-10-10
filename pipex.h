/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:00:11 by flafi             #+#    #+#             */
/*   Updated: 2023/10/02 19:04:50 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
#include <fcntl.h>
# include <stdio.h>
#include <sys/wait.h>

# define READ_END  0
# define WRITE_END  1

typedef struct s_pipex
{
    pid_t *pid;

    
} t_pipex ;

#endif