/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 01:23:23 by ehakam            #+#    #+#             */
/*   Updated: 2021/12/17 01:50:45 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_philo.h"

// static char	*state_msg(int state_type)
// {
// 	if (state_type == STATE_DEAD)
// 		return ("died");
// 	if (state_type == STATE_EATING)
// 		return ("is eating");
// 	if (state_type == STATE_SLEEPING)
// 		return ("is sleeping");
// 	if (state_type == STATE_THINKING)
// 		return ("is thinking");
// 	if (state_type == STATE_TAKE_FORK)
// 		return ("has taken a fork");
// 	return ("");
// }

void		log_state(int state_type, t_state *state)
{
	const size_t now = get_current_time() - state->start_time;
	pthread_mutex_lock(&state->params->pmtx);
	if (state_type == STATE_EATING)
		printf("%zu %d %s\n", now, state->id + 1, "is eating");
	else if (state_type == STATE_SLEEPING)
		printf("%zu %d %s\n", now, state->id + 1, "is sleeping");
	else if (state_type == STATE_THINKING)
		printf("%zu %d %s\n", now, state->id + 1, "is thinking");
	else if (state_type == STATE_TAKE_FORK)
		printf("%zu %d %s\n", now, state->id + 1, "has taken a fork");
	else if (state_type == STATE_DEAD)
		printf("%zu %d %s\n", now, state->id + 1, "died");
	if (state_type != STATE_DEAD)
		pthread_mutex_unlock(&state->params->pmtx);
}
