#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

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
void addID()/////////////////////
{
    int i,m,c,dem=0;
    printf("Enter number of student : "); ////////////
    scanf("%d",&m);
    struct Manage sv; ////////
    struct Manage check; /// tương tự
    FILE *fptr;
    fptr=fopen("student.dat","ab+"); //////
    for(i=0;i<m;i++) //
    {
        CT:
        {
        printf("\nID of student %d : ",i+1); //
        scanf("%d",&sv.mssv);
        while(fread(&check,sizeof(struct Manage),1,fptr)) //
            {
            if(sv.mssv==check.mssv)  //
                {
                    dem++; //
                }
            }
        }
        if(dem==0)
        {
                fflush(stdin);
                printf("Name of student:");
                gets(sv.name);
                printf("Math score: ");
                scanf("%d",&sv.mat);
                printf("Physic score: ");
                scanf("%d",&sv.phy);
                printf("Chemistry score: ");
                scanf("%d",&sv.chem);
                printf("Literature score: ");
                scanf("%d",&sv.lit);
                printf("Biology score: ");
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
    mainlect();
    fclose(fptr);
    printf("\n");
}
void showData() //  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
    int n;
    struct Manage infor;
    FILE *fptr;
    fptr=fopen("student.dat","rb");
    if(fptr==NULL)
    {
        printf("Can not read the file.\n");
        printf("Enter to return menu");
        fclose(fptr);
        getch();
        system("cls");
        mainlect();
    }
    else
    {
       printf("List of students\n");
       printf("\t%-16s%-30s%-16s%-16s%-16s%-16s%-16s\n","ID","Name","Math","Physic","Chemistry","Literature","Biology");
       while(fread(&infor,sizeof(struct Manage),1,fptr))
       {
           if(infor.mssv!=0)
           printf("\t%-16d%-30s%-16d%-16d%-16d%-16d%-16d\n",infor.mssv,infor.name,infor.mat,infor.phy,infor.chem,infor.lit,infor.bio);
       }
       fclose(fptr);
    printf("1: Return menu, 2: Backup database: ");
    scanf("%d",&n);
    if(n==1)
    {
        system("cls");
        mainlect();
    }
    else if(n==2)
        {
            system("cls");
            exportTextFile();
            printf("backup.txt created !\n");
            printf("backup.dat created !\n");
            printf("Enter to return menu. ");
            getch();
            system("cls");
            mainlect();
        }
    }
}


void searchID1()////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
    struct Manage sv;
    int n,dem=0;
    char m;
    FILE *fptr=fopen("student.dat","rb");
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
        system("cls");
        searchID1();
        break;
    case 2:
        system("cls");
        mainlect();
        break;
    }
}

void searchID2()////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
    struct Manage sv;
    int n,dem=0;
    char m;
    FILE *fptr=fopen("student.dat","rb");
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
        system("cls");
        searchID2();
        break;
    case 2:
        system("cls");
        mainstu();
        break;
    }
}

void exportTextFile()////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
    struct Manage mag;
    FILE *f1=fopen("student.dat","rb" );
    FILE *f2=fopen("backup.txt","w");
    FILE *f3=fopen("backup.dat","w");
    fprintf(f2,"\t%-16s%-45s%-16s%-16s%-16s%-16s%-16s\n","ID","Name","Math","Physic","Chemistry","Literature","Biology");
    while(fread(&mag,sizeof(struct Manage),1,f1))
    {
            if(mag.mssv!=0)
            {
                fprintf(f2,"\t%-16d%-45s%-16d%-16d%-16d%-16d%-16d\n",mag.mssv,mag.name,mag.mat,mag.phy,mag.chem,mag.lit,mag.bio);
                fwrite(&mag,sizeof(struct Manage),1,f3);
            }
    }
    fclose(f2);
    fclose(f1);
    fclose(f3);
    return 0;
}

