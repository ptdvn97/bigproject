#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
<<<<<<< HEAD
#include <conio.h>
struct Manage
=======

struct Manage // Khai báo kiểu hàm struct Manage 7 biến
>>>>>>> 7742d9dea36e1b0181197cf1cff7b9095cc37667
{
    int mssv;
    char name[255];
    int mat;
    int phy;
    int chem;
    int lit;
    int bio;

};
void addID() /////////// Hàm thêm ID học sinh//////////////////////////////////////////////////////////////////////////////////////////////////////
{
    int i,m,c,dem=0;
    printf("Enter number of student : "); //////////// nhập số lượng HS
    scanf("%d",&m);
    struct Manage sv; ////////tạo biến sv mang kiểu hàm Manage.
    struct Manage check; /// tương tự
    FILE *fptr;
    fptr=fopen("student.dat","a+"); ////// mở file student.dat mode a+.
    for(i=0;i<m;i++) // chạy vòng lặp theo số lượng học sinh, từ 0 tới m.
    {
        CT:
        {
        printf("\nID of student %d : ",i+1); // Nhập ID hs thứ i+1
        scanf("%d",&sv.mssv);
        while(fread(&check,sizeof(struct Manage),1,fptr)) // vòng lặp kiểm tra xem ID đã có hay chưa, gán thông tin trong file vào biến check.
            {
            if(sv.mssv==check.mssv)  // sv.mssv là ID nhập từ phím, check.mssv là ID đọc trong file.
                {
                    dem++; // tạo biến đếm, mỗi lần trùng sẽ tăng thêm 1
                }
            }
        }
        if(dem==0) // nếu biến đếm = 0 tức là không trùng thì chạy bọn dưới.
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
                dem=0; // gán biến đếm về 0 sau mỗi vòng kiểm tra.
                rewind(fptr); // trả con trỏ về đầu file 
        }
        else // nếu đếm = 1, tức là bị trùng thì chạy bọn dưới.
        {
            system("cls"); // lệnh xóa màn hình cho đẹp.
            dem=0; // gán biến đếm về 0 sau mỗi vòng kiểm tra.
            rewind(fptr); // trả con trỏ về đầu file 
            printf("This ID already exists.\n");
            printf("Press 1 to skip, 2 to import again, 3 to return the menu: "); // tạo menu lựa chọn. 1 là bỏ qua thằng trước, nhập thằng kế tiếp, 2 là nhập lại từ đầu, 3 là trở về menu
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
void showData() // Hàm show cơ sở dữ liệu //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
           if(infor.mssv!=0)
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


void searchID()// Hàm search ID học sinh//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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


void exportTextFile()////Hàm export CSDL ra file text//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

void modify()// Hàm chỉnh sửa thông tin HS ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
    struct Manage dlt={0,"",0,0,0,0,0};
    struct Manage sv;
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
        {
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
            printf("The record is deleted !\n");
            getch();
            break;
        }
        else
        {
            system("cls");
            goto Aloha;
        }
    case 9:
        system("cls");
        main();
        break;
    }
    fseek(fp,sizeof(struct Manage)*record,SEEK_SET);
    fwrite(&sv,sizeof(struct Manage),1,fp);
    printf("\nDo you want to change something else(1:YES, 2:NO) ?: ");
    scanf("%d",&c);
    if(c==1)
    {
        system("cls");
        goto Aloha;
    }
    }
    }
    else
    {
        printf("ID not found.");
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
            main();
        }
    }
    fclose(fp);
    system("cls");
    main();
}
