#include "monty.h"

/**
 * add_node - adds the top two elements of the stack
 * @stack: pointer to top of stack
 * L_num: line number
 * Return: void
 */
void add_node(stack_t **stack, unsigned int L_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, L_num, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * nop - Does nothing.
 * @stack: Pointer to top of stack.
 * @L_num: Line number
 */
void nop(stack_t **stack, unsigned int L_num)
{
	(void)stack;
	(void)L_num;
}
