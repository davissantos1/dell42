#include <stdlib.h>
#include <stdio.h>

int	ft_is_sep(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}
int	ft_word_count(char *str, char *charset)
{
	int words;
	int sep;
	int i;
	
	words = 0;
	i = 0;
	sep = 0;
	if (!ft_is_sep(str[0], charset))
		words++;
	while(str[i])
	{
		if ((ft_is_sep(str[i], charset)) && str[i + 1])
		{
			sep = 1;
			if (!ft_is_sep(str[i + 1], charset))
				words++;
		}
		i++;	
	}
	if (!sep)
		return (0);
	return (words);
}
char	ft_word_dup_aux(char *str, char *charset, int word_index, int *cursor)
{
	int i;
	int size;
	int index;
	
	i = 0;
	index = word_index;
	size = ft_word_count(str, charset) - 1;
	while (str[i] && ft_is_sep(str[i], charset))
		i++;
	while (word_index && str[i])
	{
		if (ft_is_sep(str[i], charset) && str[i + 1])
		{
			word_index--;
			if(ft_is_sep(str[i + 1], charset))
				word_index++;
		}
		i++;
	}
	*cursor = i;
	if (size != index)
	{
		while (!ft_is_sep(str[i], charset))
			i++;
		return (str[i]);
	}
	return (str[i - 1]);
}
char	*ft_word_dup(char *str, char *charset, int word_index)
{
	char *result;
	int start;
	char sep;
	int i;
	
	sep = ft_word_dup_aux(str, charset, word_index, &i);
	start = i;
	while (!ft_is_sep(str[i], charset) && str[i])
		i++;
	result = (char *)malloc((i - start + 3) * sizeof(char));
	if (!result)
		return (NULL);
	i = 1;
	result[0] = sep;
	while(!ft_is_sep(str[start], charset) && str[start])
	{
		result[i] = str[start];
		i++;
		start++;
	}
	result[i] = sep;
	i++;
	result[i] = '\0';
	return (result);
}
char	**ft_split(char *str, char *charset)
{
	char **result;
	int size;
	int i;
	
	i = 0;
	size = ft_word_count(str, charset);
	if (!str || !charset || !size)
	{
		result = (char **)malloc(sizeof(char *));
		if (!result)
			return (NULL);
		*result = NULL;
		return (result);
	}
	result = (char **)malloc((size + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (i < size)
	{
		result[i] = ft_word_dup(str, charset, i);
		i++;
	}
	result[i] = NULL;
	return (result);
}
int	main(void)
{
	char test[] = "hello, I am * a test,,, motherfucking** string**";
	char charset[] = ",*";

	char **ptr = ft_split(test, charset);
	while (*ptr)
	{
		printf("string: %s\n", *ptr);
		ptr++;
	}
	return (0);
}
