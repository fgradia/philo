/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgradia <fgradia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 19:14:33 by fgradia           #+#    #+#             */
/*   Updated: 2021/07/19 11:26:47 by fgradia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philolib.h"

long	ft_thinking(t_philo *actual)
{
	if (actual->die == 666)
		return (666);
	if (*actual->f_l_stat == 0 && *actual->f_r_stat == 0)
		return (0);
	return (ft_timestamp(0, actual->data, actual, " is thinking\n"));
}

long	ft_sleeping(t_philo *actual)
{
	if (actual->die == 666)
		return (666);
	if (ft_timestamp(0, actual->data, actual," is sleeping\n") == 666)
		return (666);
	*actual->f_l_stat = 0;
	*actual->f_r_stat = 0;
	return (0);
}

long	ft_forking_2(t_philo	*actual)
{
	if (actual->die == 666)
		return (666);
	if (*actual->f_l_stat == 1)
	{
		ft_write(1, "\t\tstealing fork...\n");
		return (666);
	}
	*actual->f_l_stat = 1;
	if (ft_timestamp(0, actual->data, actual, " has taken a fork\n") == 666)
		return (666);
	if (*actual->f_r_stat == 1)
	{
		ft_write(1, "\t\tstealing fork...\n");
		return (666);
	}
	*actual->f_r_stat = 1;
	// return (ft_timestamp(0, actual->data, actual, " has taken a fork\n"));
	if (ft_timestamp(0, actual->data, actual, " has taken a fork\n") == 666)
		return (666);
	return (ft_timestamp(1, actual->data, actual, " is eating\n"));
}

long	ft_forking(char flag, t_philo	*actual)
{
	if (actual->die == 666)
		return (666);
	if (flag == 'l')
	{
		if (*actual->f_l_stat == 1)
		{
			ft_write(1, "\t\tstealing fork...\n");
			return (666);
		}
		*actual->f_l_stat = 1;
		return (ft_timestamp(0, actual->data, actual, " has taken a fork\n"));
	}
	else if (flag == 'r')
	{
		if (*actual->f_r_stat == 1)
		{
			ft_write(1, "\t\tstealing fork...\n");
			return (666);
		}
		*actual->f_r_stat = 1;
		return (ft_timestamp(0, actual->data, actual, " has taken a fork\n"));
	}
	return (666);
}

void	ft_exit(char *str, t_data *data)
{
	ft_write(2, str);
	ft_write(2, "\n");
	exit(0);
	(void)data;
}
