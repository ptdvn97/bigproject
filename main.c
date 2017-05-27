#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
struct Manage
{
    int mssv;
    int mstu;
    int pass;
    char name[255];
};
void main()
{
    struct Manage sv;
    struct Manage tu;
    struct Manage check;
    struct Manage check2;
    int user,a,b,g,m,n,p,i,j,c,e,f,dem=0,dem1=0;
    printf("Login as...\n");
    printf("\t[1]Student [2]Lecturer [3]Guest [4]Student Register [5]Teacher Register\n\t [6]Exit\n");
    CunCon:
        {
        printf("\tWhat is your choice ?: ");
        scanf("%d",&user);
        }
    FILE *fptr;
    switch(user)
    {
        case 1:
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
                            printf("Enter Please !");
                            dem=0;
                            rewind(fptr);
                            getch();
                            system("cls");
                            mainstu();
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
        case 2:
        {
            Logtu:
            {
                fptr=fopen("tutor.dat","rb");
                printf("Enter your account:\n");
                printf("ID:");
            }
                scanf("%d",&tu.mstu );
                while(fread(&check2,sizeof(struct Manage),1,fptr))
                {
                    if(check2.mstu==tu.mstu)
                    {
                        dem1++;
                        break;
                    }
                }
                if(dem1==1)
                {
                    printf("ID corrects !\n");
                    printf("Password : ");
                    scanf("%d",&tu.pass);
                    if(tu.pass==check2.pass)
                        {
                            printf("Login success !\n");
                            printf("Welcome %s !\n",check2.name);
                            printf("Enter Please !");
                            dem1=0;
                            rewind(fptr);
                            getch();
                            system("cls");
                            mainlect();
                            break;
                        }
                    else
                    {
                        printf("wrong password, press [1] to try again, [2] to exit.");
                        scanf("%d",&b);
                        switch(b)
                            {
                            case 1:
                                dem1=0;
                                rewind(fptr);
                                goto Logtu;
                                break;
                            case 2:
                                dem1=0;
                                rewind(fptr);
                                printf("bye!");
                                break;
                            }
                    }
                }
                else
                {
                    printf("Wrong user ID, press [1] to try again, [2] to return menu.");
                    scanf("%d",&g);
                    switch(g)
                        {
                            case 1:
                                goto Logtu;
                                break;
                            case 2:
                                system("cls");
                                main();
                                break;
                        }
                }
        break;
        }
        case 3:
        printf("You can enter without login\n");
        printf("There's nothing here for guest so...you know what i mean...\nPress the enter button pleaseee");
        getch();
        system("cls");
        main();
        break;
        case 4:
        printf("Enter number of student: ");
        scanf("%d", &m);
        for ( i=0;i<m;i++)
            {
                fptr = fopen("List.dat", "ab+");
                CT:
                {
                printf("\nStudent %d:\n", i+1);
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
                        printf("His/her name is: ");
                        gets(sv.name);
                        fwrite(&sv,sizeof(struct Manage),1,fptr);
                        rewind(fptr);
                        dem=0;
                        main();
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
            break;
        case 5:
        printf("Enter number of teacher/professor: ");
        scanf("%d", &a);
        for ( j=0;j<a;j++)
            {
                fptr = fopen("tutor.dat", "ab+");
                TU:
                {
                printf("\nteacher/professor %d:\n", j+1);
                printf("  ID  : ");
                scanf ("%d", &tu.mstu);
                }
                while(fread(&check2,sizeof(struct Manage),1,fptr))
                    {
                    if(tu.mstu==check2.mstu)
                        {
                            dem1++;
                        }
                    }
                    if(dem1==0)
                    {
                        fflush(stdin);
                        printf("Password: ");
                        scanf("%d", &tu.pass);
                        fflush(stdin);
                        printf("His/her name is: ");
                        gets(tu.name);
                        fwrite(&tu,sizeof(struct Manage),1,fptr);
                        rewind(fptr);
                        dem=0;
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
                            goto TU;
                                break;
                        case 3:
                            fclose(fptr);
                            main();
                            break;
                        }
                    }
            fclose(fptr);
            }
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Wrong selection !\n");
            goto CunCon;
    }
    }
}



void mainlect()
{
    int n;
    printf("Welcome to Student Management System for Lecturer. Please follow the instructions below !\n\n\n");
    printf("\t1. Create new student record\n");
    printf("\t2. Show data stored\n");
    printf("\t3. Searching for an account\n");
    printf("\t4. Modify the information\n");
    printf("\t5. Exit\n\n");
    CT:
        {
    printf("\tEnter your choice : ");
    scanf("%d",&n);
        }
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
        searchID1();
        break;
    case 4:
        system("cls");
        modify();
        break;
    case 5:
        system("cls");
        main();
        break;
    default:
        printf("\tWrong selection\n");
        goto CT;
        break;
    }
}


void mainstu()
{
        int n;
    printf("Welcome to Student Management System for Student. Please follow the instructions below !\n\n\n");
    printf("\t1. Scholar\n");
    printf("\t2. Listscholar\n");
    printf("\t3. Best\n");
    printf("\t4. Search\n");
    printf("\t5. Exit\n\n");
    CT:
        {
    printf("\tEnter your choice : ");
    scanf("%d",&n);
        }
    switch(n)
    {
    case 1:
        system("cls");
        scholar();
        break;
    case 2:
        system("cls");
        listscholar();
        break;
    case 3:
        system("cls");
        best();
        break;
    case 4:
        system("cls");
        searchID2();
        break;
    case 5:
        system("cls");
        main();
        break;
    default:
        printf("\tWrong selection\n");
        goto CT;
        break;
    }
}


