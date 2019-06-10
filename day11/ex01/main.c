#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data);

int	main(void)
{
	t_list *begin;
	t_list *node1;
	t_list *node2;
	void *data;
	data = NULL;
	begin = (t_list **)malloc(sizeof(t_list));
	node1 = ft_create_elem(data);
	node2 = ft_create_elem(data);
	begin = node1;
	(*node1).next = node2;

	ft_list_push_back(&begin, data);
}
