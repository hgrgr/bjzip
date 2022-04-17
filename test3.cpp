#include <iostream>
using namespace std;

int main()
{
    string name;
    int arr[10];
    char carr[10];

    scanf("%d",&arr);
    scanf("%s",&carr);
    for(int i=0; i <10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for(int i=0; i <10; i++)
    {
        printf("%c ", carr[i]);
    }
    carr[3]='\0';
    printf("\n");
    printf("%s\n", carr);
    return 0;
}
