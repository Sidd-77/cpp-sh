#include <iostream>
#include <string>

using namespace std;

string executeCommand(string input){
  // execute command logic goes here
  string ouput = "some output";
  return ouput;
}

int main(){
  cout<<"Welcome to our shell"<<endl;
  
  while(true){
    // 1. Dsplay prompt
    cout<<" $ ";
    string input;

    // 2. Take input
    getline(cin, input);
    
    // 3. Execute command
    string output = executeCommand(input);

    // 4. Show output
    cout<<output<<endl;

    //loop continues...
  }

  return 0;
}
