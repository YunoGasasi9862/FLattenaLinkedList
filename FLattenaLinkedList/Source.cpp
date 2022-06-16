#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "Header.h"

node_t* createList(node_t* hp)
{
	//creating the first row of nexts
	node_t* temp;
	printf("Enter the list in the vertical order: (-1 to stop) ");
	int number;
	scanf("%d", &number);
	hp = addBegininning(hp, number);
	temp = hp;
	while (temp != NULL)
	{
		scanf("%d", &number);
		if (number != -1)
		{
			AddAfterNext(temp, number);

		}
		temp = temp->next;

	}

	temp = hp;
	node_t* down = temp;
	//down list
	while (temp != NULL)
	{
		printf("Enter a horizontal list for the node %d previously entered node: (-1 to change to the next node) : ", temp->data);
		scanf("%d", &number);

		while (number != -1)
		{
			if (number != -1)
			{
				AddAfterDown(down, number);
				down = down->down;


			}
			scanf("%d", &number);

			
		}
		temp = temp->next;
		down = temp;



	}

	return hp;
}
node_t* search(node_t* hp, LType data)
{
	node_t* temp = hp;
	while (temp->next != NULL && data > temp->next->data)
	{
		temp = temp->next;
	}

	return temp;

}
void printFlatten(node_t* hp)
{
	while (hp != NULL)
	{
		printf("%d -> ", hp->data);
		hp = hp->next;
	}
	printf("NULL\n");
}
node_t* flattenList(node_t* hp)
{
	node_t* temp = hp;
	node_t* tempdown = temp->down;
	node_t* node = hp;
	while (temp != NULL)
	{
		//converting all horizontal to vertical points

		while (tempdown!= NULL) //for every down list
		{
		    node = search(hp, tempdown->data);
			AddAfterNext(node, tempdown->data);
			tempdown = tempdown->down;
		}
		temp = temp->next;
		if(temp!=NULL && temp->down!=NULL)
	  	 tempdown = temp->down;
	}

	return hp;
}
int main(void)
{
	node_t* hp = NULL;
	hp=createList(hp);
	node_t* newHp = flattenList(hp);
	printFlatten(newHp);
	return 0;
}


//for binary spiral order: push the root into stack 1
//while stack1 or stack2 is not empty -> while stack1is not empty, pop, and push from right to left in stack2
