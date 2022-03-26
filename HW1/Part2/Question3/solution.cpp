//solution.cpp
#include <solution.h>

void String::operator=(const String &other){
    if(size > 0){
        delete [] in_str_array;
        delete [] f;
    }

    size         = other.size;
    char *temp   = new char [size];
    int  *temp_f = new int  [size];

    for(int i=0;i<size;++i){
        temp[i]   = other.in_str_array[i];
        temp_f[i] = other.f[i];
    }
    in_str_array = temp;
    f            = temp_f;
    temp   = nullptr;
    temp_f = nullptr;
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
    int total_size = size+t.size;
    String result_str(total_size, "result_str");
    char *temp = new char [total_size];
    delete [] result_str.in_str_array;

    if(size > 0){
        for(int i=0;i<size;++i){
            temp[i] = in_str_array[i];
        }

        for(int i=size;i<total_size;++i){
            temp[i] = t.in_str_array[i-size];
        }
    }else{
        for(int i=0;i<total_size;++i){
            temp[i] = t.in_str_array[i];
        }
    }

    result_str.in_str_array = temp;
    temp = nullptr;

    return result_str;
}

String String::Substr(int i, int j){
    String tmp(j-i+1, "tmp_str");
    if(i<0 || i>(size-1) || j<0 || j>(size-1)){
        throw std::runtime_error(std::string("Error: the range of input i and j is not in the size of this string:"+name));
    }else if(i>j){
        throw std::runtime_error(std::string("Error: the input i is larger than j, which is not a correct pair of input."));
    }

    for(int start_pos=i;start_pos<=j;++start_pos){
        tmp.in_str_array[start_pos-i] = in_str_array[start_pos];
    }

    return tmp;
}


String String::Delete(int start, int length){
    if(length == 0){
        return *this;
    }else if(length < 0){
        throw std::runtime_error(std::string("Error: input argument length = "+std::to_string(length)+", which is not allowed to be <0."));
    }else if(start+length > size-1){
        throw std::runtime_error(std::string("Error: start+length = "+std::to_string(start+length)+"surpass the original size"+std::to_string(size)+"in this String: "+name));
    }

    int result_size = size-length;
    int result_index = 0;
    String result_str(result_size, "result_str");

    for(int i=0;i<size;++i){
        if((i>=start) && i<=(start+length-1)){
            continue;
        }else{
            result_str.in_str_array[result_index] = in_str_array[i];
            result_index++;
        }
    }

    return result_str;
}

String String::CharDelete(char c){
    int count_occur = 0;

    for(int i=0;i<size;++i){
        if(in_str_array[i]==c){
            count_occur++;
        }
    }

    if(count_occur == 0){
        return *this;
    }else{
        int total_size = size-count_occur;
        int result_index = 0;
        String result_str(total_size, "result_str");

        for(int i=0;i<size;++i){
            if(in_str_array[i] == c){
                continue;
            }else{
                result_str.in_str_array[result_index] = in_str_array[i];
                result_index++;
            }
        }

        return result_str;
    }
}

int String::Compare(String y){
    if(size == 0 ){
        throw std::runtime_error(std::string("Error: this String: "+std::string(name)+" is empty. Compare() cannot be applied."));
    }else if(y.size == 0){
        throw std::runtime_error(std::string("Error: the input String: "+std::string(y.name)+" is empty. Compare() cannot be applied."));
    }

    int result;

    if(size > y.size){
        bool all_equal = true;
        for(int i=0;i<y.size;++i){
            if(in_str_array[i] > y.in_str_array[i]){
                result = 1;//x>y
                all_equal = false;
                break;
            }else if(in_str_array[i] < y.in_str_array[i]){
                result = -1;//x<y
                all_equal = false;
                break;
            }
        }

        if(all_equal){//x>y
            result = 1;
        }
    }else if(size==y.size){
        bool all_equal = true;
        for(int i=0;i<y.size;++i){
            if(in_str_array[i] > y.in_str_array[i]){
                result = 1;//x>y
                all_equal = false;
                break;
            }else if(in_str_array[i] < y.in_str_array[i]){
                result = -1;//x<y
                all_equal = false;
                break;
            }
        }

        if(all_equal){//x=y
            result = 0;
        }
    }else{//size < y.size
        bool all_equal = true;
        for(int i=0;i<size;++i){
            if(in_str_array[i] > y.in_str_array[i]){
                result = 1;//x>y
                all_equal = false;
                break;
            }else if(in_str_array[i] < y.in_str_array[i]){
                result = -1;//x<y
                all_equal = false;
                break;
            }
        }

        if(all_equal){//x<y
            result = -1;
        }
    }
    return result;
}

void String::FailuerFunction(){
    if(size == 0){
        throw std::runtime_error(std::string("Error: the input String: "+std::string(name)+" is empty. FailuerFunction() cannot be applied."));
    }

    f[0] = -1;
    for(int j=1;j<size;++j){
        int i = f[j-1];
        while((in_str_array[j] != in_str_array[i+1]) && (i>=0)){
            i = f[i];
        }

        if(in_str_array[i+1]==in_str_array[j]){
            f[j] = i+1;
        }else{
            f[j] = -1;
        }
    }
}

int String::Find(String pat){
    if(pat.size == 0){
        return -1;
    }

    int pos_p = 0;
    int pos_s = 0;

    pat.FailuerFunction();

    while((pos_s<size) && (pos_p<pat.size)){
        if(in_str_array[pos_s] == pat.in_str_array[pos_p]){
            pos_s++;
            pos_p++;
        }else{
            if(pos_p==0){
                pos_s++;
            }else{
                pos_p = pat.f[pos_p-1]+1;
            }
        }
    }

    if(pos_p>=pat.size){
        return pos_s-pat.size;
    }else{
        return -1;
    }
}