void modify()// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
    struct Manage dlt={0,"",0,0,0,0,0};
    struct Manage sv;
    struct Manage check;
    int n,record=0,c,dem=0;
    FILE *fp=fopen("student.dat","rb+");
    Alibaba:
        {
            printf("Enter the ID of record: ");
            scanf("%d",&n);

    while(fread(&sv,sizeof(struct Manage),1,fp))
    {
        if(sv.mssv==n)
        {
            dem++;
            break;
        }
        record++;
    }
    }
    if(dem==1)
    {
    Aloha:
        {}
    printf("\t%-16s%-30s%-16s%-16s%-16s%-16s%-16s\n\n","ID","Name","Math","Physic","Chemistry","Literature","Biology");
    printf("\n\t%-16d%-30s%-16d%-16d%-16d%-16d%-16d\n\n",sv.mssv,sv.name,sv.mat,sv.phy,sv.chem,sv.lit,sv.bio);
    printf("What will be changed ?\n");
    printf("1. ID\n");
    printf("2. Name\n");
    printf("3. Math score\n");
    printf("4. Physic score\n");
    printf("5. Chemistry score\n");
    printf("6. Literature score\n");
    printf("7. Biology score\n");
    printf("8. Delete this record\n");
    printf("9. Return the menu\n");
    printf("\nEnter your selection: ");
    scanf("%d",&c);
    switch(c)
    {
    case 1:
        printf("New ID : ");
        scanf("%d",&sv.mssv);
        rewind(fp);
        while(fread(&check,sizeof(struct Manage),1,fp))
        {
            if(sv.mssv==check.mssv)
            {
                printf("ID already exists !: ");
                scanf("%d",&sv.mssv);
                rewind(fp);
            }
        }
        printf("ID has been changed !\n");
        break;
    case 2:
        fflush(stdin);
        printf("New Name : ");
        gets(sv.name);
        printf("Name has been changed !\n");
        break;
    case 3:
        printf("New Math score : ");
        scanf("%d",&sv.mat);
        printf("Score has been changed !\n");
        break;
    case 4:
        printf("New Physic score : ");
        scanf("%d",&sv.phy);
        printf("Score has been changed !\n");
        break;
    case 5:
        printf("New Chemistry score : ");
        scanf("%d",&sv.chem);
        printf("Score has been changed !\n");
        break;
    case 6:
        printf("New Literature score : ");
        scanf("%d",&sv.lit);
        printf("Score has been changed !\n");
        break;
    case 7:
        printf("New Biology score : ");
        scanf("%d",&sv.bio);
        printf("Score has been changed !\n");
        break;
    case 8:
        printf("Are you sure ?(1:YES 2:NO): ");
        scanf("%d",&c);
        if(c==1)
        {
            sv=dlt;
            printf("The record is deleted !");
            fseek(fp,sizeof(struct Manage)*record,SEEK_SET);
            fwrite(&sv,sizeof(struct Manage),1,fp);
            fclose(fp);
            getch();
            system("cls");
            mainlect();
            break;
        }
        else
        {
            system("cls");
            goto Aloha;
        }
    case 9:
        fclose(fp);
        system("cls");
        mainlect();
        break;
    }
    fseek(fp,sizeof(struct Manage)*record,SEEK_SET);
    fwrite(&sv,sizeof(struct Manage),1,fp);
    fclose(fp);
    printf("\nDo you want to change something else(1:YES, 2:NO) ?: ");
    scanf("%d",&c);
    if(c==1)
    {
        system("cls");
        FILE *fp=fopen("student.dat","rb+");
        goto Aloha;
    }
    }
    else
    {
        printf("ID not found.\n");
        printf("Press 1 to enter again, 2 to return the menu: ");
        scanf("%d",&c);
        if(c==1)
        {
            system("cls");
            rewind(fp);
            goto Alibaba;
        }
        else if(c==2)
        {
            system("cls");
            mainlect();
        }
    }
    fclose(fp);
    system("cls");
    mainlect();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void scholar()
{
    struct Manage sv;
    int n, GPA, dem=0;
    FILE *fptr = fopen("student.dat","rb");
    printf("Enter your ID: ");
    scanf("%d",&n);
    while(fread(&sv,sizeof(struct Manage),1,fptr))
    {
        if(sv.mssv == n)
        {
           printf("\t%-16s%-30s%-16s%-16s%-16s%-16s%-16s\n","ID","Name","Math","Physic","Chemistry","Literature","Biology");
           printf("\n\t%-16d%-30s%-16d%-16d%-16d%-16d%-16d\n",sv.mssv,sv.name,sv.mat,sv.phy,sv.chem,sv.lit,sv.bio);
           printf("GPA : %d\n",(sv.mat+sv.phy+sv.chem+sv.lit+sv.bio)/5);
           GPA = (sv.mat+sv.phy+sv.chem+sv.lit+sv.bio)/5;
           if ((GPA>=8)&&(sv.mat>=5)&&(sv.phy>=5)&&(sv.chem>=5)&&(sv.lit>=5)&&(sv.bio>=5))
            printf("\n YOU'VE GOT A SCHOLAR \n");
           else
           {
               printf("\n Course needed to retake: ");
               if (sv.mat<5) printf(" Maths ");
               if (sv.phy<5) printf(" Physics ");
               if (sv.chem<5) printf(" Chemistry ");
               if (sv.lit<5) printf(" Literature ");
               if (sv.bio<5) printf(" Biology ");
           }
           dem++;
        }
    }
    if(dem==0)
    {
        printf("\n\tID Not found\n");
    }
    fclose(fptr);
    printf("\nEnter 1 to search again, 2 to return the menu: ");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        system("cls");
        scholar();
        break;
    case 2:
        system("cls");
        mainstu();
        break;
    }
}

