/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:01:12 by ehakam            #+#    #+#             */
/*   Updated: 2022/02/10 22:09:28 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include "ft_types.h"
# include "ft_errors.h"

/*
** Helper Functions
*/
size_t		m_aton(const char *str);
bool		m_is_number(char *arg);
void		log_state(int state_type, t_state *state);
void		log_death(t_state *state);

/*
** Time Functions
*/
size_t		get_current_time(void);
size_t		elapsed(size_t msec);
void		m_sleep(size_t msec);

/*
** Init/Destructor Functions
*/
bool		init_mutex(pthread_mutex_t *mtx);
t_params	*init_params(int count, char **args);
t_state		*init_state(t_params *params, t_fork *forks);
t_state		*init_state2(t_state *state, t_params *params, t_fork *forks);
t_fork		*init_forks(size_t count);
void		delete_all(t_params *params, t_fork *forks);
void		delete_forks(t_fork *forks, size_t last_index);

/*
** Start Functions
*/
int			start_threads(t_state *state);
int			start_supervisor_thread(t_state *state);
int			start_philo_machine(t_state *state);

/*
** Routine Functions
*/
bool		total_meals_reached(t_state *state);
bool		super_routine_check_meals(t_state *state);
void		*routine(void *args);
void		*super_routine(void *args);
void		ro_eat(t_state *state);
void		ro_sleep(t_state *state);
void		ro_think(t_state *state);

#endif