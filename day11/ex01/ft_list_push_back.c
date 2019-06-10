#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *node;
	t_list *aux;

	aux = *begin_list;
	node =ft_create_elem(data);
	if (aux)
	{
		while ((aux)->next)
			aux = (aux)->next;
		(aux)->next = node;
	}
	else
		*begin_list = node;

}
