/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_sorting_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 02:44:26 by mmoreira          #+#    #+#             */
/*   Updated: 2021/07/22 23:16:03 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorting(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->n - 1)
		if (stack->array[i] > stack->array[i + 1])
			return (0);
	return (1);
}

void	micro_sorting(t_stack *a, t_stack *b)
{
	if (check_sorting(a))
		return ;
	else if (a->n == 2)
		sm(a, b, 'a');
	else
	{
		if (a->array[0] < a->array[1])
		{
			rrm(a, b, 'a');
			if (a->array[0] > a->array[1])
				sm(a, b, 'a');
		}
		else
		{
			if (a->array[0] < a->array[2])
				sm(a, b, 'a');
			else
			{
				rm(a, b, 'a');
				if (a->array[0] > a->array[1])
					sm(a, b, 'a');
			}
		}
	}
}

void	little_sorting_aux(t_stack *a, t_stack *b, int little)
{
	int	i;

	i = 0;
	while (a->array[i] != little)
		i++;
	if (i <= a->n / 2)
		while (i--)
			rm(a, b, 'a');
	else
		while (i++ < a->n)
			rrm(a, b, 'a');
	pm(a, b, 'b');
}

void	little_sorting(t_stack *a, t_stack *b)
{
	int	little;
	int	i;

	i = 0;
	little = a->array[0];
	while (++i < a->n)
		if (little > a->array[i])
			little = a->array[i];
	i = 0;
	while (a->n != 3 && ++little && ++i)
		little_sorting_aux(a, b, little - 1);
	micro_sorting(a, b);
	while (i--)
		pm(a, b, 'a');
}
