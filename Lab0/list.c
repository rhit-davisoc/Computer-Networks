/* File: list.c 
 * Author: Olivia Davis
   
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct List_node_s {
	int length;
	char* word;
    struct List_node_s* next;
} List_node;

int main(int argc, char *argv[]){
    List_node* list = (List_node*)malloc(sizeof(List_node));;
    list->word = argv[1];
    list->length = strlen(argv[1]);
    list->next = NULL;

    List_node* root = (List_node*)malloc(sizeof(List_node));;
    root->word = NULL;
    root->next = list;

    for (int i = 2; i < argc; i++) {
        List_node* current = root;
        char* word = argv[i];
        List_node* add = (List_node*)malloc(sizeof(List_node));;
        add->word = word;
        add->length = strlen(word);
        add->next = NULL;

        while(current->next != NULL && current->next->length <= add->length){
            current = current->next;
        }

        add->next = current->next;
        current->next = add;
    }

    List_node* cur = root->next;

    while (cur != NULL) {
        printf("%s\n", cur->word);
        cur = cur->next;
    }

}
