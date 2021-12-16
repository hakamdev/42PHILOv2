/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:08:28 by ehakam            #+#    #+#             */
/*   Updated: 2021/12/14 21:04:07 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERRORS_H
# define FT_ERRORS_H

#include <stdbool.h>
#include <stdio.h>

# define EVOID -1
# define ENOERROR 0

# define ENOMEM 100
# define MSG_ENOMEM "Failed to allocate memory\n"

# define EMTXINIT 101
# define MSG_EMTXINIT "Failed to init mutex\n"

# define EMTXLOCK 102
# define MSG_EMTXLOCK "Failed to lock mutex\n"

# define EMTXUNLCK 103
# define MSG_EMTXUNLCK "Failed to unlock mutex\n"

# define EMTXDEST 104
# define MSG_EMTXDEST "Failed to destroy mutex\n"

# define ETRDINIT 105
# define MSG_ETRDINIT "Failed init thread\n"

# define EARGS 106
# define MSG_EARGS "Arguments not valid\n"

int		m_errno(int errnoval);
bool 	m_is_error(void);
int		m_put_error(void);

#endif