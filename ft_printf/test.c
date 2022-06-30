#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

int		somme(int nb1, int nb2)
{
	return (nb1 * nb2);
}

int		produit(int nb1, int nb2)
{
	return (nb1 * nb2);
}

void	call_func(int (*func[])(int nb1, int nb2))
{

	func[0] = &somme;
	func[1] = &produit;
}

int		main()
{
	int		a;
	int (*func[2])(int nb1, int nb2);

	call_func(func);
	a = func[0](52, 2);
	printf("a = %d\n", a);
	return 0;
}
