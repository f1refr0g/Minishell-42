/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldrolet <oldrolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:34:47 by oldrolet          #+#    #+#             */
/*   Updated: 2024/05/27 17:34:50 by oldrolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

//Janitor function that free any allocated memory
void	ft_clean(t_data *data)
{
	if (data->env != NULL)
	{
		ft_free_array(data->env);
	}
	if (data->array != NULL)
	{
		ft_free_array(data->array);
	}
}

//if minishell doesn't launch
int	launch_fail(char **env)
{
	if (!env[0])
		ft_putendl_fd("Unable to launch Minishell", 2);
	return (0);
}
