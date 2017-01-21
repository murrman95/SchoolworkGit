#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node Node;
struct node{
  char pName;
  int pTime;
  int pPriority;
  struct Node *next;
}

Node *addProcess(Node *head, char name, int time, int priority);
bool isEmpty(Node *head);

int main(){
  return 0;
}

Node *addProcess(Node *head, char name, int time, int priority){
  Node *current = head;
  Node *newProcessNode = NULL;

  newProcessNode = malloc(sizeof(Node));
  newProcessNode -> pName = name;
  newProcessNode -> pTime = time;
  newProcessNode -> pPriority = priority;
  newProcessNode -> next = NULL;

  if(isEmpty(current)){
    head = newProcessNode;
  }
  else{
    Node *previous = current;
    while(current != NULL && newProcessNode->pPriority > current->pPriority){
      previous = current;
      current = current->next;
    }
    if(current == NULL){
      previous->next = newProcessNode;
    }
    else{
      if(previous == current){
        newProcessNode -> next = current;
        head = newProcessNode;
      }
      else{
        newProcessNode -> next = current;
        previous -> next = newProcessNode;
      }
    }
  }
  return head;
}

bool isEmpty(Node *head){
  Node *current = head;
  if(current){
    return true;
  }
  else{
    return false;
  }
}
