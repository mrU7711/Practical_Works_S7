#include <unistd.h> //For EXIT_SUCCESS/FAILURE
#include <stdlib.h>
#include <stdio.h>
#include <string.h> //For strlen
#include <fcntl.h> //For open/creat
#include <sys/wait.h>

#define WELCOME_MESSAGE "Welcome to ShellENSEA! \nType 'exit' to quit\n"
#define WAITING_PROMPT "enseash %\n"
#define MAX_INPUT_SIZE 256

// File Descriptors
int terminal = STDOUT_FILENO; // Sending arguments to terminal
int fd_input = STDIN_FILENO;  // Getting arguments
int status;

// Input variable
char input[MAX_INPUT_SIZE];
int bytesRead;

void shellDisplay(void) {

    //Displaying
    write(terminal,WELCOME_MESSAGE,strlen(WELCOME_MESSAGE));

}

void command(char input[]){
    pid_t pid = fork();

    if (pid <= -1) {
        close(fd_input);
        close(terminal);
        exit(EXIT_FAILURE);

    } else if (pid == 0) { // Child code
        execlp(input,input,NULL);
        close(fd_input);
        close(terminal);  
        exit(EXIT_SUCCESS);

    } else {
        wait(&status);

    }
}


int main(int argc, char **argv) {

    shellDisplay();

    while (1) {
        write(terminal, WAITING_PROMPT, sizeof(WAITING_PROMPT)-1);
        bytesRead = read(fd_input, input, sizeof(input));
        input[bytesRead-1] = '\0'; //Removing the '\n' at the end

        command(input);

    }

    return EXIT_SUCCESS;
}