#include "pipex.h"


int main(int argc, char **argv, char **envp)
{
    int fd_pipe[2];
    int pid;
    int infile;
    int outfile;

    if (argc < 5)
    {
 		write(2, "Error : not enough argument.\n", 30);
		exit(1);       
    }
    if (pipe(fd_pipe) == - 1)  // OUVRE PIPE et execute premiere commande avec infile comme entrée et envoie l'output sur le pipe
        exit_error();
    pid = fork();
    if (pid == -1)
        exit_error();
    if (pid == 0)
        first_process(fd_pipe, argv, envp);
    if (waitpid(pid, NULL, 0) == -1)  
		exit_error();
    final_process(fd_pipe, argc, argv, envp); // DERNIER EXECUTION DU DERNIER PROGRAMME ET ECRIS LE RESULTAT DANS OUTFILE
    return (0);
}
