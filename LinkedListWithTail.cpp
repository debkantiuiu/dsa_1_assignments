#include<stdio.h>
#include<stdlib.h>


#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

struct listNode
{
    int item;
    struct listNode *next;
};

struct listNode *head;
struct listNode *tail;

void initializeList()
{
    head = 0;  //initially set to NULL
	tail = 0;
}

struct listNode * searchItem(int item)
{
	struct listNode * temp ;
	temp = head ; //start at the beginning
	while (temp != 0)
	{
		if (temp->item == item) return temp ;
		temp = temp->next ; //move to next node
	}
	return 0 ; //0 means invalid pointer in C, also called NULL value in C
}

void printTail()
{
    printf("Tail: %d\n", tail -> item);
}

void printList()
{
    struct listNode * temp;
    temp = head;
    while(temp!=0)
    {
        printf("%d->", temp->item);
        temp = temp->next;
    }
    printf("\n");
    //printTail();
}

//add required codes to insert item at the beginning, remember to properly set the tail pointer!
int insertItem(int newItem)
{
	struct listNode * newNode ;
	newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
	
	newNode->item = newItem ;
	
	if ( head == 0) // no node now present here
	{
	    head = newNode;
	}
	else
	{
	    newNode -> next = head;
	    head = newNode;
	}
	
	//list = newNode ; //set list to point to newnode as this is now the first node
	
	if ( tail == 0 ) 
	{
	    tail = head;
	}
}



int insertLast(int item)
{
    if ( head == 0 )
    {
        insertItem(item);
    }
    else
    {
        struct listNode * newNode ;
	    newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
	
	    newNode->item = item ;
	    tail -> next = newNode;
	    tail = newNode;
    }
    //printTail();
}

int insertBefore(int oldItem, int newItem)
{
    struct listNode *newNode ;
	newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
	
	newNode->item = newItem;
	newNode->next = 0;
	//printf("New node value: %d", newNode->item);
	
    struct listNode *current, *previous;
	current = head;
	
	while ( current != 0 )
	{
	    if ( current -> item == oldItem )
	    {
	        break; // item found
	    }
	    
	    previous = current;
	    current = current -> next;
	}
	
	if ( current == head ) // head is the oldItem
	{
	    newNode -> next = head;
	    head = newNode;
	    
	}
	else if ( current == 0 ) // oldItem not found 
	{
	    printf("item not found");
	}
	else // now we need prev, as oldItem is the last or interior node
	{
	    newNode -> next = current;
	    previous -> next = newNode;
	}
	
	//printTail();
}

int insertAfter(int oldItem, int newItem)
{
    struct listNode *newNode ;
	newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
	
	newNode->item = newItem;
	newNode->next = 0;
	//printf("New node value: %d", newNode->item);
	
    struct listNode *current, *previous;
	current = head;
	
	while ( current != 0 )
	{
	    if ( current -> item == oldItem )
	    {
	        break; // item found
	    }
	    
	    previous = current;
	    current = current -> next;
	}
	
	if ( current == 0 ) // oldItem not found
	{
	    printf("old item not found!!");
	}
	else // we have to decide whether oldItem node is the last node
	{
	    if ( current != tail )
	    {
	        newNode -> next = current -> next;
	    }
	    current -> next = newNode;
	}
}


//add required codes to delete item, remember to properly set the tail pointer!
int deleteAfter(int item)
{
    struct listNode *current, *previous;
	current = head;
	
	while ( current != 0 )
	{
	    if ( current -> item == item )
	    {
	        break; // item found
	    }
	    
	    previous = current;
	    current = current -> next;
	}
	
	if ( current == tail )
	{
	    printf("\nThere is no item after the item node, as it is the last node");
	}
	else // current is before than last
	{
	    struct listNode *nodeToBeDeleted = current -> next;
	    current -> next = nodeToBeDeleted -> next;
	    free(nodeToBeDeleted);
	    
	    if ( current -> next == 0)
	    {
	        printf("tail updated!");
	        tail = current;
	    }
	    
	    // printTail();
	}
}




int main(void)
{
    initializeList();
    while(1)
    {
        printf("1. Insert new item. 2. Delete item. 3. Search item. \n");
        printf("4. (Add from homework). 5. Print. 6. exit. 7. Insert Item at last\n");
        printf("8. Insert item before. 9. Insert item after 10. Delete item after\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            insertItem(item);
        }
        else if(ch==2)
        {
            int item;
            scanf("%d", &item);
            deleteAfter(item);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            struct listNode * res = searchItem(item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==5)
        {
            printList();
        }
        else if(ch==6)
        {
            break;
        }
        else if (ch == 7)
        {
            int item;
            scanf("%d", &item);
            insertLast(item);
        }
        else if (ch == 8)
        {
            int oldItem,  newItem;
            scanf("%d %d", &oldItem, &newItem);
            insertBefore(oldItem, newItem);
        }
        else if (ch == 9)
        {
            int oldItem,  newItem;
            scanf("%d %d", &oldItem, &newItem);
            insertAfter(oldItem, newItem);
        }
        else if (ch == 10)
        {
            int item;
            scanf("%d", &item);
            deleteAfter(item);
        }
    }

}






