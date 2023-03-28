#include "stive.h"

Data top(Node *top)
{
	if (isEmpty(top)) return CHAR_MIN;
	return top->val;
}

void push(Node**top, Data v)
{
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->val=v;
	newNode->next=*top;
	*top=newNode;
}

Data pop(Node**top)
{
	if (isEmpty(*top)) return CHAR_MIN;
	Node *temp=(*top);
	Data aux=temp->val;
	*top=(*top)->next;
	free(temp);
	return aux;
}

int isEmpty(Node*top)
{
	return top==NULL;
}

void deleteStack(Node**top)
{
	Node  *temp;
	while (!isEmpty(*top))
    {temp=*top;
    *top=(*top)->next;
    free(temp);
	}
}
void subpunc_b()
{
    Node *stiva=NULL;
    char test[10]="()(())())";
    int i,j=0;
    for(i=0;i<strlen(test);i++)
     {
        if(test[i]=='(')
           {    j++;
            push(&stiva,test[i]);
            }
    if(stiva==NULL)
        printf("%d ",i);
       else if(test[i]==')')
            {
            pop(&stiva);
            j--;
            }
     }
    while(stiva!=NULL)
    {
        pop(&stiva);
        printf("%d ",j-1);
        j--;
    }
}
