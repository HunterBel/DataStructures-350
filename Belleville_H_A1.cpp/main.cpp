  #include "Model.h"
  #include "Translator.h"
  #include "FileProcessor.h"

  #include <iostream>
  #include <string>  
        
    int main(){

        Model *m = new Model;
        Translator *t = new Translator;
        FileProcessor *f = new FileProcessor;

        f->processFile("input.txt","output.html");


        delete m;
        delete t;
        delete f;
        return 0;
    }