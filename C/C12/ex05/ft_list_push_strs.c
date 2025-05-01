#include "ft_list.h"

t_list	*t_list_push_strs(int size, char **strs)
{
	int i;
	t_list *list; // head node 
	t_list *new; // new node

	i = 0;
	list = (void *) 0;
	while (i < size)
	{
		new = ft_create_elem(strs[i]);
		if (!new)
			return ((void *) 0);
		new->next = list;
		list = new;
		i++;
		
	}
	return (list);
}
