#include <stdio.h>
#include <conio.h>
#include <process.h>

struct Student
{
    int rollno;
    char name[100];
    int p_marks, c_marks, m_marks, e_marks, cs_marks;
    float percentage;
    char grade;
    int std;
} student;
FILE *fptr;

void gotoxy(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}

void input_student()
{
    fptr = fopen("student.dat", "ab");
    printf("\nPlease Enter The New Details of student \n");
    printf("\nEnter The roll number of student ");
    scanf("%d", &student.rollno);
    fflush(stdin);
    printf("\n\nEnter The Name of student ");
    gets(student.name);
    printf("\nEnter The marks in Physics out of 100 : ");
    scanf("%d", &student.p_marks);
    printf("\nEnter The marks in Chemistry out of 100 : ");
    scanf("%d", &student.c_marks);
    printf("\nEnter The marks in Maths out of 100 : ");
    scanf("%d", &student.m_marks);
    printf("\nEnter The marks in English out of 100 : ");
    scanf("%d", &student.e_marks);
    printf("\nEnter The marks in Computer Science out of 100 : ");
    scanf("%d", &student.cs_marks);
    student.percentage = (student.p_marks + student.c_marks + student.m_marks + student.e_marks + student.cs_marks) / 5.0;
    if (student.percentage >= 80)
        student.grade = 'A';
    else if (student.percentage >= 60 && student.percentage < 80)
        student.grade = 'B';
    else if (student.percentage >= 45 && student.percentage < 60)
        student.grade = 'C';
    else if (student.percentage >= 33 && student.percentage < 45)
        student.grade = 'D';
    else
        student.grade = 'F';
    fwrite(&student, sizeof(student), 1, fptr);
    fclose(fptr);
    printf("\n\n STUDENT RECORD HAS BEEN CREATED ");
}

void display_all()
{
    printf("\n\n\n\t\t DISPLAY ALL RECORD !!\n\n");
    fptr = fopen("student.dat", "rb");
    while ((fread(&student, sizeof(student), 1, fptr)) > 0)
    {
        printf("\nRoll Number of Student : %d", student.rollno);
        printf("\nName of student : %s", student.name);
        printf("\nMarks in Physics : %d", student.p_marks);
        printf("\nMarks in Chemistry : %d", student.c_marks);
        printf("\nMarks in Maths : %d", student.m_marks);
        printf("\nMarks in English : %d", student.e_marks);
        printf("\nMarks in Computer Science : %d", student.cs_marks);
        printf("\nPercentage of student is  : %.2f", student.percentage);
        printf("\nGrade of student is : %c", student.grade);
        printf("\n\n====================================\n");
    }
    fclose(fptr);
}
void display_sp(int n)
{
    int flag = 0;
    fptr = fopen("student.dat", "rb");
    while ((fread(&student, sizeof(student), 1, fptr)) > 0)
    {
        if (student.rollno == n)
        {
            printf("\nRoll number of student : %d", student.rollno);
            printf("\nName of Student : %s", student.name);
            printf("\nMarks in Physics : %d", student.p_marks);
            printf("\nMarks in Chemistry : %d", student.c_marks);
            printf("\nMarks in Maths : %d", student.m_marks);
            printf("\nMarks in English : %d", student.e_marks);
            printf("\nMarks in Computer Science : %d", student.cs_marks);
            printf("\nPercentage of student is  : %.2f", student.percentage);
            printf("\nGrade of student is : %c", student.grade);
            flag = 1;
        }
    }
    fclose(fptr);
    if (flag == 0)
        printf("\n\nRecord does not exist");
}

void modify_student()
{
    int no, found = 0;
    printf("\n\n\tTo Modify ");
    scanf("%d", &no);
    fptr = fopen("student.dat", "rb+");
    while ((fread(&student, sizeof(student), 1, fptr)) > 0 && found == 0)
    {
        if (student.rollno == no)
        {
            printf("\nRoll number of student : %d", student.rollno);
            printf("\nName of student : %s", student.name);
            printf("\nMarks in Physics : %d", student.p_marks);
            printf("\nMarks in Chemistry : %d", student.c_marks);
            printf("\nMarks in Maths : %d", student.m_marks);
            printf("\nMarks in English : %d", student.e_marks);
            printf("\nMarks in Computer Science : %d", student.cs_marks);
            printf("\nPercentage of student is  : %.2f", student.percentage);
            printf("\nGrade of student is : %c", student.grade);
            printf("\nPlease Enter The New Details of student \n");
            printf("\nEnter The roll number of student ");
            scanf("%d", &student.rollno);
            fflush(stdin);
            printf("\n\nEnter The Name of student ");
            gets(student.name);
            printf("\nEnter The marks in physics out of 100 : ");
            scanf("%d", &student.p_marks);
            printf("\nEnter The marks in chemistry out of 100 : ");
            scanf("%d", &student.c_marks);
            printf("\nEnter The marks in maths out of 100 : ");
            scanf("%d", &student.m_marks);
            printf("\nEnter The marks in english out of 100 : ");
            scanf("%d", &student.e_marks);
            printf("\nEnter The marks in computer science out of 100 : ");
            scanf("%d", &student.cs_marks);
            student.percentage = (student.p_marks + student.c_marks + student.m_marks + student.e_marks + student.cs_marks) / 5.0;
            if (student.percentage >= 80)
                student.grade = 'A';
            else if (student.percentage >= 60 && student.percentage < 80)
                student.grade = 'B';
            else if (student.percentage >= 45 && student.percentage < 60)
                student.grade = 'C';
            else if (student.percentage >= 33 && student.percentage < 45)
                student.grade = 'D';
            else
                student.grade = 'F';
            fseek(fptr, -(long)sizeof(student), 1);
            fwrite(&student, sizeof(student), 1, fptr);
            printf("\n\n\t Record Updated");
            found = 1;
        }
    }
    fclose(fptr);
    if (found == 0)
        printf("\n\n Record does not exist ");
}

