//solution.cpp
#include<solution.h>

void ReadFile(std::string filename){
    std::string line;
    std::ifstream myfile (filename);
    if (myfile.is_open()){
        while ( std::getline (myfile,line) ){
            std::istringstream iss(line); 
            int count = 0;
            std::string tail_v = "";

            for(std::string s; iss >> s;){
                if(count != 0){
                    std::vector<std::string> tmp_vec_edge;
                    std::string delimiter = " ";
                    size_t pos = 0;
                    std::string token;

                    if((pos = s.find(delimiter)) != std::string::npos){
                        token = s.substr(0, pos);
                        tmp_vec_edge.push_back(tail_v);
                        tmp_vec_edge.push_back(token);
                        std::cout<<"(V="<<token<<" ";
                        s.erase(0, pos + delimiter.length());
                        tmp_vec_edge.push_back(s);
                        std::cout<<"W="<<s<<"), ";
                        input_edge_list.push_back(tmp_vec_edge);
                    }
                }else{
                    tail_v = s;
                    std::cout << tail_v <<": ";
                }
                ++count;
            }
            std::cout<<std::endl;
        }
        myfile.close();
    }else std::cout << "Unable to open file"; 
}
