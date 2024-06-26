LinkedListNode<int>* reverse(LinkedListNode<int>* ptr) {
    LinkedListNode<int>* pre=NULL;
    LinkedListNode<int>* nex=NULL;
    while(ptr!=NULL) {
        nex = ptr->next;
        ptr->next = pre;
        pre=ptr;
        ptr=nex;
    }
    return pre;
}
bool isPalindrome(LinkedListNode<int> *head) {
  if (head == NULL || head->next == NULL) {
    return true;
  }
    LinkedListNode<int>* slow = head;

    LinkedListNode<int>* fast = head;

        

    while(fast->next!=NULL&&fast->next->next!=NULL) {

        slow = slow->next;

        fast = fast->next->next;

    }

        

    slow->next = reverse(slow->next);

    slow = slow->next;

    LinkedListNode<int>* dummy = head;

        

    while(slow!=NULL) {

        if(dummy->data != slow->data) return false;

        dummy = dummy->next;

        slow = slow->next;

    }

    return true;

    // Write your code here.

 

}
