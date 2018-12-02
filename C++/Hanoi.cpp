#include <stdio.h>
int c = 0;
void move(char x, int n, char z)
{
    printf("%d. Move disk %d from %c to %c\n", ++c, n, x, z);
}
void hanoi(int n, char x, char y, char z)
{
    if(n == 1)
    {
        move(x, 1, z);
    }
    else
    {
        hanoi(n-1, x, z, y);
        move(x, n, z);
        hanoi(n-1, y, x, z);
    }
}
int main()
{
    char x = 'a', y = 'b', z = 'c';
    hanoi(3, x, y, z);
    return 0;
}
