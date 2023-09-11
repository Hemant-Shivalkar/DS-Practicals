#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
	*head = newNode;
    } else {
	struct Node* current = *head;
	while (current->next != NULL) {
	    current = current->next;
	}
	current->next = newNode;
    }
}

void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
	printf("The list is empty.\n");
	return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current != NULL && current->data != key) {
	prev = current;
	current = current->next;
    }

    if (current == NULL) {
	printf("Element not found in the list.\n");
	return;
    }

    if (prev == NULL) {
	*head = current->next;
    } else {
	prev->next = current->next;
    }

    free(current);
    printf("Element %d deleted from the list.\n", key);
}

void printList(struct Node* head) {
    struct Node* current = head;
    printf("List elements: ");
    while (current != NULL) {
	printf("%d -> ", current->data);
	current = current->next;
    }
    printf("NULL\n");
}

int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
	count++;
	current = current->next;
    }
    return count;
}

void main() {
clrscr();
    struct Node* head = NULL;
    int choice, value;

    while (1) {
	printf("\nLinked List Operations\n");
	printf("1. Insert\n");
	printf("2. Delete\n");
	printf("3. Print\n");
	printf("4. Count Nodes\n");
	printf("5. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice) {
	    case 1:
		printf("Enter the value to insert: ");
		scanf("%d", &value);
		insert(&head, value);
		break;
	    case 2:
		printf("Enter the value to delete: ");
		scanf("%d", &value);
		deleteNode(&head, value);
		break;
	    case 3:
		printList(head);
		break;
	    case 4:
		printf("Number of nodes in the list: %d\n", countNodes(head));
		break;
	    case 5:
		exit(0);
	    default:
		printf("Invalid choice. Please try again.\n");
	}
    }

}
