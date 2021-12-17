/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 01:23:23 by ehakam            #+#    #+#             */
/*   Updated: 2021/12/17 20:09:42 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_philo.h"

void	log_death(t_state *state)
{
	const size_t	now = get_current_time() - state->start_time;

	pthread_mutex_lock(&state->params->pmtx);
	printf(RED "[%7zu] " GRE "%d %s" DEF "\n", now, state->id + 1, "died");
}

void	log_state(int state_type, t_state *state)
{
	const size_t	now = get_current_time() - state->start_time;

	pthread_mutex_lock(&state->params->pmtx);
	if (state_type == STATE_EATING)
		printf(RED "[%7zu] " GRE "%d %s" DEF "\n",
			now, state->id + 1, "is eating");
	else if (state_type == STATE_SLEEPING)
		printf(RED "[%7zu] " GRE "%d %s" DEF "\n",
			now, state->id + 1, "is sleeping");
	else if (state_type == STATE_THINKING)
		printf(RED "[%7zu] " GRE "%d %s" DEF "\n",
			now, state->id + 1, "is thinking");
	else if (state_type == STATE_TAKE_FORK)
		printf(RED "[%7zu] " GRE "%d %s" DEF "\n",
			now, state->id + 1, "has taken a fork");
	pthread_mutex_unlock(&state->params->pmtx);
}
