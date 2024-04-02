#include "../include/minishell.h"

int	set_shlvl(void)
{
	char	*cur_shlvl;
	int		sh_lvl;
	char	*shlvl;
	char	*new_shlvl;
	t_mini	*mini;

	mini = get_data();
	shlvl = ft_strdup("SHLVL");
	cur_shlvl = get_env_part(mini, shlvl);
	if (cur_shlvl == NULL)
		return (0);
	sh_lvl = ft_atoi(cur_shlvl);
	sh_lvl++;
	new_shlvl = (ft_itoa(sh_lvl));
	update_env_part3(mini, shlvl, new_shlvl);
	new_shlvl = ft_other_free(new_shlvl);
	free(shlvl);
	return (1);
}
