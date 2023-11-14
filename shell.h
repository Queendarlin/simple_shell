#ifndef SHELL_H
#define SHELL_H

#include <errno.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>


/* for read/write buffers */
#define VIQU_GET_BUFFER_SIZE 1024
#define VIQU_PUT_BUFFER_SIZE 1024
#define VIQU_FLUSH_BUFFER -1

/* for command chaining */
#define VIQU_INSTRUCT_NORMAL      0
#define VIQU_INSTRUCT_OR          1
#define VIQU_INSTRUCT_AND         2
#define VIQU_INSTRUCT_CHAIN       3

/* for int_to_string() */
#define VIQU_TRANSFORM_LOWERCASE       1
#define VIQU_TRANSFORM_UNSIGNED        2

/* 1 if using system getline() */
#define VIQU_USE_GET_LINE 0
#define VIQU_USE_STR_TOK 0

#define VIQU_FILE_HIISTORY       ".viqu_simple_shell_history"
#define VIQU_MAXIMUM_HIISTORY        4096

extern char **viqu_environ;


/**
 * struct viqu_list_str - The structure of the list
 * @viqu_num: Linked list number
 * @viqu_str: The linked list string
 * @viqu_next: Depicts the linked list next node
 */

typedef struct viqu_list_str
{
	int viqu_num;
	char *viqu_str;
	struct viqu_list_str *viqu_next;
} list_t;

/**
 * struct viqu_pass_info - Function false argument
 * @viqu_arg: String argument
 * @viqu_argv: Argument for function
 * @viqu_path: Current command path
 * @viqu_argc: Number of arguments
 * @viqu_line_count: For error counting
 * @viqu_err_num: For exit error status
 * @viqu_linecount_flag: For counting input line
 * @viqu_file_name: The name of file for the program
 * @viqu_env: The environment of linked list
 * @viqu_environ: Custom environment
 * @viqu_history: Linked list history for the node
 * @viqu_alias: Node for creating alias
 * @viqu_env_changed: For the condition of changing environment
 * @viqu_status: the return status of the last exec'd command
 * @viqu_cmd_buf: Pointer to buffer
 * @viqu_cmd_buffer_type: For checking types
 * @viqu_read_fd: Reading through the file descriptor
 * @viqu_hist_count: the history line number count
 */

typedef struct viqu_pass_info
{
	int viqu_argc;
	unsigned int viqu_line_count;
	char *viqu_arg;
	char **viqu_argv;
	char *viqu_path;

	char *viqu_file_name;
	int viqu_linecount_flag;
	list_t *viqu_env;
	list_t *viqu_history;
	int viqu_err_num;
	list_t *viqu_alias;
	char **viqu_cmd_buf;
	char **viqu_environ;
	int viqu_env_changed;
	int viqu_status;

	int viqu_hist_count;
	int viqu_cmd_buffer_type;
	int viqu_read_fd;

} info_t;

#define VIQU_DEFAULT_INIT \
{0, 0, NULL, NULL, NULL, NULL, 0, NULL, NULL, 0, NULL, NULL, NULL, 0, 0, \
	0, 0, 0}


/**
 * struct viqu_built_in - For some string inbuilt
 * @viqu_type: For different types of command
 * @viqu_func: The structure for function
 */

typedef struct viqu_built_in
{
	char *viqu_type;
	int (*viqu_func)(info_t *);
} viqu_built_in_table;


/* toem_shloop.c */
int viqu_shell_loop(info_t *viqu_info, char **viqu_av);
int viqu_find_cmd_builtin(info_t *viqu_info);
void viqu_search_command(info_t *viqu_info);
void viqu_exec_fork_command(info_t *viqu_info);

/* toem_parser.c */
int viqu_determine_exe_cmd(info_t
		*viqu_info, char *viqu_path);
char *viqu_duplicate_str_char(char *viqu_pathstr,
		int viqu_start, int viqu_stop);
char *viqu_find_cmd_path(info_t *viqu_info,
		char *viqu_pathstr, char *viqu_cmd);

/* loophsh.c */
int loophsh(char **);

/* toem_errors.c */
void viqu_puts_error(char *viqu_string);
int viqu_putchar_error(char viqu_char);
int viqu_put_file_d(char viqu_char, int viqu_file_d);
int viqu_puts_file_d(char *viqu_string, int viqu_file_des);

/* toem_string.c */
int viqu_custom_strlen(char *viqu_string);
int viqu_custom_strcmp(char *viqu_string1, char *viqu_string2);
char *viqu_string_start(const char *viqu_haystack,
		const char *viqu_needle);
char *viqu_custom_strcat(char *viqu_dest, char *viqu_src);

/* toem_string1.c */
char *viqu_custom_strcpy(char *viqu_dest, char *viqu_src);
char *viqu_custom_strdup(const char *viqu_str);
void viqu_puts(char *viqu_str);
int viqu_putchar(char viqu_c);

