#include "headerA4.h"

void sortID (tweet ** head, tweet ** tail){
    if (isEmpty(*head) == 1){   //Checks if the q is empty
        return;
    }
    //Initilizing var
    tweet *current = *head;
    tweet *spot = NULL;
    int temp;
    char user[51];
    char tweet[141];

    while(current != NULL) {    //Runs while loop for current(head)
        spot = current->next;  //Updates temp val to val after current
        while(spot != NULL) {  
            if(current->id > spot->id) {   //If node after current has a lower id val it swaps elements
                temp = current->id;
                strcpy(user, current->user);  
                strcpy(tweet, current->text);
                
                current->id = spot->id;  
                strcpy(current->user, spot->user);
                strcpy(current->text, spot->text);

                spot->id = temp;
                strcpy(spot->user, user);
                strcpy(spot->text, tweet);
            }  
            spot = spot->next;   //Goes to next element and checks it
        }  
        current = current->next;    
    }       
}

void reverse (tweet ** head, tweet ** tail){
    //Initilizing val
    tweet * prev = NULL;
    tweet * temp = *head;
    tweet* next = NULL;

    while (temp != NULL) {  //Runs until temp is null
        next = temp->next;
        temp->next = prev;  //next val of temp is null
        prev = temp;
        temp = next;    //filps the arrow
    }
    *head = prev;   //updates the head to the other side of the q

    tweet * temp2 = *head;

    while (temp2->next != NULL) {    //Updating where the tail is
        temp2 = temp2->next;
    }
    *tail = temp2;
}

void sortUsername (tweet ** head, tweet ** tail){
    if (isEmpty(*head) == 1){   //checking if the list is empty
        return;
    }
    //Initlizing val
    tweet *current = *head;
    tweet *spot = NULL;
    int temp;
    char user[51];
    char tweet[141];

    while(current != NULL) {    //Runs in a simmiallar fasion to a 2D array
        spot = current->next;  
        while(spot != NULL) {  //Compares each element to the one after it continuosly so it will compare for each val
            if(strcmp(current->user, spot->user) > 0) {    //If current user ASCII val is greater than the next element they will swap
                temp = current->id;
                strcpy(user, current->user);  
                strcpy(tweet, current->text);
                
                current->id = spot->id;  
                strcpy(current->user, spot->user);
                strcpy(current->text, spot->text);

                spot->id = temp;
                strcpy(spot->user, user);
                strcpy(spot->text, tweet);
            }  
            spot = spot->next;    //Traverses to next index
        }  
        current = current->next;    //Goes to next val
    }       
}