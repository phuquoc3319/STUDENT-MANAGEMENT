#include "define.h"


/*
        TIEU LUAN NHOM
        DE TAI QUAN LI SINH VIEN
        TRUONG DAI HOC CAN THO CTU
        KHOA CONG NGHE

        Sinh vien thuc hien: 1.Ngo Phu Quoc
                             2.Nguyen Chi Tinh
                             3.Nguyen Duc Tan
                             4.Le Duc Tien

        Giao vien huong dan: Ts.Truong Quoc Bao

        Source code co su dung thu vien tu dinh nghia "define.h" kem theo duong link thu vien de compile

        1. hien thi thong tin sinh vien: OK
        2. nhap sinh vien OK
        3. thanh tich cua sinh vien OK
        4. sap xep sinh vien theo khoa hoc OK
        5. sap xep sinh viien theo mssv OK
        6. sap xep sinh vien theo nam sinh OK
        7. sap xep sinh vien theo GPA OK
        8. tim kiem sinh vien theo GPA OK
        9. tim kiem sinh vien theo khoa hoc OK
        10. tim kiem sinh vien theo nam sinh OK
        11. tim kiem sinh vien theo mssv OK




*/

// private variables
u32 n=0;


// define structure for student
typedef struct
{
   char id[8];
   char name[100];
   char address[1000];
   char parent[100];
   char department[1000];
   u32 birth;
   u32 year;
   float gpa ;
}student;

student s[1000];

// calling functions
static u32 student_init(void);
static void classify_student(void);
static u32 menu(void);
static void show_student(void);
static void sort_student_year(void);
static void sort_student_id(void);
static void find_student_name(void);
static void find_student_id(void);
static void find_student_birth(void);
static void find_student_course(void);
static void find_student_gpa(void);
static void bubble_sort(s32 a[], s32 n);
static void swap(s32 *a, s32 *b);
static void swap1(s32 a, s32 b);
static void sort_student_birth(void);
static void sort_student_gpa(void);





// Main program
int main(void)
{
    printf("\t\t\tCHAO MUNG BAN DEN VOI CHUONG TRINH QUAN LI SINH VIEN\n\n");
    static u32 pass;
    printf("\nVui long nhap password: ");
    scanf("%d",&pass);
    fflush(stdin);
    while(pass!=3355)
    {
        printf("Ban da nhap sai mat khau");
        printf("\nVui long nhap lai: ");
        scanf("%d",&pass);
    }
    if(pass==3355)
    {
        printf("Mat khau hop le\n");
        static u32 a;
        do
        {
            a=menu();
            switch(a)
            {
                case 1:
                    student_init();
                    break;
                case 2:
                    classify_student();
                    break;
                case 3:
                    show_student();
                    break;
                case 4:
                    sort_student_year();
                    break;
                case 5:
                    sort_student_id();
                    break;
                case 6:
                    sort_student_birth();
                    break;
                case 7:
                    sort_student_gpa();
                    break;
                case 8:
                    find_student_id();
                    break;
                case 9:
                    find_student_birth();
                    break;
                case 10:
                    find_student_course();
                    break;
                case 11:
                    find_student_gpa();
                    break;

                default:
                    printf("Ban da lua chon sai");
                    break;
            }
        }while(a!=15);
    }
//	else
//	{
//		printf("Mat khau da nhap sai!");
//		getch();
//	}
}


// Input Student information
static u32 student_init(void)
{
    u32 check;

    do
    {
            printf("\nVui long nhap thong tin sinh vien thu: %d",n+1);
            printf("\nHo ten sinh vien: ");
            fflush(stdin);
            gets(s[n].name);
            fflush(stdin);
            printf("Ma so sinh vien: ");
            fflush(stdin);
            gets(s[n].id);
            printf("Nhap nam sinh: ");
            fflush(stdin);
            scanf("%d",&s[n].birth);
            printf("Vui long nhap khoa hoc: ");
            fflush(stdin);
            scanf("%d",&s[n].year);
            printf("Vui long nhap diem trung binh: ");
            fflush(stdin);
            scanf("%f",&s[n].gpa);
            n++;
            fflush(stdin);
            printf("Ban co muon tiep tuc khong");
            printf("\n 1. Tiep tuc");
            printf("\n 2. Khong");
            printf("\n Ban Chon: ");
            scanf("%d",&check);
            fflush(stdin);
    }while(check==1);
    return 0;
}


