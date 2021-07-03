#pragma once
#include <iostream>
#include <functional>
#include "node.h"

template <typename A>
class DoubleCircularList{
    private:
        Node<A>* cursor = nullptr;
    public:
        DoubleCircularList();
        void addFirst(const A &dat);
        void addLast(const A &dat);
        void addAt(const A &dat, int index);
        void eraserAt(int index);
        Node<A>* at(int index);
        int size();
        bool isEmpty();

        void for_each(std::function<void(Node<A> *, int)> callback);
        void for_each(std::function<void(Node<A>*)> callback);
        void for_each(std::function<void(A, int)> callback);
        void for_each(std::function<void(A)> callback);
        
        void until(std::function<bool(Node<A>*)> callback);
        void until(std::function<bool(A)> callback);

        Node<A> *find(std::function<bool(Node<A> *, int)> callback);
        Node<A>* find(std::function<bool(Node<A>*)> callback);
        Node<A> *find(std::function<bool(A, int)> callback);
        Node<A>* find(std::function<bool(A)> callback);
};

template <typename A>
DoubleCircularList<A>::DoubleCircularList(){
}

template <typename A>
void DoubleCircularList<A>::addFirst(const A &dat){
    Node<A>* recent = new Node<A>(dat);
    if(isEmpty()){
        recent->setNext(recent);
        recent->setPrevious(recent);
        cursor = recent;
    }else{
        Node<A>* last = cursor->getPrevious();
        recent->setNext(cursor);
        recent->setPrevious(last);
        last->setNext(recent);
        cursor->setPrevious(recent);
        cursor = recent;
    }
}

template <typename A>
void DoubleCircularList<A>::addLast(const A &dat){

}

template <typename A>
void DoubleCircularList<A>::addAt(const A &dat, int index){

}

template<typename A>
bool DoubleCircularList<A>::isEmpty(){
    return this->cursor ==nullptr;
}

template <typename A>
void DoubleCircularList<A>::for_each(std::function<void(A)> callback){
    for_each([&](Node<A> *node, int index) {
        callback(node->getDat());
    });
}

template<typename A>
void DoubleCircularList<A>::for_each(std::function<void(Node<A>*, int)> callback) {
    Node<A> *current = cursor;

    int index = 0;

    do {
        callback(current, index);
        current = current->getNext();
        index++;
    } while (current != cursor);
}