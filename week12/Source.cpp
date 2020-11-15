#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    int key;
    struct node* next;
};

struct node* head = NULL;
struct node* current = NULL;

void printList() {
    struct node* ptr = head;
    printf("\n[ ");

    while (ptr != NULL) {
        printf("(%d) ",ptr->data);
        ptr = ptr->next;
    }
    printf(" ]");
}

void insertFirst(int key, int data) {
    struct node* link = (struct node*)malloc(sizeof(struct node));
    link->key = key;
    link->data = data;
    link->next = head;
    head = link;
}

bool isEmpty() {
    return head == NULL;
}

int length() {
    int length = 0;
    struct node* current;
    for (current = head; current != NULL; current = current->next) {
        length++;
    }
    return length;
}

void sort() {

    int i, j, k, tempKey, tempData;
    struct node* current;
    struct node* next;

    int size = length();
    k = size;

    for (i = 0; i < size - 1; i++, k--) {
        current = head;
        next = head->next;

        for (j = 1; j < k; j++) {

            if (current->data > next->data) {
                tempData = current->data;
                current->data = next->data;
                next->data = tempData;

                tempKey = current->key;
                current->key = next->key;
                next->key = tempKey;
            }
            current = current->next;
            next = next->next;
        }
    }
}

void main() {
    int number[10];
    for (int j = 0; j < 10; j++)
    {
        scanf_s("%d", &number[j]);
    }
    for (int i = 0; i < 10;i++)
    {
        if (number[i] > 0 && number[i] != NULL)
        {
            insertFirst(i, number[i]);
        }
    }
    printf("List : ");
    printList();
    sort();
    printf("\nSort : ");
    printList();
}