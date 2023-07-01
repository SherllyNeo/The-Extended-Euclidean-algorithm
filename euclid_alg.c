#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int extended_alg(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    int _x, _y;
    int gcd = extended_alg(b % a, a, &_x, &_y);

    *x = _y - (b/a) * _x;
    *y = _x;

    return gcd;
}



int main(int argc, char** argv) {

if (argc<3) {
printf("Please tyoe in 2 values\n");
exit(1);
}
int val_1 = atoi(argv[1]);
int val_2 = atoi(argv[2]);

if (val_2 > val_1) {
	/* Always make sure val_1 is the largest */
	int tmp;
	tmp = val_1;
	val_1 = val_2;
	val_2 = tmp;
}

int result = val_1;
int remainder = ( val_1 % val_2);
int multi = val_2;
int multiplier = val_1 / val_2;
int finished = -1;
int step = 1;
printf("step %d: %d = %d * %d + %d\n",step,result,multiplier,multi,remainder);
int prev_result;
int prev_remainder;
int prev_multi;
int prev_multiplier;
int gcd;

while (finished < 0) {
	step++;
	prev_result = result;
	prev_remainder = remainder;
	prev_multi = multi;
	prev_multiplier = multiplier;
	result = multi;
	multi = remainder;
	multiplier = (result / remainder);
	remainder = (result % remainder);

	printf("step %d: %d = %d * %d + %d\n",step,result,multiplier,multi,remainder);
	if (remainder == 0) {

		printf("finished: \n\n %d = %d * %d + %d\n",prev_result,prev_multiplier,prev_multi,prev_remainder);
		gcd = prev_remainder;
		finished = 1;
	}
}


printf("Found the gcd of %d and %d to be %d\n",val_1,val_2,gcd);
int x, y;

printf("solving %dx + %dy = %d\n",val_1,val_2,gcd);
extended_alg(val_1, val_2, &x, &y);
printf("x = %d, y = %d\n", x, y);
return 0;
}

