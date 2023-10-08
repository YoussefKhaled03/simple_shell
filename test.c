int main() {
    char command[1024] ;
    char **arr2 = NULL;
    while (1) {
        printf("$ ");
        fflush(stdin);
        if (fgets(command,sizeof(command), stdin) == NULL)
        {
            break;
        }
            if (command[strlen(command) - 1] == '\n')
                command[strlen(command) - 1] = '\0';
                arr2 = fill(command);
            pid_t id = fork();
            if (id == 0)
            {
          char *path =location(arr2[0]);
                execve(path, arr2, environ);
                perror("execve");
                exit(EXIT_FAILURE);
            }
            else
            {
                waitpid(id, &status, 0);
                    /free here 
            }
    }
    return 0;
}
