/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:36:09 by ehakam            #+#    #+#             */
/*   Updated: 2022/02/10 22:10:11 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_philo.h"

/*
** Initialize a mutex and check for errors
*/
bool	init_mutex(pthread_mutex_t *mtx)
{
	if (pthread_mutex_init(mtx, NULL) != 0)
	{
		m_errno(ENOMEM);
		return (false);
	}
	return (true);
}

/*
** Initialize all Arguments and check for agrs errors
*/
t_params	*init_params(int count, char **args)
{
	t_params	*params;

	if (count > 6 || count < 3 || !m_is_number(args[1])
		|| !m_is_number(args[2]) || !m_is_number(args[3])
		|| !m_is_number(args[4]) || (count == 6 && !m_is_number(args[5])))
	{
		m_errno(EARGS);
		return (NULL);
	}
	params = (t_params *)malloc(sizeof(t_params));
	if (!params || !init_mutex(&params->pmtx))
	{
		if (params)
			free(params);
		m_errno(ENOMEM);
		return (NULL);
	}
	params->must_eat = count == 6;
	params->n_philos = m_aton(args[1]);
	params->t_die = m_aton(args[2]);
	params->t_eat = m_aton(args[3]);
	params->t_sleep = m_aton(args[4]);
	if (params->must_eat)
		params->n_eat = m_aton(args[5]);
	return (params);
}

/*
** Initialize a list fork objects
*/
t_fork	*init_forks(size_t count)
{
	size_t	i;
	t_fork	*forks;

	forks = (t_fork *)malloc(sizeof(t_fork) * count);
	if (!forks)
	{
		m_errno(ENOMEM);
		return (NULL);
	}
	i = 0;
	while (i < count)
	{
		forks[i].id = i;
		if (!init_mutex(&forks[i].mtx))
		{
			delete_forks(forks, i);
			return (NULL);
		}
		i++;
	}
	return (forks);
}

/*
** Initialize a list state object for each philo
*/
t_state	*init_state(t_params *params, t_fork *forks)
{
	t_state		*state;

	state = (t_state *)malloc(sizeof(t_state) * params->n_philos);
	if (!state)
	{
		delete_all(params, forks);
		m_errno(ENOMEM);
		return (NULL);
	}
	init_state2(state, params, forks);
	return (state);
}

t_state	*init_state2(t_state *state, t_params *params, t_fork *forks)
{
	size_t		i;
	size_t		start_time;

	i = 0;
	start_time = get_current_time();
	while (i < params->n_philos)
	{
		if (!init_mutex(&state[i].eating_mtx))
		{
			free(state);
			delete_all(params, forks);
			return (NULL);
		}
		state[i].id = i;
		state[i].finish_meals = false;
		state[i].last_meal_t = get_current_time();
		state[i].is_eating = false;
		state[i].params = params;
		state[i].forks = forks;
		state[i].start_t = start_time;
		++i;
	}
	return (state);
}
