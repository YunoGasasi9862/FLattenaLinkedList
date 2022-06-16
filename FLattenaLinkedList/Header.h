#pragma once
typedef int LType;
typedef struct node_s
{
	LType data;
	node_s* next;
	node_s* down;

}node_t;

node_t* getNode(void)
{
	node_t* tp;
	tp = (node_t*)malloc(sizeof(node_t));
	tp->next = NULL;
	tp->down = NULL;
	return tp;
}

node_t* addBegininning(node_t* hp, LType data)
{
	node_t* tp;
	tp = getNode();
	tp->next = hp;
	tp->data = data;
	return tp;
}

void AddAfterNext(node_t* hp, LType data)
{

	node_t* tp;
	tp = getNode();
	tp->next = hp->next;
	hp->next = tp;
	tp->data = data;
}

void AddAfterDown(node_t* hp, LType data)
{
	node_t* tp;
	tp = getNode();
	tp->down = hp->down;
	hp->down = tp;
	tp->data = data;

}

node_t* DeleteStart(node_t* hp)
{
	node_t* temp;
	temp = hp;
	hp = hp->next;
	free(temp);
	return hp;
}

void DeleteNext(node_t* hp)
{
	node_t* temp;
	temp = hp->next;
	hp->next = temp->next;
	free(temp);
}
void DeleteDown(node_t* hp)
{
	node_t* temp;
	temp = hp->down;
	hp->down = temp->down;
	free(temp);
}