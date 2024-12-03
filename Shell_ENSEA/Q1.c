#include <unistd.h> //For EXIT_SUCCESS/FAILURE
#include <stdlib.h>
#include <stdio.h>
#include <string.h> //For strlen
#include <fcntl.h> //For open/creat


#define WELCOME_MESSAGE "Welcome to ShellENSEA! \nType 'exit' to quit\n"
#define WAITING_PROMPT "enseash %\n"

//Files descriptor
int terminal = STDOUT_FILENO; //Sending arguments to terminal

void shellDisplay(void) {

    //Displaying

    write(terminal,WELCOME_MESSAGE,strlen(WELCOME_MESSAGE));
    write(terminal,WAITING_PROMPT,strlen(WAITING_PROMPT));
    close(terminal);

}

void main(int argc,char** argv){

    shellDisplay();
    close(terminal);
    exit(EXIT_SUCCESS);

}