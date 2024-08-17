#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

typedef struct SinglyLinkedListNode SinglyLinkedListNode;
typedef struct SinglyLinkedList SinglyLinkedList;

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

struct SinglyLinkedList {
    SinglyLinkedListNode* head;
};

SinglyLinkedListNode* create_singly_linked_list_node(int node_data) {
    SinglyLinkedListNode* node = malloc(sizeof(SinglyLinkedListNode));

    node->data = node_data;
    node->next = NULL;

    return node;
}

void print_singly_linked_list(SinglyLinkedListNode* node, char* sep) {
    while (node) {
        printf("%d", node->data);

        node = node->next;

        if (node) {
            printf("%s", sep);
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the insertNodeAtTail function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    // Step 1: Create a new node with the given data
    SinglyLinkedListNode* newNode = create_singly_linked_list_node(data);

    // Step 2: Check if the list is empty
    if (head == NULL) {
        // If the list is empty, the new node is the head
        return newNode;
    }

    // Step 3: Traverse the list to find the last node
    SinglyLinkedListNode* current_node = head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }

    // Step 4: Update the last node's next pointer to the new node
    current_node->next = newNode;

    // Return the head of the list (unchanged)
    return head;
}

int main()
{
    SinglyLinkedList* llist = malloc(sizeof(SinglyLinkedList));
    llist->head = NULL;
  
    char* llist_count_endptr;
    char* llist_count_str = readline();
    int llist_count = strtol(llist_count_str, &llist_count_endptr, 10);

    if (llist_count_endptr == llist_count_str || *llist_count_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int i = 0; i < llist_count; i++) {
        char* llist_item_endptr;
        char* llist_item_str = readline();
        int llist_item = strtol(llist_item_str, &llist_item_endptr, 10);

        if (llist_item_endptr == llist_item_str || *llist_item_endptr != '\0') { exit(EXIT_FAILURE); }

		SinglyLinkedListNode* llist_head = insertNodeAtTail(llist->head, llist_item);
        llist->head = llist_head;
    }



    char *sep = "\n";

    print_singly_linked_list(llist->head, sep);
    printf("\n");

    free_singly_linked_list(llist->head);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!line) {
            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);
    } else {
        data = realloc(data, data_length + 1);

        data[data_length] = '\0';
    }

    return data;
}