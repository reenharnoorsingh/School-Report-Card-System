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
    else if (student.percentage >=33 && student.percentage <45)
        student.grade = 'D';
    else
        student.grade = 'F';
    fwrite(&student, sizeof(student), 1,fptr);
    fclose(fptr);
    printf("\n\n STUDENT RECORD HAS BEEN CREATED ");
}
