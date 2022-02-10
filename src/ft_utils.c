/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:03:20 by ehakam            #+#    #+#             */
/*   Updated: 2022/02/10 22:03:35 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_philo.h"

bool	total_meals_reached(t_state *state)
{
	size_t	i;

	i = 0;
	while (i < state->params->n_philos)
		if (!state[i++].finish_meals)
			return (false);
	return (true);
}
