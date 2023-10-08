#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>
int _strlen(char *s)
{
	int p;

	for (p = 0; *s != '\0'; s++)
		p++;
	return (p);
}
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int main() {
    extern char **environ;
    char *command = NULL;
    char *s = NULL, *input;
    char **arr2 = NULL;
    size_t len = 0;
    pid_t status;
    arr2 = malloc(sizeof(char *) * 1024);

    if (arr2 == NULL) {
        perror("Memory allocation error");
        return 1;
    }

    while (1) {
        int i = 0;
        printf("$ ");
        fflush(stdin);
        if (getline(&command, &len, stdin) == -1) {
            break;
        } else {
            // Remove the newline character from the end of the command
            if (command[strlen(command) - 1] == '\n') {
                command[strlen(command) - 1] = '\0';
            }
            s = strtok(command, " ");
	    arr2[0] = malloc(sizeof(char) * _strlen(s) + 1);
	    _strcpy(arr2[0], s);
	    i++;
            while (s = strtok(NULL, " ")) {
		arr2[i] = malloc(sizeof(char) * _strlen(s) + 1);
	      	_strcpy(arr2[i], s);
		i++;
            }
            arr2[i] = NULL; // Null-terminate the array for execvp
            pid_t id = fork();
            if (id == 0) {
               printf ("%s\n",arr2[0]);
	       char *argv[] ={"/bin/ls",NULL};
                execve(arr2[0], arr2, environ);
                perror("execve");
                exit(EXIT_FAILURE);
            } else {
                waitpid(id, &status, 0);

                // Free the allocated memory in both parent and child processes
                for (int j = 0; j < i; j++) {
                   // free(arr2[j]);
                }
            }
        }
    }
    free(arr2); // Free the memory for the array

    return 0;
}

