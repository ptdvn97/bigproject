#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

char ten[255];
void main()
{
    struct Manage
{
    int mssv;
    int pass;
    char name[255];
};
    struct Manage sv;
    struct Manage check;
    int user,m,n,p,i,c,e,f,dem=0;
    char ten[255];
    printf("Login as...\n");
    printf("\t[1]Student [2]Lecturer [3]Guest [4]Register\n\t[5]Exit\n");
    printf("\tWhat is your choice ?: ");
    scanf("%d",&user);
    FILE *fptr;
    switch(user)
    {
        case 1: case 2:
        {
            Log:
            {
                fptr=fopen("List.dat","rb");
                printf("Enter your account:\n");
                printf("ID:");
            }
                scanf("%d",&sv.mssv );
                while(fread(&check,sizeof(struct Manage),1,fptr))
                {
                    if(check.mssv==sv.mssv)
                    {
                        dem++;
                        break;
                    }
                }
                if(dem==1)
                {
                    printf("ID corrects !\n");
                    printf("Password : ");
                    scanf("%d",&sv.pass);
                    if(sv.pass==check.pass)
                        {
                            printf("Login success !\n");
                            printf("Welcome %s !\n",check.name);
                            printf("Please enter !");
                            getch();
                            dem=0;
                            rewind(fptr);
                            fclose(fptr);
                            system("cls");
                            mainlect();
                            break;
                        }
                    else
                    {
                        printf("wrong password, press [1] to try again, [2] to exit.");
                        scanf("%d",&e);
                        switch(e)
                            {
                            case 1:
                                dem=0;
                                rewind(fptr);
                                goto Log;
                                break;
                            case 2:
                                dem=0;
                                rewind(fptr);
                                printf("bye!");
                                break;
                            }
                    }
                }
                else
                {
                    printf("Wrong user ID, press [1] to try again, [2] to return menu.");
                    scanf("%d",&f);
                    switch(f)
                        {
                            case 1:
                                goto Log;
                                break;
                            case 2:
                                system("cls");
                                main();
                                break;
                        }
                }
        break;
        case 3:
        printf("You can enter without login\n");
        printf("There's nothing here for guest so...you know what i mean...\nPress the enter button pleaseee");
        getch();
        system("cls");
        main();
        break;
        case 4:
        printf("Enter number of student/teacher/professor: ");
        scanf("%d", &m);
        for ( i=0;i<m;i++)
            {
                fptr = fopen("List.dat", "ab+");
                CT:
                {
                printf("\nStudent/teacher/professor %d:\n", i+1);
                printf("  ID  : ");
                scanf ("%d", &sv.mssv);
                }
                while(fread(&check,sizeof(struct Manage),1,fptr))
                    {
                    if(sv.mssv==check.mssv)
                        {
                            dem++;
                        }
                    }
                    if(dem==0)
                    {
                        fflush(stdin);
                        printf("Password: ");
                        scanf("%d", &sv.pass);
                        fflush(stdin);
                        printf("Your name is: ");
                        gets(sv.name);
                        fwrite(&sv,sizeof(struct Manage),1,fptr);
                        rewind(fptr);
                        dem=0;
                        printf("Account created !.");
                        getch();
                    }
                    else
                    {
                        system("cls");
                        printf("ID already used.\n");
                        rewind(fptr);
                        dem=0;
                        printf("press [1] to skip, [2]to do again, [3] to return the menu: ");
                        scanf("%d",&c);
                        switch(c)
                        {
                        case 2:
                            goto CT;
                                break;
                        case 3:
                            fclose(fptr);
                            main();
                            break;
                        }
                    }
            fclose(fptr);
            }
            system("cls");
            main();
            break;
        case 5:
            exit(0);
            break;
    }
    }
}




int mainlect()
{
    int n;
    printf("Welcome to Student Management System. Please follow the instructions below !\n\n\n");
    printf("\t1. Create new student record\n");
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
