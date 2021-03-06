#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <vector>
#include <string>
#include <cfloat>
#include <climits>
#include <math.h>
#include <unordered_map>
#include <algorithm>
#include <iostream>

class String{
    private:
        int         size;
        std::string name;
        char*       in_str_array;
        int*        f;//failure function for Find()
    public:
        String(const std::string &name = "Null"):size(0), name(name), in_str_array(nullptr), f(nullptr){}

        String(int m, const std::string &name="NULL"):size(m), name(name), f(nullptr){
            in_str_array = new char [size];
            f            = new int  [size];
            std::fill(f, f + size, -1);
        }

        String(char* init, int m, const std::string &name="NULL"):size(m), name(name){
            in_str_array = new char [size];
            f            = new int [size];

            for(int i=0;i<size;++i){
                in_str_array[i] = init[i];
            }

            std::fill(f, f+size, -1);
        }

        //Copy consturctor
        String(const String &p){
            size     = p.size;
            name     = p.name;
            f            = new int  [size];
            in_str_array = new char [size];

            for(int i=0;i<size;++i){
                in_str_array[i] = p.in_str_array[i];
                f[i] = p.f[i];
            }
        }

        //Destructor
        ~String(){
            if(size > 0 && in_str_array != nullptr){
                delete [] in_str_array;
                in_str_array = nullptr;
            }

            if(size > 0 && f != nullptr){
                delete [] f;
                f = nullptr;
            }
        }

        //Support Functions
        int                                GetSize             () const {return size;}
        std::string                        GetName             () const {return name;}
        char*                              GetStrArray         () const {return in_str_array;}

        void                               SetSize             (const int &in_size)        {size    = in_size;}
        void                               SetName             (const std::string &in_name){name    = in_name;}

        int                                Length              (){return size;}
        String                             Concat              (String t);
        String                             Substr              (int i, int j);
        int                                Find                (String pat);
        String                             Delete              (int start, int length);
        String                             CharDelete          (char c);
        int                                Compare             (String y);
        void                               FailuerFunction     ();

        void operator=(const String &other);
        bool operator==(String t);
        bool operator!(){return (size==0);}

        void PrintFailureFunction(){
            for(int i=0;i<size;++i){
                if(i==0){
                    std::cout<<"["<<f[i]<<" ";
                }else if(i==size-1){
                    std::cout<<f[i]<<"]"<<std::endl;
                }else{
                    std::cout<<f[i]<<" ";
                }
            }
        }

        friend std::ostream & operator<<(std::ostream &os, const String &out_string){
            os<<out_string.name<<" is: ";
            if(out_string.size == 0){
                throw std::runtime_error(std::string("Warning: The String is empty.\n"+std::string("The size of ")+out_string.name+std::string(" is ")+std::to_string(out_string.size)));
            }

            for(int i=0;i<out_string.size;++i){
                if(i == out_string.size-1){
                    os<<out_string.in_str_array[i]<<"\""<<std::endl;
                }else if(i==0){
                    os<<"\""<<out_string.in_str_array[i];
                }else{
                    os<<out_string.in_str_array[i];
                }
            }
            os<<"The size of "<<out_string.name<<" is "<<out_string.size<<std::endl;
            return os;
        }
};

#endif

