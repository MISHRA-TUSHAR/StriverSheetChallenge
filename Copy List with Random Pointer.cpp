class Solution {
public:
    void insertAtTail (Node* &head, Node* &tail, int d){
        Node* newNode = new Node(d);
        if(head==NULL){
            head = newNode;
            tail = newNode;
            return ;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    Node* copyRandomList(Node* head) {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        //creating clone
        while(temp!=NULL){
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }

        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        //changing the next pointer
        while(originalNode !=NULL){
            Node *nextNode = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = nextNode;

            nextNode = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = nextNode;
        }
        //random pointer pointing
        temp = head;
        while(temp !=NULL){
            if(temp->next !=NULL){
                if(temp->random !=NULL){
                    temp->next->random = temp->random->next;
                } else {
                    temp->next->random = temp->random;
                }
            }
            temp = temp->next->next;
        }
        //reverting the next pointers to the default
        originalNode = head;
        cloneNode = cloneHead;

        while(originalNode !=NULL && cloneNode !=NULL){
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;
            
            if(originalNode != NULL){
                cloneNode->next = originalNode->next;
            }
            cloneNode = cloneNode->next;
        }

        return cloneHead;
