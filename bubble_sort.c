/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgils <jgils@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:10:40 by jgils             #+#    #+#             */
/*   Updated: 2024/04/26 15:10:42 by jgils            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(long *numbers, int len)
{
	int	i;
	int	temp;

	i = 0;
	while (i + 1 < len)
	{
		if (numbers[i] > numbers[i + 1])
		{
			temp = numbers[i];
			numbers[i] = numbers[i + 1];
			numbers[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

int	arraynbr(long *array, int nbr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (array[i] == nbr)
			return (i);
		i++;
	}
	return (-1);
}

void	index_stack(t_stack *stack, long *numbers)
{
	int		count;
	t_node	*node;

	count = 0;
	node = stack->head;
	while (count < stack->len)
	{
		node->index = arraynbr(numbers, node->value, stack->len);
		node = node->next;
		count++;
	}
}
