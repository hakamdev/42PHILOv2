/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 00:48:21 by ehakam            #+#    #+#             */
/*   Updated: 2021/12/16 19:37:59 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_philo.h"

useconds_t	get_current_time()
{
	struct timeval tp;

	gettimeofday(&tp, NULL);
	return (tp.tv_sec * 1e6 + tp.tv_usec);
}

useconds_t	get_elapsed_since(useconds_t usec)
{
	return (get_current_time() - usec);
}

useconds_t	get_time_diff(useconds_t new_usec, useconds_t old_usec)
{
	return (new_usec - old_usec);
}

void		m_sleep(useconds_t usec)
{
	useconds_t now = get_current_time();
	usleep(usec - 1e4);
	while(get_elapsed_since(now) < usec)
		;
}
