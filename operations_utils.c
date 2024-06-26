/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgils <jgils@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:11:01 by jgils             #+#    #+#             */
/*   Updated: 2024/04/30 14:12:12 by jgils            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(long number)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		exit(1);
	node->index = 0;
	node->value = number;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	push(t_node *node, t_stack *stack)
{
	if (stack->len == 0)
	{
		stack->head = node;
		stack->tail = stack->head;
	}
	else
	{
		node->next = stack->head;
		stack->head->prev = node;
		stack->head = node;
	}
	stack->len++;
}

t_node	*pop(t_stack *stack)
{
	t_node	*node;

	if (!stack->head)
		return (NULL);
	node = stack->head;
	if (stack->len == 1)
	{
		stack->head = NULL;
		stack->tail = stack->head;
	}
	else
	{
		stack->head = stack->head->next;
		stack->head->prev = NULL;
	}
	node->prev = NULL;
	node->next = NULL;
	stack->len--;
	return (node);
}

void	push_end(t_node *node, t_stack *stack)
{
	if (stack->len == 0)
	{
		stack->tail = node;
		stack->head = stack->tail;
	}
	else
	{
		node->prev = stack->tail;
		stack->tail->next = node;
		stack->tail = node;
	}
	stack->len++;
}

t_node	*pop_end(t_stack *stack)
{
	t_node	*node;

	if (!stack->head)
		return (NULL);
	node = stack->tail;
	if (stack->len == 1)
	{
		stack->tail = NULL;
		stack->head = stack->tail;
	}
	else
	{
		stack->tail = stack->tail->prev;
		stack->tail->next = NULL;
	}
	node->prev = NULL;
	node->next = NULL;
	stack->len--;
	return (node);
}
