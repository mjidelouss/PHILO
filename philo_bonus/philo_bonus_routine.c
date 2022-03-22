/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:18:44 by aelousse          #+#    #+#             */
/*   Updated: 2022/03/22 18:54:40 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print(t_pthread *philo, char *s, int lamp)
{
	sem_wait(philo->all->write);
	printf("%lld philo %d %s\n", (ft_time() - philo->all->time), philo->i, s);
	if (lamp)
		sem_post(philo->all->write);
}

void	init_fork(t_pthread *philo, int c)
{
	if (c == 0)
	{
		sem_wait(philo->all->sem);
		print(philo, "has taken a fork", 1);
		sem_wait(philo->all->sem);
		print(philo, "has taken a fork", 1);
	}
	else
	{
		sem_post(philo->all->sem);
		sem_post(philo->all->sem);
	}
}

void	philo_manager(t_pthread *philo)
{
	pthread_t	procces;

	pthread_create(&procces, NULL, routine, philo);
	pthread_detach(procces);
	while (1)
	{
		if (philo->all->nb_time_must_eat)
		{
			if (philo->nb_time_must_eat >= philo->all->nb_time_must_eat)
				ft_free(philo->all, 0);
		}
		if ((ft_time() - philo->time) > philo->all->time_to_die)
		{
			print(philo, "died", 0);
			ft_free(philo->all, 1);
		}
		usleep(50);
	}
}

void	ft_exit(t_philo *philo, int *pid, int size)
{
	int	i;
	int	status;

	if (size == philo->nb_philo)
	{
		free(pid);
		ft_free(philo, 0);
	}
	wait(&status);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 1)
		{
			i = -1;
			while (++i < philo->nb_philo)
				kill(pid[i], SIGKILL);
		}
		else
			ft_exit(philo, pid, size + 1);
	}
	else
	{
		i = -1;
		while (++i < philo->nb_philo)
			kill(pid[i], SIGKILL);
	}
	free(pid);
	ft_free(philo, 0);
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
		ft_usleep(philo->all->time_to_eat);
		init_fork(philo, 1);
		philo->time = ft_time();
		print(philo, "is sleeping", 1);
		philo->nb_time_must_eat += 1;
		ft_usleep(philo->all->time_to_sleep);
		print(philo, "is thinking", 1);
	}
}
