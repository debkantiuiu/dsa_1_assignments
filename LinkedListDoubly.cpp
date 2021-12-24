#include<stdio.h>
#include<stdlib.h>


#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

struct listNode
{
    int item;
    struct listNode * next;
    struct listNode * prev;
};

struct listNode * list;

struct listNode * tail;

void initializeList()
{
    list = 0;  //initially set to NULL
    tail = 0;
}

int insertFirst(int item) //insert at the beginning
{
	struct listNode * newNode ;
	newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
	newNode->item = item ;

	if(list==0) //inserting the first item
    {
        newNode->next = 0;
        newNode->prev = 0;
        list = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = list;
        list->prev = newNode;
        newNode->prev = 0;
        list = newNode;
    }
	return SUCCESS_VALUE ;
}


int deleteAfter(int item)
{
    //write your codes here
    struct listNode *temp;
    struct listNode *deletedNode;
    temp=list;
    deletedNode=temp->next;
    while(temp->next!=NULL){

        if(temp->item==item){
            break;
        }


        temp=temp->next;
        deletedNode=temp->next;


    }
        if(temp->item!=item){
            printf("Item is not in the list \n");
        }
        else if(temp->next==NULL){
            printf("There is no item after %d \n",item);
        }

        else if(deletedNode->next==NULL){
         temp->next=NULL;
         free(deletedNode);
       }
        else
       {
        deletedNode->next->prev=temp->next;
        temp->next=deletedNode->next;
        free(deletedNode);
       }
}

int deleteLast()
{
    //write your codes here
    struct listNode *temp;
    if(list == NULL)
    {
        printf("No item in the list");
    }
    else if(list->next == NULL)
    {
        list = NULL;
        free(list);

    }
    else
    {
        temp = list;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp -> prev -> next = NULL;
        free(temp);

    }

    return NULL_VALUE;

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

void printListForward()
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

void printListBackward()
{
	//will print the list backward starting from the tail position
	struct listNode *temp;
	temp=tail;
	while(temp!=0){
        printf("%d->",temp->item);
        temp=temp->prev;
	}
    printf("\n");
}


//insertAfter, insertBefore, deleteBefore

void insertBefore(int searchItem,int newItem){

   struct listNode *temp;

   temp=list;

   while(temp->next!=NULL){

       if(temp->item==searchItem)
       {
           break;
       }

       temp=temp->next;


   }


    struct listNode *newNode;
	newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
	newNode->item = newItem ;
	newNode->next=temp;
	newNode->prev=temp->prev;
	temp->prev->next=newNode;
	temp->prev=newNode;



}

void insertAfter(int searchItem,int newItem){

    struct listNode *temp;
    temp=list;
    while(temp->next!=NULL){
        if(temp->item==searchItem){
            break;
        }
        temp=temp->next;
    }

    struct listNode *newNode;
    newNode=(struct listNode*)malloc(sizeof(struct listNode));
    newNode->item=newItem;

    newNode->next=temp->next;
    temp->next->prev=newNode;
    newNode->prev=temp;
    temp->next=newNode;

}

void deleteBefore(int item){



  struct listNode *deletedNode;
  struct listNode *temp;
  deletedNode=list;
  temp=deletedNode->next;
  while(temp->next!=NULL){
    if(temp->item==item){
        break;
    }
    deletedNode=deletedNode->next;
    temp=deletedNode->next;

  }

   temp->prev=deletedNode->prev;
   deletedNode->prev->next=temp;
   free(deletedNode);


}


 void insertLast(int item){

    struct listNode *temp;
    temp=list;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    struct listNode *newNode;
    newNode=(struct listNode*)malloc(sizeof(struct listNode));
    newNode->item=item;
    newNode->next=NULL;
    temp->next=newNode;
    newNode->prev=temp;
    tail=newNode;
}



int main(void)
{
    initializeList();
    while(1)
    {
        printf("1. Insert new item. 2. Delete After. 3.Delete Last 4. Search item. \n");
        printf("5. Print forward. 6. Print backward. 7. exit. 8.insertBefore 9.insertAfter 10.deleteBefore 11.insertLast\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            insertFirst(item);
        }
        else if(ch==2)
        {
              int item;
              scanf("%d",&item);
              deleteAfter(item);
        }

        else if(ch==3){
            int item = deleteLast();
            if(item!=NULL_VALUE) printf("Deleted: %d\n", item);
        }
        else if(ch==4)
        {
            int item;
            scanf("%d", &item);
            struct listNode * res = searchItem(item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==5)
        {
            printListForward();
        }
        else if(ch==6)
        {
            printListBackward();
        }
        else if(ch==7)
        {
            break;
        }
        else if(ch==8){
            int searchitem,newitem;
            printf("Insert Before:");
            scanf("%d",&searchitem);
            printf("Insert:");
            scanf("%d",&newitem);
            insertBefore(searchitem,newitem);
        }
        else if(ch==9){
            int searchitem,newitem;
            printf("Insert After:");
            scanf("%d",&searchitem);
            printf("Insert:");
            scanf("%d",&newitem);
            insertAfter(searchitem,newitem);
        }
        else if(ch==10){
            int item;
            scanf("%d",&item);
            deleteBefore(item);
        }
        else if(ch==11){
            int item;
            scanf("%d",&item);
            insertLast(item);
        }

    }

}
