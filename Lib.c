#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
struct Manage
{
    int mssv;
    char name[255];
    int mat;
    int phy;
    int chem;
    int lit;
    int bio;

};
void addID()
{
    int i,m,c,dem=0;
    printf("Enter number of student : ");
    scanf("%d",&m);
    struct Manage sv;
    struct Manage check;
    FILE *fptr;
    fptr=fopen("student.dat","a+");
    for(i=0;i<m;i++)
    {
        CT:
        {
        printf("\nID of student %d : ",i+1);
        scanf("%d",&sv.mssv);
        while(fread(&check,sizeof(struct Manage),1,fptr))
            {
            if(sv.mssv==check.mssv)
                {
                    dem++;
                }
            }
        }
        if(dem==0)
        {
                fflush(stdin);
                printf("Name of student %d :",i+1);
                gets(sv.name);
                printf("Math score %d: ",i+1);
                scanf("%d",&sv.mat);
                printf("Physic score %d: ",i+1);
                scanf("%d",&sv.phy);
                printf("Chemistry score %d: ",i+1);
                scanf("%d",&sv.chem);
                printf("Literature score %d: ",i+1);
                scanf("%d",&sv.lit);
                printf("Biology score %d: ",i+1);
                scanf("%d",&sv.bio);
                fwrite(&sv,sizeof(struct Manage),1,fptr);
                dem=0;
                rewind(fptr);
        }
        else
        {
            system("cls");
            dem=0;
            rewind(fptr);
            printf("This ID already exists.\n");
            printf("Press 1 to skip, 2 to import again, 3 to return the menu: ");
            scanf("%d",&c);
            if(c==2)
            {
                goto CT;
            }else if(c==3)
            {
                break;
            }
        }
    }
    system("cls");
    main();
    fclose(fptr);
    printf("\n");
}
void showData()
{
    int n;
    struct Manage infor;
    FILE *fptr;
    fptr=fopen("student.dat","r");
    if(fptr==NULL)
    {
        printf("Can not read the file");
    }
    else
    {
       printf("List of students\n");
       printf("\t%-16s%-30s%-16s%-16s%-16s%-16s%-16s\n","ID","Name","Math","Physic","Chemistry","Literature","Biology");
       while(fread(&infor,sizeof(struct Manage),1,fptr))
       {
           printf("\t%-16d%-30s%-16d%-16d%-16d%-16d%-16d\n",infor.mssv,infor.name,infor.mat,infor.phy,infor.chem,infor.lit,infor.bio);
       }
    }
    printf("enter 1 to return the menu: ");
    scanf("%d",&n);
    if(n==1)
    {
        system("cls");
        main();
    }
    else
        {
            exit(0);
        }

    return 0;
}


void searchID()
{
    struct Manage sv;
    int n,dem=0;
    char m;
    FILE *fptr=fopen("student.dat","r");
    printf("Enter the ID for searching: ");
    scanf("%d",&n);
    while(fread(&sv,sizeof(struct Manage),1,fptr))
    {
        if(sv.mssv==n)
        {
            printf("\t%-16s%-30s%-16s%-16s%-16s%-16s%-16s\n","ID","Name","Math","Physic","Chemistry","Literature","Biology");
            printf("\n\t%-16d%-30s%-16d%-16d%-16d%-16d%-16d\n",sv.mssv,sv.name,sv.mat,sv.phy,sv.chem,sv.lit,sv.bio);
            dem++;
        }
    }
    if(dem==0)
    {
        printf("\n\tID Not found\n");
    }
    fclose(fptr);
    printf("Enter 1 to search again, 2 to return the menu: ");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        searchID();
        break;
    case 2:
        system("cls");
        main();
        break;
    }
}


void exportTextFile()
{
    struct Manage mag;
    FILE *f1=fopen("student.dat","r" );
    FILE *f2=fopen("student.txt","w");
    fprintf(f2,"\t%-16s%-45s%-16s%-16s%-16s%-16s%-16s\n","ID","Name","Math","Physic","Chemistry","Literature","Biology");
    while(!feof(f1))
    {
        fread(&mag,sizeof(struct Manage),1,f1);
        if(!feof(f1))
            fprintf(f2,"\t%-16d%-45s%-16d%-16d%-16d%-16d%-16d\n",mag.mssv,mag.name,mag.mat,mag.phy,mag.chem,mag.lit,mag.bio);
    }
    fclose(f2);
    fclose(f1);
    return 0;
}

