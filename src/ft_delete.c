/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:37:38 by ehakam            #+#    #+#             */
/*   Updated: 2021/12/17 17:39:39 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_philo.h"

void	delete_forks(t_fork *forks, size_t last_index)
{
	size_t	i;

	i = 0;
	while (i < last_index)
		pthread_mutex_destroy(&forks[i++].mtx);
	free(forks);
}

int	delete_all(t_params *params, t_fork *forks)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	if (params)
	{
		count = params->n_philos;
		pthread_mutex_destroy(&params->pmtx);
		free(params);
	}
	if (forks)
		delete_forks(forks, count);
	return (0);
}
