/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 23:55:48 by ehakam            #+#    #+#             */
/*   Updated: 2021/12/16 20:19:45 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_philo.h"

void		take_forks(t_state *state)
{
	const int left = state->id;
	const int right = (state->id + 1) % state->params->n_philos;

	if (state->id % 2 == 0)
	{
		pthread_mutex_lock(&state->forks[left].mtx);
		//state->current_state = STATE_TAKE_FORK;
		log_state(STATE_TAKE_FORK, state);
		pthread_mutex_lock(&state->forks[right].mtx);
		//state->current_state = STATE_TAKE_FORK;
		log_state(STATE_TAKE_FORK, state);
	}
	else
	{
		pthread_mutex_lock(&state->forks[right].mtx);
		//state->current_state = STATE_TAKE_FORK;
		log_state(STATE_TAKE_FORK, state);
		pthread_mutex_lock(&state->forks[left].mtx);
		//state->current_state = STATE_TAKE_FORK;
		log_state(STATE_TAKE_FORK, state);
	}
}

void		release_forks(t_state *state)
{
	const int left = state->id;
	const int right = (state->id + 1) % state->params->n_philos;

	if (state->id % 2 == 0)
	{
		pthread_mutex_unlock(&state->forks[left].mtx);
		pthread_mutex_unlock(&state->forks[right].mtx);
	}
	else
	{
		pthread_mutex_unlock(&state->forks[right].mtx);
		pthread_mutex_unlock(&state->forks[left].mtx);
	}
}

void		ro_eat(t_state *state)
{
	const size_t count = state->params->n_philos;

	take_forks(state);
	state->last_meal_time = get_current_time();
	//state->current_state = STATE_EATING;
	log_state(STATE_EATING, state);
	m_sleep(state->params->t_eat);
	release_forks(state);
}

void		ro_sleep(t_state *state)
{
	const size_t count = state->params->n_philos;

	//state->current_state = STATE_SLEEPING;
	log_state(STATE_SLEEPING, state);
	m_sleep(state->params->t_sleep);
}

void		ro_think(t_state *state)
{
	//state->current_state = STATE_THINKING;
	log_state(STATE_THINKING, state);
}

/*
** Routine...
** prototype: void *(*start_routine)(void *)
*/
void		*routine(void *args)
{
	t_state *state = (t_state *)args;
	size_t	n_eat;

	n_eat = 0;
	if (state->params->must_eat)
	{
		while (n_eat < state->params->n_eat /* && !(*state->is_dead) */)
		{
			ro_eat(state);
			n_eat++;
			ro_sleep(state);
			ro_think(state);
		}
		state->finished_all_meals = n_eat == state->params->n_eat;
	} else
	{
		while (true /*!(*state->is_dead)*/)
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
	while (i < state->params->n_philos)
	{
		if (get_elapsed_since(state[i].last_meal_time) >= state->params->t_die)
			{
				if (!state[i].finished_all_meals)
					log_state(STATE_DEAD, &state[i]);
				break;
			}
		++i;
		i %= state->params->n_philos;
	}
	return state;
}
