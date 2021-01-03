#include <stdio.h>
#include <stdlib.h>
struct node {
  int info;
  struct node *llink,*rlink;
};typedef struct node *Node;
Node getnode(int item) {
  Node temp = (Node )malloc(sizeof(struct node));
  temp->info = item;
  temp->llink = temp->rlink = NULL;
  return temp;
}
Node insert(Node node, int info) {
  if (node == NULL)
    return getnode(info);
  if (info < node->info)
    node->llink = insert(node->llink, info);
  else
    node->rlink = insert(node->rlink, info);
  return node;
}
void preorder(Node root) {
  if(root == NULL){
    return;
  }
  printf("%d -> ",root->info);
  preorder(root->llink);
  preorder(root->rlink);
}
void inorder(Node root) {
  if(root == NULL){
    return;
  }
  inorder(root->llink);
  printf("%d -> ",root->info);
  inorder(root->rlink);
}
void postorder(Node root) {
  if(root == NULL){
    return;
  }
  postorder(root->llink);
  postorder(root->rlink);
  printf("%d -> ",root->info);
}
void display(Node root,int i)
{
  int j;
  if(root!=NULL)
  {
    display(root->rlink,i+1);
    for(j=0;j<i;j++)
      printf("  ");
    printf("%d\n",root->info);
    display(root->llink,i+1);
  }
}
int main(){
  Node root = NULL;
  int choice,item;
  for(;;){
    printf("\n1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Display\n6.exit\n");
    printf("Enter choice : ");
    scanf("%d",&choice);
    switch(choice){
      case 1:printf("Enter item to be inserted : ");
            scanf("%d",&item);
            root = insert(root,item);
            break;
      case 2:printf("Preorder traversal: ");
          preorder(root);
            break;
      case 3:printf("Inorder traversal: ");
            inorder(root);
            break;
      case 4:printf("Postorder traversal: ");
            postorder(root);
            break;
      case 5:display(root,0);
            break;
      case 6:exit(0);
      default:printf("Enter proper instructions!!\n");
            break;
    }
  }
  return 0;
}
