/********************************************************************

    Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    
********************************************************************/
node *middleOfNode(node *head){
    node *slow=head;
    node *fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }

    return slow;
}
node *mergesort(node *&left , node *&right){
    if(left==NULL){
        return right;
    }

    if(right==NULL){
        return left;
    }
  node *result=new node(-1);
  node *temp=result;
  
  // now check which is bigger
  while(left!=NULL && right!=NULL){
      
      if(left->data > right->data){
          temp->next = right;
          temp = right;
          right = right-> next;
      }
      else{ 
          temp->next=left;
          temp=left;
          left=left->next;
      }
  }

  while(left!=NULL){
      temp->next=left;
      temp=left;
      left=left->next;
  }


  while(right!=NULL){
      temp->next=right;
      temp=right;
      right=right->next;
  }
  result=result->next;
  return result;

}
node* mergeSort(node *head) {
  if(head==NULL || head->next==NULL){
      return head;
  } 


  node *mid=middleOfNode(head);

  node *left=head;
  node *right=mid->next;
  mid->next=NULL;
  left=mergeSort(left);
  right=mergeSort(right);

  // now times for merge 
  node *result_1=mergesort(left , right);

  return result_1;

}
