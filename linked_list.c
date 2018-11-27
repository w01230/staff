#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

#define LEN sizeof(struct student)

struct student 
{
	int num;
	float score;
	struct student *next;
};

int n = 0;

/*
 * create 
 *
 * create linked list
 */

struct student *create(void)
{
	struct student *head, *p1, *p2;

	n = 0;
	p1 = (struct student *)malloc(LEN);
	p2 = p1;
	scanf("%d %f", &p1->num, &p1->score);

	while(p1->num != 0) {
		n = n + 1;
		if (n == 1)
			head = p1;
		else
			p2->next = p1;
		p2 = p1;
		p1 = (struct student *)malloc(LEN);
		scanf("%d %f", &p1->num, &p1->score);
	}
	p2->next = NULL;

	return head;
}	

/* 
 * del
 *
 * del items form linked list
 */

struct student *del(struct student *head, long num)
{
	struct student *p1, *p2;

	if (head == NULL) {
		printf("null head of the linked list\n");
		return head;
	}

	p1 = head;
	
	while(num != p1->num && p1->next != NULL) {
		p2 = p1;
		p1 = p1->next;
	}

	if (num == p1->num) {
		if (p1 == head)
			head = p1->next;
		else
			p2->next = p1->next;
		printf("delet:%d\n", num);
		free(p1);
		n = n - 1;
	} else {
		printf("%d not been found\n", num);
	}

	return head;
}

/*
 * insert
 *
 * insert to linked list
 */

struct student *insert(struct student *head, struct student *new)
{
	struct student *p0, *p1, *p2;
	p1 = head;
	p0 = new;

	if (head == NULL) {
		head = p0;
		p0->next = NULL;
	} else {
		while(p0->num > p1->num && p1->next != NULL) {
			p2 = p1;
			p1 = p1->next;
		}

		if (p0->num <= p1->num ) {
			if (head == p1)
				head = p0;
			else
				p2->next = p0;
			p0->next = p1;
		} else {
			p1->next = p0;
			p0->next = NULL;
		}
	}

	n = n + 1;

	return head;
}

/*
 * print
 *
 * print linked list
 */

struct student *print(struct student *head)
{
	struct student *p;

	p = head;
	if (head == NULL) {
		printf("null linked list\n");
		return head;
	}

	do {
		printf("%d %f\n", p->num, p->score);
		p = p->next;
	} while (p != NULL);

	return head;
}


/*
 * main
 *
 *
 * linked list test 
 */

int main(int argc, char *argv[])
{
	struct student *head, *student;
	long del_num;

	printf("input recoreds:\n");
	head = create();
	print(head);

	printf("input the num to delete:\n");
	scanf("%ld", &del_num);
	head = del(head, del_num);
	print(head);

	printf("input the num to add:\n");
	student = (struct student *)malloc(LEN);
	scanf("%d %f", &student->num, &student->score);
	head = insert(head, student);
	print(head);

	return 0;
}

