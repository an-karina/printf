#include <stdio.h>
#include "ft_printf.h"

int		main()
{
	char	*s = "fhvjfkv";
	
	printf("|%11.10d|\n", -12);
	ft_printf("|%11.10d|\n\n", -12);

	printf("|%15.10d|\n", -12);
	ft_printf("|%15.10d|\n\n", -12);

	printf("|%15.10d|\n", 12);
	ft_printf("|%15.10d|\n\n", 12);

	printf("|%15.d|\n", 12);
	ft_printf("|%15.d|\n\n", 12);

	printf("|%1.15d|\n", 12);
	ft_printf("|%1.15d|\n\n", 12);

	printf("|%1.1d|\n", 12);
	ft_printf("|%1.1d|\n\n", 12);

	printf("|%1d|\n", 12);
	ft_printf("|%1d|\n\n", 12);

	printf("|%1d|\n", -12);
	ft_printf("|%1d|\n\n", -12);


	printf("9)|%010d|\n", -12);
	ft_printf("9)|%010d|\n\n", -12);

 	printf("|%-10d|\n", 12);
	ft_printf("|%-10d|\n\n", 12);


 	printf("|%-10d|\n", -12);
	ft_printf("|%-10d|\n\n", -12);


	printf("|%0-10d|\n", -12);
	ft_printf("|%0-10d|\n\n", -12);
	
	printf("|%010.0d|\n", -12);
	ft_printf("|%010.0d|\n\n", -12);

	//undefined
	printf("|%010-d|\n", -12);
	ft_printf("|%010-d|\n\n", -12);

	//undefined
	printf("|%010.-d|\n", -12);
	ft_printf("|%010.-d|\n\n", -12);

	printf("31) standart PRINTF : |%-.d|\n", 0);
 	ft_printf("31) my       PRINTF : |%-.d|\n\n", 0);

	printf("mine : |%d| |%.20d|\n", 2147483647, -2147483647 - 1);
 	ft_printf("Karisha<3 : |%d| |%.20d|\n", 2147483647, -2147483647 - 1);


return (0);
}