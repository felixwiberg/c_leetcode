/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <math.h>

struct ListNode{
	int val;
	struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

	int n = 0;
	int sum1 = 0;
	int sum2 = 0;
	while(l1 != NULL){
		sum1 += pow(10, n)*l1->val;
		printf("%d %d\n", n, sum1);
		l1 = l1->next;
		n++;
	}
	
	n = 0;	
	while(l2 != NULL){
		sum2 += pow(10, n)*l2->val;
		printf("%d %d\n", n, sum2);
		l2 = l2->next;
		n++;
	}

	int sum3 = sum1+sum2;

	struct ListNode* head = NULL;
	head = malloc(sizeof *head);
	struct ListNode* current = NULL;
	current = head;
	while(sum3 != 0){
		struct ListNode* next = NULL;
		next = malloc(sizeof *next);
		current->val = sum3%10;
		sum3 /= 10;
		current->next = next;
		current = next;	
	}

	return head;
}


int main(){
	struct ListNode* l1_head = NULL;
	struct ListNode* l1_second = NULL;
	struct ListNode* l1_third = NULL;
       
	struct ListNode* l2_head = NULL;
	struct ListNode* l2_second = NULL;
	struct ListNode* l2_third = NULL;
	
	l1_head = malloc(sizeof *l1_head);
	l1_second = malloc(sizeof *l1_second);
	l1_third = malloc(sizeof *l1_third);

	l2_head = malloc(sizeof *l2_head);
	l2_second = malloc(sizeof *l2_second);
	l2_third = malloc(sizeof *l2_third);
	
	l1_head->val = 1;
	l1_second->val = 2; 
	l1_third->val = 3;
	l2_head->val = 4;
	l2_second->val = 5;
	l2_third->val = 6;

	l1_head->next = l1_second;
	l1_second->next = l1_third;
	l1_third->next = NULL;
	l2_head->next = l2_second;
	l2_second->next = l2_third;
	l2_third->next = NULL;

	struct ListNode* returnlist;
	returnlist = addTwoNumbers(l1_head, l2_head);
	printf("%d\n",returnlist->val);
	returnlist = returnlist->next;
	printf("%d\n",returnlist->val);
	returnlist = returnlist->next;
	printf("%d\n",returnlist->val);

	free(l1_head);
	free(l1_second);
	free(l1_third);
	free(l2_head);
	free(l2_second);
	free(l2_third);
	free(returnlist);
	return 0;
}
