/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subroutines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:02:40 by ehakam            #+#    #+#             */
/*   Updated: 2021/12/17 19:23:25 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_philo.h"

void	take_forks(t_state *state)
{
	pthread_mutex_lock(&state->forks[state->id].mtx);
	log_state(STATE_TAKE_FORK, state);
	pthread_mutex_lock(&state->forks[(state->id + 1) % state->params->n_philos].mtx);
	log_state(STATE_TAKE_FORK, state);
}

void	release_forks(t_state *state)
{
	pthread_mutex_unlock(&state->forks[state->id].mtx);
	pthread_mutex_unlock(&state->forks[(state->id + 1) % state->params->n_philos].mtx);
}

void	ro_eat(t_state *state)
{
	take_forks(state);
	state->last_meal_time = get_current_time();
	log_state(STATE_EATING, state);
	m_sleep(state->params->t_eat);
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
