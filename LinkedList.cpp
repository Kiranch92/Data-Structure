#include <iostream>
using namespace std ;

class Node
{
	public:
			Node(){
                data_ = 0 ;
				next_ = NULL;
			}

	        void SetData(int data){
				this->data_ = data ;
			}
			
		    int GetData(){
				return data_;
			}

			void SetNext(Node* next){
				this->next_ = next ;
			}

			Node* GetNext(){
				return next_;
			}

	private:

			int data_ ;
			Node* next_ ;
};

class List 
{
    public:
			List()
			{
				head =  NULL ;
			}

			void Print();
			void Insert(int data);
			void Delete(int data);
			
	private:
		Node* head ; 
};


void List :: Print()
{
	Node *curr = head;
	if(curr == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}
	while(curr != NULL)
	{
		cout <<curr -> GetData() << "->";
		curr = curr -> GetNext();
	}
}


void List :: Insert(int data)
{
	Node* newNode = new Node;

	newNode->SetData(data);
	newNode->SetNext(NULL);
	

	 // Create a temp pointer
    Node *curr = head;

    if ( curr != NULL ) 
    {
    	while ( curr->GetNext() != NULL ) 
    		curr = curr->GetNext();
  	  	
    	curr->SetNext(newNode);
    }
    else
    {
    	head = newNode;
    }
}



void List :: Delete(int data)
{
	Node *curr = head ;

	if(curr == NULL)
	{
		cout << "List is empty";
		return;
	}

    if (curr->GetNext() == NULL)
	{
		head = NULL;
	}
	else
	{
		Node *prev  = curr ;
		while ( curr != NULL )
		{
			if ( curr->GetData() == data)
				break;
			
			prev = curr ;
			curr = curr->GetNext();
		} 
    	
    	prev->SetNext( curr->GetNext());
    	delete curr ;
	}
}

int main()
{
	List singlyLinkedList ;

	int arr[] = {1,2,3,4,5};

	for(int i = 0 ; i < sizeof(arr)/sizeof(arr[0]) ; i++){
		singlyLinkedList.Insert(arr[i]);
	}
	
	
	cout << "Before Deletion List ";
	singlyLinkedList.Print();
	cout << endl ;

	singlyLinkedList.Delete(1);
	singlyLinkedList.Delete(4);

	cout << "After Deletion List ";
	singlyLinkedList.Print();
	cout << endl ;
    
    return  0 ;
}

