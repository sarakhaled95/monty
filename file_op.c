#include "monty.h"

/**
 * open_file - opens a file
 * @file_name: file name
 * Return: Always zero
 */
void open_file(char *file_name)
{
	FILE *fp;
	fp = fopen(file_name, "r");

	if (file_name == NULL || fp == NULL)
		error(2, file_name);

	read_file(fp);
	fclose(fp);
}

/**
 * read_file - reads a file
 * @fp: pointer to file descreptor
 * Return: void
 */
void read_file(FILE *fp)
{
	int L_num, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (L_num = 1; getline(&buffer, &len, fp) != -1; L_num++)
	{
		format = parse(buffer, L_num, format);
	}
	free(buffer);
}

/**
 * parse - sparates each line to token to know which func to call
 * @buffer: line from file
 * @L_num: line number
 * @format: storage format. 0 will be entered as stack
 * 1 will be entered as queue
 * Return: 0 if opcode stack 1 if queue
 */
int parse(char *buffer, int line_number, int format)
{
	char *opcode, *val;
	const char *delim = "\n";

	if (buffer == NULL)
		error(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	val = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_function(opcode, val, line_number, format);
	return (format);
}

/**
 * find_function - find the appropriate function for opcode
 * @opcode: opcode
 * @val: arg of opcode
 * @L_num: line number
 * @format: storage format. 0 will be entered as stack
 * 1 will be entered as queue
 * Return: void
 */
void find_function(char *opcode, char *val, int L_num, int format)
{
	int j;
	int flag;

	instruction_t list_functions[] = {
		{"push", push},
		{"pall", print_all},
		{"pint", print_top},
		{"pop", pop},
		{"swap", swap},
		{"add", add_node},
		{"nop", nop},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, j = 0; list_functions[j].opcode != NULL; j++)
	{
		if (strcmp(opcode, list_functions[j].opcode) == 0)
		{
			call_func(list_functions[j].f, opcode, val, L_num, format);
			flag = 0;
		}
	}
	if (flag == 1)
		error(3, L_num, opcode);
}
/**
 * call_func - calls the function
 * @func: pointer to funtion
 * @op: string representing opcode
 * @val: string rep a num value
 * @L_num: line number
 * @format: storage format. 0 will be entered as stack
 * 1 will be entered as queue
 * Return: void
 */
void call_func(op_func func, char *op, char *val, int L_num, int format)

{
	stack_t *node;
	int flag;
	int k;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val += 1;
			flag = -1;
		}
		if (val == NULL)
			error(5, L_num);
		for (k = 0; val[k] != '\0'; k++)
		{
			if (isdigit(val[k] == 0))
				error(5, L_num);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, L_num);
		if (format == 1)
			add_to_queue(&node, L_num);
	}
	else
		func(&head, L_num);
}
