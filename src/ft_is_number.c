/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:03:29 by ehakam            #+#    #+#             */
/*   Updated: 2021/12/14 21:03:52 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_philo.h"

bool	m_is_number(char *arg)
{
	int 	i;

	if (!arg)
		return (false);
	i = 0;
	while (arg[i] == ' ')
		i++;
	if (arg[i] == '+')
		i++;
	if (!(arg[i] >= '0' && arg[i] <= '9'))
		return (false);
	while (arg[i] >= '0' && arg[i] <= '9')
		i++;
	while (arg[i] == ' ')
		i++;
	if (arg[i] != '\0')
		return (false);
	return (true);
}
