#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("\t1. Create new account\n");
    printf("\t2. Read data alrealy stored\n");
    printf("\t3. Searching for an account\n");
    printf("\t4. ...\n");
    printf("\t5. Exit\n\n");
    CT:
        {
    printf("\tEnter your choice :");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        addID();
        break;
    case 2:
        showData();
        break;
    case 3:
        searchID();
        break;
    case 4:
        function4();
        break;
    case 5:
        break;
    default:
        printf("\tWrong selection\n");
        goto CT;
        break;
    }
    }
return 0;
}
