#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;
int main()
{
char s[20], f[20], sr[20], a[20];
int l, ll;
cout << "\n Input stroky s:\n" ;
cin >> s;
cout << "Input stroky f:\n";
cin >> f;
l = strlen(s);
cout << "\n Dovzhina stroky s=" << l;
ll = strlen(f);
cout << "\n Dovzhina stroki f=" << ll;
strcat(s,f);
strcpy(sr,s);
cout << "\n Nova stroka " << sr;
strncpy(sr,"eeeeee",8);
cout << "\n Nova stroka = " << sr;
getch();
return 0;
}
