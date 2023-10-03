/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:19:36 by flafi             #+#    #+#             */
/*   Updated: 2023/10/03 20:26:16 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_pipex pipex;
	
	if (argc == 5)
	{
		// int fd[2];
		
		// if (pipe(fd) == -1)
		// {
		// 	perror("myerror pipe");
		// 	exit(EXIT_FAILURE);
		// }
		// pid_t pid1 = fork();
		// if (pid1 == - 1)
		// {
		// 	perror("myerror fork");
		// 	exit(EXIT_FAILURE);
		// }
		int i = 0;
		while(envp[i])
		{
			if (ft_strnstr(envp[i], "PATH", 5))
				break;
			i++;
		}
		char **array = ft_split(envp[i], ':');
		array[0] = ft_substr(array[0], 5, ft_strlen(array[0]) - 5);
		
		char **cmd1 = ft_split(argv[2], ' ');
		
		printf("cmd1 = %s", *cmd1);
		i = 0;
		char *path;

		while(array[i])
		{
			path = ft_strjoin(array[i], "/");
			path = ft_strjoin(array[i], *cmd1);
			if (access(path, X_OK) == 0)
				{
					// path = array[i];
					break;
				}
			else
				i++;
	

		}
		
		// printf("cmd path = %s\n", path);
		
		// execve(cmd_path, cmd1, NULL);
		// execve("/usr/local/bin/ls", cmd1, NULL);

		// if (pid1 == 0)
		// {
		// 	char **cmd1 = ft_split(argv[2], ' ');
		// 	execve("/bin/ls", "-lah", NULL);
		// }
		
		
 		// fds = open("example.txt", O_WRONLY | O_CREAT, 0644);
		// execve("/bin/ls", &argv[2], NULL);
		// sleep(5);
		// unlink("example.txt");
	}
	else
		return(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}