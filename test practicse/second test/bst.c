#include<stdio.h>
#include<malloc.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
struct node *tree;

void create_tree(struct node **);
struct node *insert_element(struct node *tree,int);
void preorderTraversal(struct node *tree);
void inorderTraversal(struct node *tree);
void postorderTravsal(struct node *tree);
struct node *findSmallestElement(struct node *tree);
struct node *findLargestElement(struct node *tree);
int totalNodes(struct node *tree);
struct node *deleteTree(struct node *tree);
struct node *deleteElement(struct node *tree,int);
int totalExternalNodes(struct node *tree);
int totalInternalNodes(struct node *tree);
int height(struct node*);
void main() {
    int choice, val;
    struct node* ptr;
    create_tree(&tree);
    do {
        printf("\nRonitSatishMehta 6009230207");
        printf("\n\t------------MAIN MENU ---------\n");
        printf("\n1.Insert Element");
        printf("\n2.preorder traversal");
        printf("\n3.inorder traversal");
        printf("\n4.postorder traversal");
        printf("\n5.Find the smallest element");
        printf("\n6.Find the largest Element");
        printf("\n7. count the total number of nodes");
        printf("\n8.delete The tree");
        printf("\n9.delete an element");
        printf("\n10.mirrorImage of tree");
        printf("\n11.total internal nodes");
        printf("\n12.total external nodes");
        printf("\n13.height of tree");
        printf("\n14.Exit");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\n Enter the value of the new node : ");
                scanf("%d", &val);
                tree = insert_element(tree, val);
                break;
            case 2:
                printf("\n The elements of the tree are : \n");
                preorderTraversal(tree);
                break;
            case 3:
                printf("\n The elements of the tree are : \n");
                inorderTraversal(tree);
                break;
            case 4:
                printf("\n The elements of the tree are : \n");
                postorderTraversal(tree);
                break;
            case 5:
                ptr = findSmallestElement(tree);
                printf("\n Smallest element is: %d", ptr->data);
                break;
            case 6:
                ptr = findLargestElement(tree);
                printf("\n Largest element is: %d", ptr->data);
                break;
            case 7:
                printf("\n Total no. of nodes = %d", totalNodes(tree));
                break;
            case 8:
                tree = deleteTree(tree);
                break;
            case 9:
                printf("\nEnter val to be deleted:");
                scanf("%d", &val);
                tree = deleteElement(tree, val);
                break;
            case 10:
                tree = mirrorImage(tree);
                printf("\nThe mirror image of tree is created.");
                break;
            case 11:
                printf("\nTotal number of the internal node=%d ", totalInternalNodes(tree));
                break;
            case 12:
                printf("\nTotal number of the external nodes=%d", totalExternalNodes(tree));
                break;
            case 13:
                printf("\nThe height of the tree is = %d", height(tree));
                break;
            case 14:
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid Choice");
                break;
        }
    } while (choice != 14);

}
void create_tree(struct node **tree){
    *tree = NULL;
}
struct node *insert_element(struct node *tree,int val){
    struct node *ptr,*nodeptr,*parentptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    if (tree == NULL)
    {
        tree = ptr;
        tree->left = NULL;
        tree ->right = NULL;
    }
    else{
        parentptr = NULL;
        nodeptr = tree;
        while (nodeptr !=NULL)
        {
            parentptr = nodeptr;
            if (val<nodeptr->data)
            {
                nodeptr = nodeptr->left;
            }
            else{
                nodeptr = nodeptr->right;
            }
        }
        if (val<parentptr->data)
        {
            parentptr->left = ptr;
        }
        else{
            parentptr->right = ptr;
        }
        
    }
    return tree;
}
void preorder_traversal(struct node *tree){
    if (tree != NULL)
    {
        printf("%d\t",tree->data);
        preorder_traversal(tree->left);
        preorder_traversal(tree->right);
    }
    
}
void inorder_traversal(struct node *tree){
    if (tree != NULL)
    {
        inorder_traversal(tree->left);
        printf("%d\t",tree->data);
        inorder_traversal(tree->right);
    }
    
}
void postorder_traversal(struct node *tree){
    if (tree != NULL)
    {
        postorder_traversal(tree->left);
        postorder_traversal(tree->right);
        printf("%d\t",tree->data);
    }
    
}
struct node *findSmallestElement(struct node *tree){
    if (tree == NULL || tree->left == NULL)
    {
        return tree;
    }
    else{
        return findSmallestElement(tree->left);
    }
}
struct node *findLargestElement(struct node *tree){
    if (tree == NULL || tree ->right == NULL)
    {
        return tree;
    }
    else{
        return findLargestElement(tree->right);
    }
}
int totalNodes(struct node *tree){
    if (tree == NULL)
    {
        return 0;
    }
    else{
        return (totalNodes(tree->left)+totalNodes(tree->right)+1);
    }
}
struct node *deleteTree(struct node *tree){
    if (tree != NULL)
    {
        deleteTree(tree->left);
        deleteTree(tree->right);
        free(tree);
    }
    return NULL;
}
struct node *deleteElement(struct node* tree,int val){
    struct node *cur,*parent,*suc,*psuc,*ptr;
    if (tree == NULL)
    {
        printf("\nTree is Empty");
        return tree;
    }
    parent = tree;
    cur = tree;
    while (cur != NULL && val != cur->data)
    {
        parent = cur;
        if (val<cur->left)
        {
            cur = cur->left;
        }
         else{
            cur = cur->right;
         }
    }
    if (cur == NULL)
    {
        printf("\nThe value not found");
        return tree;
    }
    if (cur->left == NULL)
    {
        ptr = cur->right;
    }
    else if(cur->right == NULL){
        ptr = cur->left;
    }
    else
    {
        psuc = cur;
        suc = cur->left;
        while (suc->right!=NULL)
        {
            psuc = suc;
            suc = suc->right;
        }
        if (cur == psuc)
        {
            suc->right = cur->right;
        }
        else{
            suc->right = cur->right;
            psuc->right = suc->left;
            suc->left = cur->left;
        }
        ptr = suc;
    }
    if (parent->left == cur)
    {
        parent->left = ptr;
    }
    else{
        parent->right = ptr;
    }
    free(cur);
    return tree;
}
struct node *mirrorImge(struct node *tree){
    struct node *ptr;
    if (tree != NULL)
    {
        mirrorImge(tree->left);
        mirrorImge(tree->right);
        ptr = tree->left;
        tree->left = tree->right;
        tree->right = ptr;
    }
    return tree;
    
}
int totalInternalNodes(struct node *tree){
    if (tree == NULL || (tree->left == NULL) && (tree->right == NULL))
    {
        return 0;
    }
    else{
        return totalInternalNodes(tree->left)+totalInternalNodes(tree->right);
    }
}
int totalExternalNodes(struct node *tree){
    if (tree == NULL)
    {
        return 0;
    }
    else if(tree->left == NULL && tree->right == NULL){
        return 1;
    }
    else{
        return totalExternalNodes(tree->left)+totalExternalNodes(tree->right);
    }
}
int height(struct node* tree){
    int leftheight,righheight;
    if (tree == NULL)
    {
        return 0;
    }
    else{
        leftheight = height(tree->left);
        righheight = height(tree ->right);
        return (leftheight>righheight)?(leftheight+1):(righheight+1);
    }
}