// classify student by their GPA
static void classify_student(void)
{
    volatile u32 i;
    volatile u32 count=0;
    volatile u32 count1=0;
    volatile u32 count2=0;
    volatile u32 count3=0;
    for(i=0;i<n;i++)
    {
        if(s[i].gpa>3.2)
        {
            count++;
        }
        else if ((s[i].gpa>2.5)&&(s[i].gpa<3.2))
        {
            count1++;
        }
        else if ((s[i].gpa>2.0)&&(s[i].gpa<2.5))
        {
            count2++;
        }
        else if((s[i].gpa<1.0))
        {
            count3++;
        }
    }
    printf("\nSO LUONG HOC SINH GIOI LA: %d",count);
    printf("\nSO LUONG HOC SINH KHA LA: %d",count1);
    printf("\nSO LUONG HOC SINH TRUNG BINH LA: %d",count2);
    printf("\nSO LUONG HOC SINH YEU LA: %d",count3);
}

// display selection menu
static u32 menu(void)
{
    printf("\n\n **********  VUI LONG CHON MUC CAN QUAN LI  	************");
    printf("\n **********  1.NHAP SINH VIEN                   ************");
    printf("\n **********  2.THANH TICH CUA SINH VIEN         ************");
    printf("\n **********  3.HIEN THI THONG TIN SINH VIEN  	************");
    printf("\n **********  4.SAP XEP SINH VIEN TU NHO DEN LON THEO KHOA HOC");
    printf("\n **********  5.SAP XEP SINH VIEN THEO MSSV 	************");
    printf("\n **********  6.SAP XEP SINH VIEN THEO NAM SINH  ************");
    printf("\n **********  7.SAP XEP SINH VIEN THEO GPA 	************");
    printf("\n **********  8.TIM SINH VIEN THEO MSSV 		************");
    printf("\n **********  9.TIM SINH VIEN THEO NAM SINH 	************");
    printf("\n **********  10.TIM SINH VIEN THEO KHOA HOC 	************");
    printf("\n **********  11.TIM KIEM SINH VIEN THEO GPA	************");
    printf("\n\n VUI LONG CHON MUC: ");

    static u32 select=0;
    scanf("%d",&select);
    fflush(stdin);
    return select;
}

// show all student
static void show_student(void)
{
    printf("\n+------+------------------------------------+----------+-------+-----+-------+");
    printf("\n|----- +               DANH SACH SINH VIEN             |---------------------|");
    printf("\n+------+------------------------------------+----------+-------+-----+-------+");
    printf("\n %-20s %-20s %-20s %-20s %-20s \n","Sinh vien","MSSV","Nam sinh","Khoa Hoc","Diem Trung Binh");
    printf("\n+------+------------------------------------+----------+-------+-----+-------+");

    volatile u32 k;
    for(k=0;k<n;k++)
    {
        printf("\n%-20s %-20s %-20d %-20d %0.2f \n",s[k].name,s[k].id,s[k].birth,s[k].year,s[k].gpa);

    }
}


