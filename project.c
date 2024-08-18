#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for storing student information
struct student {
    int id;
    char name[50];
    int age;
    float gpa;
};

// Define a structure for a linked list node that stores a student
struct node {
    struct student data;  // student data
    struct node *next;    // pointer to the next node
};

// Declare the head of the linked list
struct node *head = NULL;

// Function prototypes
void addStudent(const struct student *const ptr);
void displayStudents(void);
void searchStudentByID(int id);
void updateStudent(int id);
float calculateAverageGPA(void);
void searchHighestGPA(void);
void deleteStudent(int id);

int main() {
    // Disable output buffering for the console
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    int choice, id;
    struct student newStudent;

    while (1) {
        // Display menu options
        printf("\nMenu:\n");
        printf("1. Add a Student\n");
        printf("2. Display All Students\n");
        printf("3. Search for a Student by ID\n");
        printf("4. Update Student Information\n");
        printf("5. Delete a Student\n");
        printf("6. Calculate Average GPA\n");
        printf("7. Find Student with Highest GPA\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handle user menu choice
        switch (choice) {
            case 1:
                // Collect student details
                printf("Enter student ID: ");
                scanf("%d", &newStudent.id);
                printf("Enter student name: ");
                scanf(" %[^\n]", newStudent.name);
                printf("Enter student age: ");
                scanf("%d", &newStudent.age);
                printf("Enter student GPA: ");
                scanf("%f", &newStudent.gpa);

                // Add student to the linked list
                addStudent(&newStudent);
                break;

            case 2:
                // Display all students
                displayStudents();
                break;

            case 3:
                // Search for a student by ID
                printf("Enter student ID: ");
                scanf("%d", &id);
                searchStudentByID(id);
                break;

            case 4:
                // Update student information by ID
                printf("Enter student ID to update: ");
                scanf("%d", &id);
                updateStudent(id);
                break;

            case 5:
                // Delete a student by ID
                printf("Enter student ID to delete: ");
                scanf("%d", &id);
                deleteStudent(id);
                break;

            case 6:
                // Calculate and display the average GPA
                printf("Average GPA: %f\n", calculateAverageGPA());
                break;

            case 7:
                // Find and display the student with the highest GPA
                searchHighestGPA();
                break;

            case 8:
                // Exit the program
                printf("Exiting program.\n");
                exit(0);
                break;

            default:
                // Handle invalid choices
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to add a student to the linked list
void addStudent(const struct student *const ptr) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    // Allocate memory for a new node
    struct node *link = (struct node*)malloc(sizeof(struct node));
    if (!link) {
        printf("Memory allocation failed\n");
        return;
    }

    // Check for duplicate student ID
    struct node *current = head;
    while (current != NULL) {
        if (current->data.id == ptr->id) {
            printf("The entered ID already exists\n");
            free(link);  // free the allocated memory if duplicate is found
            return;
        }
        current = current->next;
    }

    // Assign student data to the new node and link it to the list
    link->data = *ptr;
    link->next = NULL;
    if (head == NULL) {
        head = link;  // if list is empty, set the new node as head
    } else {
        current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = link;  // append the new node at the end of the list
    }
    printf("Student added successfully\n");
}

// Function to display all students in the linked list
void displayStudents(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    struct node *current = head;
    if (current == NULL) {
        printf("No students found\n");
        return;
    }

    // Traverse the linked list and display each student's details
    while (current != NULL) {
        printf("ID: %d\n", current->data.id);
        printf("Name: %s\n", current->data.name);
        printf("Age: %d\n", current->data.age);
        printf("GPA: %.2f\n", current->data.gpa);
        current = current->next;
    }
}

// Function to search for a student by ID
void searchStudentByID(int id) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    struct node *current = head;

    // Traverse the linked list to find the student by ID
    while (current != NULL) {
        if (current->data.id == id) {
            printf("ID found\n");
            printf("ID: %d\n", current->data.id);
            printf("Name: %s\n", current->data.name);
            printf("Age: %d\n", current->data.age);
            printf("GPA: %.2f\n", current->data.gpa);
            return;
        }
        current = current->next;
    }
    printf("ID not found\n");
}

// Function to update student information by ID
void updateStudent(int id) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    struct node *current = head;

    // Traverse the linked list to find the student by ID
    while (current != NULL) {
        if (current->data.id == id) {
            printf("Updating student with ID: %d\n", id);
            printf("Enter new name: ");
            scanf(" %[^\n]", current->data.name);
            printf("Enter new age: ");
            scanf("%d", &current->data.age);
            printf("Enter new GPA: ");
            scanf("%f", &current->data.gpa);
            printf("Student information updated successfully.\n");
            return;
        }
        current = current->next;
    }
    printf("ID not found\n");
}

// Function to calculate the average GPA of all students
float calculateAverageGPA(void) {
    struct node *current = head;
    int count = 0;
    float sum = 0.0;

    // Traverse the linked list to calculate the sum of GPAs and the number of students
    while (current != NULL) {
        sum += current->data.gpa;
        count++;
        current = current->next;
    }

    // Return the average GPA
    if (count == 0) {
        return 0.0;  // no students found
    }
    return sum / count;
}

// Function to find and display the student with the highest GPA
void searchHighestGPA(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    struct node *current = head;
    if (current == NULL) {
        printf("No students found\n");
        return;
    }

    struct node *max = head;  // assume the first student has the highest GPA

    // Traverse the linked list to find the student with the highest GPA
    while (current != NULL) {
        if (current->data.gpa > max->data.gpa) {
            max = current;
        }
        current = current->next;
    }

    // Display the student with the highest GPA
    printf("The student with the highest GPA is:\n");
    printf("ID: %d\n", max->data.id);
    printf("Name: %s\n", max->data.name);
    printf("Age: %d\n", max->data.age);
    printf("GPA: %.2f\n", max->data.gpa);
}

// Function to delete a student by ID
void deleteStudent(int id) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    struct node *current = head;
    struct node *prev = NULL;

    // If the student to be deleted is the head of the list
    if (current != NULL && current->data.id == id) {
        head = current->next;  // change the head to the next node
        free(current);  // free memory
        printf("Student with ID %d deleted successfully.\n", id);
        return;
    }

    // Traverse the linked list to find the student to delete
    while (current != NULL && current->data.id != id) {
        prev = current;
        current = current->next;
    }

    // If the student was not found
    if (current == NULL) {
        printf("Student with ID %d not found.\n", id);
        return;
    }

    // Remove the student from the list
    prev->next = current->next;
    free(current);  // free memory
    printf("Student with ID %d deleted successfully.\n", id);
}
