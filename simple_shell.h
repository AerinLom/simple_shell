#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <readline/history.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>

void start_new_shell(void);
int command_input(char *type_command);
void perf_command(char *action[]);
void save_command_history(char *command);
int standby(int *condition);


#endif
