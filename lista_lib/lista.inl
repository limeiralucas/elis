#include <iostream>

//No
//construtor
template <class T>
No<T>::No(){
	this->prox = NULL;
	this->ant = NULL;
}

//get
template <class T>
T No<T>::getValor(){ return this->valor; } //valor
template <class T>
No<T>* No<T>::getAnt(){ return this->ant; } //anterior
template <class T>
No<T>* No<T>::getProx(){ return this->prox; } //proximo

//set
template <class T>
void No<T>::setValor(T v){ this->valor = v; } //valor
template <class T>
void No<T>::setAnt(No<T>* a){ this->ant = a; } //anterior
template <class T>
void No<T>::setProx(No<T>* p){ this->prox = p; } //proximo

//Lista
//construtor
template <class T>
Lista<T>::Lista(){
	this->tam = 0;
	this->pri = new No<T>();
	this->ult = new No<T>();
}

//get
template <class T>
int Lista<T>::getTam(){ return this->tam; } //quantidade de elementos (tamanho da lista)
template <class T>
No<T>* Lista<T>::getPri(){ return this->pri->getProx(); } //primeiro elemento
template <class T>
No<T>* Lista<T>::getUlt(){ return this->ult->getAnt(); } //ultimo elemento

//operações
//inserção
template <class T>
void Lista<T>::inserir(T v){
	No<T>* aux = new No<T>();
	aux->setValor(v);
	if(tam == 0){
		aux->setProx(this->ult);
		aux->setAnt(this->pri);
		this->pri->setProx(aux);
		this->ult->setAnt(aux);
	}else{
		aux->setAnt(this->ult->getAnt());
		aux->setProx(ult);
		aux->getAnt()->setProx(aux);
		this->ult->setAnt(aux);
	}		
	tam++;
}

//impressão
template <class T>
void Lista<T>::imprimir(){
	if(tam > 0){
		No<T>* aux = this->pri;
		while(aux->getProx() != this->ult){
			aux = aux->getProx();
			std::cout << aux->getValor() << " ";
		}
		std::cout << std::endl;
	}else
		std::cout << "empty" << std::endl;
}

//remoção
template <class T>
bool Lista<T>::remove(T el){
	if(tam > 0)
	{
		No<T>* aux = this->pri;
		while(aux->getProx() != this->ult){
			aux = aux->getProx();
			if(aux->getValor() == el){
				aux->getAnt()->setProx(aux->getProx());
				aux->getProx()->setAnt(aux->getAnt());
				delete aux;
				
				tam--;
				return true;
			}
		}
	}
	return false;
}

//remoção: primeiro elemento
template <class T>
bool Lista<T>::removePri(){
	if(tam > 0){
		No<T>* aux = this->pri->getProx();
		this->pri->setProx(aux->getProx());
		aux->getProx()->setAnt(this->pri);
		delete aux;
		
		tam--;
		return true;
	}
	return false;
}

//remoção: último elemento
template <class T>
bool Lista<T>::removeUlt(){
if(tam > 0){
	No<T>* aux = this->ult->getAnt();
	this->ult->setAnt(aux->getAnt());
	aux->getAnt()->setProx(this->ult);
	delete aux;
	
	tam--;
	return true;
	}
	return false;
}

//lista vazia?
template <class T>
bool Lista<T>::isEmpty(){ return (tam > 0) ? false : true; }
