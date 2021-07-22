/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 22:23:29 by mmoreira          #+#    #+#             */
/*   Updated: 2021/07/22 01:46:39 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack *stack)
{
	int i;

	i = -1;
	while (++i < stack->n - 1)
		if (stack->array[i] > stack->array[i + 1])
			return (0);
	return (1);
}

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
	write(1,"Error\n",6);
	exit(1);
}

void	print_stacks(t_stack *a, t_stack *b);

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		error(&a, &b, 0);
	if (init_stacks(argc - 1, &a, &b))
		error(&a, &b, 0);
	if (check_args(argc, argv, &a, &b))
		error(&a, &b, 1);
	if (check_sort(&a))
		return (0);
	print_stacks(&a,&b);

	//começar as coisa
	return (0);
}