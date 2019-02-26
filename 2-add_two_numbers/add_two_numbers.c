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

	int n, tmp_sum = 0, sum_of_list_vals = 0;
	while(l1 != NULL){
		tmp_sum += pow(10, n)*l1->val;
		l1 = l1->next;
		n++;
	}
	sum_of_list_vals += tmp_sum;	

	n = 0;
	tmp_sum = 0;
	while(l2 != NULL){
		tmp_sum += pow(10, n)*l2->val;
		l2 = l2->next;
		n++;
	}
	sum_of_list_vals += tmp_sum;	

	struct ListNode* head = NULL;
	head = malloc(sizeof *head);
	struct ListNode* current = NULL;
	current = head;
	
	while(sum_of_list_vals != 0){
		current->val = sum_of_list_vals%10;
		printf("%d %d\n", current->val, sum_of_list_vals);
		sum_of_list_vals /= 10;
		printf("%d %d\n\n", current->val, sum_of_list_vals);
		
		struct ListNode* next = NULL;
		
		if(sum_of_list_vals!=0){
			next = malloc(sizeof *next);
			current->next = next;
			current = next;	
		}else{
			current->next = NULL;
		}
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
	
	l1_head->val = 2;
	l1_second->val = 4; 
	l1_third->val = 6;
	l2_head->val = 5;
	l2_second->val = 3;
	l2_third->val = 1;

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
