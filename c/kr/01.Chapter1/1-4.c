#include <stdio.h>

main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = -60;
	upper = 200;
	step = 20;

	printf("Celsius\tFahrenheit\n");
	celsius = lower;
	while (celsius <= upper) {
		fahr = (9.0/5.0) * celsius + 32.0;
		printf("%3.0f\t%6.2f\n", celsius, fahr);
		celsius += step;
	}
}
