#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#define ulint unsigned long long int


_Bool is_prime (ulint num)
{
	if (num == 1)
		return 0;
	else if ( num < 4 )
		return 1; // 2 and 3 are prime
	else if ( num % 2 == 0 )
		return 0;
	else if ( num < 9 )
		return 1; /* We have already excluded 4,6 and 8. */
	else if ( num % 3 == 0 )
		return 0;
	else
	{
		ulint root = sqrt (num); /* rounded to the greatest integer r so that r*r <=n */
		int f = 5;
		while (f <= root)
		{
			if (num % f == 0)
				return 0;
			if (num % (f+2) == 0)
				return 0;
			f += 6;
		}
	}
	return 1;
}
int main()
{
	ulint num;
	scanf ("%llu", &num);
	if(is_prime(num))
		puts("PRIME\n");
	else
		printf("NOT PRIME\n");
	printf("\n");

	return 0;
}

