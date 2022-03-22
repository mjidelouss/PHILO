/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:22:07 by aelousse          #+#    #+#             */
/*   Updated: 2022/03/21 17:59:57 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_pthread {
	long long		time;
	int				i;
	int				nb_time_must_eat;
	struct s_philo	*all;
	pthread_t		philo;
}	t_pthread;

typedef struct s_philo {
	long long		time;
	int				lamp;
	int				nb_philo;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	int				nb_time_must_eat;
	pthread_mutex_t	mutex;
	t_pthread		*philos;
	pthread_mutex_t	*forks;
}	t_philo;

// Libft Functions :
long	ft_atoi(const char *str);

// Philo Functions :
void	ft_initializing(t_philo *philo);
void	check_lamp(int ac, t_philo *philo);
void	init_thread(t_philo *philo);
void	ft_usleep(unsigned long time);
int		checker(int ac, char **av);
void	*philo_manager(t_philo *philo);
void	init_fork(t_pthread *philo, int c);
void	print(t_pthread *philo, char *s, int lamp);
void	*routine(void *phil);
int		nb_time_must_eat(int *c, t_pthread *philo);
long long	ft_time(void);
#endif
