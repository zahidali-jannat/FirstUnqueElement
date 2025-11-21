class Solution {
    public:
      void CloneNode(Node *&head , Node *&clonetail , int d){
          Node *newNode= new Node(d);
          if(head==NULL){
              head=newNode;
              clonetail=newNode;
          }
          else{
              clonetail->next=newNode;
              clonetail=newNode;
          }
      }
      Node *cloneLinkedList(Node *head) {
        Node *clonehead=nullptr;
        Node *clonetail=nullptr;
        
        Node *temp=head;
        while(temp!=NULL){
            CloneNode(clonehead , clonetail , temp->data);
            temp=temp->next;
        }
        
        
        // now random wala game krna hai 
        Node *originalNode=head;
        Node *cloneNode=clonehead;
        map< Node * , Node *> oldToNew;
        
        while(originalNode!=NULL && cloneNode!=NULL){
            oldToNew[originalNode]=cloneNode;
            cloneNode=cloneNode->next;
            originalNode=originalNode->next;
        }
        
        originalNode=head;
        
        cloneNode=clonehead;
        while(originalNode != NULL){
            cloneNode->random=oldToNew[originalNode->random];
            cloneNode=cloneNode->next;
            originalNode=originalNode->next;
        }
        
        return clonehead;
      }
  };