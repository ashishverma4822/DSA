#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node* next;
}Node;
Node* getNode(int val){
	Node* newnode=(Node*)malloc(sizeof(Node));
	newnode->data=val;
	newnode->next=NULL;
	return newnode;
}
int length(Node* head){
	Node* temp=head;
	int cnt=0;
	while(temp!=NULL){
		cnt++;
		temp=temp->next;
	}
	return cnt;
}
Node* insert_at_beg(Node* head){
	Node* temp=head;
	int n,i;
	printf("Enter The Number Element You Want To Create or Insert at Begining :: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter The Data You Want To Insert :: ");
		int t;
		scanf("%d",&t);
		Node* newnode=getNode(t);
		if(temp==NULL){
			temp=newnode;
		}
		else{
			newnode->next=temp;
			temp=newnode;
		}
	}
	return temp;
}
Node* insert_at_end(Node* head){
	Node* temp=head;
	int n,i;
	printf("Enter The Number Element You Want To Create or Insert at End :: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter The Data You Want To Insert :: ");
		int t;
		scanf("%d",&t);
		Node* newnode=getNode(t);
		if(temp==NULL){
			head=newnode;
		}
		else{
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=newnode;
		}
	}
	return head;
}
Node* insert_at_pos(Node* head){
	int n,i;
	if(isEmpty(head)){
		printf("Linked List is Empty\n");
		return;
	}
	printf("Enter The Number Of Element You Want Insert In Between The Singly Linked List :: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		Node* temp=head;
		int pos,val,j=1;
		printf("Enter The Position Where You Want Insert And Data Respectively :: ");
		scanf("%d %d",&pos,&val);
		Node* newnode=getNode(val);
		int count=length(temp);
		if(pos>count+1 || pos<1){
			printf("Invalid Position\n");
		}
		else if(pos==1){
			newnode->next=temp;
			temp=newnode;
			head=temp;
		}
		else if(pos==length(head)+1){
			while(j<pos-1){
				temp=temp->next;
				j++;
			}
			temp->next=newnode;
		}
		else{
			while(j<pos-1){
				temp=temp->next;
				j++;
			}
			newnode->next=temp->next;
			temp->next=newnode;
		}
	}
	return head;
}
void print(Node* head){
	Node* temp=head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
int isEmpty(Node* head){
	if(head==NULL){
		return 1;
	}
	else{
		return 0;
	}
}
Node* deleteNode(Node* head){
	int n,i;
	if(isEmpty(head)){
		printf("Linked List is Empty\n");
		return;
	}
	printf("Enter The Number Of Element You Want Delete :: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
	Node* temp=head;
	printf("Enter The Position Which You Want to Delete :: ");
	int pos;
	scanf("%d",&pos);
	int count = length(head);
	if(pos>count || pos<1){
		printf("Invalid Position\n");
	}
	else if(pos==1){
		Node* delNode=temp;
		temp=temp->next;
		head=temp;
		free(delNode);
	}
	else if(pos==length(head)){
		int j=1;
		while(j<pos-1){
			temp=temp->next;
			j++;
		}
		Node* delNode=temp->next;
		temp->next=NULL;
		free(delNode);
	}
	else{
		int j=1;
		while(j<pos-1){
			temp=temp->next;
			j++;
		}
		Node* delNode=temp->next;
		temp->next=temp->next->next;
		free(delNode);
	}
	}
	return head;
}
Node* update_data(Node* head){
	int n,i;
	printf("Enter The Number Of Element You Want Change The Data :: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
	Node* temp=head;
	int pos,val;
	printf("Enter The Position Where You Want Insert And Data Respectively :: ");
	scanf("%d %d",&pos,&val);
	int count = length(head);
	if(pos>count || pos<1){
		printf("Invalid Position\n");
	}
	else if(pos==1){
		temp->data=val;
	}
	else if(pos==length(head)){
		int j=1;
		while(j<pos){
			temp=temp->next;
			j++;
		}
		temp->data=val;
	}
	else{
		int j=1;
		while(j<pos){
			temp=temp->next;
			j++;
		}
		temp->data=val;
	}
	}
	return head;
}
int main(){
	Node* head=NULL;
	/*head=insert_at_beg(head);
	print(head);
	printf("\n%d\n",length(head));
	head=insert_at_end(head);
	print(head);
	printf("\n%d\n",length(head));
	head=insert_at_pos(head);
	print(head);
    printf("\n%d\n",length(head));
    head=deleteNode(head);
    printf("\n%d\n",length(head));
    print(head);
    head=update_data(head);
    printf("\n%d\n",length(head));
	print(head);
	*/
	int n,i;
	printf("For Run All The Function One Time You Should Type 6\n");
	printf("Enter How Many Time You Want To Run Menu :: ");
	scanf("%d",&n);
	printf("Insertion At Begining - Type 1\n");
	printf("Insertion At End - Type 2\n");
	printf("Insertion At Any Position - Type 3\n");
	printf("Deletion At Any Position - Type 4\n");
	printf("Update The Value At Any Position - Type 5\n");
	printf("Print The Node - Type 6\n");
	for(i=0;i<n;i++){
		printf("Type :: ");
		int t;
		scanf("%d",&t);
		if(t==1){
			head=insert_at_beg(head);
		}
		else if(t==2){
			head=insert_at_end(head);
		}
		else if(t==3){
			head=insert_at_pos(head);
		}
		else if(t==4){
			head=deleteNode(head);
		}
		else if(t==5){
			head=update_data(head);
		}
		else if(t==6){
			print(head);
		}
	}
	return 0;
}
