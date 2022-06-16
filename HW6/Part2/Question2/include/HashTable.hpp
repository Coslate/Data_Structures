//HashTable.hpp
#include <HashTable.h>

template <class K> //Only key, omitted element in this implementation
int SymbolTable1<K>::hash_func(const K* in_key, const int key_size) const {
    if(key_size <= 0){
        throw std::runtime_error(std::string("Error: The key size cannot be smaller than or equal to 0. hash_func() terminated."));
    }

    return (int(in_key[0])-97)%ht_capacity;
}

template <class K> //Only key, omitted element in this implementation
void SymbolTable1<K>::Insert(const pair<K> &in_pair){
    if(in_pair.size <= 0){
        throw std::runtime_error(std::string("Error: The key size cannot be smaller than or equal to 0. Insert() terminated."));
    }

    int nxt_linear_probing;
    pair<K> *search_result = Search(in_pair.arr, in_pair.size, nxt_linear_probing);

    if(search_result == NULL){//not existed
        ht[nxt_linear_probing] = in_pair;
    }else{//already existed
        delete [] search_result->arr;

        search_result->size = in_pair.size;
        search_result->arr = new K [in_pair.size];
        for(int i=0; i<in_pair.size; ++i){
            search_result->arr[i] = in_pair.arr[i];
        }
    }

    ht_size++;
}

template <class K> //Only key, omitted element in this implementation
bool SymbolTable1<K>::Compare(const K *arr1, const K *arr2, const int key_size1, const int key_size2) const {
    if((arr1 == NULL) || (arr2 == NULL)) return false;
    if(key_size1 != key_size2) return false;

    for(int i=0;i<key_size1;++i){
        if(arr1[i] != arr2[i]){
            return false;
        }
    }

    return true;
}

template <class K> //Only key, omitted element in this implementation
pair<K>* SymbolTable1<K>::Search(const K *key, const int key_size, int &nxt_bucket) const {
    if(key_size <= 0){
        throw std::runtime_error(std::string("Error: The key size cannot be smaller than or equal to 0. Search() terminated."));
    }

    pair<K> *search_result = NULL;
    int hashed_value = hash_func(key, key_size);
    int tmp_org_hashed_value = hashed_value;

    while(1){
        if(ht[hashed_value].size == 0){
            break;
        }
        if(Compare(ht[hashed_value].arr, key, ht[hashed_value].size, key_size)){
            search_result = &ht[hashed_value];
            break;
        }else{
            hashed_value = (hashed_value+1)%ht_capacity;
            if((hashed_value == tmp_org_hashed_value) || (ht[hashed_value].size == 0)){//back to the beginning
                break;
            }
        }
    }

    nxt_bucket = hashed_value;
    return search_result;
}

template <class K> //Only key, omitted element in this implementation
void SymbolTable1<K>::Display() const {
    for(int i=0; i<ht_capacity; i++){
        if(i == 0){
            std::cout<<name<<" = ["<<std::endl;
        }
        if(ht[i].size == 0){
            std::cout<<"\t--(NULL)"<<std::endl;
        }else{
            std::cout<<"\t"<<ht[i]<<std::endl;
        }
    }
    std::cout<<"]"<<std::endl;
}

