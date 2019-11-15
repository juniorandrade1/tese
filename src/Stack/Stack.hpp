// Stack.h
#ifndef QUEUE 
#define QUEUE_H

#pragma once

#include <bits/stdc++.h>
#include "../BST/IntervalTree.cpp"
#include "../BST/Treap.cpp"


/**
  Implementação retroativa das operações em uma pilha
*/
namespace Retroactivity {
  /** 
  * Pilha parciamente retroativa
  */
  template<typename T>
  class PartialStack {
  private:
    /** Árvore de segmentos para manutenção da árvore de prefixos
    * 
    */
    BST::IntervalTree< T > v;



  public:
    /** Insere o objeto x no tempo t na pilha
    * => Insert(t, Push(x))
    * 
    *
    * @param t -> tempo de inserção do objeto
    * @param x -> objeto a ser inserido no topo da pilha no tempo t
    */
    void InsertPush(int t, const T &x);


    /** Adiciona a realização da operação Pop no tempo t
    * => Insert(t, Pop())
    * 
    * 
    * @param t -> tempo de realização da operação Pop()
    */
    void InsertPop(int t);


    /** Remove a operação Push realizada no tempo t
    * => Delete(t, Push(x))
    * 
    * 
    * @param t -> tempo em que uma operação Push foi realizada
    * @pre -> deve existir uma operação Push no tempo t
    */
    void DeletePush(int t);


    /** Remove a operação Pop realizada no tempo t
    * => Delete(t, Pop())
    * 
    * 
    * @param t -> tempo em que uma operação Pop foi realizada
    * @pre -> deve existir uma operação Pop no tempo t
    */
    void DeletePop(int t);


    /** Retorna o topo da pilha no tempo atual
    * => Peak()
    * 
    *
    * @returns -> retorna objeto no topo da pilha no tempo atual
    */
    T peak();


    /** Obtem o tamanho da pilha no tempo atual
    * => getSize()
    * 
    *
    * @returns -> retorna o número de elementos na pilha no tempo atual
    */
    int getSize();
  };

  /** 
  * Pilha totalmente retroativa
  */
  template<typename T>
  class FullStack {
  private:
    /** Árvore de segmentos para manutenção da árvore de prefixos
    * 
    */
    BST::IntervalTree< T > v;



  public:
    /** Insere o objeto x no tempo t na pilha
    * => Insert(t, Push(x))
    * 
    *
    * @param t -> tempo de inserção do objeto
    * @param x -> objeto a ser inserido no topo da pilha no tempo t
    */
    void InsertPush(int t, const T &x);


    /** Adiciona a realização da operação Pop no tempo t
    * => Insert(t, Pop())
    * 
    * 
    * @param t -> tempo de realização da operação Pop()
    */
    void InsertPop(int t);


    /** Remove a operação Push realizada no tempo t
    * => Delete(t, Push(x))
    * 
    * 
    * @param t -> tempo em que uma operação Push foi realizada
    * @pre -> deve existir uma operação Push no tempo t
    */
    void DeletePush(int t);


    /** Remove a operação Pop realizada no tempo t
    * => Delete(t, Pop())
    * 
    * 
    * @param t -> tempo em que uma operação Pop foi realizada
    * @pre -> deve existir uma operação Pop no tempo t
    */
    void DeletePop(int t);


     /** Retorna o topo da pilha no tempo t
    * => Peak(t)
    * 
    *
    * @params t -> tempo que é desejado o elemento ao topo da pilha
    * @returns -> retorna objeto no topo da pilha no tempo t
    */
    T peak(int t);


     /** Obtem o tamanho da pilha no tempo atual
    * => getSize(t)
    * 
    *
    * @params t -> tempo que é desejado o tamanho da pilha
    * @returns -> retorna o número de elementos na pilha no tempo t
    */
    int getSize(int t);
  };

  /** 
  * Pilha com retroatividade não consistente
  */
  template <typename T>
  class NonObliviousStack {
  private:
    /** Árvore de segmentos para manutenção da árvore de prefixos
    * 
    */
    BST::IntervalTree< T > prefixTree;


    /** Árvore binária de busca que mantém as operações de Push(x) ordenadas por tempo
    * 
    * Contém uma chave (inteiro) representando o tempo de inserção da operação Push(x) e um 
    * par (T, int) representando o objeto inserido, e, se existir, o tempo de remoção desse objeto.
    */
    BST::Treap< int, std::pair<T, int> > tpush;


