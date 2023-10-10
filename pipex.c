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
void	ft_error(char *sms)
{
	ft_putendl_fd(sms, 2);
	exit(EXIT_FAILURE);
}
// checking for excuting permissions and return path
char *ft_check_x(char **array, char **cmd1)
{
	int i;
	char *path;

	i = 0;
	while(array[i])
	{
		array[i] = ft_strjoin(array[i], "/");
		array[i] = ft_strjoin(array[i], *cmd1);
		if (access(array[i], X_OK) == 0)
			{
				path = array[i];
				break;
			}
		else
			i++;
	}
	// printf("path is = %s\n", path);
	return (path);
}
// void ft_execute()
// {

// }
int main(int argc, char **argv, char **envp)
{
	t_pipex pipex;
	
	if (argc == 5)
	{
		int fds[2];
		
		if (pipe(fds) == -1)
			ft_error("myerror pipe");

		// getting the PATH line and splitting it into a 2d array
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


		pid_t pid = fork();
		if (pid == - 1)
			ft_error("myerror fork");


		if (pid == 0)
		{
			int fd1;
			
			fd1 = open("file1", O_RDONLY);
			if (fd1 == -1)
				perror("myerror fd1");
			close(fds[READ_END]);
			dup2(fds[WRITE_END], STDOUT_FILENO);
			close(fds[WRITE_END]);
			dup2(fd1, STDIN_FILENO);
			execve(ft_check_x(array, cmd1), cmd1, NULL);

		}
		else
		{
			// wait(NULL);
			// char arr[20000];
			// read(fds[READ_END], arr, 20000);
			// ft_putendl_fd(arr, 2);
			pid_t pid2 = fork();
			if (pid2 == - 1)
				{
					perror("myerror fork");
					exit(EXIT_FAILURE);
				}
			if (pid2 == 0)
			{
				int fd2;

				fd2 = open("file2", O_WRONLY | O_CREAT | O_TRUNC, 0644);
				close(fds[WRITE_END]);
				dup2(fds[READ_END], STDIN_FILENO);
				close(fds[READ_END]);
				dup2(fd2, STDOUT_FILENO);
				char **cmd2 = ft_split(argv[3], ' ');
				execve(ft_check_x(array, cmd2), cmd2, NULL);
			}
		}


		// printf("cmd path = %s\n", path);
		


		
 		// fds = open("example.txt", O_WRONLY | O_CREAT, 0644);
		// execve("/bin/ls", &argv[2], NULL);
		// sleep(5);
		// unlink("example.txt");
	}
	else
		return(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}