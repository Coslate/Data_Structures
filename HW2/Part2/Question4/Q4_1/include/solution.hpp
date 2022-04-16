//solution.hpp

template <class T>
void Node<T>::operator=(const Node &other){
    x = other.x;
    y = other.y;
    dir = other.dir;
}
