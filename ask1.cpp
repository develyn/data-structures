#include <stdio.h>
#include <stdlib.h>


typedef int TItem;

typedef struct TDynamicStackTAG
{
	TItem				Item;
	TDynamicStackTAG	*Next;
} TDynamicStack;

void DynamicStack_Init(TDynamicStack **s)
{
	*s = NULL;
}

bool DynamicStack_IsEmpty(TDynamicStack *s)
{
	return ( s == NULL );
}

bool DynamicStack_Push(TDynamicStack **s, TItem Item)
{
	TDynamicStack	*NewItem;


	NewItem = (TDynamicStack *) malloc(sizeof(TDynamicStack));
	if ( NewItem != NULL )
	{
		NewItem->Item = Item;
		NewItem->Next = *s;
		*s = NewItem;

		return ( true );
	}
	else
	{
		return ( false );
	}
}

bool DynamicStack_Pop(TDynamicStack **s, TItem *Item)
{
	if ( *s == NULL ) return ( false );

	TDynamicStack	*Tmp = *s;
	*s = (*s)->Next;
	*Item = Tmp->Item;
	free(Tmp);
	return ( true );
}

bool DynamicStack_Top(TDynamicStack *s, TItem *Item)
{
	if ( s == NULL ) return ( false );
	*Item = s->Item;
	return ( true );
}

int DynamicStack_Count(TDynamicStack *s)
{
	TDynamicStack	*Tmp = s;
	int				Counter = 0;


	while ( Tmp != NULL )
	{
		Tmp = Tmp->Next;
		Counter++;
	}

	return ( Counter );
}

void DynamicStack_Deallocate(TDynamicStack **s)
{
	TDynamicStack	*Tmp = *s;


	while ( *s != NULL )
	{
		*s = (*s)->Next;
		free(Tmp);
		Tmp = *s;
	}
}

bool DynamicStuck_SafeRemove(TDynamicStack **s, TItem rem, int *ItemsRemoved)
{
	TDynamicStack	*Tmp = NULL;
	int				Counter = 0;
	while (*s != NULL)
	{
		if (s != 50)
		{
			*s = (*s)->Tmp;
		}
		else
		{
			Counter++;
		}
	}
	while (*Tmp != NULL)
	{
		Tmp = (Tmp)->*s;
	}
	return Counter;
}

void main()
{
	TDynamicStack	*Head;
	TItem			Item;


	DynamicStack_Init(&Head);
	printf("Head = 0x%08X\n", Head);
	if ( DynamicStack_IsEmpty(Head) )
		printf("Stack is Empty\n");
	else
		printf("Stack is NOT Empty\n");

	printf("\n");
	printf("Push 10 onto stack.\n");
	printf("------------------------------------------------\n");
	printf("Items on stack: %2d\n", DynamicStack_Count(Head));
	DynamicStack_Push(&Head, 10);
	printf("Head = 0x%08X\n", Head);
	printf("Items on stack: %2d\n", DynamicStack_Count(Head));

	printf("\n");
	printf("Pop 10 from stack.\n");
	printf("------------------------------------------------\n");
	DynamicStack_Pop(&Head, &Item);
	printf("Head = 0x%08X\n", Head);
	printf("Item = %d\n", Item);
	printf("Items on stack: %2d\n", DynamicStack_Count(Head));

	printf("\n");
	printf("Push 20 onto stack.\n");
	printf("------------------------------------------------\n");
	DynamicStack_Push(&Head, 20);
	printf("Head = 0x%08X\n", Head);
	printf("Items on stack: %2d\n", DynamicStack_Count(Head));

	printf("\n");
	printf("Read top of stack.\n");
	printf("------------------------------------------------\n");
	DynamicStack_Top(Head, &Item);
	printf("Head = 0x%08X\n", Head);
	printf("Item = %d\n", Item);

	printf("\n");
	printf("Push 30 onto stack.\n");
	printf("------------------------------------------------\n");
	DynamicStack_Push(&Head, 30);
	printf("Head = 0x%08X\n", Head);
	printf("Items on stack: %2d\n", DynamicStack_Count(Head));

	printf("\n");
	printf("Read top of stack.\n");
	printf("------------------------------------------------\n");
	DynamicStack_Top(Head, &Item);
	printf("Head = 0x%08X\n", Head);
	printf("Item = %d\n", Item);

	printf("\n");
	printf("Deallocate stack.\n");
	printf("------------------------------------------------\n");
	DynamicStack_Deallocate(&Head);
	printf("Items on stack: %2d\n", DynamicStack_Count(Head));
	printf("Head = 0x%08X\n", Head);
}
