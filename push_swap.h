/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:21:30 by mmoreira          #+#    #+#             */
/*   Updated: 2021/07/23 21:00:34 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int			n;
	int			*array;
}				t_stack;

//------------------------------------Uteis-------------------------------------
int		ft_isdigit(int c);
int		ft_isspace(int c);
double	ft_atod(const char *nptr);
int		get_little(t_stack *stack);
int		get_big(t_stack *stack);
//------------------------------------------------------------------------------

//----------------------------Checando os Argumentos----------------------------
int		check_args(int n, char **args, t_stack *a, t_stack *b);
//------------------------------------------------------------------------------

//----------------------------------Movimentos----------------------------------
void	s_move(t_stack *stack);
void	r_move(t_stack *stack);
void	rr_move(t_stack *stack);
void	p_move(t_stack *stack_1, t_stack *stack_2);

void	sm(t_stack *a, t_stack *b, char c);
void	rm(t_stack *a, t_stack *b, char c);
void	rrm(t_stack *a, t_stack *b, char c);
void	pm(t_stack *a, t_stack *b, char c);
//------------------------------------------------------------------------------

//-----------------------------Funções de Ordenação-----------------------------
int		check_sorting(t_stack *stack, int inv);
void	micro_sorting(t_stack *a, t_stack *b);
void	little_sorting(t_stack *a, t_stack *b);
void	medium_sorting(t_stack *a, t_stack *b, int nb);
void	big_sorting(t_stack *a, t_stack *b, int nb);
//------------------------------------------------------------------------------

//-------------------------Funções de Ordenação Inversa-------------------------
void	micro_sorting_i(t_stack *a, t_stack *b);
void	little_sorting_i(t_stack *a, t_stack *b);
void	medium_sorting_i(t_stack *a, t_stack *b, int nb);
//------------------------------------------------------------------------------

#endif
