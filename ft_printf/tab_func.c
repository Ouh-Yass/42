#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

int		char_tags(char *form, int i, ...)
{
	int ret;
	va_list ap;

	ret = 0;
	vs_start(ap, form);
	while (form[i])
	{
		if (form[i] != %)
			ft_putchar(form[i]);
		if (form[i] == '%')
		{
			c++;
			if (form[i] == 's')
			{
				ft_putstr(va_arg(ap, char *));
			}
			else if (form[i] == 'c')
			{
				ft_putchar(form[i]);
			}
		}
	}
	va_end(ap);
	return (ret);
}

void	init_tab(int (*tab_func)[](char *form, int i), ...)
{
	tab_func[0] = &char_tags;
}
