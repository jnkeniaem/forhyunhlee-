#include "pushswap.h"
#include <stdio.h>
void pa(t_arg *parg, t_a *ptr_a, t_b *ptr_b) // a에 뭔가 남아있을 경우와 없는 경우
{
	if (ptr_b->current == 0)
	{
		ft_putstr_fd("No more in stack b.\n", 1);
		return;
	}
	if (ptr_a->front == 0)
		ptr_a->front = parg->total - 1;
	else
		ptr_a->front = (ptr_a->front - 1) % parg->total;
	ptr_a->stack[ptr_a->front] = ptr_b->stack[ptr_b->front];
	(ptr_b->current)--;
	(ptr_a->current)++;
	put_instruction("pa");
	if (ptr_b->front == ptr_b->rear)
		return ;
	else
		ptr_b->front = (ptr_b->front + 1) % parg->total;
	
}

void pb(t_arg *parg, t_a *ptr_a, t_b *ptr_b)
{
	if (ptr_a->current == 0)
	{
		ft_putstr_fd("No more in stack a.\n", 1);
		return;
	}
	if (ptr_b->front == 0)
		ptr_b->front = parg->total -1;//조건문을 탈출하는 그런게 없으니까
	else
		ptr_b->front = (ptr_b->front - 1) % parg->total;
	ptr_b->stack[ptr_b->front] = ptr_a->stack[ptr_a->front];
	(ptr_a->current)--;
	(ptr_b->current)++;
	put_instruction("pb");
	if (ptr_a->front == ptr_a->rear)
		return;
	else
		ptr_a->front = (ptr_a->front + 1) % parg->total;
}