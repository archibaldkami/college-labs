#include <stdio.h>
#include <conio.h>
#include <math.h>

int main() {
    float p;
    float a;
    float b;
    float c;
    printf("\nВведіть сторону a: ");
    scanf( "%f", &a );
    printf("\nВведіть сторону b: ");
    scanf( "%f", &b );  
    printf("\nВведіть сторону c: ");
    scanf( "%f", &c );
    p = ( a + b + c ) / 2;
    printf("\nВисота по стороні a: %f", ( 2 * pow(( p * ( p-a ) * ( p-b ) * ( p - c )), 1/2.0) ) / a );
    printf("\nВисота по стороні b: %f", ( 2 * pow(( p * ( p-a ) * ( p-b ) * ( p - c )), 1/2.0) ) / b );
    printf("\nВисота по стороні c: %f", ( 2 * pow(( p * ( p-a ) * ( p-b ) * ( p - c )), 1/2.0) ) / c );
    printf("\nПлоща трикутника abc: %f", ( p * pow(( p * ( p-a ) * ( p-b ) * ( p - c )), 1/2.0) ));
}