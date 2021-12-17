/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 00:48:21 by ehakam            #+#    #+#             */
/*   Updated: 2021/12/17 01:47:38 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_philo.h"

size_t	get_current_time()
{
	struct timeval tp;

	gettimeofday(&tp, NULL);
	return ((tp.tv_sec * 1000) + (tp.tv_usec / 1000));
}

size_t	get_elapsed_since(size_t msec)
{
	return (get_current_time() - msec);
}

void		m_sleep(size_t msec)
{
	unsigned long long	current_time;

	current_time = get_current_time();
	usleep((msec * 1e3) - 10000);
	while (get_current_time() - current_time < msec)
		continue ;
	// size_t now = get_current_time();
	// usleep((msec * 1000) - 10000);
	// while(get_elapsed_since(now) <= msec)
	// 	;
}
