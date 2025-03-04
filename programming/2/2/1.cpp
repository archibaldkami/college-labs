
#include <iostream.h>
#include <conio.h>
int main()
{
const int n=5, m=5;
int a[n][m];
int i, j;
//Введення масиву a
cout << "Input massiv A\n";
for (i=0; i<n; i++)
{
for (j=0 ; j <m ; j++)
{
cout << "a[" << i << "][" << j << "]=";
cin >> a[i][j];
}
}
//Виведення масиву А у вигляді матриці
cout << "Massiv A\n";
for (i=0; i<n; i++)
{
for (j=0; j<m; j++)
{
cout << a[i][j] << "\t";
}
cout << "\n";
}
//Виведення заштрихованої області масиву на екран
cout << "Massiv s zashtrihovaniy oblasti:\n";
for (i=0; i<n; i++)
{
for (j=0; (j<=i)&&(i<=n/2); j++)
//вверхня половина заштрихованої області
{
cout << a[i][j] << "\t"; }
for (j=0; (j<m-i)&&(i>n/2); j++)
//нижня половина заштрихованої області
{
cout << a[i][j] << "\t";
}
cout << "\n";
}
getch();
return 0;
}