/* toem_exits.c */
char *viqu_copy_string(char *viqu_dest, char *viqu_src, int viqu_num);
char *viqu_string_concat(char *viqu_dest, char *viqu_src, int viqu_num);
char *viqu_get_str_char(char *viqu_string, char viqu_character);

/* toem_tokenizer.c */
char **viqu_main_string_token(char *viqu_str, char *viqu_delim);
char **viqu_string_token(char *viqu_str, char viqu_delim);

/* toem_custom_realloc.c */
char *viqu_memory_set(char *viqu_s, char viqu_b,
		unsigned int viqu_n);
void viqu_free_web_string(char **viqu_str_free);
void *viqu_custom_realloc(void *viqu_ptr, unsigned int viqu_old_size,
		unsigned int viqu_new_size);

/* toem_memory.c */
int viqu_free_ptr(void **viqu_ptr);

/* toem_atoi.c */
int viqu_interactive_mode(info_t *viqu_info);
int viqu_checks_delimiter(char viqu_c, char *viqu_delim);
int viqu_alpha_check(int viqu_letter);
int viqu_conv_str_int(char *viqu_string);

/* toem_errors1.c */
int viqu_error_check_int(char *viqu_string);
void viqu_display_error(info_t *viqu_info, char *viqu_estring);
int viqu_display_decimal(int viqu_input, int viqu_fd);
char *viqu_int_to_string(long int viqu_num,
		int viqu_base, int viqu_flags);
void viqu_comment_sign_removal(char *viqu_buf);

/* toem_builtin.c */
int viqu_exit_control(info_t *viqu_info);
int viqu_change_directory(info_t *g);
int viqu_help_function(info_t *viqu_info);

/* toem_builtin1.c */
int viqu_display_command_hist(info_t *viqu_info);
int viqu_custom_alias(info_t *viqu_info);

/*toemgetsline.c */
ssize_t viqu_buffer_read(info_t *viqu_info, char *viqu_buf,
		size_t *viqu_idx);
ssize_t viqu_buffer_input(info_t *viqu_info, char **viqu_buf,
		size_t *viqu_len);
ssize_t viqu_receive_input(info_t *viqu_info);
int viqu_getsline(info_t *viqu_info, char **viqu_ptr, size_t *viqu_length);
void viqu_get_command_prompt(__attribute__((unused))int viqu_sig_num);

/* toem_getinfo.c */
void viqu_reset_info(info_t *viqu_info);
void viqu_initialize_info(info_t *viqu_info, char **viqu_av);
void viqu_free_list_field(info_t *viqu_info, int viqu_every);

/* toem_environ.c */
char *viqu_obtain_environ(info_t *viqu_info, const char *viqu_name);
int viqu_current_environ(info_t *viqu_info);
int viqu_modify_environ_var(info_t *viqu_info);
int viqu_remove_environ_var(info_t *viqu_info);
int viqu_occupy_environ_list(info_t *viqu_info);

/* toem_getenv.c */
char **viqu_gets_env(info_t *viqu_info);
int viqu_delete_env(info_t *viqu_info, char *viqu_var);
int viqu_create_env(info_t *viqu_info, char *viqu_var, char *viqu_value);

/* toem_history.c */
char *viqu_retrieve_file_hist(info_t *viqu_info);
int viqu_create_append_hist(info_t *viqu_info);
int viqu_read_file_hist(info_t *viqu_info);
int viqu_enter_hist_list(info_t *viqu_info,
		char *viqu_buf, int viqu_linecount);
int viqu_renum_hist_list(info_t *viqu_info);

/* toem_lists.c */
list_t *viqu_affix_node(list_t **viqu_head,
		const char *viqu_string, int viqu_n);
list_t *viqu_suffix_node(list_t **viqu_head,
		const char *viqu_string, int viqu_n);
size_t viqu_print_str_element(const list_t *viqu_head);
int viqu_del_node_idx(list_t **viqu_head, unsigned int viqu_index);
void viqu_free_all_nodes(list_t **viqu_head_ptr);

/* toem_lists1.c */
size_t viqu_length_of_list(const list_t *viqu_h);
char **viqu_array_string_list(list_t *viqu_head);
size_t viqu_print_list_elements(const list_t *viqu_h);
list_t *viqu_prefix_node(list_t *viqu_node, char *viqu_prefix, char viqu_c);
ssize_t viqu_gets_index_node(list_t *viqu_head, list_t *viqu_node);

/* toem_vars.c */
int viqu_test_chain_delimiter(info_t *viqu_info,
		char *viqu_buf, size_t *viqu_p);
void viqu_check_str_chain(info_t *viqu_info, char *viqu_buf,
		size_t *viqu_p, size_t viqu_index, size_t viqu_len);
int viqu_rep_alias(info_t *viqu_info);
int viqu_rep_variables(info_t *viqu_info);
int viqu_rep_str(char **viqu_old, char *viqu_new);

/** alias */
int viqu_set_alias(info_t *viqu_info, char *viqu_str);
int viqu_print_alias(list_t *viqu_node);


#endif
