#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **stack, unsigned int);

/* File I/O file_op.c */
void open_file(char *file_name);
void read_file(FILE *);
int parse(char *buffer, int L_num, int format);
void call_func(op_func func, char *op, char *val, int L_num, int format);
void find_function(char *, char *, int, int);

/* error handling in error.c */
void error(int error_code, ...);
void more_error(int error_code, ...);

/*main.c*/
stack_t *create_node(int n);
void free_nodes(void);
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln);

/* mandatory.c */
void push(stack_t **new_node, __attribute__((unused))unsigned int ln);
void print_all(stack_t **stack, unsigned int L_num);
void print_top(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int L_num);
void swap(stack_t **stack, unsigned int L_num);

#endif
