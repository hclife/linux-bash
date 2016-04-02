#include <stdio.h>

main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	printf("The Fahrenheit to Celsius table:\n");
	printf("Fahrenheit\tCelsius\n");
	fahr = lower;
	while (fahr <= upper) {
		//celsius = (fahr - 32) * 5 / 9;
		//printf("%3d\t%6d\n", fahr, celsius);
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f\t\t%6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}
