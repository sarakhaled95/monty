#include "monty.h"

/**
 * push - push to stack
 * @new_node: pointer to new node
 * L_num: line number
 * Return: void
 */
void push(stack_t **new_node, __attribute__((unused))unsigned int L_num)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	head = *new_node;
	head->next = temp;
	temp->prev = head;
}

/**
 * print_all - print stack
 * @stack: pointer at head of stack
 * L_num: line number
 * Return: void
 */
void print_all(stack_t **stack, unsigned int L_num)
{
	stack_t *temp;

	(void) L_num;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