void delete_student()
{
    int no;
    FILE *fptr2;

    printf("\n\n\n\tDelete Record");
    printf("\n\nPlease Enter The roll number of student You Want To Delete");
    scanf("%d", &no);
    fptr = fopen("student.dat", "rb");

    fptr2 = fopen("Temp.dat", "wb");
    rewind(fptr);
    while ((fread(&student, sizeof(student), 1, fptr)) > 0)
    {
        if (student.rollno != no)
        {
            fwrite(&student, sizeof(student), 1, fptr2);
        }
    }
    fclose(fptr2);
    fclose(fptr);
    remove("student.dat");
    rename("Temp.dat", "student.dat");
    printf("\n\n\tRecord Deleted ..");
}

void class_result()
{
    fptr = fopen("student.dat", "rb");
    if (fptr == NULL)
    {
        printf("ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Entry Menu to create File");
        printf("\n\n\n Program is closing ....");
        getch();
        exit(0);
    }

    printf("\n\n\t\tALL STUDENTS RESULT \n\n");
    printf("====================================================\n");
    printf("R.No.  Name       P   C   M   E   CS  Percentage   Grade\n");
    printf("====================================================\n");

    while ((fread(&student, sizeof(student), 1, fptr)) > 0)
    {
        printf("%-6d %-10s %-3d %-3d %-3d %-3d %-3d %-3.2f  %-1c\n", student.rollno, student.name, student.p_marks, student.c_marks, student.m_marks, student.e_marks, student.cs_marks, student.percentage, student.grade);
    }
    fclose(fptr);
}

void result()
{
    int ans, rno;
    char ch;
    
    printf("\n\n\nRESULT MENU");
    printf("\n\n\n1. Class Result\n\n2. Student Report Card\n\n3.Back to Main Menu");
    printf("\n\n\nEnter Choice (1-3)? ");
    scanf("%d", &ans);
    switch (ans)
    {
    case 1:
        class_result();
        break;
    case 2:
    {
        do
        {
            char ans;
            
            printf("\n\nEnter Roll Number Of Student : ");
            scanf("%d", &rno);
            display_sp(rno);
            printf("\n\nDo you want to See More Result (y/n)?");
            scanf("%c", &ans);
        } while (ans == 'y' || ans == 'Y');
        break;
    }
    case 3:
        break;
    default:
        printf("\a");
    }
}

void intro()
{
    
    gotoxy(35, 11);
    printf("STUDENT");
    gotoxy(33, 14);
    printf("REPORT CARD");
    gotoxy(35, 17);
    printf("PROJECT");
}

void entry_menu()
{
    char ch2;
    
    printf("\n\n\n\tENTRY MENU");
    printf("\n\n\t1.CREATE STUDENT RECORD");
    printf("\n\n\t2.DISPLAY ALL STUDENTS RECORDS");
    printf("\n\n\t3.SEARCH STUDENT RECORD ");
    printf("\n\n\t4.MODIFY STUDENT RECORD");
    printf("\n\n\t5.DELETE STUDENT RECORD");
    printf("\n\n\t6.BACK TO MAIN MENU");
    printf("\n\n\tPlease Enter Your Choice (1-6) ");
    ch2 = getche();
    switch (ch2)
    {
    case '1':
        input_student();
        break;
    case '2':
        display_all();
        break;
    case '3':
    {
        int num;
        
        printf("\n\n\tPlease Enter The roll number ");
        scanf("%d", &num);
        display_sp(num);
    }
    break;
    case '4':
        modify_student();
        break;
    case '5':
        delete_student();
        break;
    case '6':
        break;
    default:
        printf("\a");
        entry_menu();
    }
}

void main()
{
    char ch;
    intro();
    do
    {
        
        printf("\n\n\n\tMAIN MENU");
        printf("\n\n\t01. RESULT MENU");
        printf("\n\n\t02. ENTRY/EDIT MENU");
        printf("\n\n\t03. EXIT");
        printf("\n\n\tPlease Select Your Option (1-3) ");
        ch = getche();
        switch (ch)
        {
        case '1':            
            result();
            break;
        case '2':
            entry_menu();
            break;
        case '3':
            exit(0);
        default:
            printf("\a");
        }
    } while (ch != '3');
}