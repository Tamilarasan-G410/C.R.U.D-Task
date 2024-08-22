#include <stdio.h>
#include<string.h>

void create(char arr[][50], int *size,int roll[]) {
    printf("Enter the number of students: ");
    scanf("%d", size);
    

    printf("Enter the student names and their roll no. :\n");
    for (int i = 0; i < *size; i++) {
        printf("Student %d name: ", i + 1);
        scanf("%s", arr[i]);
        printf("Student %d roll no: ", i + 1);
        scanf("%d",&roll[i]);
    }
}

void read(char arr[][50], int size,int roll[]) {
    if (size == 0) {
        printf("No students found.\n");
        return;
       
    }

    printf("Student names and their roll no. are:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s %d\n", i + 1, arr[i],roll[i]);
        
    }
}

void update(char arr[][50], int size,int roll[]) {
    int pos;
    int newr;
    char newName[50];
    if (size == 0) {
        printf("No students found.\n");
        return;
        
    }
    printf("Enter the position to update (0 to %d): ",size-1);
    scanf("%d", &pos);
    

    if (pos < 0 || pos >= size) {
        printf("Invalid position!\n");
       
    }

    printf("Enter the new name: ");
    scanf("%s", newName);
    strcpy(arr[pos], newName);
    printf("Enter the new roll no.:");
    scanf("%d",&newr);
    roll[pos]=newr;
}

void delete(char arr[][50], int *size,int roll[]) {
    int pos;
    if (*size == 0) {
        printf("No students found.\n");
        return;
      
    }
    printf("Enter the position of the student to delete (0 to %d): ",*size-1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= *size) {
        printf("Invalid position!\n");
        
    }

    for (int i = pos; i < *size - 1; i++) {
        strcpy(arr[i],arr[i + 1]);
        roll[i]=roll[i + 1];
    }
    (*size)--;
    
     
}

int main() {
    char arr[100][50];
    int size ;
    int roll[100];
    int sizer;
    int choice;

    while (1) {
        printf("\nOperations available:\n");
        printf("1. Create the students list\n");
        printf("2. Read the student list\n");
        printf("3. Update a student in the  list\n");
        printf("4. Delete a student in the list\n");
        printf("5. Exit the program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create(arr, &size , roll);
                break;
            case 2:
                read(arr, size,roll);
                break;
            case 3:
                update(arr, size,roll);
                break;
            case 4:
                delete(arr, &size , roll);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
