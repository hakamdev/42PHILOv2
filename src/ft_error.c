/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:15:57 by ehakam            #+#    #+#             */
/*   Updated: 2021/12/17 17:28:06 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_errors.h"

int	m_errno(int errnoval)
{
	static int	errno;

	if (errnoval != EVOID)
		errno = errnoval;
	return (errno);
}

bool	m_is_error(void)
{
	return (m_errno(EVOID) != ENOERROR);
}

int	m_put_error(void)
{
	if (m_errno(EVOID) == ENOERROR)
		return (0);
	write(2, "Error\n", 6);
	if (m_errno(EVOID) == ENOMEM)
		write(2, MSG_ENOMEM, 26);
	else if (m_errno(EVOID) == EMTXINIT)
		write(2, MSG_EMTXINIT, 21);
	else if (m_errno(EVOID) == EMTXLOCK)
		write(2, MSG_EMTXLOCK, 21);
	else if (m_errno(EVOID) == EMTXUNLCK)
		write(2, MSG_EMTXUNLCK, 23);
	else if (m_errno(EVOID) == EMTXDEST)
		write(2, MSG_EMTXDEST, 24);
	else if (m_errno(EVOID) == ETRDINIT)
		write(2, MSG_ETRDINIT, 19);
	else if (m_errno(EVOID) == EARGS)
		write(2, MSG_EARGS, 20);
	return (1);
}
