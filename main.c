#include <stdio.h>
#include "ft_printf.h"

int		main()
{
	char	*s = "fhvjfkv";

	//printf("|%d|\n", 12);
	//printf("|%010d|\n", 12);
	//ft_printf("|%010d|\n", 12);
	printf("|%-214748364.5d|\n", 12);
	// ft_printf("|%-2147483647.5d|\n", 12);
	//printf("|%10.5d|\n", 12);
return (0);
}