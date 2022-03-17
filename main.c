#include "headerA4.h"

// typedef struct microtweet{
//     int id; 				//unique integer value	
//     char user[51]; 			// the userid / username of the person who wrote the tweet
//     char text[141]; 		// the text of the tweet
//     struct microtweet *next;  //dynamic connection to the next tweet
// }tweet;


int main(){
    int choice = 0;
    printf("Please choose what test case you would like to run\nTest 1. Manual input with three elements in the string and one node that you can attach\nTest 2. Empty list (helps check for segmentation faults)\nTest 3. Premade script where you will press the return button to run the code (very simple) has 4 nodes and 1 that you can attach\n");
    scanf("%d", &choice);
  
        tweet * info1 = malloc(sizeof(tweet));
        info1->id = 1;
        strcpy(info1->user, "Brad1");
        strcpy(info1->text, "this is the first tweet");
        info1->next = NULL;

        tweet * info2 = malloc(sizeof(tweet));
        info2->id = 2;
        strcpy(info2->user, "Brad2");
        strcpy(info2->text, "this is the second tweet");
        info2->next = NULL;

        tweet * info3 = malloc(sizeof(tweet));
        info3->id = 3;
        strcpy(info3->user, "Brad3");
        strcpy(info3->text, "this is the third tweet");
        info3->next = NULL;

        tweet * head = info1;
        info1->next = info2;
        info2->next = info3;

        tweet * tail = info3;

        tweet * node = malloc(sizeof(tweet));
        node->id = 97;
        strcpy(node->user, "McDavid");
        strcpy(node->text, "Best NHL player");
        node->next = NULL;
        
        int menuNum = 0;

        while(menuNum != 8){

            printf("\n1. enqueue - Adds an item to the queue\n");
            printf("2. dequeue - Removes the tail\n");
            printf("3. isEmpty - Checks if empty\n");
            printf("4. printQueue - Prints List\n");
            printf("5. sortID - Sorts ID in accending order\n");
            printf("6. reverse - Reverses order if the tweets\n");
            printf("7. sortUser = Sorts Username using ACSII val\n");
            printf("8. Exit program\n");

            printf("Choose a menu option: ");
            scanf("%d", &menuNum);
        
            if (menuNum<1 || menuNum>8){
                printf("Please choose a number between 1-8.\n");
                getchar();
            }
            
            if (menuNum == 1) { 
                enqueue (&head, &tail, node);
            }
            if (menuNum == 2) {  
                dequeue (&head, &tail);
            }
            if (menuNum == 3) { 
                printf("isEmpty (1 if empty, 0 if not empty) returned %d\n", isEmpty (head));
            }
            if (menuNum == 4) {
                printQueue (head);
            }
            if (menuNum == 5) {
                sortID (&head, &tail);
            }
            if (menuNum == 6) {
                reverse (&head, &tail);
            }
            if (menuNum == 7) {
                sortUsername (&head, &tail);
            }
            
        }

        printf("You exited the program\n");
        tweet * current = head;
        tweet * place;

        while (current != NULL) {
            place = current->next;
            free(current);
            current = place;
        }
    
    return 0;
}
