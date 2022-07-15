#include "pushswap.h"
//total을 current로 바꿔보겠음
void rra(t_arg *parg, t_a *ptr_a)
{
	int	temp;

	temp = ptr_a->stack[ptr_a->rear];
	if (ptr_a->front == 0)
		ptr_a->front = ptr_a->rear;
	else
		ptr_a->front = (ptr_a->front - 1) % parg->total;
	if (ptr_a->rear == 0)
		ptr_a->rear = parg->total - 1;
	else
		ptr_a->rear = (ptr_a->rear - 1) % parg->total;//if (rear == 0)
	ptr_a->stack[ptr_a->front] = temp;
	put_instruction("rra");
}

void rrb(t_arg *parg, t_b *ptr_b)//여기 건드림
{
	int	temp;

	temp = ptr_b->stack[ptr_b->rear];
	if (ptr_b->front == 0)
		ptr_b->front = parg->total -1;
	else
		ptr_b->front = (ptr_b->front - 1) % parg->total;
	if (ptr_b->rear == 0)
		ptr_b->rear = ptr_b-> current -1;
	else
		ptr_b->rear = (ptr_b->rear - 1) % parg->total;
	ptr_b->stack[ptr_b->front] = temp;
	put_instruction("rrb");
}

void rrr(t_arg *parg, t_a *ptr_a, t_b *ptr_b)
{
	rra(parg, ptr_a);
	rrb(parg, ptr_b);
	put_instruction("rrr");
}