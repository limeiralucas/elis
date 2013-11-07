#ifndef _LISTA_H_
#define _LISTA_H_

template <class T>
class No{
	private:
		T valor;
		No<T>* ant;
		No<T>* prox;
	public:
		//construtor
		No();
		
		//get
		T getValor();
		No<T>* getAnt();
		No<T>* getProx();
		
		//set
		void setValor(T v);
		void setAnt(No<T>* a);
		void setProx(No<T>* p);
};

template <class T>
class Lista{
	private:
		int tam;
		No<T>* pri;
		No<T>* ult;
	public:
		//construtor
		Lista();
		
		//get
		int getTam();
		No<T>* getPri();
		No<T>* getUlt();
		
		//operações
		//inserção
		void inserir(T v);
		
		//impressão
		void imprimir();
		
		//remoção
		bool remove(T el);
		
		//remoção: primeiro elemento
		bool removePri();
		
		//remoção: último elemento
		bool removeUlt();
		
		//lista vazia?
		bool isEmpty();
};

#include "lista.inl"

#endif
