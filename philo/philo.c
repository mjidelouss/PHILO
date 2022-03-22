/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:21:45 by aelousse          #+#    #+#             */
/*   Updated: 2022/03/21 17:42:08 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_thread(t_philo *philo)
{
	int	i;

	i = -1;
	pthread_mutex_init(&philo->mutex, NULL);
	while (++i < philo->nb_philo)
		pthread_create(&philo->philos[i].philo, NULL, \
			routine, &philo->philos[i]);
	i = -1;
	while (++i < philo->nb_philo)
		pthread_detach(philo->philos[i].philo);
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

int	main(int ac, char **av)
{
	t_philo	philo;

	if ((ac == 6 || ac == 5) && checker(ac, av))
	{
		philo.nb_philo = ft_atoi(av[1]);
		philo.time_to_die = ft_atoi(av[2]);
		philo.time_to_eat = ft_atoi(av[3]);
		philo.time_to_sleep = ft_atoi(av[4]);
		if (av[5])
			philo.nb_time_must_eat = ft_atoi(av[5]);
		philo.philos = malloc(sizeof(t_pthread) * philo.nb_philo);
		philo.forks = malloc(sizeof(pthread_mutex_t) * philo.nb_philo);
		philo.time = ft_time();
		ft_initializing(&philo);
		init_thread(&philo);
		philo_manager(&philo);
	}
	return (0);
}
