#ifndef TEAM_LAB_LINKEDLIST_H
#define TEAM_LAB_LINKEDLIST_H
#include <string>

// Forward declarations
template<typename T> class List;
template<typename T> class Iterator;

template<typename T>
class Node {
public:
    Node(const T& element);
    Node(const T& element, Node<T>* next);
    T get_data() const;
    void set_data(const T& element);
private:
    T data;
    Node<T>* previous;
    Node<T>* next;

friend class List<T>;
friend class Iterator<T>;
};


template<typename T>
class Iterator {
public:
    //Iterator();
    Iterator(Node<T>* pos = nullptr, List<T>* cont = nullptr) : position(pos), container(cont) {}
    T get() const;
    void next();
    void previous();
    bool equals(Iterator<T> other) const;
    Node<T>* get_position() const {
        return this->position;
    }

private:
    Node<T>* position;
    List<T>* container;

    friend class List<T>;
};

template<typename T>
class List {
public:
    List();
    void push_back(const T& element);       // add elements to the end of the list
    void insert(Iterator<T> iter, const T& element);    //insert elements at a specific position
    Iterator<T> erase(Iterator<T> iter);    //erase elements at a specific position
    Iterator<T> begin();
    Iterator<T> end();

private:
    Node<T>* first;
    Node<T>* last;

friend class Iterator<T>;
};


//-------------Node---------------------
template<typename T>
Node<T>::Node(const T& element){
    this->data = element;
    this->previous = nullptr;
    this->next = nullptr;
}

//-------------Iterator------------------

template<typename T>
T Iterator<T>::get() const {
    return position->data;
}

template<typename T>
void Iterator<T>::next() {
    if (position)
        position = position->next;
}

template<typename T>
void Iterator<T>::previous() {
    if (position)
        position = position->previous;
}

template<typename T>
bool Iterator<T>::equals(Iterator<T> other) const {
    return position == other.position && container == other.container;
}

//-------------List------------------
template<typename T>
List<T>::List(){
    this -> first = nullptr;
    this -> last = nullptr;
};

template<typename T>
void List<T>::push_back(const T& element) {
    Node<T>* new_node = new Node<T>(element);
    if (!first) {
        first = new_node;
        last = new_node;
    } else {
        new_node -> previous = last;
        last -> next = new_node;
        last = new_node;
    }
}

template<typename T>
void List<T>::insert(Iterator<T> iter, const T& element) {
    if (iter.position == nullptr) {
        push_back(element);
        return;
    }
    Node<T>* new_node = new Node<T>(element);
    new_node->next = iter.position;
    new_node->previous = iter.position->previous;
    if (iter.position->previous)
        iter.position->previous->next = new_node;
    else
        first = new_node;
    iter.position->previous = new_node;
}

template<typename T>
Iterator<T> List<T>::erase(Iterator<T> iter) {
    if (iter.position == nullptr) {
        return iter;
    }

    Iterator<T> result(iter.position->next, iter.container);
    if (iter.position->previous) {
        iter.position->previous->next = iter.position->next;
    }else {
        first = iter.position->next;
    }

    if (iter.position->next) {
        iter.position->next->previous = iter.position->previous;
    }else {
        last = iter.position->previous;
    }

    delete iter.position;
    return result;
}

template<typename T>
Iterator<T> List<T>::begin() {
    Iterator<T> iter;
    iter.position = first;
    iter.container = this;
    return iter;
}

template<typename T>
Iterator<T> List<T>::end(){
    Iterator<T> iter;
    iter.position = last;
    iter.container = this;
    return iter;
}


//getter
template<typename T>
T Node<T>::get_data() const{
    return data;
}

//setter
template<typename T>
void Node<T>::set_data(const T& element){
    this->data = element;
    
}




#endif //TEAM_LAB_LINKEDLIST_H
