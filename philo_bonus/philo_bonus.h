/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:58:57 by aelousse          #+#    #+#             */
/*   Updated: 2022/03/22 18:47:53 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <pthread.h>
# include <signal.h>
# include <sys/time.h>
# include <semaphore.h>
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
	long long	time;
	int			nb_philo;
	int			time_to_eat;
	int			time_to_die;
	int			time_to_sleep;
	int			nb_time_must_eat;
	t_pthread	*philos;
	sem_t		*write;
	sem_t		*sem;
}	t_philo;

// Libft Functions :
long	ft_atoi(const char *str);

// Philo Functions :
int		ft_allocation(t_philo *philo, char **av);
void	*init_thread(t_philo *philo);
void	ft_usleep(unsigned long time);
int		checker(int ac, char **av);
void	init_sem(t_philo *philo);
void	philo_manager(t_pthread *philo);
void	ft_exit(t_philo *philo, int *pid, int size);
void	init_fork(t_pthread *philo, int c);
void	print(t_pthread *philo, char *s, int lamp);
void	*routine(void *phil);
long long	ft_time(void);
int		ft_free(t_philo *philo, int k);

#endif
