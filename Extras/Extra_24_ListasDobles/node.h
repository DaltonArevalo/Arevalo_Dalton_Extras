#pragma once

template <typename A>
class Node{
    private:
        A dat;
        Node<A>* next = nullptr;
        Node<A>* previous = nullptr;
    public:
        Node();
        Node(A dat);
        A getDat();
        void setDat(A dat);
        Node<A>* getNext();
        void setNext(Node<A>* next_);
        Node<A>* getPrevious();
        void setPrevious(Node<A>* previous);
};

template <typename A>
Node<A>::Node(){
}

template <typename A>
Node<A>::Node(A dat){
    this->dat = dat;
}

template <typename A>
A Node<A>::getDat(){
    return this->dat;
}

template <typename A>
void Node<A>::setDat(A dat){
    this->dat = dat;
}

template <typename A>
Node<A>* Node<A>::getNext(){
    return this->next;
}

template <typename A>
void Node<A>::setNext(Node<A> *next_){
    this->next = next_;
}

template <typename A>        
Node<A>* Node<A>::getPrevious(){
    return this->previous;
}

template <typename A>
void Node<A>::setPrevious(Node<A>* previous){
    this->previous = previous;
}