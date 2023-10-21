/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:19:36 by flafi             #+#    #+#             */
/*   Updated: 2023/10/21 21:54:12 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

// checking for excuting permissions and return path
char	*ft_check_x(char **array, char **cmd1)
{
	int		i;
	char	*path;

	i = 0;
	while (array[i])
	{
		array[i] = ft_strjoin(array[i], "/");
		array[i] = ft_strjoin(array[i], *cmd1);
		if (access(array[i], X_OK) == 0)
		{
			path = array[i];
			break ;
		}
		else
			i++;
	}
	if (!path)
		ft_error("no path");
	return (path);
}

// getting the PATH line and splitting it into a 2d array
char	**get_array_envp(char **envp)
{
	int		i;
	char	**array;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 5))
			break ;
		i++;
	}
	array = ft_split(envp[i], ':');
	array[0] = ft_substr(array[0], 5, ft_strlen(array[0]) - 5);
	return (array);
}

void	ft_xcmd1(int *fds, char **argv, char **envp)
{
	int		fd1;
	char	**cmd1;

	cmd1 = ft_split(argv[2], ' ');
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
		ft_error("file1 issue");
	close(fds[READ_END]);
	dup2(fds[WRITE_END], STDOUT_FILENO);
	close(fds[WRITE_END]);
	dup2(fd1, STDIN_FILENO);
	if (execve(ft_check_x(get_array_envp(envp), cmd1), cmd1, envp) < 0)
		ft_error("cmd err");
}

void	ft_xcmd2(int *fds, char **argv, char **envp)
{
	pid_t	pid2;
	int		fd2;
	char	**cmd2;

	pid2 = fork();
	if (pid2 == -1)
		ft_error("myerror fork");
	if (pid2 == 0)
	{
		fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		close(fds[WRITE_END]);
		dup2(fds[READ_END], STDIN_FILENO);
		close(fds[READ_END]);
		dup2(fd2, STDOUT_FILENO);
		cmd2 = ft_split(argv[3], ' ');
		execve(ft_check_x(get_array_envp(envp), cmd2), cmd2, envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		fds[2];
	int		i;
	pid_t	pid;

	if (argc == 5)
	{
		i = 0;
		if (pipe(fds) == -1)
			ft_error("myerror pipe");
		pid = fork();
		if (pid == -1)
			ft_error("myerror fork");
		if (pid == 0)
			ft_xcmd1(fds, argv, envp);
		else
		{
			wait(NULL);
			ft_xcmd2(fds, argv, envp);
		}
	}
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
