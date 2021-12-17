/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 23:55:48 by ehakam            #+#    #+#             */
/*   Updated: 2021/12/17 02:02:10 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_philo.h"

void		take_forks(t_state *state)
{
	// const int left = state->id;
	// const int right = (state->id + 1) % state->params->n_philos;
	if (state->id % 2 == 0)
	{
		pthread_mutex_lock(&state->forks[state->id].mtx);
		log_state(STATE_TAKE_FORK, state);
		pthread_mutex_lock(&state->forks[(state->id + 1) % state->params->n_philos].mtx);
		log_state(STATE_TAKE_FORK, state);
	}
	else
	{
		pthread_mutex_lock(&state->forks[(state->id + 1) % state->params->n_philos].mtx);
		log_state(STATE_TAKE_FORK, state);
		pthread_mutex_lock(&state->forks[state->id].mtx);
		log_state(STATE_TAKE_FORK, state);
	}
}

void		release_forks(t_state *state)
{
	const int left = state->id;
	const int right = (state->id + 1) % state->params->n_philos;

	pthread_mutex_unlock(&state->forks[left].mtx);
	pthread_mutex_unlock(&state->forks[right].mtx);
}

void		ro_eat(t_state *state)
{
	take_forks(state);
	state->last_meal_time = get_current_time();
	log_state(STATE_EATING, state);
	m_sleep(state->params->t_eat);
	release_forks(state);
}

void		ro_sleep(t_state *state)
{
	log_state(STATE_SLEEPING, state);
	m_sleep(state->params->t_sleep);
}

void		ro_think(t_state *state)
{
	log_state(STATE_THINKING, state);
}

void		*routine(void *args)
{
	t_state *state = (t_state *)args;
	size_t	n_eat;

	n_eat = 0;
	if (state->params->must_eat)
	{
		while (n_eat < state->params->n_eat)
		{
			ro_eat(state);
			n_eat++;
			ro_sleep(state);
			ro_think(state);
		}
		state->finished_all_meals = n_eat == state->params->n_eat;
	} else
	{
		while (true)
		{
			ro_eat(state);
			ro_sleep(state);
			ro_think(state);
		}
	}
	return state;
}

void		*super_routine(void *args)
{
	size_t		i;
	t_state *state = (t_state *)args;

	i = 0;
	usleep(100);
	while (i < state->params->n_philos)
	{
		if (get_elapsed_since(state[i].last_meal_time) >= state->params->t_die)
			{
				if (!state[i].finished_all_meals)
					log_state(STATE_DEAD, &state[i]);
				break;
			}
		++i;
		if (i == state->params->n_philos)
			usleep(100);
		i %= state->params->n_philos;
	}
	return state;
}
