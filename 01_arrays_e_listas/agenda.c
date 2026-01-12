#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contact{
    char name[30];
    char phone[15];
    struct contact *next;
} contact;

contact* find_number(contact *head, const char *phone) {
    if(head == NULL) return NULL;

    contact *current = head;
    
    while(current != NULL) {
        if(strcmp(current->phone, phone) == 0) return current;
        current = current->next;
    }
    return NULL;
}

int add_person(contact **head, const char *name, const char *phone) {
    
    contact *in_use = find_number(*head, phone);

    if(in_use != NULL) {
        printf("O número %s já está registrado para %s\n", phone, in_use->name);
        return -1;
    }

    contact *new_contact = calloc(1, sizeof(contact));
    if(!new_contact) return -1;

    snprintf(new_contact->name, sizeof(new_contact->name), "%s", name);
    snprintf(new_contact->phone, sizeof(new_contact->phone), "%s", phone);

    if(*head == NULL) {
        *head = new_contact;
        return 0;
    }
    
    contact *current = *head;
    
    while(current->next != NULL) {
        current = current->next;
    }

    current->next = new_contact;
    return 0;
}

void show(contact *head) {
    contact *current = head;
    puts("Lista:");
    while(current != NULL) {
        printf("%s: %s\n", current->name, current->phone);
        current = current->next;
    }
}

void find_name(contact *head, const char *name) {
    contact *current = head;
    
    int results = 0;
    printf("\nResultados da busca por '%s':\n", name);
    while(current != NULL) {
        char *result = strcasestr(current->name, name);
        if(result != NULL) {
            printf("%s %s\n", current->name, current->phone);
            results++;
        }
        current = current->next;
    }
    printf("%d resultados.\n", results);
}

int drop(contact **head, contact *target) {
    if(*head == NULL || target == NULL) return -1;

    printf("drop(%s)\n", target->name);
    if(*head == target) {
        contact *temp = *head;
        *head = (*head)->next;
        free(temp);
        return 0;
    }
    contact *current = *head;
    while(current->next != NULL) {
        if(current->next == target) {
            contact *rm = current->next;
            current->next = rm->next;
            free(rm);
            return 0;
        }
        current = current->next;
    }
}

int main() {
    contact *head = NULL;
    add_person(&head, "João da Silva", "0099334422");
    add_person(&head, "Pedro", "0033444555");
    add_person(&head, "Maria", "0033334555");
    add_person(&head, "Madalena", "99933399933");
    add_person(&head, "Maria das Dores", "99933399933");
    show(head);
    find_name(head, "Ma");
    find_name(head, "João");
    
    char phone[] = "0099334422";
    char phone2[] = "99933399933";
    
    contact *search_number = find_number(head, phone);
    if(search_number) printf("o número %s pertence a %s\n", phone, search_number->name);
    
    //search_number = find_number(head, phone2);
    //if(search_number) printf("o número %s pertence a %s\n", phone, search_number->name);

    drop(&head, search_number);
    show(head);
    return 0;
}