    /** Árvore binária de busca que mantém as operações de Pop() ordenadas por tempo
    * 
    * Contém uma chave (inteiro) representando o tempo de inserção da operação Pop e um valor (inteiro) representando o 
    * o objeto removido por essa operação
    */
    BST::Treap< int, T > tpop;


    /** Inteiro representando o valor nulo
    */
    const int NULLVALUE = -1;
  public:


    /** Insere o objeto x no tempo t na pilha
    * => Insert(t, Push(x))
    * 
    *
    * @param t -> tempo de inserção do objeto
    * @param x -> objeto a ser inserido no topo da pilha no tempo t
    * @returns -> a próxima operação Pop inconsistente
    */
    int InsertPush(int t, T x);


    /** Adiciona a realização da operação Pop no tempo t
    * => Insert(t, Pop())
    * 
    * 
    * @param t -> tempo de realização da operação Pop()
    * @returns -> a próxima operação Pop inconsistente
    */
    int InsertPop(int t);


    /** Remove a operação Push realizada no tempo t
    * => Delete(t, Push(x))
    * 
    * 
    * @param t -> tempo em que uma operação Push foi realizada
    * @pre -> deve existir uma operação Push no tempo t
    * @returns -> a próxima operação Pop inconsistente
    */
    int DeletePush(int t);


    /** Remove a operação Pop realizada no tempo t
    * => Delete(t, Pop())
    * 
    * 
    * @param t -> tempo em que uma operação Pop foi realizada
    * @pre -> deve existir uma operação Pop no tempo t
    * @returns -> a próxima operação Pop inconsistente
    */
    int DeletePop(int t);


    /** Corrige a estrutura após uma inconsistencia no tempo t
    *
    * @param t -> tempo em que ocorreu uma inconsistencia na estrutura
    */
    void fixPopOperation(int t);


    /** Função auxiliar para mostrar os elementos do conjuto tpush
    *
    * @return -> os elementos do conjunto tpush no formato "tempoInsercao, (elemento, tempoRemocao)"
    */
    void showtpush();


    /** Função auxiliar para mostrar os elementos do conjuto tpop
    *
    * @return -> os elementos do conjunto tpop no formato "tempoDelecao, (elementoDeletado)"
    */
    void showtpop();

  };
}


/**
  Implementação trivial das operações em uma stack retroativa
  Utilizada para a implementação dos testes
*/
namespace Brute {
  template<typename T>
  class PartialStack {
  public:
    set< pair< int, T > > v;
    vector< T > aux;
    void InsertPush(int t, const T &x) {
      v.insert(make_pair(t, x));
    }
    void InsertPop(int t) {
      v.insert(make_pair(t, -INF));
    }
    void DeletePush(int t) {
      auto f = v.lower_bound(make_pair(t, -INF));
      v.erase(f);
    }
    void DeletePop(int t) {
      auto f = v.lower_bound(make_pair(t, -INF));
      v.erase(f);
    }
    T peak() {
      aux.clear();
      for(typename set< pair< int, T > > :: iterator it = v.begin(); it != v.end(); it++) {
        if(it->second == -INF) aux.pop_back();
        else aux.push_back(it->second);
      }
      return aux[(int)aux.size() - 1];
    }
  };

  template<typename T>
  class FullStack {
  public:
    set< pair< int, T > > v;
    vector< T > aux;
    void InsertPush(int t, const T &x) {
      v.insert(make_pair(t, x));
    }
    void InsertPop(int t) {
      v.insert(make_pair(t, -INF));
    }
    void DeletePush(int t) {
      auto f = v.lower_bound(make_pair(t, -INF));
      v.erase(f);
    }
    void DeletePop(int t) {
      auto f = v.lower_bound(make_pair(t, -INF));
      v.erase(f);
    }
    bool empty(int t) {
      aux.clear();
      for(typename set< pair< int, T > > :: iterator it = v.begin(); it != v.end(); it++) {
        if(it->first > t) break;
        if(it->second == -INF) aux.pop_back();
        else aux.push_back(it->second);
      }
      return aux.size() == 0;
    }
    T peak(int t) {
      aux.clear();
      for(typename set< pair< int, T > > :: iterator it = v.begin(); it != v.end(); it++) {
        if(it->first > t) break;
        if(it->second == -INF) aux.pop_back();
        else aux.push_back(it->second);
      }
      return aux[(int)aux.size() - 1];
    }
  };
};


#include "Stack.cpp"

#endif /* STACK_H */