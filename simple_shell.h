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

extern char **environ;

#define MAX_SIZE 256

void start_new_shell(void);
int command_input(char *type_command);
void exe_command(char *command);
void save_command_history(char *command);
int main(void);
void shell_print(const char *input);
int read_input(char *input, size_t input_size);
void exit_shell(void);
void list_dir(char *stored_arguments[]);
int change_dir(char *stored_arguments[]);
int path_check(char *command);
char *string_cpy(char *destination, char *source);
void handle_builtins(char **argument_param, char **current_env);

#endif
