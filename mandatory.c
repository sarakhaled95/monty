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

/**
 * print_top - prints the value at the top of the stack
 * @stack: pointer at head of stack
 * L_num: line number
 * Return: void
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_error(6, line_number);
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: pointer at head of stack
 * L_num: line number
 * Return: void
 */
void pop(stack_t **stack, unsigned int L_num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		more_error(7, L_num);

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer at head of stack
 * L_num: line number
 * Return: void
 */
void swap(stack_t **stack, unsigned int L_num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, L_num, "swap");
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}
