char    *ft_strlowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

int	ft_firstletter(int i, char *str)
{		
	if (i == 0)
	{
		if(!(str[i] >= 'a' && str[i] <= 'z'))
			return (0);
		else 
			return (1);
	}
	else
	{
		if(!((str[i - 1] >= 'a' && str[i - 1] <= 'z') ||
		(str[i - 1] >= '0' && str[i - 1] <= '9') ||
		(str[i - 1] >= 'A' && str[i - 1] <= 'Z')))
		{
			if((str[i] >= 'a' && str[i] <= 'z'))
				return (1);
			return (0);
		}
		else
			return (0);
	}
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int firstletter;

	i = 0;
	firstletter = 0;

	str = ft_strlowercase(str);
	while(str[i])
	{
		firstletter = ft_firstletter(i, str);

		if ((str[i] >= 'a' && str[i] <= 'z') && firstletter)
		{
			str[i] -= 32;
		}
		i++;
	}
	
	return(str);
}
