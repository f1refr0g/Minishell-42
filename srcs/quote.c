#include "../include/minishell.h"

//Return true if is in quote and all quote are closed properly
bool    valid_quote(char *str, int len, int quote)
{
    bool    single_quote;
    bool    double_quote;
    int     i;

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
bool    contain_cash(char *str)
{
    int i;

    i = 0;
    while (str[i] && str[i] != '\0')
    {
        if (str[i] == '$')
            return (1);
        i++;
    }
    return (0);
}

// // Find the length of the $string if it ends with ' ' or '\0'
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

// char *ft_dollar_switch(char *str)
// {
//     int     i;
//     char    *ptr;
//     char    *new_str;
//     int     og_len;

//     ptr = ft_strnstr(str, "$", ft_strlen(str));
//     i = 0;
//     while (str[i])
//     {
//         if (ptr != NULL)
//         {
//             og_len = ft_strchange(ptr, " \t\n");
            
//         }
//         if(str[i] == '$')
//         {

//         }
//         i++;
//     }
// }