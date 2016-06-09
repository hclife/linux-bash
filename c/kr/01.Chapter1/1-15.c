/* Print Fahrenheit-Celsius table */
#include <stdio.h>

float calculate_celsius(float fahr)
{
	return (5.0/9.0)*(fahr-32.0);
}

main()
{
	int fahr;

	for (fahr = 0; fahr <= 300; fahr += 20)
		printf("%3d %6.1f\n", fahr, calculate_celsius(fahr));
}

