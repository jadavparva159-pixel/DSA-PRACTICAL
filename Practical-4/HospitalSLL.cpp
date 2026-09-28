#include <bits/stdc++.h>
using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};


class Solution {
public:
    
    ListNode* insertAtHead(ListNode* head, int X) {
       
        ListNode* newnode = new ListNode(X);
        
        newnode->next = head;
        
        head = newnode;
       
        return head;
    }

    ListNode* insertAtTail(ListNode* &head, int X) {
        if (head == NULL)
            return new ListNode(X);

        ListNode* temp = head;
        
        while (temp->next != NULL) {
            temp = temp->next;
        }
        
        ListNode* newNode = new ListNode(X);
        temp->next = newNode;

        return head;
    }

     ListNode* insertAtKthPosition(ListNode* &head, int X, int K) {
      
        if (head == NULL) {
            if (K == 1)
                return new ListNode(X);
            else
                return head;
        }
    
       
        if (K == 1)
            return new ListNode(X, head);
    
        int cnt = 0;
        ListNode* temp = head;
    
       
        while (temp != NULL) {
            cnt++;
            if (cnt == K-1) {
            
                ListNode* newNode = new ListNode(X, temp->next);
                temp->next = newNode;
                break;
            }
            temp = temp->next;
        }
    
        return head;
    }
};



void printLL(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
   
    vector<int> arr = {20, 30, 40};
    int X= 10;int K = 2;
    ListNode* head = new ListNode(arr[0]);
    head->next = new ListNode(arr[1]);
    head->next->next = new ListNode(arr[2]);
    
    
    cout << "Original List: ";
    printLL(head);
    
     
    Solution sol;
    head = sol.insertAtHead(head, X);
    head = sol.insertAtTail(head, X);
    head = sol.insertAtKthPosition(head, X, K);
   
    cout << "List after inserting the given value at head: ";
    printLL(head);
    
    cout << "List after inserting the given value at the tail:";
    printLL(head);

    cout << "List after inserting the given value at the Kth position: ";
    printLL(head);

    return 0;
}