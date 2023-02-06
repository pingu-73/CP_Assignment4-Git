#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 23

struct Student {
  char email[100];
  int roll_no;
  int marks[3];
};

int main() {
  struct Student students[MAX_STUDENTS];
  int i, j;
  int num_students;

  // Read student information
  printf("Enter the number of students (maximum %d):\n", MAX_STUDENTS);
  scanf("%d", &num_students);
  for (i = 0; i < num_students; i++) {
    printf("Enter email, roll number and marks of assignment 1, 2 and 3 for student %d:\n", i + 1);
    scanf("%s%d%d%d%d", students[i].email, &students[i].roll_no, &students[i].marks[0], &students[i].marks[1], &students[i].marks[2]);
  }

  // Write student information to file
  FILE *fp;
  fp = fopen("record.txt", "w");
  if (fp == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }
  for (i = 0; i < num_students; i++) {
    fprintf(fp, "%s %d %d %d %d\n", students[i].email, students[i].roll_no, students[i].marks[0], students[i].marks[1], students[i].marks[2]);
  }
  fclose(fp);

  // Read student information from file
  fp = fopen("record.txt", "r");
  if (fp == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }
  printf("\nStudent information read from file:\n");
  for (i = 0; i < num_students; i++) {
    fscanf(fp, "%s%d%d%d%d", students[i].email, &students[i].roll_no, &students[i].marks[0], &students[i].marks[1], &students[i].marks[2]);
    printf("%s %d %d %d %d\n", students[i].email, students[i].roll_no, students[i].marks[0], students[i].marks[1], students[i].marks[2]);
  }
  fclose(fp);

  return 0;
}
