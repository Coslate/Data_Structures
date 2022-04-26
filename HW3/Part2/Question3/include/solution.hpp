//solution.hpp
#include <solution.h>

template <class T>
T ComputeExpression(List<T> &in_list){
    T result = 0;
    for(typename List<T>::Iterator i = in_list.Begin(); i!=in_list.End(); i++){
        if((i+5) == in_list.End()){
            break;
        };
        result += (*i)*(*(i+5));
    }

    return result;
}
