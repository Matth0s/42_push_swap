/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_inv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 19:47:15 by mmoreira          #+#    #+#             */
/*   Updated: 2021/07/23 21:58:36 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	micro_sort_inv(t_stack *a, t_stack *b)
{
	if (check_sort(b, 1))
		return ;
	else if (b->n == 2)
		sm(a, b, 'b');
	else
	{
		if (b->array[0] > b->array[1])
		{
			rrm(a, b, 'b');
			if (b->array[0] < b->array[1])
				sm(a, b, 'b');
		}
		else
		{
			if (b->array[0] > b->array[2])
				sm(a, b, 'b');
			else
			{
				rm(a, b, 'b');
				if (b->array[0] < b->array[1])
					sm(a, b, 'b');
			}
		}
	}
}

void	little_sort_inv(t_stack *a, t_stack *b)
{
	int	big;
	int	i;
	int	j;

	i = 0;
	big = get_big(b);
	while (b->n != 3 && --big && ++i)
	{
		j = 0;
		while (b->array[j] != big + 1)
			j++;
		if (j <= b->n / 2)
			while (j--)
				rm(a, b, 'b');
		else
			while (j++ < b->n)
				rrm(a, b, 'b');
		pm(a, b, 'a');
	}
	micro_sort_inv(a, b);
	while (i--)
		pm(a, b, 'b');
}

void	move_block_i(t_stack *a, t_stack *b, int start, int end)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= b->n / 2)
		if (b->array[i] > start && b->array[i] <= end)
			break ;
	j = b->n;
	while (--j > b->n / 2)
		if (b->array[j] > start && b->array[j] <= end)
			break ;
	if (i <= b->n - j)
		while (i--)
			rm(a, b, 'b');
	else
		while (j++ < b->n)
			rrm(a, b, 'b');
	pm(a, b, 'a');
	if (a->n > 1)
		if (a->array[0] > a->array[1])
			sm(a, b, 'a');
}

void	move_back_i(t_stack *a, t_stack *b, int num)
{
	int	i;

	i = 0;
	while (a->array[i] != num)
		i++;
	if (i <= a->n / 2)
		while (i--)
			rm(a, b, 'a');
	else
		while (i++ < a->n)
			rrm(a, b, 'a');
	pm(a, b, 'b');
}

void	medium_sort_inv(t_stack *a, t_stack *b, int nb)
{
	int	little;
	int	range;
	int	j;
	int	i;

	i = nb;
	range = b->n / nb;
	little = get_little(b) + b->n % nb - 1;
	while (i--)
	{
		j = 0;
		while (j++ < range)
			move_block_i(a, b, little + i * range, little + (i + 1) * range);
	}
	if (b->n > 1)
	{
		if (b->n <= 3)
			micro_sort_inv(a, b);
		else
			little_sort_inv(a, b);
	}
	i = little;
	while (++i <= range * nb)
		move_back_i(a, b, i);
}
