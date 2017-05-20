#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("\t1. Create new account\n");
    printf("\t2. Show data stored\n");
    printf("\t3. Searching for an account\n");
    printf("\t4. Export the data\n");
    printf("\t5. Modify the information\n");
    printf("\t6. Exit\n\n");
    CT:
        {
    printf("\tEnter your choice : ");
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
        exportTextFile();
        break;
    case 6:
        exit(0);
        break;
    case 5:
        modify();
        break;
    default:
        printf("\tWrong selection\n");
        goto CT;
        break;
    }
    }
return 0;
}
