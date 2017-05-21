#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    int n;
    printf("\t1. Create new account\n");
    printf("\t2. Show data stored\n");
    printf("\t3. Searching for an account\n");
    printf("\t4. Modify the information\n");
    printf("\t5. Exit\n\n");
    CT:
        {
    printf("\tEnter your choice : ");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        system("cls");
        addID();
        break;
    case 2:
        system("cls");
        showData();
        break;
    case 3:
        system("cls");
        searchID();
        break;
    case 4:
        system("cls");
        modify();
        break;
    case 5:
        exit(0);
        break;
    default:
        printf("\tWrong selection\n");
        goto CT;
        break;
    }
    }
return 0;
}
