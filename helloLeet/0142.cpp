//Linked list cycle2 (two pointers, good ques)

/*
	find the position a circle start in a link
	use two pointers fast and slow
	fast moves 2 steps each time, slow moves 1 step
	when they meet each other, slow moves k steps, fast moves 2k
	assume the distance between start point and loop start position is x1
	the distance between loop start and meet point is x2
	the distance between meet point to the loop start(move to the end and back to the loop start) is x3
	so fast moves x1 + x2 + x3 + x2 = 2k
	slow moves x1 + x2 = k
	so x1 + x2 + x3 + x2 = 2(x1 + x2)
	=> x1 = x3
	so the distance between the start point to loop star and meet point to loop start is same

	when fast and slow meet each other and meeting position, another pointer s start from start point, slow and s move at the same time with 1 shep each time, because of x1 = x3, when they meet each other, they will at loop start.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr; 
        bool has_circle = false;
        ListNode *p, *q, *s;
        p = q = s = head;
        while (p && q) {
            p = p->next;
            if (!q->next) return nullptr;
            q = q->next->next;
            if (p == q) {
                has_circle = true;
                break;
            }
        }
        if (!has_circle) return nullptr;
        while (q != s) {
            q = q->next;
            s = s->next;
        }
        return s;
    }
};
