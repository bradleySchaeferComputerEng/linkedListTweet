#include "headerA4.h"

void enqueue (tweet ** head, tweet ** tail, tweet * node){
    node->next = (*head);   //Adds node to head
    (*head) = NULL; //Derefrences head
    (*head) = node; //Attaches head to node
}

void dequeue (tweet ** head, tweet ** tail){
    tweet * cycle = *head;

    int num = 0;
    while (cycle != NULL){  //Finds how many nodes there are
        cycle = cycle->next;
        num++;
    }
    //printf("There are %d Number of Tweets", num);
    if (num == 0){  //If there is none it will not run
        return;
    }
    else if (num == 1){ //If there is one it will free the head
        *head = NULL;
        free(*head);
    }
    else{
        tweet * temp = *head;  
        tweet * last = *head;  //If there is more than one it will go to the second last element
        while (temp->next != (*tail) && temp != NULL) {
            temp = temp->next;
        }
        last = temp->next;
        temp->next = NULL;
        *tail = temp;   //Attaches the tail to the second last elemet
        free(last); //Free the last element
    }
}

int isEmpty (tweet * head){
    tweet * temp = head;    //Temp pointer files through and checks
    
    int num = 0;
    while (temp != NULL){
        temp = temp->next;
        num++;
    }
    if (num == 0){
        return 1;
    }
    else{
        return 0;
    }
}

void printQueue (tweet * head){ //Files through and prints nodes
    if (isEmpty(head) == 1){
        return;
    }
    else{
        tweet * temp = head;

        while (temp != NULL){
            printf("%d: Created by %s: %s\n", temp->id, temp->user, temp->text);
            temp = temp->next;
        }
    }
}