/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldrolet <oldrolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:39:29 by oldrolet          #+#    #+#             */
/*   Updated: 2024/05/27 17:39:30 by oldrolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*pre_dollar_sign(char *mini_cmd)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (contain_cash(mini_cmd) == 0)
		return (ft_strdup("\0"));
	str = malloc(contain_cash(mini_cmd) + 1);
	if (!str)
		return (NULL);
	if (is_quote(mini_cmd[i]))
		i++;
	while (mini_cmd && mini_cmd[i] && mini_cmd[i] != '$')
	{
		str[j++] = mini_cmd[i++];
	}
	str[j] = 0;
	return (str);
}

char	*get_dollar_sign(char *mini_cmd)
{
	t_mini	*mini;
	char	*str;
	char	*dollar_sign;
	int		i;

	mini = get_data();
	i = contain_cash(mini_cmd) + 1;
	str = check_part(&mini_cmd[i]);
	if (has_quotes(mini_cmd) < 2)
		dollar_sign = ft_strdup(get_env_part(mini, str));
	else
		dollar_sign = ft_strjoin("$", str);
	free(str);
	return (dollar_sign);
}

//Return true if is in quote and all quote are closed properly
bool	valid_quote(char *str, int len, int quote)
{
	bool	single_quote;
	bool	double_quote;
	int		i;

	single_quote = false;
	double_quote = false;
	i = 0;
	if (len == 0 || !str)
		return (false);
	while (i <= len)
	{
		if (str[i] == '\"' && !single_quote)
			double_quote = !double_quote;
		else if (str[i] == '\'' && !double_quote)
			single_quote = !single_quote;
		i++;
	}
	if (quote == QUOTE && (single_quote || double_quote))
		return (true);
	else if (quote == SINGLE_QUOTE && single_quote)
		return (true);
	else if (quote == DOUBLE_QUOTE && double_quote)
		return (true);
	return (false);
}

int	dollar_len(char *mini_cmd)
{
	int	i;

	i = 0;
	while (mini_cmd && mini_cmd[i] && mini_cmd[i] != '$')
		i++;
	if (is_quote(mini_cmd[i]))
		i++;
	while (mini_cmd[i] && !ft_isonlyspace(mini_cmd[i]))
	{
		i++;
		if (is_quote(mini_cmd[i]))
			return (i + 1);
	}
	return (i);
}

char	*ft_dollar_switch(char *mini_cmd)
{
	char	*dollar_sign;
	char	*pre_dollar;
	char	*get_dollar;
	char	*temp;
	int		len;

	if (mini_cmd[1] && mini_cmd[1] == '?')
		return (ft_itoa(g_errno));
	if (!mini_cmd[1])
		return (mini_cmd);
	pre_dollar = pre_dollar_sign(mini_cmd);
	get_dollar = get_dollar_sign(mini_cmd);
	dollar_sign = ft_strjoin(pre_dollar, get_dollar);
	len = dollar_len(mini_cmd);
	free(pre_dollar);
	free(get_dollar);
	if (dollar_sign[0] && mini_cmd[len])
	{
		temp = ft_strjoin(dollar_sign, &mini_cmd[len - 1]);
		free(dollar_sign);
		return (temp);
	}
	return (dollar_sign);
}
