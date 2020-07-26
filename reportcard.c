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
    int flag =0;
    fptr = fopen("student.dat","rb");
    while ((freaad(&student,sizeof(student),1,fptr))>0)
    {
        if(student.rollno == n)
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
    if (flag ==0)\
        printf("\n\nRecord does not exist");
}

void modify_student()
{
    int no,found =0;
}