// sort by course
static void sort_student_year(void)
{

    volatile u32 i;
    volatile u32 j;
    student tmp;

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(s[j].year>s[j+1].year)
            {
                tmp = s[j];
                s[j] = s[j+1];
                s[j+1] = tmp;
            }
        }
    }


    printf("\n+------+------------------------------------+----------+-------+-----+-------+");
    printf("\n|----- +               DANH SACH SINH VIEN             |---------------------|");
    printf("\n+------+------------------------------------+----------+-------+-----+-------+");
    printf("\n %-20s %-20s %-20s %-20s %-20s \n","Sinh vien","MSSV","Nam sinh","Khoa Hoc","Diem Trung Binh");
    printf("\n+------+------------------------------------+----------+-------+-----+-------+");
    for(i=0;i<n;i++)
    {
        printf("\n%-20s %-20s %-20d %-20d %0.2f \n",s[i].name,s[i].id,s[i].birth,s[i].year,s[i].gpa);
    }
}

// sort student by birth
static void sort_student_birth(void)
{
    volatile u32 i;
    volatile u32 j;
    student tmp;

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(s[j].birth>s[j+1].birth)
            {
                tmp = s[j];
                s[j] = s[j+1];
                s[j+1] = tmp;

            }
        }
    }

    printf("\n+------+------------------------------------+----------+-------+-----+-------+");
    printf("\n|----- +               DANH SACH SINH VIEN             |---------------------|");
    printf("\n+------+------------------------------------+----------+-------+-----+-------+");
    printf("\n %-20s %-20s %-20s %-20s %-20s \n","Sinh vien","MSSV","Nam sinh","Khoa Hoc","Diem Trung Binh");
    printf("\n+------+------------------------------------+----------+-------+-----+-------+");
    for(i=0;i<n;i++)
    {
        printf("\n%-20s %-20s %-20d %-20d %0.2f \n",s[i].name,s[i].id,s[i].birth,s[i].year,s[i].gpa);
    }
}


// sort student by id
static void sort_student_id(void)
{
    u32 i,j,min;
    student tmp;
    for(i=0;i<n;i++)
              {
                              min=i;
                              for(j=i+1;j<n;j++)
                              {
                                                if ((strlen(s[j].id)<strlen(s[min].id))||
                                                ((strlen(s[j].id)==strlen(s[min].id)) &&(strcmp(s[j].id,s[min].id) < 0)))
                                                min=j;
                              }
                              if(min!=i)
                              {
                                        tmp=s[i];
                                        s[i]=s[min];
                                        s[min]=tmp;
                              }
              }
    printf("\n+------+------------------------------------+----------+-------+-----+-------+");
    printf("\n|----- +           MA SINH VIEN DA DUOC SAP XEP        |---------------------|");
    printf("\n+------+------------------------------------+----------+-------+-----+-------+");
    printf("\n|----- +               DANH SACH SINH VIEN             |---------------------|");
    printf("\n+------+------------------------------------+----------+-------+-----+-------+");
    printf("\n %-20s %-20s %-20s %-20s %-20s \n","Sinh vien","MSSV","Nam sinh","Khoa Hoc","Diem Trung Binh");

    for (i=0;i<n;i++)
       {
           printf("\n%-20s %-20s %-20d %-20d %0.2f \n",s[i].name,s[i].id,s[i].birth,s[i].year,s[i].gpa);
       }
}


static void sort_student_gpa(void)
{
    volatile s32 i;
    volatile s32 j;
    student tmp;

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(s[j].gpa>s[j+1].gpa)
            {
                tmp = s[j];
                s[j] = s[j+1];
                s[j+1] = tmp;
            }
        }
    }

    printf("\n+------+------------------------------------+----------+-------+-----+-------+");
    printf("\n|----- +               DANH SACH SINH VIEN             |---------------------|");
    printf("\n+------+------------------------------------+----------+-------+-----+-------+");
    printf("\n %-20s %-20s %-20s %-20s %-20s \n","Sinh vien","MSSV","Nam sinh","Khoa Hoc","Diem Trung Binh");
    printf("\n+------+------------------------------------+----------+-------+-----+-------+");
    for(i=0;i<n;i++)
    {
        printf("\n%-20s %-20s %-20d %-20d %0.2f \n",s[i].name,s[i].id,s[i].birth,s[i].year,s[i].gpa);
    }
}

