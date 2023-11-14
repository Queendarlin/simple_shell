#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - singly linked list
 * @viqu_num: the number field
 * @viqu_str: a string
 * @viqu_next: points to the next node
 */
typedef struct viqu_liststr
{
	int viqu_num;
	char *viqu_str;
	struct viqu_liststr *viqu_next;
} list_t;

/**
 * struct viqu_passinfo - contains pseudo-arguements to pass into a function,
 * allowing uniform prototype for function pointer struct
 * @viqu_arg: a string generated from getline containing arguements
 * @viqu_argv:an array of strings generated from arg
 * @viqu_path: a string path for the current command
 * @viqu_argc: the argument count
 * @viqu_line_count: the error count
 * @viqu_err_num: the error code for exit()s
 * @viqu_linecount_flag: if on count this line of input
 * @viqu_fname: the program filename
 * @viqu_env: linked list local copy of environ
 * @viqu_environ: custom modified copy of environ from LL env
 * @viqu_history: the history node
 * @viqu_alias: the alias node
 * @viqu_env_changed: on if environ was changed
 * @viqu_status: the return status of the last exec'd command
 * @viqu_cmd_buf: address of pointer to cmd_buf, on if chaining
 * @viqu_cmd_buf_type: CMD_type ||, &&, ;
 * @viqu_readfd: the fd from which to read line input
 * @viqu_histcount: the history line number count
 */
typedef struct viqu_passinfo
{
	char *viqu_arg;
	char **viqu_argv;
	char *viqu_path;
	int viqu_argc;
	unsigned int viqu_line_count;
	int viqu_err_num;
	int viqu_linecount_flag;
	char *viqu_fname;
	list_t *viqu_env;
	list_t *viqu_history;
	list_t *viqu_alias;
	char **viqu_environ;
	int viqu_env_changed;
	int viqu_status;

	char **viqu_cmd_buf;
	int viqu_cmd_buf_type;
	int viqu_readfd;
	int viqu_histcount;
} info_t;

#define VIQU_INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * struct viqu_builtin - contains a builtin string and related function
 * @viqu_type: the builtin command flag
 * @viqu_func: the function
 */
typedef struct viqu_builtin
{
	char *viqu_type;
	int (*viqu_func)(info_t *);
} builtin_table;


/* toem_shloop.c */
int viqu_hsh(info_t *, char **);
int viqu_find_builtin(info_t *);
void viqu_find_cmd(info_t *);
void viqu_fork_cmd(info_t *);

/* toem_parser.c */
int viqu_is_cmd(info_t *, char *);
char *viqu_dup_chars(char *, int, int);
char *viqu_find_path(info_t *, char *, char *);

/* loophsh.c */
int viqu_loophsh(char **);

/* toem_errors.c */
void viqu_eputs(char *);
int viqu_eputchar(char);
int viqu_putfd(char c, int fd);
int viqu_putsfd(char *str, int fd);

/* toem_string.c */
int viqu_strlen(char *);
int viqu_strcmp(char *, char *);
char *viqu_starts_with(const char *, const char *);
char *viqu_strcat(char *, char *);

/* toem_string1.c */
char *viqu_strcpy(char *, char *);
char *viqu_strdup(const char *);
void viqu_puts(char *);
int viqu_putchar(char);

/* toem_exits.c */
char *viqu_strncpy(char *, char *, int);
char *viqu_strncat(char *, char *, int);
char *viqu_strchr(char *, char);

/* toem_tokenizer.c */
char **viqu_strtow(char *, char *);
char **viqu_strtow2(char *, char);

/* toem_realloc.c */
char *viqu_memset(char *, char, unsigned int);
void viqu_ffree(char **);
void *viqu_realloc(void *, unsigned int, unsigned int);

/* toem_memory.c */
int viqu_bfree(void **);

/* toem_atoi.c */
int viqu_interactive(info_t *);
int viqu_is_delim(char, char *);
int viqu_isalpha(int);
int viqu_atoi(char *);

/* toem_errors1.c */
int viqu_erratoi(char *);
void viqu_print_error(info_t *, char *);
int viqu_print_d(int, int);
char *viqu_convert_number(long int, int, int);
void viqu_remove_comments(char *);

/* toem_builtin.c */
int viqu_myexit(info_t *);
int viqu_mycd(info_t *);
int viqu_myhelp(info_t *);

/* toem_builtin1.c */
int viqu_myhistory(info_t *);
int viqu_myalias(info_t *);

/*toem_getline.c */
ssize_t viqu_get_input(info_t *);
int viqu_getline(info_t *, char **, size_t *);
void viqu_sigintHandler(int);

/* toem_getinfo.c */
void viqu_clear_info(info_t *);
void viqu_set_info(info_t *, char **);
void viqu_free_info(info_t *, int);

/* toem_environ.c */
char *viqu_getenv(info_t *, const char *);
int viqu_myenv(info_t *);
int viqu_mysetenv(info_t *);
int viqu_myunsetenv(info_t *);
int viqu_populate_env_list(info_t *);

/* toem_getenv.c */
char **viqu_get_environ(info_t *);
int viqu_unsetenv(info_t *, char *);
int viqu_setenv(info_t *, char *, char *);

/* toem_history.c */
char *viqu_get_history_file(info_t *info);
int viqu_write_history(info_t *info);
int viqu_read_history(info_t *info);
int viqu_build_history_list(info_t *info, char *buf, int linecount);
int viqu_renumber_history(info_t *info);

/* toem_lists.c */
list_t *viqu_add_node(list_t **, const char *, int);
list_t *viqu_add_node_end(list_t **, const char *, int);
size_t viqu_print_list_str(const list_t *);
int viqu_delete_node_at_index(list_t **, unsigned int);
void viqu_free_list(list_t **);

/* toem_lists1.c */
size_t viqu_list_len(const list_t *);
char **viqu_list_to_strings(list_t *);
size_t viqu_print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t viqu_get_node_index(list_t *, list_t *);

/* toem_vars.c */
int viqu_is_chain(info_t *, char *, size_t *);
void viqu_check_chain(info_t *, char *, size_t *, size_t, size_t);
int viqu_replace_alias(info_t *);
int viqu_replace_vars(info_t *);
int viqu_replace_string(char **, char *);

#endif

