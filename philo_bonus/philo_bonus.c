/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:58:46 by aelousse          #+#    #+#             */
/*   Updated: 2022/03/22 18:45:17 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	*init_thread(t_philo *philo)
{
	int	i;
	int	pid;
	int	*pids;

	init_sem(philo);
	i = -1;
	pids = malloc(sizeof(int) * philo->nb_philo);
	while (++i < philo->nb_philo)
	{
		pid = fork();
		if (pid == 0)
			philo_manager(&philo->philos[i]);
		else
			pids[i] = pid;
	}
	return (pids);
}

int	checker(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (ft_atoi(av[i]) < 1)
			return (printf("Error\n"), 0);
	}
	return (1);
}

int	ft_allocation(t_philo *philo, char **av)
{
	int	i;

	i = -1;
	philo->nb_philo = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->nb_time_must_eat = ft_atoi(av[5]);
	philo->philos = malloc(sizeof(t_pthread) * (philo->nb_philo));
	if (!philo->philos)
		return (0);
	philo->time = ft_time();
	while (++i < philo->nb_philo)
	{
		philo->philos[i].i = i + 1;
		philo->philos[i].time = philo->time;
		philo->philos[i].nb_time_must_eat = 0;
		philo->philos[i].all = philo;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_philo	philo;
	int		*pid;

	if ((ac == 6 || ac == 5) && checker(ac, av))
	{
		if (!ft_allocation(&philo, av))
			return (printf("Allocation Error\n"), 1);
		pid = init_thread(&philo);
		sem_close(philo.write);
		sem_close(philo.sem);
		ft_exit(&philo, pid, 0);
	}
}
