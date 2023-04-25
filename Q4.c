#include <stdio.h>
#include <stdlib.h>

struct student
{
  char email[50];
  int roll_no;
  int marks[3];
};

int main()
{
  struct student s;
  FILE *fptr;
  int i;

  // Open file in write mode
  fptr = fopen("record.txt", "w");
  if (fptr == NULL)
  {
    printf("Error opening file!\n");
    exit(1);
  }

  // recieve student data
  printf("Enter student email: ");
  scanf("%s", s.email);
  printf("Enter roll number: ");
  scanf("%d", &s.roll_no);
  printf("Enter marks of assignment1,2,3: ");
  for (i = 0; i < 3; i++)
  {
    scanf("%d", &s.marks[i]);
  }

  // Write student data to file
  fprintf(fptr, "Email: %s\n", s.email);
  fprintf(fptr, "Roll Number: %d\n", s.roll_no);
  fprintf(fptr, "Marks of assignment1,2,3: ");
  for (i = 0; i < 3; i++)
  {
    fprintf(fptr, "%d ", s.marks[i]);
  }

  fclose(fptr);

  // Open file in read mode
  fptr = fopen("record.txt", "r");
  if (fptr == NULL)
  {
    printf("Error opening file!\n");
    exit(1);
  }

  // Read student data from file
  fscanf(fptr, "Email: %s\n", s.email);
  fscanf(fptr, "Roll Number: %d\n", &s.roll_no);
  fscanf(fptr, "Marks of three assignments: %d %d %d", &s.marks[0], &s.marks[1], &s.marks[2]);

  // Print student data
  printf("\nStudent data from file:\n");
  printf("Email: %s\n", s.email);
  printf("Roll Number: %d\n", s.roll_no);
  printf("Marks of three assignments: ");
  for (i = 0; i < 3; i++)
  {
    printf("%d ", s.marks[i]);
  }

  fclose(fptr);
}
