/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 23:55:48 by ehakam            #+#    #+#             */
/*   Updated: 2022/02/11 20:04:01 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_philo.h"

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
	state->finish_meals = true;
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
	bool	is_first_iter;

	is_first_iter = true;
	state = (t_state *)args;
	if (state->params->must_eat)
		routine_must_eat(state, &is_first_iter);
	else
		routine_default(state, &is_first_iter);
	return (state);
}

bool	super_routine_check_meals(t_state *state)
{
	usleep(1000);
	if (state->params->must_eat && total_meals_reached(state))
		return (true);
	return (false);
}

void	*super_routine(void *args)
{
	size_t		i;
	t_state		*state;

	i = 0;
	state = (t_state *)args;
	while (i < state->params->n_philos)
	{
		if (i == 0 && super_routine_check_meals(state))
			break ;
		pthread_mutex_lock(&state[i].eating_mtx);
		if (!state[i].is_eating)
		{
			pthread_mutex_unlock(&state[i].eating_mtx);
			if (elapsed(state[i].last_meal_t) >= state->params->t_die)
			{
				log_death(&state[i]);
				break ;
			}
		}
		else
			pthread_mutex_unlock(&state[i].eating_mtx);
		i = (i + 1) % state->params->n_philos;
	}
	return (state);
}
