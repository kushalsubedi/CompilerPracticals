#include <iostream>
#include <fstream>
#include<string>
int main(int argc,char* argv[]){
    if (argc !=2){
        std::cerr <<"Incorrect Usage"<<std::endl;
        return EXIT_FAILURE; 
    }
    std::cout << argv[1]<< std::endl;
    std::fstream input(argv[1],std::ios::in);
    std::stringstream cotents_stream;
    {
          std::fstream input(argv[1],std::ios::in);
    }
    contents_stream << input.rdbuf();
    input.close();
    return EXIT_SUCCESS;
}