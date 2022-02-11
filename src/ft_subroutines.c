/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subroutines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:02:40 by ehakam            #+#    #+#             */
/*   Updated: 2022/02/11 20:04:22 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_philo.h"

void	take_forks(t_state *state)
{
	pthread_mutex_lock(&state->forks[state->id].mtx);
	log_state(STATE_TAKE_FORK, state);
	pthread_mutex_lock(
		&state->forks[(state->id + 1) % state->params->n_philos].mtx
		);
	log_state(STATE_TAKE_FORK, state);
}

void	release_forks(t_state *state)
{
	pthread_mutex_unlock(&state->forks[state->id].mtx);
	pthread_mutex_unlock(
		&state->forks[(state->id + 1) % state->params->n_philos].mtx
		);
}

void	ro_eat(t_state *state)
{
	take_forks(state);
	state->last_meal_t = get_current_time();
	pthread_mutex_lock(&state->eating_mtx);
	state->is_eating = true;
	pthread_mutex_unlock(&state->eating_mtx);
	log_state(STATE_EATING, state);
	m_sleep(state->params->t_eat);
	pthread_mutex_lock(&state->eating_mtx);
	state->is_eating = false;
	pthread_mutex_unlock(&state->eating_mtx);
	release_forks(state);
}

void	ro_sleep(t_state *state)
{
	log_state(STATE_SLEEPING, state);
	m_sleep(state->params->t_sleep);
}

void	ro_think(t_state *state)
{
	log_state(STATE_THINKING, state);
}
