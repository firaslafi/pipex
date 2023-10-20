/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:07:01 by flafi             #+#    #+#             */
/*   Updated: 2023/10/20 21:08:09 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void	ft_error(char *sms)
{
	ft_putendl_fd(sms, 2);
	exit(EXIT_FAILURE);
}
