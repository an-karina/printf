#include <stdio.h>
#include "ft_printf.h"

int		main()
{
	// char	*s = "fhvjfkv";
	// int p;
	// printf("|%11.10d|\n", -12);
	// ft_printf("|%11.10d|\n\n", -12);

	// printf("|%15.10d|\n", -12);
	// ft_printf("|%15.10d|\n\n", -12);

	// printf("|%15.10d|\n", 12);
	// ft_printf("|%15.10d|\n\n", 12);

	// printf("|%15.d|\n", 12);
	// ft_printf("|%15.d|\n\n", 12);

	// printf("|%1.15d|\n", 12);
	// ft_printf("|%1.15d|\n\n", 12);

	// printf("|%1.1d|\n", 12);
	// ft_printf("|%1.1d|\n\n", 12);

	// printf("|%1d|\n", 12);
	// ft_printf("|%1d|\n\n", 12);

	// printf("|%1d|\n", -12);
	// ft_printf("|%1d|\n\n", -12);


	// printf("9)|%010d|\n", -12);
	// ft_printf("9)|%010d|\n\n", -12);

 	// printf("|%-10d|\n", 12);
	// ft_printf("|%-10d|\n\n", 12);


 	// printf("|%-10d|\n", -12);
	// ft_printf("|%-10d|\n\n", -12);


	// printf("|%0-10d|\n", -12);
	// ft_printf("|%0-10d|\n\n", -12);
	
	// printf("|%010.0d|\n", -12);
	// ft_printf("|%010.0d|\n\n", -12);

	// printf("|%010-d|\n", -12);
	// ft_printf("|%010-d|\n\n", -12);

	// printf("|%010.-d|\n", -12);
	// ft_printf("|%010.-d|\n\n", -12);

	// printf("31) standart PRINTF : |%-.d|\n", 0);
 	// ft_printf("31) my       PRINTF : |%-.d|\n\n", 0);

	// printf("|%d| |%.20d|\n", 2147483647, -2147483647 - 1);
 	// ft_printf("|%d| |%.20d|\n", 2147483647, -2147483647 - 1);

	// printf("|%-25p|\n", &p);
	// ft_printf("|%-25p|\n\n", &p);

	// printf("|%s|\n", "\0");
	// ft_printf("|%s|\n\n", "\0");

	// printf("|%s|\n", "a");
	// ft_printf("|%s|\n\n", "a");

	// printf("|%-25u|\n", -15);
	// ft_printf("|%-25u|\n\n", -15);

	// printf("|%X|\n", -15);
	// ft_printf("|%X|\n", -15);

	//printf("|%-05%|\n");
	//ft_printf("|%-05%|\n");

	// printf("%d\n", printf("helloworld\n"));
	//int i = ft_printf("helloworld\n");
	//printf("%d\n", i);
	printf("%d\n", printf("hello, %s.", "gavin"));
	int i;
	i = printf("hello, %s.", "gavin");
	printf("%d\n", i);
return (0);
}