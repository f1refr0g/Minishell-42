#include "../include/minishell.h"

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

//Check if input contain a dollars sign
bool	contain_cash(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\0')
	{
		if (str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

// Find the length of the $string if it ends with ' ' or '\0'
// static int  ft_strchange(const char *str, const char *charset)
// {
//     int len;
//     const char *ptr;

//     len = 0;
//     ptr = str;
//     while(*ptr != '\0' && ft_strchr(charset, *ptr) == NULL)
//     {
//         len++;
//         ptr++;
//     }
//     return (len);
// }

//Function to return the value of the variable in the env

//FIND THE $and return the trimmed variable name following it
char	*ft_dollar_switch(char *str, t_data *data)
{
	int		i;
	char	*ptr;
	char	*new_str;
	char	**temp;

	(void)(data);
	ptr = ft_strnstr(str, "$", ft_strlen(str));
	temp = ft_split(ptr, ' ');
	new_str = ft_calloc(1, ft_strlen(temp[0]));
	ft_memcpy(new_str, temp[0], ft_strlen(temp[0]));
	ft_free_array(temp);
	ft_memmove(new_str, new_str + 1, ft_strlen(new_str));
	i = 0;
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], new_str, ft_strlen(new_str)) == 0
			&& data->env[i][ft_strlen(new_str)] == '=')
		{
			new_str = ft_strdup(&data->env[i][ft_strlen(new_str) + 1]);
			return (new_str);
		}
		i++;
	}
	printf("str: %s\n", new_str);
	return ("a");
}
