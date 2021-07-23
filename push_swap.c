/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 22:23:29 by mmoreira          #+#    #+#             */
/*   Updated: 2021/07/23 19:46:43 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stack *a, t_stack *b);

//------------------------------Funções da main---------------------------------
int	init_stacks(int n, t_stack *a, t_stack *b)
{
	a->n = n;
	a->array = malloc(n * sizeof(int));
	if (!(a->array))
		return (1);
	b->n = 0;
	b->array = malloc(n * sizeof(int));
	if (!(b->array))
	{
		free(a->array);
		return (1);
	}
	return (0);
}

void	error(t_stack *a, t_stack *b, int i)
{
	if (i)
	{
		free(a->array);
		free(b->array);
	}
	write(1, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (init_stacks(argc - 1, &a, &b))
		error(&a, &b, 0);
	if (check_args(argc, argv, &a, &b))
		error(&a, &b, 1);
	if (check_sorting(&a, 0))
		return (0);
	//print_stacks(&a,&b);
	if (a.n <= 3)
		micro_sorting(&a, &b);
	else if (a.n <= 14)
		little_sorting(&a, &b);
	else if (a.n <= 100)
		medium_sorting(&a, &b, 6);
	else
		big_sorting(&a, &b, 12);
	//print_stacks(&a,&b);
	return (0);
}
