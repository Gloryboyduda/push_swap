#include "push_swap.h"

/* int main()
{
	t_node **stack_a;
	t_node **stack_b;
	t_node *nodea1;
	t_node *nodea2;
	t_node *nodea3;
	t_node *nodeb1;
	t_node *nodeb2;
	t_node *nodeb3;


	stack_a = malloc(sizeof(t_node **));
	if (!stack_a)
		return(printf("malloc failed\n"));
	stack_b = malloc(sizeof(t_node **));
	if (!stack_b)
		return(printf("malloc failed\n"));
	nodea1 = ft_lstnew(90);
	nodea2 = ft_lstnew(30);
	nodea3 = ft_lstnew(5);

	*stack_a = nodea1;
	nodea1->next = nodea2;
	nodea2->next = nodea3;
	nodea3->next = NULL;

	nodeb1 = ft_lstnew(25);
	nodeb2 = ft_lstnew(63);
	nodeb3 = ft_lstnew(87);

	*stack_b = nodeb1;
	nodeb1->next = nodeb2;
	nodeb2->next = nodeb3;
	nodeb3->next = NULL;

	printf("stack_a   stack_b\nnode1: %d   node1: %d\nnode2: %d   node2: %d\nnode3: %d   node3: %d\n",nodea1->value, nodeb1->value, nodea2->value, nodeb2->value, nodea3->value, nodeb3->value);
	ss(stack_a, stack_b);
	printf("stack_a   stack_b\nnode1: %d   node1: %d\nnode2: %d   node2: %d\nnode3: %d   node3: %d\n",nodea1->value, nodeb1->value, nodea2->value, nodeb2->value, nodea3->value, nodeb3->value);
} */
int main(int ac, char **av)
{
	t_node *a;
	t_node *b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	init_stack(&a, av + 1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			lil_sort(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
}