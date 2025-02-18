#include <stdio.h>
int main ()
{
    long long num;
    printf("\nType a number: ");
    scanf("%lld", &num);
    num += 1;
    printf("%lld", num);
    return 0;
}