#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 3
#define MAX_EMAIL_LENGTH 47
#define MIN_AGE 17
#define MAX_AGE 22

struct student
{
  char name[50];
  char email[MAX_EMAIL_LENGTH];
  int age;
  int roll_no;
  char hostel_address[100];
};

struct student students[MAX_STUDENTS];
int student_count = 0;

// Function to add student information
void add_student(char name[], char email[], int age, int roll_no, char hostel_address[])
{
  strcpy(students[student_count].name, name);
  strcpy(students[student_count].email, email);
  students[student_count].age = age;
  students[student_count].roll_no = roll_no;
  strcpy(students[student_count].hostel_address, hostel_address);
  student_count++;
}

// Function to print the names of students with age 19
void print_students_with_age_19()
{
  printf("Students with age 19:\n");
  for (int i = 0; i < student_count; i++)
  {
    if (students[i].age == 19)
    {
      printf("%s\n", students[i].name);
    }
  }
}

// Function to print the names of students with email addresses starting with 'I' or 'T' and having even numbers
void print_students_with_email_IT_and_even()
{
  printf("Students with email addresses starting with 'I' or 'T' and having even numbers:\n");
  for (int i = 0; i < student_count; i++)
  {
    char first_letter = students[i].email[0];
    if ((first_letter == 'I' || first_letter == 'T') && (students[i].roll_no % 2 == 0))
    {
      printf("%s\n", students[i].name);
    }
  }
}

// Function to display details of a student with a given email
void display_student_details(char email[])
{
  for (int i = 0; i < student_count; i++)
  {
    if (strcmp(students[i].email, email) == 0)
    {
      printf("Name: %s\n", students[i].name);
      printf("Email: %s\n", students[i].email);
      printf("Age: %d\n", students[i].age);
      printf("Roll No: %d\n", students[i].roll_no);
      printf("Hostel Address: %s\n", students[i].hostel_address);
      return;
    }
  }
  printf("No student found with email: %s\n", email);
}

int main()
{
  char name[50];
  char email[MAX_EMAIL_LENGTH];
  int age;
  int roll_no;
  char hostel_address[100];

  while (student_count < MAX_STUDENTS)
  {
    printf("Enter the student's name: ");
    scanf("%s", name);
    printf("Enter the student's email: ");
    scanf("%s", email);
    printf("Enter the student's age: ");
    scanf("%d", &age);
    if (age < MIN_AGE || age > MAX_AGE)
    {
      printf("Age must be between %d and %d\n", MIN_AGE, MAX_AGE);
      continue;
    }
    printf("Enter the student's roll number: ");
    scanf("%d", &roll_no);
    printf("Enter the student's hostel address: ");
    scanf("%s", hostel_address);

    add_student(name, email, age, roll_no, hostel_address);
  }

  print_students_with_age_19();
  print_students_with_email_IT_and_even();

  char email_to_search[MAX_EMAIL_LENGTH];
  printf("Enter the email of the student to display details for: ");
  scanf("%s", email_to_search);
  display_student_details(email_to_search);
}