#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list *cursor;
	
	cursor = begin_list;
	if (!begin_list)
		return ((void *) 0);
	while (cursor->next)
		cursor = cursor->next;
	return(cursor);
}
