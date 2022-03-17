#include "headerA4.h"

// typedef struct microtweet{
//     int id; 				//unique integer value	
//     char user[51]; 			// the userid / username of the person who wrote the tweet
//     char text[141]; 		// the text of the tweet
//     struct microtweet *next;  //dynamic connection to the next tweet
// }tweet;


int main(){
    tweet * head = NULL;

    for (int i = 0; i < 4; i++){
        char user[51], text[141];
        int sumChar = 0;

        printf("Enter a username: ");
        scanf("%s", user);
        int lenOfUser = strlen(user);
        getchar();
        printf("Enter the user's tweet: ");
        fgets(text, 140, stdin);

        int lenOfText = strlen(text);

        //Finds sum of ASCII char of username
        for (int i = 0; i < lenOfUser; i++){
            sumChar = sumChar + user[i];
        }

        int userID = (sumChar) + (lenOfText-1);

        //Updating the last value of text to \0
        for (int i = 0; i < lenOfText; i++){
            if (text[i] == '\n'){
                text[i] = '\0';
            }
        }
        
        //Checking if this userID is already in use
        tweet * temp1 = head;
        while(temp1 != NULL && head != NULL) {
            if (temp1->id == userID) {
                userID = userID + rand()%998+1;
            }
            else {
                temp1 = temp1->next;
            }
        }

        tweet * temp2 = head;

        while (head != NULL && temp2->next != NULL) {   //Traverses to the last node
            temp2 = temp2->next;
        }

        tweet * newTweet = malloc(sizeof(tweet));   //allocate memory for new node
        newTweet->id = userID;  //Input userID into the node
        strcpy(newTweet->user, user);   //Input user into the node
        strcpy(newTweet->text, text);   //Input text into the node
        newTweet->next = NULL;  //updates NULL placment

        if (head == NULL) {
            head = newTweet;
        } 
        else {
            temp2->next = newTweet; //Attaches node to linked list
        }
        
        printf("Your computer-generated userid is %d.\n", userID);
    }

    //Attach the tail to the list
    tweet * attach = head;
    while(attach->next != NULL){
        attach = attach->next;
    }
    tweet * tail = attach;

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

        //-------------------------------------------//
        printf("\nPrint the Queue\n");
        printQueue(head);
        getchar();

        printf("Add Node [1], userID: %d, user: %s, user tweet: %s\n", info1->id, info1->user, info1->text);
        enqueue (&head, &tail, info1);
        printQueue(head);
        getchar();

        printf("Add Node [2], userID: %d, user: %s, user tweet: %s\n", info2->id, info2->user, info2->text);
        enqueue (&head, &tail, info2);
        printQueue(head);
        getchar();

        printf("Add Node [3], userID: %d, user: %s, user tweet: %s\n", info3->id, info3->user, info3->text);
        enqueue (&head, &tail, info3);
        printQueue(head);
        getchar();
        //Add node and print q used 3 times


        for (int i = 0; i < 3; i++){
            printf("Testing Dequeue Function\nIteration [%d]\nAfter Dequeue, queue looks like:\n", i+1);
            dequeue (&head, &tail);
            printQueue(head);
            getchar();
        }

        printf("Testing isEmpty function\n");
        printf("isEmpty returned %d\n", isEmpty(head));
        getchar();

        tweet * emptyTest = NULL;

        printf("Testing isEmpty function with empty list\nisEmpty returned %d\n", isEmpty(emptyTest));
        getchar();

        printf("Testing isEmpty function with queue again\nisEmpty returned %d\n", isEmpty(head));
        getchar();

        printf("Testing printQueue function\nprintQueue was used through the verification process already...\n");
        getchar();

        printf("Testing acendSortID function\n");
        sortID(&head, &tail);
        printQueue(head);
        getchar();

        printf("Testing ascendSortUsername function\n");
        sortUsername(&head, &tail);
        printQueue(head);
        getchar();

        printf("Testing reverseQueue function\n");
        reverse(&head, &tail);
        printQueue(head);
        getchar();

        //-------------------------------------------//

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
