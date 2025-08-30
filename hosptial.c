#include <stdio.h>
#include <string.h>

#define MAX 1000

struct Patient {
    int id;
    char name[50];
    char disease[100];
    int age;
};

struct Patient patients[MAX];
int count = 0;

void addPatient() {
    if (count >= MAX) {
        printf("Patient list is full!\n");
        return;
    }
    printf("\n--- Add Patient ---\n");
    printf("Enter ID: ");
    scanf("%d", &patients[count].id);
    printf("Enter Name (no spaces): ");
    scanf("%s", patients[count].name);
    printf("Enter Disease (no spaces): ");
    scanf("%s", patients[count].disease);
    printf("Enter Age: ");
    scanf("%d", &patients[count].age);
    count++;
    printf("Patient added successfully.\n");
}

void sortByAge() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (patients[j].age > patients[j + 1].age) {
                struct Patient temp = patients[j];
                patients[j] = patients[j + 1];
                patients[j + 1] = temp;
            }
        }
    }
    printf("\n--- Patients Sorted by Age ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Age: %d, Disease: %s\n", patients[i].id, patients[i].name, patients[i].age, patients[i].disease);
    }
}

void searchByID() {
    int id, found = 0;
    printf("\nEnter Patient ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (patients[i].id == id) {
            printf("\n--- Patient Found ---\n");
            printf("ID: %d\n", patients[i].id);
            printf("Name: %s\n", patients[i].name);
            printf("Disease: %s\n", patients[i].disease);
            printf("Age: %d\n", patients[i].age);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No patient found with ID %d.\n", id);
    }
}


int main() {
    int choice;
    while (1) {
        printf("\n--- Hospital System ---\n");
        printf("1. Add Patient\n");
        printf("2. Search Patient by ID\n");
        printf("3. Sort by Age\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addPatient(); break;
            case 2: searchByID(); break;
            case 3: sortByAge(); break;
            case 4: return 0;
            default: printf("Invalid choice. Try again.\n");
        }
    }
}

