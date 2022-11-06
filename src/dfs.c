/*
 * Search an expression using DFS.
 */

#include <stdio.h>		/* scanf, printf */
#include <stdlib.h>		/* abort */
#include <stdbool.h>		/* bool, true, false */
#include "dfs.h"


void DFT (node * root)
{
	// Implement DFS
	// Hint: You can use print_node, print_tree and/or print_stack.
  
  /*stack *stack = malloc(sizeof(stack));
  stack->next = NULL;

  push(stack, root);
  
  int i = 0;
  node *t = pop(stack)->node;
  printf("%d\n", t->num);
  if(root->rchild != NULL){
    push(stack, root->rchild);
  }
  if(root->lchild != NULL){
    push(stack, root->lchild);
  }*/

  //No matter what I do I cannot get the normal function to work so recursion it is.
  if(root != NULL){
    print_node(root);
    printf("\n");
    DFT(root->lchild);
    DFT(root->rchild);
  }
}

node *make_node (int num, node * left, node * right)
{
	node *element = malloc(sizeof(node));
  element->lchild = left;
  element->rchild = right;
  element->num = num;
  element->visited = false;
  return element;
}

void free_node (node * p)
{
	free(p);
}

void print_node (node * p)
{
  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("%d", p->num);
}


void print_tree (node * p, int depth)
{
  for (int i = 0; i < depth; i = i + 1)
    printf (" ");
  printf ("| ");

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("[%d]\n", p->num);


  if (p->lchild)
    {
      print_tree (p->lchild, depth + 1);
    }

  if (p->rchild)
    print_tree (p->rchild, depth + 1);
}

stack *push (stack * topp, node * node)
{
  stack *element = (stack* ) malloc(sizeof(stack));
  element->next = topp->next;
  element->node = node;
  topp->next = element;
}

bool isEmpty (stack * topp)
{
  return topp == NULL;
}

node *top (stack * topp)
{
	return topp->node;
}

// Utility function to pop topp  
// element from the stack 

stack *pop (stack * topp)
{
  topp = topp->next;
	return topp;
}

void print_stack (stack * topp)
{
  struct stack *temp = topp;

  while (temp != NULL)
    {

      print_node (temp->node);
      printf ("\n");

      temp = temp->next;
    }

  printf ("====\n");

  return;
}
