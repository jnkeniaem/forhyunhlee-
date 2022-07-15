#include "pushswap.h"

#include <stdio.h>
void a_to_b(t_arg *parg, t_a *ptr_a, t_b *ptr_b, int chunk)
{
	int	i;

	i = 0;
	while (ptr_a->current)//pb하면 i++해줌
	{
		if (ptr_a->stack[ptr_a->front] <= i)
		{
			pb(parg, ptr_a, ptr_b);
			i++;
		}
		else if (ptr_a->stack[ptr_a->front] > i && ptr_a->stack[ptr_a->front] <= chunk + i)
		{
			pb(parg, ptr_a, ptr_b);
			rb(parg, ptr_b);
			i++;
		}
		else
		{
		// 	if (i < ptr_a->current / 2)
		// 		rra(parg, ptr_a);
		// 	else
				ra(parg, ptr_a);
		}
	}
}


void find_max(t_arg *parg, t_b *ptr_b, int size)//깊이!!!
{
	int	i;

	i = 0;
	while (i < ptr_b->current && ptr_b->stack[(ptr_b->front + i) % parg->total] != size)
		i++;
	while (i < ptr_b->current / 2 && i > 0)
	{
		rb(parg, ptr_b);
		i--;
	}
	while (i >= ptr_b->current / 2 && i <= size)
	{
		rrb(parg, ptr_b);
		i++;
	}
}

void b_to_a(t_arg *parg, t_a *ptr_a, t_b *ptr_b)
{
	int	size;

	size = ptr_b->current -1;
	while (ptr_b->current)
	{
		find_max(parg, ptr_b, size);
		pa(parg, ptr_a, ptr_b);
		size--;
		test_print_stack(ptr_a, ptr_b, parg);
	}
}

void if_exceed_5(t_arg *parg, t_a *ptr_a, t_b *ptr_b)
{
	int	chunk;

	chunk = 0.000000053 * ptr_a->current * ptr_a->current + 0.03 * ptr_a->current + 14.5;
	a_to_b(parg, ptr_a, ptr_b, chunk);
	printf("after a_to_b\n");
	test_print_stack(ptr_a, ptr_b, parg);
	b_to_a(parg, ptr_a, ptr_b);
}