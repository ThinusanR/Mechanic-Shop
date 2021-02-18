#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;
#include <cstdlib>

template <class T>
class LinkedList
{
	template <typename V>
	friend ostream& operator<<(ostream&, const LinkedList<V>&);

	class Node
	{

	  friend class LinkedList<T>;
	  private:
		T* data;
		Node* next;
	};

	public:
	  LinkedList();
	 ~LinkedList();
	  int getSize() const;
	  LinkedList<T>& operator+=(T*);
	  LinkedList<T>& operator-=(T*);
	  T* operator[](int);

	private:
		Node* head;

}; 

template <class T>
LinkedList<T>::LinkedList() : head(0){}

template <class T>
LinkedList<T>::~LinkedList()
{
	Node *currNode, *nextNode;

	currNode = head;

	while(currNode != 0){
		nextNode = currNode->next;
		delete currNode->data;
		delete currNode;
		currNode = nextNode;
	}
}

/*Function: getSize()*/
/*In: none */
/*Out: returns size */
/*Purpose: template for getting the size of a Linkedlist*/
template <class T>
int LinkedList<T>::getSize() const{
	Node *currNode = head;
	int size =0;

	while (currNode !=0){
		currNode = currNode->next;
		size++;
	}
	return size;
}

/*Function: operator+= */
/*In: T pointer*/
/*Out: none*/
/*Purpose: template for adding into the linklist  */
template <class T>
LinkedList<T>& LinkedList<T>::operator+=(T* newData)
{
	Node *currNode, *prevNode;
  Node* newNode = new Node;
  newNode->data = newData;
  newNode->next = 0;

  currNode = head;
  prevNode = 0;

  while (currNode != 0) {
    if (*(newNode->data) < *(currNode->data))
      break;
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == 0) {
    head = newNode;
  }
  else {
    prevNode->next = newNode;
  }

  newNode->next = currNode;

  return *this;
}

/*Function: operator-= */
/*In: T pointer*/
/*Out: none*/
/*Purpose: template for removing in linkedlist */
template <class T>
LinkedList<T>& LinkedList<T>::operator-=(T* oldData)
{
  Node *currNode, *prevNode;

  currNode = head;
  prevNode = 0;

  while (currNode != 0) {
    if (currNode->data == oldData)
      break;
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (currNode == 0) 
    return *this;

  if (prevNode == 0) {
    head = currNode->next;
  }
  else {
    prevNode->next = currNode->next;
  }


  delete currNode;

  return *this;
}

/*Function: operator[] */
/*In: int */
/*Out: returns T* */
/*Purpose:  tempalte for getting data at a certain index in the LinkedList*/
template <class T>
T* LinkedList<T>::operator[](int i) 
{
    if(i < 0 || i > (getSize()-1)) {
        return 0;
    } else {

        Node *currNode = head;

        for (int j = 0; j < i; j++) {
            currNode = currNode->next;
        }

        return currNode->data;
    }
}


/*Function: operator<< */
/*In: ostream reference */
/*Out: returns output*/
/*Purpose: template for printing out all the contents in the LinkedList*/
template <class T>
ostream& operator<<(ostream& output, LinkedList<T>& link)
{
  
  for (int i = 0; i < link.getSize(); i++)  {
    output << (*(link[i]));
    
  }
    
  return output;

}
#endif
