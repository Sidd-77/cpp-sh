#include "cd.h"

using namespace std;

void changeDir(string givenPath) {
  filesystem::path newPath;

  if(givenPath == "."){
    return; 
  }else if(givenPath == ".."){
    newPath = filesystem::current_path().parent_path();
  }else{
    newPath = filesystem::absolute(givenPath);
  }

  if(newPath.empty()){
    cerr << "cd: No parent directory.\n";
    return;
  }

  if(chdir(newPath.c_str()) != 0){
    perror("cd"); 
  }

  return;
}