void listscholar()
{
    struct Manage list;
    int n;
    double GPA;
    FILE *fptr = fopen("student.dat","rb");
    if(fptr==NULL)
    {
        printf("Can not read the file.\n");
        printf("Enter to return menu");
        fclose(fptr);
        getch();
        system("cls");
        mainstu();
    }
    else
    {
        printf("\nList of student get scholar: \n");
        printf("\t%-16s%-30s%-16s\n","ID","Name","GPA");
        while(fread(&list,sizeof(struct Manage),1,fptr))
        {
            GPA = (list.mat+list.phy+list.chem+list.lit+list.bio)/5;
            if (GPA>=8)
                printf("\t%-16d%-30s%-16.2f\n",list.mssv,list.name,GPA);
        }
    }
    printf("enter to return menu");
    getch();
    fclose(fptr);
    system("cls");
    mainstu();
}
void best()
{
    struct Manage list;
    struct Manage stu;
    int n,math=0,lit=0,phy=0,chem=0,bio=0,GPA,best=0,a,b,c,d,e,f;
    FILE *fptr = fopen("student.dat","rb");
    if(fptr==NULL)
    {
        printf("Can not read the file.\n");
        printf("Enter to return menu");
        fclose(fptr);
        getch();
        system("cls");
        mainlect();
    }
    else
    {
        while(fread(&list,sizeof(struct Manage),1,fptr))
        {
            GPA = (list.mat+list.phy+list.chem+list.lit+list.bio)/5;
            if (GPA>=best)
            {
                best = GPA;
            }
            if (list.mat>=math)
            {
                math = list.mat;
            }
            if (list.phy>=phy)
            {
                phy = list.phy;
            }
            if (list.chem>=chem)
            {
                chem = list.chem;
            }
            if (list.lit>=lit)
            {
                lit = list.lit;
            }
            if (list.bio>=bio)
            {
                bio = list.bio;
            }
        }
    }
    printf("\nList of best student : \n");
    while(fread(&stu,sizeof(struct Manage),1,fptr))
    {
        GPA = (stu.mat+stu.phy+stu.chem+stu.lit+stu.bio)/5;
        printf("\nStudent with highest GPA: \n");
        printf("\t%-16s%-30s%-16s\n","ID","Name","GPA");
        if (GPA==best)
        {
            printf("\t%-16s%-30s%-16s\n",stu.mssv,stu.name,GPA);
        }
        printf("\nStudent with highest Math: \n");
        printf("\t%-16s%-30s%-16s\n","ID","Name","Math");
        if (stu.mat==math)
        {
            printf("\t%-16s%-30s%-16s\n",stu.mssv,stu.name,stu.mat);
        }
        printf("\nStudent with highest Physics: \n");
        printf("\t%-16s%-30s%-16s\n","ID","Name","Physics");
        if (stu.phy==phy)
        {
            printf("\t%-16s%-30s%-16s\n",stu.mssv,stu.name,stu.phy);
        }
        printf("\nStudent with highest Chemistry: \n");
        printf("\t%-16s%-30s%-16s\n","ID","Name","Chemistry");
        if (stu.chem==chem)
        {
            printf("\t%-16s%-30s%-16s\n",stu.mssv,stu.name,stu.chem);
        }
        printf("\nStudent with highest Literature: \n");
        printf("\t%-16s%-30s%-16s\n","ID","Name","Literature");
        if (stu.lit==lit)
        {
            printf("\t%-16s%-30s%-16s\n",stu.mssv,stu.name,stu.lit);
        }
        printf("\nStudent with highest Biology: \n");
        printf("\t%-16s%-30s%-16s\n","ID","Name","Biology");
        if (stu.bio==bio)
        {
            printf("\t%-16s%-30s%-16s\n",stu.mssv,stu.name,stu.bio);
        }
    }
    printf("enter to return menu");
    getch();
    fclose(fptr);
    system("cls");
    mainstu();
}
