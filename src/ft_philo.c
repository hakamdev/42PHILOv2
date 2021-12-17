/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:35:16 by ehakam            #+#    #+#             */
/*   Updated: 2021/12/17 20:32:34 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_philo.h"

int	start_threads(t_state *state)
{
	size_t			i;
	const size_t	count = state->params->n_philos;

	i = 0;
	while (i < count)
	{
		if (pthread_create(&state->philo_thread, NULL, &routine, &state[i++])
			!= 0)
		{
			m_errno(ETRDINIT);
			return (1);
		}
	}
	return (0);
}

int	start_supervisor_thread(t_state *state)
{
	pthread_t	supervisor;

	if (pthread_create(&supervisor, NULL, &super_routine, state) != 0)
	{
		m_errno(ETRDINIT);
		return (0);
	}
	if (pthread_join(supervisor, NULL) != 0)
	{
		m_errno(ETRJOIN);
		return (0);
	}
	return (0);
}

int	start_philo_machine(t_state *state)
{
	start_threads(state);
	start_supervisor_thread(state);
	delete_all(state->params, state->forks);
	free(state);
	return (0);
}

int	main(int ac, char **av)
{
	t_fork		*forks;
	t_params	*params;
	t_state		*state;

	m_errno(ENOERROR);
	params = init_params(ac, av);
	if (m_is_error())
		return (m_put_error());
	forks = init_forks(params->n_philos);
	if (m_is_error())
		return (m_put_error());
	state = init_state(params, forks);
	if (m_is_error())
		return (m_put_error());
	start_philo_machine(state);
	if (m_is_error())
		return (m_put_error());
	return (0);
}
