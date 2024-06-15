#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // For string functions

struct contact {
    char name[50];
    long long int number;
    struct contact* next;
};

// Function Prototyping
struct contact* makenode();
void Create(struct contact** head);
void Delete(struct contact** head);
void Search(struct contact** head);
void Edit(struct contact** head);
int duplicate(struct contact** head, long long int number);

int main() {
    int x;
    struct contact* head = NULL;

    while (1) {
        printf("Select from the following operations: \n");
        printf("1) Create new contact\n");
        printf("2) Delete existing contact\n");
        printf("3) Edit existing contact\n");
        printf("4) Search existing contact\n");
        printf("5) Exit\n");
        scanf("%d", &x);
        switch (x) {
            case 1:
                Create(&head);
                break;
            case 2:
                Delete(&head);
                break;
            case 3:
                Edit(&head);
                break;
            case 4:
                Search(&head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid option, select from 1 to 5\n");
        }
    }
}

struct contact* makenode() {
    char name[50];
    long long int number;
    printf("Enter the name: \n");
    scanf("%s", name);
    printf("Enter the phone number\n");
    scanf("%lld", &number);

    struct contact* newnode = (struct contact*)malloc(sizeof(struct contact));
    if (newnode == NULL) {
        printf("Memory Allocation Failed\n");
        exit(1);
    }
    strcpy(newnode->name, name);
    newnode->number = number;
    newnode->next = NULL;

    return newnode;
}

int duplicate(struct contact** head, long long int number) {
    struct contact* temp = *head;
    while (temp != NULL) {
        if (temp->number == number) {
            return 1; // Duplicate found
        }
        temp = temp->next;
    }
    return 0; // No duplicate
}

void Create(struct contact** head) {
    struct contact* newcontact = makenode();

    if (duplicate(head, newcontact->number)) {
        printf("Contact already exists. Want to edit the contact? Press 1 for Yes or 2 for No\n");
        int x;
        scanf("%d", &x);
        if (x == 1) {
            Edit(head);
        }
        free(newcontact);
        return;
    }

    if (*head == NULL) {
        *head = newcontact;
    } else {
        struct contact* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newcontact;
    }
    printf("Contact created.\n");
}

void Search(struct contact** head) {
    int x;
    printf("Search by Name press 1, by Number press 2\n");
    scanf("%d", &x);
    struct contact* temp = *head;
    int found = 0;

    switch (x) {
        case 1: {
            char name[50];
            printf("Enter the Name\n");
            scanf("%s", name);
            while (temp != NULL) {
                if (strcmp(temp->name, name) == 0) {
                    printf("The number is %lld\n", temp->number);
                    found = 1;
                    break;
                }
                temp = temp->next;
            }
            break;
        }
        case 2: {
            long long int number;
            printf("Enter the Number\n");
            scanf("%lld", &number);
            while (temp != NULL) {
                if (temp->number == number) {
                    printf("The name is %s\n", temp->name);
                    found = 1;
                    break;
                }
                temp = temp->next;
            }
            break;
        }
        default:
            printf("Invalid choice\n");
    }
    if (!found) {
        printf("Contact not found\n");
    }
}

// Function to delete a contact by number
void Delete(struct contact** head) {
    long long int number;
    printf("Enter the Number\n");
    scanf("%lld", &number);

    if (*head == NULL) {
        printf("The phonebook is empty\n");
        return;
    }

    struct contact* temp = *head;
    struct contact* prev = NULL;

    if (temp != NULL && temp->number == number) {
        *head = temp->next;
        free(temp);
        printf("Contact deleted.\n");
        return;
    }

    while (temp != NULL && temp->number != number) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Contact not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Contact deleted.\n");
}

void Edit(struct contact** head) {
    long long int number;
    printf("Enter the Number\n");
    scanf("%lld", &number);

    if (*head == NULL) {
        printf("The phonebook is empty\n");
        return;
    }

    struct contact* temp = *head;
    while (temp != NULL && temp->number != number) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Contact not found\n");
        return;
    }

    char newname[50];
    printf("Enter the new name: \n");
    scanf("%s", newname);
    strcpy(temp->name, newname);
    printf("Contact updated.\n");
}
