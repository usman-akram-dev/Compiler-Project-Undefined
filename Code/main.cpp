#include <bits/stdc++.h>

#include "lexicalAnalyzer.cpp"

int main() {

        std::string file = "input.un";
        LexicalAnalyzer undefined;
        undefined.Tokenization(file);
        if(undefined.flag==1){
          std::cout<<"Syntax Error" << std::endl;
          std::cout<<"Parsing Failed!" << std::endl;
        }
        else {
          std::cout<<"Parsing Successful!" << std::endl;
        }

        return 0;

}
