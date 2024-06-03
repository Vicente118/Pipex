#include "pipex.h"

void    permission_denied(char **argv)
{
    if (ft_strncmp(argv[2], "/dev/stdin", 11) == 0 
        || ft_strncmp(argv[2], "/dev/urandom", 13) == 0
        || ft_strncmp(argv[2], "/dev/random", 12) == 0)
    {
        write(2, "zsh: permission denied: ", 25);
        write(2, argv[2], ft_strlen(argv[2]));
        write(2, "\n", 1);
        exit(1);
    }    
}

int main(int argc, char **argv, char **envp)
{
    int fd_pipe[2];
    int pid;

    if (argc < 5)
    {
 		write(2, "Error : not enough arguments.\n", 30);
		exit(1);       
    }
    permission_denied(argv);
    if (argc > 5)
    {
 		write(2, "Error : too much arguments.\n", 29);
		exit(1);       
    }
    if (pipe(fd_pipe) == - 1)  // OUVRE PIPE et execute premiere commande avec infile comme entrée et envoie l'output sur le pipe
        exit_error();
    pid = fork();
    if (pid == -1)
        exit_error();
    if (pid == 0)
        first_process(fd_pipe, argv, envp);
    final_process(fd_pipe, argc, argv, envp); // DERNIER EXECUTION DU DERNIER PROGRAMME ET ECRIS LE RESULTAT DANS OUTFILE
    return (0);
}
