#include <vector>
#include "execute.h"

int main (int argc, char *argv[]) {
  vector<string> command1 = {"ls"};
  vector<string> command2 = {"grep", "cpp"};

  string output = executeCommand(command1);
  cout<<output<<endl;
  string out2 = executeCommand(output, command2);
  cout<<out2<<endl;
  return 0;
}
