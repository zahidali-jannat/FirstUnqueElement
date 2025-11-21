3Include <iostream>
#include <vector>       
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

int count = 0;
vector<int> store;

ListNode* temp = head;
while (temp != NULL) {
    if (temp->val == 0) {
        count++;
    }
    temp = temp->next;
}

store.push_back(count);
count = 0;
temp = head;
while (temp != NULL) {
    if (temp->val == 1) {
        count++;
    }
    temp = temp->next;
}
store.push_back(count);

count = 0;
temp = head;
while (temp != NULL) {
    if (temp->val == 2) {
        count++;
    }
    temp = temp->next;
}
 store.push_back(count);
ListNode *check=head;
int number=0;
int i=0;
while(number<=2){
    int vari=store[i];
    while(check!=NULL && vari!=0){
        check->val=number;
        check=check->next;
        vari--;
    }
    number++;
   i++;
}
return head;