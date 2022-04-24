/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:18:17 by aelousse          #+#    #+#             */
/*   Updated: 2022/03/22 18:50:03 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	ft_atoi(const char *str)
{
	int		i;
	long	s;
	long	result;

	i = 0;
	s = 1;
	result = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -s;
		i++;
	}
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * s);
}

long long	ft_time(void)
{
	struct timeval	timenow;

	gettimeofday(&timenow, NULL);
	return ((timenow.tv_sec * 1000) + (timenow.tv_usec / 1000));
}

void	ft_usleep(unsigned long time)
{
	unsigned long	timenow;

	timenow = ft_time();
	while (ft_time() - timenow < time)
		usleep(50);
}

void	ft_free(t_philo *philo, int k)
{
	free(philo->philos);
	exit(k);
}

void	init_sem(t_philo *philo)
{
	sem_unlink("sem");
	sem_unlink("write");
	philo->sem = sem_open("sem", O_CREAT, 0644, philo->nb_philo);
	philo->write = sem_open("write", O_CREAT, 0644, 1);
	if (philo->sem == SEM_FAILED || philo->sem == SEM_FAILED)
		return (free(philo->philos), exit(0));
}
