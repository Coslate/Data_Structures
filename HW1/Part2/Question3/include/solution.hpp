//solution.hpp
#include <solution.h>
#include <cstdlib>

void String::operator=(const String &other){
    if(size > 0){
        delete [] in_str_array;
    }

    size       = other.size;
    char *temp = new char [size];

    for(int i=0;i<size;++i){
        temp[i] = other.in_str_array[i];
    }
    in_str_array = temp;
    temp = nullptr;
}

bool String::operator==(String t){
    bool result_eq = true;
    if(t.size == size){
        for(int i=0;i<size;++i){
            if(in_str_array[i] != t.in_str_array[i]){
                result_eq = false;
                break;
            }
        }
    }else{
        result_eq = false;
    }

    return result_eq;
}

String String::Concat(String t){
    String tmp(size+t.size, "tmp_str");
    int orig_size = size;
    size += t.size;
    char *temp = new char [size];
    delete [] tmp.in_str_array;

    if(orig_size > 0){
        for(int i=0;i<orig_size;++i){
            temp[i] = in_str_array[i];
        }

        for(int i=orig_size;i<size;++i){
            temp[i] = t.in_str_array[i-orig_size];
        }
    }else{
        for(int i=0;i<size;++i){
            temp[i] = t.in_str_array[i];
        }
    }

    tmp.in_str_array = temp;
    temp = nullptr;

    return tmp;
}

String String::Substr(int i, int j){
    String tmp(j-i+1, "tmp_str");
    if(i<0 || i>(size-1) || j<0 || j>(size-1)){
        throw std::runtime_error(std::string("Error: the range of input i and j is not in the size of this string:"+name));
    }else if(i>j){
        throw std::runtime_error(std::string("Error: the input i is larger than j, which is not a correct pair of input."));
    }

    for(int start_pos=i;start_pos<=j;++start_pos){
        tmp.in_str_array[start_pos] = in_str_array[start_pos];
    }

    return tmp;
}
