#include <stdio.h>
#include <stdlib.h>
#include <string.h>	

typedef struct microtweet{
    int id; 				//unique integer value	
    char user[51]; 			// the userid / username of the person who wrote the tweet
    char text[141]; 		// the text of the tweet
   
    struct microtweet *next;  //dynamic connection to the next tweet
}tweet;

void enqueue (tweet ** head, tweet ** tail, tweet * node); 

void dequeue (tweet ** head, tweet ** tail);

int isEmpty (tweet * head);

void printQueue (tweet * head);   

//-------------------------------------------------------------------

void sortID (tweet ** head, tweet ** tail);

void reverse (tweet ** head, tweet ** tail);

void sortUsername (tweet ** head, tweet ** tail);

//-------------------------------------------------------------------