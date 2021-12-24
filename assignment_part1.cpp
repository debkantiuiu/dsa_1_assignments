#include <stdio.h>
#include <stdlib.h>


#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

struct listNode
{
    int item;
    struct listNode * next;
};

struct listNode * list;

void initializeList()
{
    list = 0;  //initially set to NULL
}

int insertItem(int item) //insert at the beginning of the linked list
{
	struct listNode * newNode ;
	newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
	newNode->item = item ;
	newNode->next = list ; //point to previous first node
	list = newNode ; //set list to point to newnode as this is now the first node
	return SUCCESS_VALUE ;
}


int deleteItem(int item)
{
	struct listNode *temp, *prev ;
	temp = list ; //start at the beginning
	while (temp != 0)
	{
		if (temp->item == item) break ;
		prev = temp;
		temp = temp->next ; //move to next node
	}
	if (temp == 0) return NULL_VALUE ; //item not found to delete
	if (temp == list) //delete the first node
	{
		list = list->next ;
		free(temp) ;
	}
	else
	{
		prev->next = temp->next ;
		free(temp);
	}
	return SUCCESS_VALUE ;
}


struct listNode * searchItem(int item)
{
	struct listNode * temp ;
	temp = list ; //start at the beginning
	while (temp != 0)
	{
		if (temp->item == item) return temp ;
		temp = temp->next ; //move to next node
	}
	return 0 ; //0 means invalid pointer in C, also called NULL value in C
}

void printList()
{
    struct listNode * temp;
    temp = list;
    while(temp!=0)
    {
        printf("%d->", temp->item);
        temp = temp->next;
    }
    printf("\n");
}

int insertLast(int item)
{
    struct listNode *newNode ;
	newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
	
	newNode->item = item;
	newNode->next = 0;
	//printf("New node value: %d", newNode->item);
	
	if ( list == 0 ) // no node there
	{
	    list = newNode;
	}
	else // at least one node exists
	{
	    struct listNode *temp;
    	temp = list;
    	
    	while ( temp -> next != 0 )
    	{
    	    temp = temp -> next;
    	}
    	
    	temp -> next = newNode;    
	}
	
}

int insertBefore(int oldItem, int newItem)
{
	struct listNode *newNode ;
	newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
	
	newNode->item = newItem;
	newNode->next = 0;
	//printf("New node value: %d", newNode->item);
	
    struct listNode *current, *previous;
	current = list;
	
	while ( current != 0 )
	{
	    if ( current -> item == oldItem )
	    {
	        break; // item found
	    }
	    
	    previous = current;
	    current = current -> next;
	}
	
	if ( current == list ) // head is the oldItem
	{
	    newNode -> next = list;
	    list = newNode;
	    
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
	
}

int insertAfter(int oldItem, int newItem) // bonus
{
    struct listNode *newNode ;
	newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
	
	newNode->item = newItem;
	newNode->next = 0;
	//printf("New node value: %d", newNode->item);
	
    struct listNode *current, *previous;
	current = list;
	
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
	    if ( current -> next == 0 )
	    {
	        current -> next = newNode;
	    }
	    else // current is the intermediary node, so we need next of current
	    {
	        newNode -> next = current -> next;
	        current -> next = newNode;
	    }
	}
}

int deleteBefore(int item) // bonus
{
    struct listNode *current, *previous;
	current = list;
	
	while ( current != 0 )
	{
	    if ( current -> item == item )
	    {
	        break; // item found
	    }
	    
	    previous = current;
	    current = current -> next;
	}
	
	if ( current == list ) // found item is the head, so there is no previous node, so delete 
	{
	    printf("Delete not possible!");
	}
	else
	{
	    previous -> next = current -> next;
	    free(current);
	}
}

int deleteAfter(int item)
{
	struct listNode *newNode ;
	newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
	newNode->item = item;
	newNode->next = 0;
	//printf("New node value: %d", newNode->item);
	
	struct listNode *temp;
	temp = list;
	
	// findint the node with oldItem
	
}

int deleteLast()
{
    struct listNode *temp, *prev;
	temp = list;
	prev = list;
	
	while ( temp->next != 0 ) // going to last node
	{
	    //printf("node value: %d", temp->item);
	    temp = temp->next;
	    prev = temp;
	}
	
	if ( prev == temp ) // there's only head
	{
	    free(temp);
	}
	else
	{
	    prev->next = 0;
	    free(temp);
	}
	
}



int main(void)
{
    initializeList();
    while(1)
    {
        printf("1. Insert new item. 2. Delete item. 3. Search item. \n");
        printf("4. Insert Last. 5. Insert Before 6. Insert After 7. Delete Before 8. Delete After.\n");
        printf("9. Delete Last 10. Print. 11. exit.\n");

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
            deleteItem(item);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            struct listNode * res = searchItem(item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==4)
        {
            int item;
            scanf("%d", &item);
            insertLast(item);
        }
        
        else if(ch==5)
        {
            int oldItem, newItem;
            scanf("%d %d", &oldItem, &newItem);
            insertBefore(oldItem, newItem);
        }
        else if(ch==6)
        {
            int oldItem, newItem;
            scanf("%d %d", &oldItem, &newItem);
            insertAfter(oldItem, newItem);
        }
        else if(ch==7)
        {
            int oldItem;
            scanf("%d", &oldItem);
            deleteBefore(oldItem);
        }
        else if(ch==8)
        {
            int oldItem;
            scanf("%d", &oldItem);
            deleteAfter(oldItem);
        }
        else if(ch==9)
        {
            deleteLast();
        }
        else if(ch==10)
        {
            printList();
        }
        else if(ch==11)
        {
            break;
        }
    }

}




