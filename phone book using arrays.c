#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phoneNumber[MAX_PHONE_LENGTH];
} PhoneBookEntry;

PhoneBookEntry phoneBook[MAX_ENTRIES];
int entryCount = 0;

void addEntry(const char *name, const char *phoneNumber) {
    if (entryCount < MAX_ENTRIES) {
        strncpy(phoneBook[entryCount].name, name, MAX_NAME_LENGTH);
        strncpy(phoneBook[entryCount].phoneNumber, phoneNumber, MAX_PHONE_LENGTH);
        entryCount++;
    } else {
        printf("Phone book is full. Cannot add more entries.\n");
    }
}
void searchEntry(const char *name) {
    for (int i = 0; i < entryCount; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Name: %s, Phone Number: %s\n", phoneBook[i].name, phoneBook[i].phoneNumber);
            return;
        }
    }
    printf("Entry not found.\n");
}

void displayEntries() {
    if (entryCount == 0) {
        printf("Phone book is empty.\n");
    } else {
        for (int i = 0; i < entryCount; i++) {
            printf("Name: %s, Phone Number: %s\n", phoneBook[i].name, phoneBook[i].phoneNumber);
        }
    }
}
int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    char phoneNumber[MAX_PHONE_LENGTH];

    while (1) {
        printf("Phone Book Menu:\n");
        printf("1. Add Entry\n");
        printf("2. Search Entry\n");
        printf("3. Display All Entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0';  // Remove trailing newline
                printf("Enter phone number: ");
                fgets(phoneNumber, MAX_PHONE_LENGTH, stdin);
                phoneNumber[strcspn(phoneNumber, "\n")] = '\0';  // Remove trailing newline
                addEntry(name, phoneNumber);
                break;
            case 2:
                            printf("Enter name to search: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0';  // Remove trailing newline
                searchEntry(name);
                break;
            case 3:
                displayEntries();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}