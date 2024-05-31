#include "pipex_bonus.h"


int main(int argc, char **argv, char **envp)
{
    int *fd_pipe;
    int pid;
    int infile;
    int outfile;
    int i;
    int j;

    if (argc < 5)
    {
 		write(2, "Error : not enough argument.\n", 30);
		exit(1);       
    }
    i = 0;
    if (pipe(fd_pipe[i]) == - 1)  // OUVRE PIPE et execute premiere commande avec infile comme entrée et envoie l'output sur le pipe
        exit_error();
    pid[i] = fork();
    if (pid[i] == 0)
        first_process(fd_pipe[i], argv, envp);
    if (waitpid(pid[i], NULL, 0) == -1)  
		exit_error();
    while (i < argc - 3)
    {
        pid = fork();
        if (pif == -1)
            exit_error();
        
    }
    // while (i < argc - 4 && argc > 5) // BOUCLE QUI VA EXECUTER TOUTES LES COMMANDES AVEC TOUS LES PIPES BON COURAGE
    // {
    //     pid[i] = fork();
    //     if (pid[i] == -1)
    //         exit_error();
    //     if (pid[i] == 0)
    //     {
    //         j = -1;
    //         close_unused_pipes(i, j, argc, fd_pipe);
    //         process_pipe(i, fd_pipe, argv, envp);
    //     }
    //     i++;
    //     if (i >= argc - 4)
    //     {
    //         i--;
    //         break;
    //     }
    // }
    final_process(fd_pipe[i], argc, argv, envp); // DERNIER EXECUTION DU DERNIER PROGRAMME ET ECRIS LE RESULTAT DANS OUTFILE
    return (0);
}
