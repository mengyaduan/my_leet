#include "head.h"
using namespace std;

//Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution234 {
public:
	bool isPalindrome(ListNode* head) {
		ListNode* p = head;
		ListNode* q = head;
		int sum = 0;
		while (q->next != NULL && q->next->next != NULL){
			++sum;
			p = p->next;
			q = q->next->next;
		}
		p->next = reverselink(p->next);
		p = p->next;
		while (p != NULL){
			if (head->val != p->val){
				return false;
			}
			head = head->next;
			p = p->next;
		}
		return true;
	}
	ListNode* reverselink(ListNode* head){
		ListNode* newhead = NULL;
		ListNode* a = NULL;
		while (head != NULL){
			a = head->next;
			head->next = newhead;
			newhead = head;
			head = a;
		}
	}
};


// Time Limit Exceeded
//class Solution234 {
//public:
//	bool isPalindrome(ListNode* head) {
//		ListNode* p = head;
//		ListNode* q = head;
//		int sum = 0;
//		while (q->next != NULL && q->next->next != NULL){
//			++sum;
//			p = p->next;
//			q = q->next->next;
//		}
//		if (q->next != NULL&&q->next->next == NULL)
//			++sum;
//		int x = 0;
//		while (x < sum){
//			ListNode* a = head;
//			for (int i = 0; i < x; ++i){
//				a = a->next;
//			}
//			ListNode* b = p;
//			for (int i = 0; i < sum - x; ++i){
//				b = b->next;
//			}
//			if (a->val != b->val)
//				return false;
//			++x;
//		}
//		return true;
//
//	}
//};