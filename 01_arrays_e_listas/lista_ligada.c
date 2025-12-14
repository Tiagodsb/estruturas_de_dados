#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node *next;
} node;

//**list argument is pointer to pointer for our linked list
int add(node **list, int value) {	
	node *new_node = malloc(sizeof(node));
	
	//if error on memory allocations
	if(! new_node) return -1;

	new_node->value = value;
	new_node->next = NULL;

	//if list is empty
	if(*list == NULL) {
		*list = new_node;
		return 0;
	}
	
	//find last item
	node *current = *list;
	while(current->next != NULL) {
		current = current->next;
	}

	//append new_node in last position
	current->next = new_node;
	return 0;
}

//remove the first match not all occurrences of the value
int del(node **list, int value) {
	//if list is empty return
	if(*list == NULL) return 0;

	node *current = *list;
	node *prev = NULL;

	while(current != NULL) {
		if(current->value == value) {
			if(prev == NULL) {
				*list = current->next;
			} else {
				prev->next = current->next;
			}
			free(current);
			printf("valor removido(primeira ocorrência)\n");
			return 1;//value removed
		}
		prev = current;
		current = current->next;
	}	
	return 0; //value not found
}

void show(node **list){
	printf("\n----------------------------------\n");
	if(*list == NULL) {
		printf("\nLista vazia\n");
		return;
	}
	node *current = *list;
	while(current->next != NULL) {
		printf("%d ", current->value);
		current = current->next;
	}
	printf("%d\nfim da lista\n", current->value);
}

int menu(){
	int opt;
	printf("\n----------------------------------\n");
	printf("1 - adicionar elemento na lista\n");
	printf("2 - exibir a lista\n");
	printf("3 - remover valor\n");
	printf("0 - sair\nopt: ");
	scanf("%d", &opt);
	return opt;
}

int main(void) {
	
	//declare the list pointer
	node *list = NULL;

	int opt = menu();
	
	while(opt != 0){
		switch (opt) {
		case 1:
			int value;
			printf("valor: ");
			scanf("%d", &value);
			add(&list, value);
			break;
		case 2:
			show(&list);
			break;
		case 3:
			int rmvalue;
			printf("valor a remover: ");
			scanf("%d", &rmvalue);
			del(&list, rmvalue);
			break;
		default:
			printf("Opção inválida.\n");
		}
		opt = menu();
	}
	printf("tchau!\n");
	return 0;
}
