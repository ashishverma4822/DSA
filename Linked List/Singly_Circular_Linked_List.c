#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node* next;
}Node;
Node* tail;
Node* getNode(int val){
	Node* newnode=(Node*)malloc(sizeof(Node));
	newnode->data=val;
	newnode->next=NULL;
	return newnode;
}
int length(Node* head){
	Node* temp=head;
	int count=0;
	do{
		count++;
		temp=temp->next;
	}while(temp!=head);
	return count;
}
int isEmpty(Node* head){
	if(head==NULL){
		return 1;
	}
	else{
		return 0;
	}
}
Node* insertion_at_beg(Node* head){
printf("Enter The Number Of Element You Want To Insert at Begining :: ");
int n,i;
scanf("%d",&n);
for(i=0;i<n;i++){
	printf("Enter The Data :: ");
	int t;
	scanf("%d",&t);
	Node* newnode=getNode(t);	
	if(head==NULL){
		head=newnode;
		tail=newnode;
		newnode->next=head;
	}
	else{
		newnode->next=head;
		tail->next=newnode;
		head=newnode;
	}
}
	return head;
} 
Node* insertion_at_end(Node* head){
printf("Enter The Number Of Element You Want To Insert at End :: ");
int n,i;
scanf("%d",&n);
for(i=0;i<n;i++){
	printf("Enter The Data :: ");
	int t;
	scanf("%d",&t);
	Node* newnode=getNode(t);	
	if(head==NULL){
		head=newnode;
		tail=newnode;
		newnode->next=head;
	}
	else{
		newnode->next=head;
		tail->next=newnode;
		tail=newnode;
	}
}
	return head;
} 
Node* insertion_at_pos(Node* head){
	int t,i;
	printf("Enter The Number Of Data Which You Want To Insert :: ");
	scanf("%d",&t);
	for(i=0;i<t;i++){
	int count=length(head);
	int pos,val;
	printf("Enter The Position and Data Respectively :: ");
	scanf("%d %d",&pos,&val);
	Node* newnode=getNode(val);
	if(pos>count+1 || pos<1){
		printf("Invalid Position");
	}
	else if(pos==count){
		newnode->next=head;
		tail->next=newnode;
		tail=newnode;
	}
	else if(pos==1){
		newnode->next=head;
		tail->next=newnode;
		head=newnode;
	}
	else{
		int j=1; 
		Node* temp=head;
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
Node* delete_Node(Node* head){
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
	if(pos>count+1 || pos<1){
		printf("Invalid Position\n");
	}
	else if(pos==1){
		Node* delNode=temp;
		temp=temp->next;
		head=temp;
		tail->next=head;
		free(delNode);
	}
	else if(pos==length(head)){
		int j=1;
		while(j<pos-1){
			temp=temp->next;
			j++;
		}
		Node* delNode=temp->next;
		temp->next=head;
		tail=temp;
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
void print(Node* head){
	Node* temp=head;
	do{
		printf("%d ",temp->data);
		temp=temp->next;
	}while(temp!=head);
}
int main(){
	Node* head=NULL;
	/*head=insertion_at_beg(head);
	print(head);
	head=insertion_at_end(head);
	print(head);	
	head=insertion_at_pos(head);
	print(head);
	head=delete_Node(head);
	print(head);
	head=update_data(head);
	print(head);
	*/
	//int n,i;
	//printf("For Run All The Function One Time You Should Type 6\n");
	//printf("Enter How Many Time You Want To Run Menu :: ");
	//scanf("%d",&n);
	//int n,i;
	//printf("For Run All The Function One Time You Should Type 6\n");
	//printf("Enter How Many Time You Want To Run Menu :: ");
	//scanf("%d",&n);
	printf("Insertion At Begining - Type 1\n");
	printf("Insertion At End - Type 2\n");
	printf("Insertion At Any Position - Type 3\n");
	printf("Deletion At Any Position - Type 4\n");
	printf("Update The Value At Any Position - Type 5\n");
	printf("Print The Node - Type 6\n");
	printf("Length of Linked List - Type 7\n");
	printf("Exit The Program - Type 8\n");
	while(1){
		printf("Type :: ");
		int t;
		scanf("%d",&t);
		if(t==1){
			head=insertion_at_beg(head);
		}
		else if(t==2){
			head=insertion_at_end(head);
		}
		else if(t==3){
			head=insertion_at_pos(head);
		}
		else if(t==4){
			head=delete_Node(head);
		}
		else if(t==5){
			head=update_data(head);
		}
		else if(t==6){
			print(head);
			printf("\n");
		}
		else if(t==7){
			printf("Length Of Linked List is :- %d\n",length(head));
		}
		else if(t==8){
			exit(0);
		}
		else{
			printf("---INVALID CHOICE---\n");
		}
	}
	return 0;
}
