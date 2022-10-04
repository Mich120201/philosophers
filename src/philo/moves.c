/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:31:41 by mvolpi            #+#    #+#             */
/*   Updated: 2022/10/04 11:40:29 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_file/philo.h"

int	eating(t_info *info, t_philo *philo)
{
	if (info->flag_of_death)
		return (1);
	if (philo->left_fork < philo->right_fork)
		pthread_mutex_lock(&info->fork[philo->left_fork]);
	else
		pthread_mutex_lock(&info->fork[philo->right_fork]);
	philo_print(info, philo, "has taken a fork");
	if (info->count_philo == 1)
	{
		pthread_mutex_unlock(&info->fork[info->philo->left_fork]);
		return (1);
	}
	if (philo->left_fork < philo->right_fork)
		pthread_mutex_lock(&info->fork[philo->right_fork]);
	else
		pthread_mutex_lock(&info->fork[philo->left_fork]);
	philo_print(info, philo, "has taken a fork");
	philo_print(info, philo, "is eating");
	philo->count_eat++;
	philo->last_eat = get_timestamp();
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock(&info->fork[philo->left_fork]);
	pthread_mutex_unlock(&info->fork[philo->right_fork]);
	return (0);
}

void	sleeping(t_info *info, t_philo *philo)
{
	if (info->flag_of_death)
		return ;
	philo_print(info, philo, "is sleeping");
	ft_usleep(philo->time_to_sleep);
}

void	thinking(t_info *info, t_philo *philo)
{
	if (info->flag_of_death)
		return ;
	philo_print(info, philo, "is thinking");
}
