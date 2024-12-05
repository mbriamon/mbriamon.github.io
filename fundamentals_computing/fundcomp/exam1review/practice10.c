#include <stdio.h>
void disp(int[], int);
int fun1(int[], int);
void fun2(int[], int);

int main()
{
const int size = 5;
int i, a[size];
for (i = 0; i < size; i++)
a[i] = i*i+1;
disp(a, size);
printf("%d\n", fun1(a, size));
fun2(a, size);
disp(a, size);
fun2(a, size);
disp(a, size);
return 0;
}

void disp(int a[], int s)
{
int i;
for (i = 0; i < s; i++)
printf("%d ", a[i]);
printf("\n");;
}
int fun1(int a[], int s)
{
int i, m = 0;
for (i = 0; i < s; i++)
m += a[i];
return m;
}
void fun2(int a[], int s)
{
int i, z = a[0];
for (i = 0; i < s-1; i++)
a[i] = a[i+1];
a[s-1] = z;
}
