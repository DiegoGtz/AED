#include <iostream>
using namespace std;
template<class T>
class Node
{
public:
	T m_pDate;
	Node<T>* m_pSig;
	Node<T>* m_pAnt;
public:
	Node(T d){
		this->m_pDate = d;
		this->m_pSig = NULL;
		this->m_pAnt = NULL;
	}
};

template<class T>
class ListDouble
{
public:
	Node<T>* m_pHead;
	Node<T>* m_pLast;
public:
	ListDouble(){
		this->m_pHead = NULL;
		this->m_pLast = NULL;
	}


	



	
	
};