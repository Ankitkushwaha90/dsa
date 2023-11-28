#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node *next;

};

struct node *front;
struct node *rear;
void insert();
void delete();
void display();
void main(){
    int choise;
    while(choise!=4){
        printf("\n main menu");
        printf("\n ================\n");
        printf("\n1.insert and element\n 2.Delete an element \n 3.Display the queue \n 4.Exit\n");
        printf("\n Enter your choise...");
        scanf("%d", &choise);
        switch(choise){
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;

            case 3:
                display();

                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\n Enter valid choice ?? \n");
        }

    }
}


void insert()
{
    struct node *ptr;
    int item;

    ptr = (struct node *) malloc(sizeof(struct node));

    if(ptr == NULL)
    {
        printf("\n OVERFLOW\n");
        return;

    }
    else{
        printf("\nEnter the value ... \n");
        scanf("%d", &item);

        ptr -> data = item;
        if(front == NULL){
            front = ptr;
            rear = ptr;

            front -> next = NULL;
            rear -> next = NULL;

        }
        else{
            rear-> next = ptr;
            rear = ptr;
            rear -> next = NULL;

        }
    }

}

void delete(){
    struct node *ptr;

    if(front == NULL)
    {
        printf("\n UNDERFLOW\n");
        return;

    }
    else{
        ptr = front;
        front = front -> next;
        free(ptr);
    }
}

void display(){
    struct node *ptr;
    ptr = front;
    if(front == NULL){
        printf("\n Empty queue\n");
    }
    else{
        printf("\n printing value ... \n");
        while(ptr != NULL){
            printf("\n %d\n", ptr -> data);
            ptr = ptr ->next;
        }
    }
}