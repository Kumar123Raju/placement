#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

void insertStart(Node** head, int data){

    Node* newNode = new Node();

    // assign data value
    newNode->data = data;
    // change the next node of this newNode 
    // to current head of Linked List
    newNode->next = *head;

    //changing the new head to this freshly entered node
    *head = newNode;

}

void insertLast(Node** head, int data){

    Node* newNode = new Node();

    newNode->data = data;
    // since this will be the last node so it will point to NULL
    newNode->next = NULL;

    //need this if there is no node present in linked list at all
    if(*head==NULL){
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    
    // traverse to the last node of Linked List
    while(temp->next!=NULL)
        temp = temp->next;

    // assign last node's next to this newNode
    temp->next = newNode;
}

int calcSize(Node* node){
    int size=0;

    while(node!=NULL){
        node = node->next;
        size++;
    }
    return size;
}

void insertPosition(int n, int data, Node** head)
{
    int size = calcSize(*head);

    // Can only insert after 1st position
    // Can't insert if position to insert is greater than size of Linked List
    if(n < 1 || size < n)
    {
        cout << "Not Valid position to insert" << endl; 
    } 
    else { 

        Node* temp = *head; 
        Node* newNode = new Node(); 
        
        newNode->data = data;
        newNode->next = NULL;

        // traverse till the nth node
        while(--n)
            temp=temp->next;
        
        // assign newNode's next to nth node's next
        newNode->next= temp->next;
        // assign nth node's next to this new node
        temp->next = newNode;
        // newNode inserted b/w 3rd and 4th node
    }
}

void display(Node* node){

    //as linked list will end when Node is Null
    while(node!=NULL){
        cout << node->data << " "; node = node->next;
    }
    cout << endl;
}
// ------------------recursion--------------------
 
  void print(Node *head){
  	
  	// base case
  	if(head==NULL) return;
  	cout<< head->data <<" ";
  	print(head->next);
  }

  // print in reverse order
  void ReversePrint(Node *head){
  	// base case
  	if(head==NULL) return;
  	ReversePrint(head->next);
  	cout<<head->data<<endl;
  }
// -----------------------------------------------

  // print k-th node from end/last
  void printLastNode(Node *head,int &k){
  	if(head==NULL) return ;
  	printLastNode(head->next,k);
  	k--;
  	if(k==0)
  	 cout<< head->data <<endl;

  }

  // --------------------------------
  // Reverse the link list by recursion------------
  Node * reverseLinklist(Node *head){
            if(head==NULL || head->next==NULL) return head;
            Node *chotahead=reverseLinklist(head->next);
            head->next->next=head;
            head->next=NULL;
            return chotahead;
  }

  // by itteration method:::
  Node * reverseLinklistItterative(Node *head){
  	Node *prev=NULL;
  	Node *current=head;
  	Node *forward;
  	while(current!=NULL){
  		forward=current->next;
  		current->next=prev;
  		prev=current;
  		current=forward;
  	}
  	return prev;
  }

  // reverse a Linklist in K group ex: 1,2,3,4,5,6,7,8  let k=2
  // output will be:  2,1,4,3,6,5,8,7
  Node *KReverseLinklist(Node *head,int k){

  	
  	// base case
  	if(head==NULL ) return NULL;
  	Node *prev=NULL;
  	Node *current=head;
  	Node *forward;
  	int count=0 ;//take count=k
  	// check condtion for if node are present upto kth 
  	
  
  	// --------------------------------------------
  	while(current!=NULL && count<k){
  		forward=current->next;
  		current->next=prev;
  		prev=current;
  		current=forward;
  		count++;
  	}
  	if(forward!=NULL){
  		head->next=KReverseLinklist(forward,k);
  	}
  	return prev;

  }

  // ---------------------------------------------

int main(){

    Node* head = NULL;

     /*Need & i.e. address as we
    need to change head address
    */
    

    insertLast(&head,1);
    insertLast(&head,2);
    insertLast(&head,3);
    insertLast(&head,4);
    insertLast(&head,5);
    insertLast(&head,6);

    //Inserts after 3rd position
    // insertPosition(3,100,&head);

    /*No need for & i.e. address as we do not
    need to change head address
    */
    // display(head); 
    // display:
    print(head);
    // cout<<"-----"<<endl;
    // ReversePrint(head);

    // print from kth node from last:
    // int k; //kth node form last:
    // cin>>k;
    // printLastNode(head,k);
    // // -------------------------------

    // reverse linklist:-------
    // Node *result=reverseLinklist(head);
    // Node *result=reverseLinklistItterative(head);  
    int k=4;
    Node *result=KReverseLinklist(head,k);
    cout<<endl;
    print(result);
    // -------end--------------
    return 0;  
}
