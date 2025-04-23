#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *cursor;
	t_list *last;
	
	if (!*begin_list)
	{
		*begin_list = ft_create_elem(data);
		return;
	}
	cursor = *begin_list;
	while (cursor->next)
		cursor = cursor->next;
	last = cursor;
	cursor = ft_create_elem(data);
	last->next = cursor;
}
