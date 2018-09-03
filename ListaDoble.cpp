//DGtz
//Lista Doble Enlazada 
//AED-GrupoA

#include <iostream>
using namespace std;
template<class T>
// Estructura de nodo
class Node
{
public:
	T m_pDate; 		 			//Dato almacendo en el nodo 
	Node<T>* m_pSig; 			//Puntero a un nodo anterior de la lista
	Node<T>* m_pAnt; 			//Puntero a un nodo siguiente de la lista 
public:
	Node(T d){					//Constructor de la clase nodo, al crear un nuodo inicializa el dato del nodo con el ingresado
		this->m_pDate = d;		//inicializa los punteros Anty Sig en null
		this->m_pSig = NULL;
		this->m_pAnt = NULL;
	}
};

//Estructura de la Lista Doble Enlazada
template<class T>
class ListDouble
{
public:
	Node<T>* m_pHead;       	// Puntero a la cabeza de la Lista
	Node<T>* m_pLast;			// Puntero al final de la lista
public:
	ListDouble(){
		this->m_pHead = NULL;  //iniciarmos los punteros Head y  Last en null (cuando creamos la lista )
		this->m_pLast = NULL;
	}

	void push_front(T d)     	// Funcion para añadir un nodo al frente de la lista 
	{
		Node<T>* newN = new Node<T>(d);
		if(!this->m_pHead){
			this->m_pHead = newN;
			this->m_pLast = newN;
			return;
		}
		newN->m_pSig = this->m_pHead;
		this->m_pHead->m_pAnt = newN;
		this->m_pHead = newN;
		return;

	}

	void push_back(T d){       			//Funcion para agregar Nodos al final de la lista, no evalua si el nodo ya existe 
		Node<T>* newN = new Node<T>(d);
		if(!this->m_pHead){
			this->m_pHead = newN;
			this->m_pLast = newN;
			return;
		}

		this->m_pLast->m_pSig =  newN;
		newN->m_pAnt = this->m_pLast;
		this->m_pLast = newN;
		return;

	}


	bool findNode(T d,Node<T>*& p){  		 	//Busca un nodo en la lista enlazada indicando si existe
		p = m_pHead;
		while(p!=NULL){							//y si no existe situa el puntero p(paso por referencia) en la posicion indicada 
			if(p->m_pDate == d) return 1;						 		 	//para poder insertar un nuevo nodo 
			if(p->m_pDate > d) return 0;
			p = p->m_pSig;

		}
		return 0;						  	
	} 

	bool add_Node(T d){
		Node<T>* q;
		if(!findNode(d,q)){
			cout<<"No encontrado"<<d;
			Node<T>* newN = new Node<T>(d);

			newN->m_pAnt = q;
			
			//q->m_pSig->m_pAnt = newN;
			//q->m_pSig = newN;
			cout<<"olis";
			return true;
		}
		cout<<" encontrado";
		return false;

	} 


	void printList(){					//Imprime la lista enlazada de manera normal

		//cout<<"estoy aqui";
		if(!m_pHead){
			cout<<"No hay datos en la Lista"<<endl;
		}
		else{
			Node<T>* temp = m_pHead;
			while(temp != NULL){
				cout<<temp->m_pDate<<"->";
				temp=temp->m_pSig;
			}
		}

	}

	void printList2(){				//Imprime la Lista Enlazada de forma invertida a como la ingresas  
		if(!m_pHead){
			cout<<"No hay datos en la Lista"<<endl;
		}
		else{
			Node<T>* temp = m_pLast;
			while(temp != NULL){
				cout<<temp->m_pDate<<"->";
				temp=temp->m_pAnt;
			}
		}

	}

	
};


int main()
{
	ListDouble<int> A;

	/*A.push_front(10);
	A.push_front(11);
	A.push_front(12);*/

	/*A.push_back(9);
	A.push_back(8);
	A.push_back(12);
	A.push_back(16);
	A.push_back(2);*/

	A.add_Node(5);
	//A.add_Node(15);

	A.printList();

	cout<<endl;
	
	//A.printList2();
	return 0;
}