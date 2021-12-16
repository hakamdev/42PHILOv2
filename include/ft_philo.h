/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:01:12 by ehakam            #+#    #+#             */
/*   Updated: 2021/12/16 18:49:32 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

# include "ft_types.h"
# include "ft_errors.h"

# define STATE_NONE -1
# define STATE_DEAD 0
# define STATE_EATING 1
# define STATE_SLEEPING 2
# define STATE_THINKING 3
# define STATE_TAKE_FORK 4

size_t		m_aton(const char *str);
bool		m_is_number(char *arg);

t_params	*init_params(int count, char **params);

t_state		*init_state(t_params *params, t_fork *forks);

t_fork		*init_forks(size_t count);

int			start_threads(t_state *state);

int			start_supervisor_thread(t_state *state);

int			start_philo_machine(t_state *state);

int			destroy_all(t_params *params, t_fork *forks);
void		destroy_forks(t_fork *forks, int last_index);

void		*routine(void *params);
void		*super_routine(void *params);

useconds_t	get_current_time();
useconds_t	get_elapsed_since(useconds_t usec);
useconds_t	get_time_diff(useconds_t new_usec, useconds_t old_usec);
void		m_sleep(useconds_t usec);

void	log_state(int state_type, t_state *state);

#endif