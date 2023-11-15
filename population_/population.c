#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int start;
    do
    {
        start = get_float("Start Size: ");
    }while(start<9);

    int x=start;

    int end;
    do
    {
        end=get_float("End size: ");
    }while(end<start);

    int years=0;
    while(start<end)
    {
        start = start + (start/3)-(start/4);
        years++;
    }

    // printf("%i\n",start);
    printf("Years: %i\n",years);
}