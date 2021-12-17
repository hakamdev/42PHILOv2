/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 23:55:48 by ehakam            #+#    #+#             */
/*   Updated: 2021/12/17 19:44:28 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_philo.h"

bool	total_meals_reached(t_state *state)
{
	size_t	i;

	i = 0;
	while (i < state->params->n_philos)
		if (!state[i++].finished_all_meals)
			return (false);
	return (true);
}

void	routine_must_eat(t_state *state, bool *is_first_iter)
{
	size_t	n_eat;

	n_eat = 0;
	if (is_first_iter && state->id % 2 != 0)
		m_sleep(state->params->t_eat / 2);
	while (n_eat < state->params->n_eat)
	{
		ro_eat(state);
		n_eat++;
		ro_sleep(state);
		ro_think(state);
		*is_first_iter = false;
	}
	state->finished_all_meals = n_eat == state->params->n_eat;
}

void	routine_default(t_state *state, bool *is_first_iter)
{
	if (is_first_iter && state->id % 2 != 0)
		m_sleep(state->params->t_eat / 2);
	while (true)
	{
		ro_eat(state);
		ro_sleep(state);
		ro_think(state);
		*is_first_iter = false;
	}
}

void	*routine(void *args)
{
	t_state	*state;
	size_t	n_eat;
	bool	is_first_iter;

	n_eat = 0;
	is_first_iter = true;
	state = (t_state *)args;
	if (state->params->must_eat)
		routine_must_eat(state, &is_first_iter);
	else
		routine_default(state, &is_first_iter);
	return (state);
}

void	*super_routine(void *args)
{
	size_t		i;
	t_state		*state;

	i = 0;
	state = (t_state *)args;
	usleep(1000);
	while (i < state->params->n_philos)
	{
		if (get_elapsed_since(state[i].last_meal_time) >= state->params->t_die)
		{
			log_death(&state[i]);
			break ;
		}
		++i;
		if (i == state->params->n_philos)
		{
			if (state->params->must_eat && total_meals_reached(state))
				break ;
			usleep(1000);
		}
		i %= state->params->n_philos;
	}
	return (state);
}
