#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int size;
	t_list *cursor;

	cursor = begin_list;
	size = 0;
	while (cursor)
	{
		size++;
		cursor = cursor->next;
	}
	return(size);
}
