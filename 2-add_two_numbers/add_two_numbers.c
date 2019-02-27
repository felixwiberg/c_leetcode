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

	int 	n = 0,
	    	tmp_sum = 0,
		val_to_next = 0,
		carry = 0;

	struct ListNode* head = NULL;
	head = malloc(sizeof *head);
	struct ListNode* next_node = NULL, *current_node = head;
	struct ListNode* last_node = NULL;
	
	while(l1 != NULL || l2 != NULL || carry > 0){
		tmp_sum = 0;
		if(l1 != NULL){
			tmp_sum += l1->val;
			l1 = l1->next;
		}
		if(l2 != NULL){
			tmp_sum += l2->val;
			l2 = l2->next;
		}
		val_to_next = (tmp_sum + carry);
		carry = val_to_next/10;
		val_to_next = val_to_next%10;

		current_node->val = val_to_next;
		struct ListNode* next_node = NULL;
		next_node = malloc(sizeof *next_node);
		current_node->next = next_node;
		last_node = current_node;
		current_node = next_node;
	}
	last_node->next = NULL;
	free(current_node);
	
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
	l1_third->val = 3;
	l2_head->val = 5;
	l2_second->val = 6;
	l2_third->val = 4;

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
