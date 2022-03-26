//main.cpp
#include <iostream>
#include <solution.h>
#include <cstring>


int main(){
    std::string str = "I have a ";
    char *a = new char[str.length()];
    strcpy(a, str.c_str());
    String test_a_str(a, str.length(), "test_a_str");
    std::cout<<test_a_str;

    str = "dog, a very biggggggggggg one.";
    char *b = new char[str.length()];
    strcpy(b, str.c_str());
    String test_b_str(b, str.length(), "test_b_str");
    std::cout<<test_b_str;

    str = "birthday";
    char *c = new char[str.length()];
    strcpy(c, str.c_str());
    String test_c_str(c, str.length(), "test_c_str");
    std::cout<<test_c_str;

    String test_d_str("test_d_str");
    try{std::cout<<test_d_str;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    str = "birthday";
    char *e = new char[str.length()];
    strcpy(e, str.c_str());
    String test_e_str(e, str.length(), "test_e_str");
    std::cout<<test_e_str;

    std::cout<<std::endl;
    std::cout<<"------------operator==() Test--------------"<<std::endl;
    if(test_a_str==test_b_str){
        std::cout<<"test_a_str == test_b_str : True."<<std::endl;
    }else{
        std::cout<<"test_a_str == test_b_str : False."<<std::endl;
    }

    if(test_c_str==test_b_str){
        std::cout<<"test_c_str == test_b_str : True."<<std::endl;
    }else{
        std::cout<<"test_c_str == test_b_str : False."<<std::endl;
    }

    if(test_c_str==test_e_str){
        std::cout<<"test_c_str == test_e_str : True."<<std::endl;
    }else{
        std::cout<<"test_c_str == test_e_str : False."<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"------------operator!() Test--------------"<<std::endl;
    if(!test_d_str){
        std::cout<<"!test_d_str : True."<<std::endl;
    }else{
        std::cout<<"!test_d_str : False."<<std::endl;
    }

    if(!test_a_str){
        std::cout<<"!test_a_str : True."<<std::endl;
    }else{
        std::cout<<"!test_a_str : False."<<std::endl;
    }

    if(!test_b_str){
        std::cout<<"!test_b_str : True."<<std::endl;
    }else{
        std::cout<<"!test_b_str : False."<<std::endl;
    }

    if(!test_c_str){
        std::cout<<"!test_c_str : True."<<std::endl;
    }else{
        std::cout<<"!test_c_str : False."<<std::endl;
    }

    if(!test_e_str){
        std::cout<<"!test_e_str : True."<<std::endl;
    }else{
        std::cout<<"!test_e_str : False."<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"------------Length() Test--------------"<<std::endl;
    std::cout<<"Length(test_a_str) = "<<test_a_str.Length()<<std::endl;
    std::cout<<"Length(test_b_str) = "<<test_b_str.Length()<<std::endl;
    std::cout<<"Length(test_c_str) = "<<test_c_str.Length()<<std::endl;
    std::cout<<"Length(test_d_str) = "<<test_d_str.Length()<<std::endl;
    std::cout<<"Length(test_e_str) = "<<test_e_str.Length()<<std::endl;

    std::cout<<std::endl;
    std::cout<<"------------Concat() Test--------------"<<std::endl;
    String test_ab_str_concat_result("test_ab_str_concat_result");
    test_ab_str_concat_result = test_a_str.Concat(test_b_str);
    std::cout<<"test_a_str.Concat(test_b_str) = "<<std::endl;
    std::cout<<test_ab_str_concat_result;

    String test_bc_str_concat_result("test_bc_str_concat_result");
    test_bc_str_concat_result = test_b_str.Concat(test_c_str);
    std::cout<<"test_b_str.Concat(test_c_str) = "<<std::endl;
    std::cout<<test_bc_str_concat_result;

    String test_dc_str_concat_result("test_dc_str_concat_result");
    test_dc_str_concat_result = test_d_str.Concat(test_c_str);
    std::cout<<"test_d_str.Concat(test_c_str) = "<<std::endl;
    std::cout<<test_dc_str_concat_result;

    std::cout<<std::endl;
    std::cout<<"------------Substr() Test--------------"<<std::endl;
    int i = 2, j = 4;
    String test_a_substr("test_a_substr");
    std::cout<<"test_a_str.Substr("<<i<<", "<<j<<")"<<std::endl;
    try{test_a_substr = test_a_str.Substr(i, j);
        std::cout<<test_a_substr;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    i = 3, j = 5;
    String test_b_substr("test_b_substr");
    std::cout<<"test_b_str.Substr("<<i<<", "<<j<<")"<<std::endl;
    try{test_b_substr = test_b_str.Substr(i, j);
        std::cout<<test_b_substr;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    i = 1, j = 7;
    String test_c_substr("test_c_substr");
    std::cout<<"test_c_str.Substr("<<i<<", "<<j<<")"<<std::endl;
    try{test_c_substr = test_c_str.Substr(i, j);
        std::cout<<test_c_substr;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"------------Delete() Test--------------"<<std::endl;
    int start  = 1;
    int length = 5;
    String test_a_delete("test_a_delete");
    std::cout<<"test_a_str.Delete("<<start<<", "<<length<<") = "<<std::endl;
    try{test_a_delete = test_a_str.Delete(start, length); std::cout<<test_a_delete;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    start  = 4;
    length = 9;
    String test_b_delete("test_b_delete");
    std::cout<<"test_b_str.Delete("<<start<<", "<<length<<") = "<<std::endl;
    try{test_b_delete = test_b_str.Delete(start, length); std::cout<<test_b_delete;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"------------CharDelete() Test--------------"<<std::endl;
    char delete_char = 'a';
    String test_a_char_delete("test_a_char_delete");
    std::cout<<"test_a_str.CharDelete("<<delete_char<<") = "<<std::endl;
    try{test_a_char_delete = test_a_str.CharDelete(delete_char); std::cout<<test_a_char_delete;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    delete_char = 'g';
    String test_b_char_delete("test_b_char_delete");
    std::cout<<"test_b_str.CharDelete("<<delete_char<<") = "<<std::endl;
    try{test_b_char_delete = test_b_str.CharDelete(delete_char); std::cout<<test_b_char_delete;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"------------Compare() Test--------------"<<std::endl;
    str = "birthsijk";
    char *f = new char[str.length()];
    strcpy(f, str.c_str());
    String test_f_str(f, str.length(), "test_f_str");
    std::cout<<test_c_str;
    std::cout<<test_f_str;
    std::cout<<"test_c_str.Compare(test_f_str) = ";
    try{std::cout<<test_c_str.Compare(test_f_str)<<std::endl;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    std::cout<<std::endl;
    str = "birthdayxabbabc";
    delete [] f;
    f = new char[str.length()];
    strcpy(f, str.c_str());
    String test_h_str(f, str.length(), "test_h_str");
    std::cout<<test_c_str;
    std::cout<<test_h_str;
    std::cout<<"test_c_str.Compare(test_h_str) = ";
    try{std::cout<<test_c_str.Compare(test_h_str)<<std::endl;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<test_c_str;
    std::cout<<test_e_str;
    std::cout<<"test_c_str.Compare(test_e_str) = ";
    try{std::cout<<test_c_str.Compare(test_e_str)<<std::endl;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    std::cout<<std::endl;
    str = "I cave a ";
    char *g = new char[str.length()];
    strcpy(g, str.c_str());
    String test_g_str(g, str.length(), "test_g_str");
    std::cout<<test_a_str;
    std::cout<<test_g_str;
    std::cout<<"test_a_str.Compare(test_g_str) = ";
    try{std::cout<<test_a_str.Compare(test_g_str)<<std::endl;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    std::cout<<std::endl;
    str = "I have ";
    delete [] g;
    g = new char[str.length()];
    strcpy(g, str.c_str());
    String test_k_str(g, str.length(), "test_k_str");
    std::cout<<test_a_str;
    std::cout<<test_k_str;
    std::cout<<"test_a_str.Compare(test_k_str) = ";
    try{std::cout<<test_a_str.Compare(test_k_str)<<std::endl;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"------------Find() Test--------------"<<std::endl;




    delete [] a;
    delete [] b;
    delete [] c;
    delete [] e;
    delete [] f;
    delete [] g;
    return EXIT_SUCCESS;
}
