#include "../include/minishell.h" 

void print_cmd_array(char ***cmd_array)
{
    printf("____________________\n");
    for (int i = 0; cmd_array[i] != NULL; i++) {
        printf("Command %d:\n", i);
        for (int j = 0; cmd_array[i][j] != NULL; j++) {
            printf("  Argument %d: |%s|\n", j, cmd_array[i][j]);
        }
        printf("____________________\n");
    }
}

char    ***ft_commandarray(t_data *data)
{
    char    ***cmd_array;
    char    **splited_pipe;
    int     count;
    int     i;

    count = 0;
    i = 0;
    splited_pipe = ft_tok(data->prompt, '|');
    while (splited_pipe[count] != NULL)
        count++;

    cmd_array = malloc((count + 1) * sizeof(char **));
    if (cmd_array == NULL)
            printf(MALLOC_ERROR);
    
    while (i < count)
    {
        cmd_array[i] = ft_tok(splited_pipe[i], 32);
        i++;
    }
    cmd_array[i] = NULL;
    // print_cmd_array(cmd_array);
    return (cmd_array);
    

}

//Split the user input on SPACE char and return the allocated array
char    **ft_parse(t_data *data)
{
    int i;
    char    **tab;

    i = -1;
    tab = ft_split(data->prompt, 32);
    while(tab[i++])
        printf("line %d - %s\n", i, tab[i]);

    return (tab);
}

//NE PAS POUBLIER LE DOLLAR SIGNE DANS MALLOC
//Add a space before and after each redirection
char    *ft_expend(t_data *data)
{
    int i;
    int j;
    char *newstr;

    i = 0;
    j = 0;

    newstr = ft_calloc(sizeof(ft_strlen(data->prompt) + ft_count(data->prompt) + 1), 100);
    if (!newstr)
    {
        free(newstr);
        // return NULL;
        ft_error(MALLOC_ERROR);
    }

    while (data->prompt[i] != '\0')
    {
        if (data->prompt[i] == '|')
        {
            if (data->prompt[i + 1] == '|' && valid_quote(data->prompt, i + 1, QUOTE) == 0)
            {
                printf("Invalid syntax near token '||'\n");
                break ;
            }
        newstr[j] = ' ';
        j++;
        newstr[j] = '|';
        j++;
        newstr[j] = ' ';
        }
        else if (data->prompt[i] == '>')
        {
            if (data->prompt[i + 1] != '>')
            {
            newstr[j] = ' ';
            j++;
            newstr[j] = '>';
            j++;
            newstr[j] = ' ';
            }
            else if (data->prompt[i + 1] == '>')
            {
            newstr[j] = ' ';
            j++;
            newstr[j] = '>';
            j++;
            newstr[j] = '>';
            j++;
            newstr[j] = ' ';
            i += 1;
            }
        }
        else if (data->prompt[i] == '<')
        {
            if (data->prompt[i + 1] != '<')
            {
            newstr[j] = ' ';
            j++;
            newstr[j] = '<';
            j++;
            newstr[j] = ' ';
            }
            else if (data->prompt[i + 1] == '<')
            {
            newstr[j] = ' ';
            j++;
            newstr[j] = '<';
            j++;
            newstr[j] = '<';
            j++;
            newstr[j] = ' ';
            i += 1;
            }
        }
        else
            newstr[j] = data->prompt[i];
        j++;
        i++;
    }
    // printf("newstr = %s\n", newstr);
    return (newstr);
}

//Count the number of redirection (times 2) for ft_expend
int     ft_count(char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i] && str[i] != '\0')
    {
        if (str[i] == '|')
            count += 2;
        while (ft_strncmp(&str[i], ">>", 2) == 0 ||
            ft_strncmp(&str[i], "<<", 2) == 0)
            {
                count += 2;
                i += 2;
            }
        if (str[i] == '>' || str[i] == '<')
            count += 2;
        if (str[i])
            i++;
    }
    return (count);
}

