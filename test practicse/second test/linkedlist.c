
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *create_ll(struct node *start);
struct node *display(struct node *start);
struct node *insert_beg(struct node *start);
struct node *insert_end(struct node *start);
struct node *insert_before(struct node *start);
struct node *insert_after(struct node *start);
struct node *delete_beg(struct node *start);
struct node *delete_end(struct node *start);
struct node *delete_node(struct node *start);
struct node *delete_after(struct node *start);
struct node *delete_list(struct node *start);
struct node *sort_list(struct node *start);
void main(){
    int choice;
    do
    {
        printf("\t\n MENU LINKED LIST \n");
        printf("\tRonit Satish Mehta 60009230207\n");
        printf("\t press the given number :\n");
        printf("\n1.create linked list\n2.display\n3.insert beginning\n4.insert end\n5.insert after\n6.insert before\n7.delete beginning\n8.delete end\n9.delete after\n10.delete node\n11.delete entire list\n12.sort list\n13.searching\n14.exit");
        printf("\nEnter the choice from the above options:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            start = create_ll(start);
            printf("\nlinked list is created");
            break;
        case 2:
            start = display(start);
            printf("\ndone\n");
            break;
        case 3:
            start = insert_beg(start);
              printf("\ndone\n");
            break;
        case 4:
             start = insert_end(start);
               printf("\ndone\n");
             break;
        case 5:
            start = insert_after(start);
              printf("\ndone\n");
            break;
        case 6:
             start = insert_before(start);
               printf("\ndone\n");
             break;
        case 7:
             start = delete_beg(start);
               printf("\ndone\n");
             break;
        case 8:
             start = delete_end(start);
             printf("\ndone\n");
             break;
        case 9:
             start = delete_after(start);
             printf("\ndone\n");
             break;
        case 10:
             start = delete_node(start);
               printf("\ndone\n");
             break;
        case 11:
            start = delete_list(start);
              printf("\ndone\n");
            break;
        case 12:
            start = sort_list(start);
              printf("\ndone\n");
            break;
        case 13:
             printf("\nexiting...\n");
             break;
        default:
            printf("\nEnter valid choice\n");
            break;
        }
    } while (choice!=13);
}
struct node *create_ll(struct node *start){
    int val;
    struct node  *nn,*ptr;
    printf("\nEnter -1 to stop\n");
    printf("\nEnter the val:");
    scanf("%d",&val);
    while (val != -1)
    {
        nn = (struct node *)malloc(sizeof(struct node));
        nn->data=val;
        nn->next = NULL;
        if (start == NULL)
        {
            start = nn;
        }
        else{

            ptr = start;
            while (ptr->next!=NULL)
            {
                ptr = ptr ->next;
            }
            
        }
          ptr->next = nn;
          printf("\nEnter the value:\n");
          scanf("%d",&val);
    }
    return start;
}
struct node *display(struct node *start){
    struct node *ptr;
    if (start == NULL)
    {
        printf("\nLinked list is empty");
    }
    else
    {
        ptr  = start;
        while (ptr != NULL)
        {
            printf("%d",ptr->data);
            ptr = ptr -> next;
        }
        
    }
    
    return start;
}
struct node *insert_beg(struct node *start){
    int val;
    struct node *nn;
    printf("\nenter a value:");
    scanf("%d",&val);
    nn = (struct node*)malloc(sizeof(struct node));
    nn->data = val;
    nn->next = start;
    start = nn;
    return start;
}
struct node *insert_end(struct node *start){
    int val;
    struct node *nn,*ptr;
    printf("\nEnter a value");
    scanf("%d",&val);
    nn = (struct node *)malloc(sizeof(struct node));
    nn->data = val;
    nn->next = NULL;
    while (ptr->next != NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=nn;
    return start;
}
struct node *insert_before(struct node *start){
    int before_val,val;
    struct node *nn,*ptr,*pp;
    printf("\nEnter a before value:");
    scanf("%d",&before_val);
    printf("\nEnter value to be inserted:");
    scanf("%d",&val);
    ptr = start;
    pp = ptr;
    while (ptr->data != val)
    {
        pp = ptr;
        ptr = ptr->next;
    }
    nn = (struct node*)malloc(sizeof(struct node));
    nn->data = val;
    nn->next = ptr;
    pp->next = nn;
    return start;
} 
struct node *insert_after(struct node *start){
    int after_val,val;
    struct node *nn,*ptr,*pp;
    printf("\nEnter a after value:");
    scanf("%d",&after_val);
    printf("\nEnter a value:");
    scanf("%d",&val);
    ptr = start;
    pp = ptr;
    while (pp->data != val)
    {
        pp = ptr;
        ptr =  ptr->next;
    }
    nn = (struct node*)malloc(sizeof(struct node));
    nn->data = val;
    nn->next = ptr;
    pp->next = nn;
    return start;
    
}
struct node *delete_beg(struct node *start){
    struct node *ptr;
    ptr = start;
    start = start ->next;
    free(ptr);
    return start;
}
struct node *delete_end(struct node *start){
    struct node *ptr,*pp;
    ptr = start;
    pp = ptr;
    while (ptr->next != NULL)
    {
        pp = ptr;
        ptr = ptr ->next;
    }
    pp->next = NULL;
    free(ptr);
    return start;
}
struct node *delete_node(struct node *start){
    int val;
    struct node *ptr,*pp;
    ptr = start;
    pp = ptr;
    printf("\nEnter the value:");
    scanf("%d",&val);
    if (ptr->data == val)
    {
        start = delete_beg(start);
        return start;
    }
    else {
    while (ptr->data != val)
    {
        pp = ptr;
        ptr = ptr ->next;
    }
    }
        pp->next = ptr->next;
    free(ptr);
    return start;
}
struct node *delete_after(struct node *start){
    int val;
    struct node *ptr,*pp;
    ptr = start;
    pp = ptr;
    while (pp->data != val)
    {
        pp = ptr;
        ptr = ptr ->next;
    }
  pp->next = ptr->next;
  free(ptr);
  return start;
}
struct node *delete_list(struct node *start){
    struct node *ptr;
    if (start !=  NULL)
    {
        ptr = start;
        while(ptr != NULL)
        {
            printf("the value to be deleted is :%d",ptr->data);
            start = delete_beg(start);
            ptr = start;

        }
        
    }
    return start;
}
struct node *sort_list(struct node *start){
    struct node *ptr1,*ptr2;
    int temp;
    ptr1= start;

    while (ptr1 != NULL)
    {
            ptr2 = ptr1->next;
        while (ptr2 != NULL)
        {
            if (ptr1->data > ptr2->data)
            {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2 ->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return start;
}