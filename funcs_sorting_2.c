/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_sorting_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:27:18 by mmoreira          #+#    #+#             */
/*   Updated: 2021/07/23 19:05:04 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_block(t_stack *a, t_stack *b, int start, int end)
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

static void	move_back(t_stack *a, t_stack *b, int num)
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

void	medium_sorting(t_stack *a, t_stack *b, int nb)
{
	int	little;
	int	range;
	int	j;
	int	i;

	i = -1;
	range = a->n / nb;
	little = get_little(a) - 1;
	while (++i < nb)
	{
		j = 0;
		while (j++ < range)
			move_block(a, b, little + i * range, little + (i + 1) * range);
	}
	if (a->n > 1)
	{
		if (a->n <= 3)
			micro_sorting(a, b);
		else
			little_sorting(a, b);
	}
	i = b->n + 1;
	while (--i)
		move_back(a, b, i);
}

void	big_sorting(t_stack *a, t_stack *b, int nb)
{
	int	little;
	int	range;
	int	j;
	int	i;

	i = -1;
	range = a->n / nb;
	little = get_little(a) - 1;
	while (++i < nb)
	{
		j = 0;
		while (j++ < range)
			move_block(a, b, little + i * range, little + (i + 1) * range);
	}
	if (a->n > 1)
	{
		if (a->n <= 3)
			micro_sorting(a, b);
		else
			little_sorting(a, b);
	}
	i = b->n + 1;
	while (--i)
		move_back(a, b, i);
}
