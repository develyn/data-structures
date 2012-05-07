#include <stdio.h>
#include <stdlib.h>

#define		MAX_STACK_SIZE		10



typedef int TItem;

typedef struct
{
	TItem	Array[MAX_STACK_SIZE];
	int		Index;
} TStaticStack;

void StaticStack_Init(TStaticStack *s)
{
	for ( int i = 0;   i < MAX_STACK_SIZE;   i++ ) s->Array[i] = 0;
	s->Index = 0;
}

bool StaticStack_IsEmpty(TStaticStack s)
{
	return ( s.Index == 0 );
}

bool StaticStack_Push(TStaticStack *s, TItem Item)
{
	if ( s->Index < MAX_STACK_SIZE )
	{
		s->Array[s->Index] = Item;
		s->Index++;
		return ( true );
	}
	else
	{
		return ( false );
	}
}

bool StaticStack_Pop(TStaticStack *s, TItem *Item)
{
	if ( s->Index > 0 )
	{
		s->Index--;
		*Item = s->Array[s->Index];
		return ( true );
	}
	else
	{
		return ( false );
	}
}

bool StaticStack_Top(TStaticStack s, TItem *Item)
{
	if ( s.Index > 0 )
	{
		*Item = s.Array[s.Index - 1];
		return ( true );
	}
	else
	{
		return ( false );
	}
}

void main()
{
	TStaticStack	stack;
	TItem			item;


	printf("\nStaticStack_Init\n");
	printf("---------------------------\n");
	StaticStack_Init(&stack);

	printf("\nStaticStack_Push\n");
	printf("---------------------------\n");
	while ( StaticStack_Push(&stack, random(100)) )
		printf("Push: [%d] = %3d\n", stack.Index - 1, stack.Array[stack.Index - 1]);

	printf("\nStaticStack_Pop\n");
	printf("---------------------------\n");
	while ( StaticStack_Pop(&stack, &item) )
		printf("Pop: [%d] = %3d\n", stack.Index, stack.Array[stack.Index]);
}
