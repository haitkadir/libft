
/*
char *f(char *s){
    int i = 0;
    while(s[i]){
        s[i] = ft_toupper(s[i]);
        i++;
    }
    return(s);
}*/
/*
int main(){

    t_list *head;
    t_list *new;
    char str[] = "abcdefghijklmnopqrstuvwxyz";

    head = NULL;
    int i = 0;
    while(str[i]){
        new = ft_lstnew(strndup(&str[i], 1));
        ft_lstadd_back(&head, new);
        i++;
    }
    head = ft_lstmap(head, (void *)f, free);
    while(head != NULL){
        printf("%s\n", head->content);
        head = head->next;
    }


    return 0;
}*/

// int    main(void)
// {
//     const char s[15] = "lor\xff em ipsum";

//     printf("%p\t%s\n", ft_strrchr(s, '\xff'), ft_strrchr(s, '\xff'));
//     printf("%p\t%s\n", strrchr(s, '\xff'), strrchr(s, '\xff'));

//     return (0);
// }
#include "libft.h"
#include <stdio.h>
#include <string.h>

// int main(void){

//     int i = 0;
//     char *s;
//     size_t  len;
    
//     s = "<U+0000>         ";
//     len = ft_strlen(s);
    
//     ft_bzero(s, 12);
//     while (len)
//     {
//         printf("%c", s[i]);
//         i++;
//         len--;
//     }
//     return 0;
// }
static	size_t	words_counter(const char *s, char c)
{
	size_t	words;
	size_t	i;

	words = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			words += 1;
		i++;
	}
	return (words);
}

static	int	alloc_and_fill(char **arr, const char *s, size_t start, size_t len)
{
	char	*sub;
	int		i;

	sub = ft_substr(s, start, len);
	i = 0;
	if (!sub)
	{
		while (arr[i])
			free(arr[i++]);
		free(arr);
		return (0);
	}
	*arr = sub;
	return (1);
}

static	char	**spliter(const char *s, char c, char **new_arr)
{
	size_t	start;
	size_t	i;
	size_t	j;
	size_t	len;
	int		err_alloc;

	i = 0;
	j = 0;
	len = 0;
	start = 0;
	while (s[i])
	{
		if (s[i] != c)
			len++;
		if ((s[i] == c && s[i + 1] != c) || (s[i + 1] == 0))
		{
			err_alloc = alloc_and_fill(&new_arr[j++], s, start, len);
			if (err_alloc == 0)
				return (NULL);
			len = 0;
			start = (i) + 1;
		}
		i++;
	}
	return (new_arr);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	**final_result;
	char	**new_arr;

	str = ft_strtrim(s, &c);
	if (str == NULL || !s || !*s || !str[0])
	{
		final_result = ft_calloc(1, sizeof(char *));
		free(str);
		return (final_result);
	}
	new_arr = (char **)ft_calloc((words_counter(str, c) + 1), sizeof(char *));
	if (new_arr == NULL)
		return (0);
	final_result = spliter(str, c, new_arr);
	if (!final_result)
		final_result = ft_calloc(1, sizeof(char *));
	free(str);
	return (final_result);
}



int main(void){
    char **sp;
    sp = ft_split(",,,,hello,world,this,is,me,,", ',');
    int i = 0;
    while(sp[i]){
        printf("%s\n", sp[i]);
        i++;
    }
}