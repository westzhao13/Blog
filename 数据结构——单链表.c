ʲô������

���ȣ�������һ�����Ե���ʽ�洢�����ݽṹ�������� ˵������������һ��һ��Ҳ���ǡ��ڵ㡱��ɡ�
��������֣�������˫�������ѭ������

�������ڵ�1��Begin��->�ڵ�2->�ڵ�3->�ڵ�4->END

�ڵ�1Ϊͷ��ENDΪ������Ҳ��˵�ڵ�4Ϊ�����β ��->�� Ϊ���ӵķ�ʽ��
������������������ļ�ʵ�֣������˼򵥵��ԣ���������Ϊ��򵥵������Ҿ����ص�����"->"���ӷ�ʽ�����������ӷ�ʽ�����ø��������ͼ����ʽ��⡣

����������֮��Ĳ�����ڣ����������ԵĲ�������ڶ�ջ�еĴ洢�ռ��������ģ������ǲ������ģ�����ڵ��ڵ�ַ0x100����һ���ڵ�����ܵ�0x200ȥ�ˡ�
��Ϊ����Ľṹ���ԣ������Ե��������ڲ��룬ɾ���������䷽�㣬���ҿ졣ͬ���Ĳ�����������ȥʵ�־ͻ��Եø��Ӷࡣ
�����˾��ã�Ҳ�в�������ĵط����������飬�������ĸ���ֱ�������±�ȥȡֵ���ɣ�����������������������������ȥѰ������
�����������飬�����бף����Զ��г����Ͷ̴�������Ӧ�õÿ����ϡ��Ͼ���Ҷ���һ�����ݵĽṹ�� ^ ^   // ------ westzhao 2017/9/2

/*************************************************************************
	> File Name: list.c
	> Author: westzhao 
	> Created Time: 2017/08/30 Wed 22:36:36
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct NODE
{
	int value;
	struct NODE *next;
}list;


int initList(list **head, int value);
int insertTail(list **node, int value);
int insertNode(list **node, int value, int position);
int deleteNode(list **node, int position);
int deleteList(list **head);
int getListLen(list **node);
int printList(list **head);


/*
 * Function: initList
 * Author: westzhao
 */
int initList(list **head, int value)
{
	*head = (list *)malloc(sizeof(list));
	if(*head == NULL)
	{
		printf("head node alloc failed!\r\n");
		return -1;
	}
	
	(*head)->value = value;
	(*head)->next = NULL;

	return 1;
}


/*
 * Function: insertTail
 *		     insert new node at the tail of list
 * Author: westzhao
 */
int insertTail(list **node, int value)
{
	list *current;
	list *new;
	
	current = *node;
	
	/* find the last node */
	while(current->next != NULL && current != NULL)
	{
		current = current->next;
	}
	
	new = (list *)malloc(sizeof(list));
	if(new == NULL)
	{
		printf("new node alloc mem failed!\r\n");
		return -1;
	}
	
	new->value = value;
	new->next = NULL;

	if(current == NULL)
	{
		/* the list is empty add the head of the list */
		current = new;
	}
	else
	{
		current->next = new;
	}

	return 1;
}


/*
 * Function: insertNode
 *		     insert new node by the position
 * Author: westzhao
 */
int insertNode(list **node, int value, int position)
{
	int current_pos;
	list *new;
	list *before;
	list *current;
	
	if(position <= 0)
	{
		printf("position:%d error\r\n", position);
		return -1;
	}
	
	current = *node;
	if(current == NULL)
	{
		printf("head node empty\r\n");
		return -1;
	}
	
	new = (list *)malloc(sizeof(list));
	if(new == NULL)
	{
		printf("new node alloc mem failed!\r\n");
		return -1;
	}

	for(current_pos = position; current_pos>0; current_pos--)
	{
		if(current != NULL)
		{
			before = current;
			current = current->next;
		}
	}

	new->value = value;
	
	before->next = new;
	new->next = current;

	return 1;
}


/*
 * Function: deleteNode
 *		     delete the Node by position
 * Author: westzhao
 */
int deleteNode(list **node, int position)
{
	int current_pos;
	list *before;
	list *current;

	if(position == 0)
	{
		printf("position:%d error\r\n", position);
		return -1;
	}
	
	current = *node;
	if(current == NULL)
	{
		printf("head node empty\r\n");
		return -1;
	}
	
	for(current_pos = position; current_pos>0; current_pos--)
	{
		if(current != NULL)
		{
			before = current;
			current = current->next;
		}
		else
		{
			printf("pos:%d out of range\r\n", position);
			return -1;
		}
	}
	
	before->next = current->next;
	free(current);
	
	return 1;
}


/*
 * Function: deleteList
 *		     delete all of the list
 * Author: westzhao
 */
int deleteList(list **head)
{
	int pos;
	list *current;
	
	if(*head == NULL)
	{
		printf("list head NULL\r\n");
		return -1;
	}
	
	pos = getListLen(head);
	current = *head;
	
	while(pos > 1)
	{
		deleteNode(&current, pos-1);
		pos--;
	}
	
	free(current);
	*head = NULL;

	return 1;
}


/*
 * Function: getListLen
 *		     get length of the list
 * Author: westzhao
 */
int getListLen(list **node)
{
	int length = 0;
	list *current;
	
	if(*node == NULL)
	{
		printf("list empty");
		return -1;
	}

	current = *node;
	while(current != NULL)
	{
		current = current->next;
		length ++;
	}

	return length;
}


/*
 * Function: printList
 *		     print all of the list
 * Author: westzhao
 */
int printList(list **head)
{
	if(*head == NULL)
	{
		printf("list empty\r\n");
		return -1;
	}
	
	list *temp = *head;
	
	do
	{
		printf("%d\t", temp->value);
		temp = temp->next;
	}while(temp != NULL);

	printf("\r\n");

	return 1;
}


int main()
{
	list *head;
	
	initList(&head, 1);
    insertTail(&head, 12);
	insertTail(&head, 23);
	insertTail(&head, 100);
	insertNode(&head, 2, 1);
//	insertNode(&head, 2, 1);
//	insertNode(&head, 42, 2);
    //insertNode(&head, 12312, 7);
	printf("list len:%d \r\n", getListLen(&head));
    printList(&head);
	deleteNode(&head, 1);
	printf("list len:%d \r\n", getListLen(&head));
	printList(&head);
	deleteList(&head);
	printList(&head);

	return 0;
}