static void find_student_name(void)
{

}

static void find_student_id(void)
{
    char find[100];
    s32 i;
    printf("NHAP MSSV CAN TIM: ");
    scanf("%s",&find);
    for(i=0;i<n;i++)
    {
        if(strcmp(find,s[i].id)==0)
        {
            printf("\n+------+------------------------------------+----------+-------+-----+-------+");
            printf("\n %-20s %-20s %-20s %-20s %-20s \n","Sinh vien","MSSV","Nam sinh","Khoa Hoc","Diem Trung Binh");

            printf("\n%-20s %-20s %-20d %-20d %0.2f \n",s[i].name,s[i].id,s[i].birth,s[i].year,s[i].gpa);

        }
    }
    getch();
}

static void find_student_birth(void)
{
    u32 find;
    volatile u32 i;
    printf("\nNHAP NAM SINH CAN TIM: ");
    scanf("%d",&find);
    fflush(stdin);
    for(i=0;i<n;i++)
    {
        if(s[i].birth==find)
        {
            printf("\n+------+------------------------------------+----------+-------+-----+-------+");
            printf("\n %-20s %-20s %-20s %-20s %-20s \n","Sinh vien","MSSV","Nam sinh","Khoa Hoc","Diem Trung Binh");

            printf("\n%-20s %-20s %-20d %-20d %0.2f \n",s[i].name,s[i].id,s[i].birth,s[i].year,s[i].gpa);
        }
//		else
//		{
//			printf("\n+------+------------------------------------+----------+-------+-----+-------+");
//			printf("\nKHONG TIM THAY SINH VIEN THEO DIEU KIEN");
//		}

    }
}

static void find_student_course(void)
{
    u32 find;
    volatile u32 i;
    printf("\nNHAP KHOA HOC CAN TIM: ");
    scanf("%d",&find);
    fflush(stdin);
    for(i=0;i<n;i++)
    {
        if(find==s[i].year)
        {
            printf("\n+------+------------------------------------+----------+-------+-----+-------+");
            printf("\n %-20s %-20s %-20s %-20s %-20s \n","Sinh vien","MSSV","Nam sinh","Khoa Hoc","Diem Trung Binh");

            printf("\n%-20s %-20s %-20d %-20d %0.2f \n",s[i].name,s[i].id,s[i].birth,s[i].year,s[i].gpa);
        }
//		else
//		{
//			printf("\n+------+------------------------------------+----------+-------+-----+-------+");
//			printf("\nKHONG TIM THAY SINH VIEN THEO DIEU KIEN");
//		}
    }
}

static void find_student_gpa(void)
{
    float find;
    volatile u32 i;
    printf("\nNHAP GPA CAN TIM: ");
    scanf("%f",&find);
    fflush(stdin);
    for(i=0;i<n;i++)
    {
        if((find==s[i].gpa)||(find<s[i].gpa))
        {
            printf("\n+------+------------------------------------+----------+-------+-----+-------+");
            printf("\n %-20s %-20s %-20s %-20s %-20s \n","Sinh vien","MSSV","Nam sinh","Khoa Hoc","Diem Trung Binh");

            printf("\n%-20s %-20s %-20d %-20d %0.2f \n",s[i].name,s[i].id,s[i].birth,s[i].year,s[i].gpa);
        }
//		else
//		{
//			printf("\n+------+------------------------------------+----------+-------+-----+-------+");
//			printf("\nKHONG TIM THAY SINH VIEN THEO DIEU KIEN");
//		}
    }
}

static void bubble_sort(s32 a[], s32 n)
{
    volatile s32 i;
    volatile s32 j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(&a[j],&a[j+1]);
            }
        }
    }
}

static void swap(s32 *a, s32 *b)
{
    s32 tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

static void swap1(s32 a, s32 b)
{
    s32 tmp;
    tmp = a;
    a = b;
    b = tmp;

}
