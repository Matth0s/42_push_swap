/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_sorting_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:27:18 by mmoreira          #+#    #+#             */
/*   Updated: 2021/07/22 23:38:11 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_nums_block(t_stack *a, t_stack *b, int start, int end)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= a->n / 2)
		if (a->array[i] > start && a->array[i] <= end)
			break ;
	j = a->n;
	while (--j > a->n / 2)
		if (a->array[j] > start && a->array[j] <= end)
			break ;
	if (i <= a->n - j)
		while (i--)
			rm(a, b, 'a');
	else
		while (j++ < a->n)
			rrm(a, b, 'a');
	pm(a, b, 'b');
	if (b->n > 1)
		if (b->array[0] < b->array[1])
			sm(a, b, 'b');
}

static void	treat_rest(t_stack *a, t_stack *b)
{
	if (a->n <= 1)
		return ;
	else if (a->n <= 3)
		micro_sorting(a, b);
	else
		little_sorting(a, b);
}

static void	move_nums_back(t_stack *a, t_stack *b, int num)
{
	int	i;

	i = 0;
	while (b->array[i] != num)
		i++;
	if (i <= b->n / 2)
		while (i--)
			rm(a, b, 'b');
	else
		while (i++ < b->n)
			rrm(a, b, 'b');
	pm(a, b, 'a');
}

void	medium_sorting(t_stack *a, t_stack *b)
{
	int	range;
	int	j;
	int	i;

	range = a->n / NBM;
	i = -1;
	while (++i < NBM)
	{
		j = 0;
		while (j++ < range)
			move_nums_block(a, b, i * range, (i + 1)* range);
	}
	treat_rest(a, b);
	i = range * NBM + 1;
	while (--i)
		move_nums_back(a, b, i);
}
