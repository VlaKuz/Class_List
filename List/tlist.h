#ifndef __LIST_STRUCT
#define __LIST_STRUCT

#include <conio.h>
#include <iostream>

using namespace std;

template <class ValType>
struct List_node {
	ValType data;
	List_node *next;
};

template <class ValType>
class List {
	List_node<ValType> *first;
	int size_list;
public:
	List();
	List (int);                                     
	~List();
	int GetSize() { return size_list; }
	List_node<ValType>* Search (ValType);
	ValType& operator[](int);
	bool Empty_list();
	void Add(ValType ,int);
	void AddWithBegin(ValType);
	void AddWithEnd(ValType);

	void DeleteNodeWithPos(int);
	void DeleteNodeWithBegin();
	void DeleteNodeWithEnd();

	friend ostream & operator << (ostream &out, const List &p);
	friend istream & operator >> (istream &in, List &p);
};/*---------------------------------------------------------------------*/


template <class ValType>
ostream & operator << (ostream &out, const List<ValType> &p)
{
List_node <ValType>* list = p.first;
while (list!=0)
{
	out << p->data << ' ';
	list=list->next;
}
out<<endl;
return out;
};/*---------------------------------------------------------------------*/


template <class ValType>
istream & operator >> (istream &in, List<ValType> &p)
{
	in >> p.size_list;
ValType temp;
for (int i = 0; i < p.size_list; ++i) 
{
	in >> temp;
	p.AddWithEnd(temp);
}
return in;
};/*---------------------------------------------------------------------*/


template <class ValType>
List<ValType>::List() 
{
first=0;
}/*---------------------------------------------------------------------*/

template <class ValType>
List<ValType>::List(int s) 
{	if (s==0)
	{
		first=0;
		size_list=0;
	}

	if (s>=0)
	{
		size_list=s;
		first=new List_node<ValType>;
		List_node<ValType> *temp=first;
		for (int i=1; i<size_list; ++i)
		{
			temp->next=new List_node<ValType>;
			temp=temp->next;
		}
		temp->next=0;
	}
	else
		throw 1;
}/*---------------------------------------------------------------------*/


template <class ValType>
List<ValType>::~List() 
{	if (first!=0)
	{
		List_node<ValType>* node=first;
		List_node<ValType> *list=first->next;
		while (list!=0)
		{
			delete node;
			node=list;
			list=list->next;
		}
		delete node;
		first=0;
	}
}/*---------------------------------------------------------------------*/


template <class ValType>
bool List<ValType>::Empty_list()
{
	if (first!=0) 
		return 0;
	else 
		return 1;
}/*---------------------------------------------------------------------*/


template<class ValType>
ValType& List<ValType>::operator[](int ind)
{
	if ((ind>=0) && (ind<size_list))
	{
	List_node<ValType>* list=first;
	for (int i = 0; i < ind; i++) 
		list = list->next;
	return list->data;
	}
	else 
		throw 1;
}/*---------------------------------------------------------------------*/

template <class ValType>
void List<ValType>::Add(ValType data_node,int pos)
{
	if ((pos>=0) && (pos<size_list))
	{
		List_node<ValType>* list=first;
		List_node<ValType>* node=new List_node<ValType>;
		node->data=data_node;
	for (int i=0; i<pos-1; ++i)
	{
		list=list->next;
	}
	node->next=list->next;
	list->next=node;
	++size_list;
	}
	else
		throw 1;
}/*---------------------------------------------------------------------*/

template <class ValType>
void List<ValType>::AddWithBegin(ValType data_node)
{
	List_node<ValType>*node=new List_node<ValType>;
	node->data=data_node;
	node->next=first;
	first=node;
	++size_list;
}/*---------------------------------------------------------------------*/

template <class ValType>
void List<ValType>::AddWithEnd(ValType data_node)
{
	List_node<ValType>*node=new List_node<ValType>;
	node->data=data_node;
	node->next=0;

	List_node<ValType>* list=first;
	while ((list->next)!=0)
		list=list->next;
	list->next=node;

	++size_list;
}/*---------------------------------------------------------------------*/

template <class ValType>
List_node<ValType>* List<ValType>::Search(ValType data_node)
{
	if (first!=0)
	{
		List_node<ValType>* list=first;
		while ((list->data!=data_node) && (list!=0))
			list=list->next;
		return list;
	}
	else 
		return 0;
	
}/*---------------------------------------------------------------------*/

template <class ValType>
void List<ValType>::DeleteNodeWithPos(int pos)
{
	if ((pos>=0) && (pos<size_list) && (first!=0))
	{
		List_node<ValType>* list=first;
		for (int i=0; i<pos-1; ++i)
		{
			list=list->next;
		}
		List_node<ValType>* node=list->next->next;
		delete list->next;
		(list->next)=node;
		--size_list;

	}
	else
		throw 1;
}/*---------------------------------------------------------------------*/

template <class ValType>
void List<ValType>::DeleteNodeWithBegin()
{
		if (first!=0)
		{
		List_node<ValType>* node=first->next;
		delete first;
		first=node;
		--size_list;
		}
		else
		throw 1;

}/*---------------------------------------------------------------------*/

template <class ValType>
void List<ValType>::DeleteNodeWithEnd()
{
		if (first!=0)
		{
		List_node<ValType>* list=first;
		while ((list->next->next)!=0)
			list=list->next;
		delete list->next;
		(list->next)=0;
		--size_list;
		}
		else
			throw 1;
}/*---------------------------------------------------------------------*/




#endif