#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node{
  char pName;
  int pTime;
  int pPriority;
  struct node *next;
} Node;

Node *addProcess(Node *head, char name, int time, int priority);
bool isEmpty(Node *head);
void printProcesses(Node *head);

int main(){
  Node *list = NULL;
  char endLine;
  char cVal;;
  int pVal;
  int dVal;

  printf("Step1\n");
  while(!feof(stdin)){
      scanf("%c", &cVal);
      scanf("%d", &pVal);
      scanf("%d", &dVal);
      scanf("%c", &endLine);
      printf("%c %d %d\n", cVal, pVal, dVal);
      list = addProcess(list, cVal, dVal, pVal);
  }


  printf("Step2\n");
  printProcesses(list);
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

  if(current == NULL){
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

void printProcesses(Node *head){
  printf("Time\tProcess\n");
  Node *current = head;
  int timeCounter = 0;
  while(current != NULL){
    if(current->pTime <= 0){
      current = current->next;
      if(current == NULL){
        break;
      }
    }
    printf("%d\t%c\n", timeCounter, current->pName);
    current->pTime --;
    timeCounter ++;
  }
}
