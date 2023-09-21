#include "monty.h"

/**
 * sub_nodes -  subtracts the top element of the stack
 * from the second top element of the stack.
 * @stack: pointer to top of stack
 * @L_num: line number
 * Return: void
 */
void sub_nodes(stack_t **stack, unsigned int L_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_error(8, L_num, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * div_nodes - divides the second top element of the stack
 * by the top element of the stack
 * @stack: pointer to top of stack
 * @L_num: line number
 * Return: void
 */
void div_nodes(stack_t **stack, unsigned int L_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, L_num, "div");

	if ((*stack)->n == 0)
		more_error(9, L_num);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mul_nodes - multiplies the second top element of the stack
 * with the top element of the stack.
 * @stack: pointer to top of stack
 * @L_num: line number
 * Return: void
 */
void mul_nodes(stack_t **stack, unsigned int L_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, L_num, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mod_nodes - computes the rest of the division of the second top
 * element of the stack by the top element of the stack.
 * @stack: pointer to top of stack
 * @L_num: line number
 * Return: void
 */
void mod_nodes(stack_t **stack, unsigned int L_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_error(8, L_num, "mod");


	if ((*stack)->n == 0)
		more_error(9, L_num);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
