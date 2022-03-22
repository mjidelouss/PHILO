/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:26:44 by aelousse          #+#    #+#             */
/*   Updated: 2022/03/21 18:03:07 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	while ((str[i] <= '9' && str[i] >= '0') && str[i] != '\0')
	{
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

int	ft_free(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->nb_philo)
		pthread_mutex_destroy(&(philo->forks[i]));
	pthread_mutex_destroy(&(philo->mutex));
	free(philo->philos);
	free(philo->forks);
	return (0);
}

void	ft_initializing(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->nb_philo)
	{
		pthread_mutex_init(&philo->forks[i], NULL);
		philo->philos[i].i = i + 1;
		philo->philos[i].nb_time_must_eat = 0;
		philo->philos[i].all = philo;
		philo->philos[i].time = philo->time;
	}
}
