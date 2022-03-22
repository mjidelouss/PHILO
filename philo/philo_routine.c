/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:29:30 by aelousse          #+#    #+#             */
/*   Updated: 2022/03/21 18:12:21 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_pthread *philo, char *s, int lamp)
{
	pthread_mutex_lock(&philo->all->mutex);
	if (s)
		printf("%lld %d %s\n", (ft_time() - philo->all->time), philo->i, s);
	if (lamp)
		pthread_mutex_unlock(&philo->all->mutex);
}

void	init_fork(t_pthread *philo, int c)
{
	if (c == 0)
	{
		pthread_mutex_lock(&philo->all->forks[(philo->i - 1) \
				% philo->all->nb_philo]);
		print(philo, "has taken a fork", 1);
		pthread_mutex_lock(&philo->all->forks[(philo->i) \
				% philo->all->nb_philo]);
		print(philo, "has taken a fork", 1);
	}
	else
	{
		pthread_mutex_unlock(&philo->all->forks[(philo->i - 1) \
				% philo->all->nb_philo]);
		pthread_mutex_unlock(&philo->all->forks[(philo->i) \
				% philo->all->nb_philo]);
	}
}

void	*philo_manager(t_philo *philo)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (1)
	{
		if (i == philo->nb_philo)
		{
			i = 0;
			j = 0;
		}
		if (philo->nb_time_must_eat)
			if (!nb_time_must_eat(&j, &philo->philos[i]))
				return (NULL);
		if ((ft_time() - philo->philos[i].time) >= philo->time_to_die)
		{
			print(&philo->philos[i], "died", 0);
			return (NULL);
		}
		i++;
	}
	return (NULL);
}

int	nb_time_must_eat(int *c, t_pthread *philo)
{
	if (philo->nb_time_must_eat >= philo->all->nb_time_must_eat)
		*c += 1;
	if (*c == philo->all->nb_philo)
	{
		print(philo, NULL, 0);
		return (0);
	}
	return (1);
}

void	*routine(void *phil)
{
	t_pthread	*philo;

	philo = phil;
	if (!(philo->i & 1))
		ft_usleep(philo->all->time_to_eat / 2);
	while (1)
	{
		init_fork(philo, 0);
		print(philo, "is eating", 1);
		philo->nb_time_must_eat += 1;
		ft_usleep(philo->all->time_to_eat);
		init_fork(philo, 1);
		philo->time = ft_time();
		print(philo, "is sleeping", 1);
		ft_usleep(philo->all->time_to_sleep);
		print(philo, "is thinking", 1);
	}
}
