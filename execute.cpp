#include "execute.h"

string executeCommand(vector<string> input){
  int pipearr[2];
  string result;

  if(pipe(pipearr) == -1){
    perror("Error while creating pipe");
    exit(1);
  }

  pid_t pid = fork();
  if(pid==0){

    close(pipearr[0]);
    dup2(pipearr[1], STDOUT_FILENO); 
    close(pipearr[1]);

    char* args[input.size() + 1];
    for(int i=0; i<input.size(); i++){
      char* tmp = input[i].data();
      args[i] = tmp;
    }
    args[input.size()] = NULL;
    execvp(args[0], args);
    perror("execvp failed...");
    exit(1);
  }else if(pid > 0){
    close(pipearr[1]);
    char buffer[1024];
    ssize_t bytesRead;
    while((bytesRead = read(pipearr[0], buffer, sizeof(buffer)-1)) > 0){
      result.append(buffer, bytesRead);
    }
    close(pipearr[0]);

    int status;
    waitpid(pid, &status, 0);
  }else{
    cout<<" [[ ERROR ]] Fork failed..."<<endl;
    return "";
  }

  return result;
}

vector<pid_t> bgProcesses;

string executeCommand(vector<string> input, bool background) {
  int pipearr[2];
  string result;
  if(background) input.pop_back();
  if(pipe(pipearr) == -1){
    perror("Error while creating pipe");
    exit(1);
  }

  pid_t pid = fork();

  if (pid == 0) {  
    close(pipearr[0]);
    dup2(pipearr[1], STDOUT_FILENO);  
    close(pipearr[1]);

    char* args[input.size() + 1];
    for(int i=0; i<input.size(); i++){
      char* tmp = input[i].data();
      args[i] = tmp;
    }
    cout<<endl;
    args[input.size()] = NULL;
    execvp(args[0], args);
    perror("execvp failed...");
    exit(1);
  } 
  else if (pid > 0) {  
    if (background) {
      bgProcesses.push_back(pid);  
      cout << "Started background process with PID: " << pid << endl;
    } else {
      close(pipearr[1]);
      char buffer[1024];
      ssize_t bytesRead;
      while((bytesRead = read(pipearr[0], buffer, sizeof(buffer)-1)) > 0){
        result.append(buffer, bytesRead);
      }
      close(pipearr[0]);

      int status;
      waitpid(pid, &status, 0);
    }
  } 
  else {
    perror("fork failed");
  }
  return result;
}

void checkBackgroundProcesses() {
  for (auto it = bgProcesses.begin(); it != bgProcesses.end();) {
    if (waitpid(*it, nullptr, WNOHANG) > 0) {
      cout << "Process " << *it << " completed\n";
      it = bgProcesses.erase(it);  
    } else {
      ++it;
    }
  }
}



string executeCommand(string input, vector<string> commands){
  int fd_in[2], fd_out[2];
  if(pipe(fd_in) < 0 || pipe(fd_out) < 0){
    perror("Error creating pipe...");
    exit(1);
  }

  string result;

  pid_t pid = fork();

  if(pid == 0){
    close(fd_in[1]);
    dup2(fd_in[0], STDIN_FILENO);
    close(fd_in[0]);
    dup2(fd_out[1], STDOUT_FILENO);
    close(fd_out[1]);

    char* args[commands.size()+1];
    for(int i=0; i<commands.size(); i++){
      char* tmp = commands[i].data();
      args[i] = tmp;
    }
    args[commands.size()] = NULL;
    execvp(args[0], args);
    perror("Execvp failed with inputs");
    exit(1);
  }else if(pid > 0){
    close(fd_in[0]);
    close(fd_out[1]);
    char* inputBuffer = input.data();
    write(fd_in[1], inputBuffer, input.size());
    close(fd_in[1]);
    char outputBuffer[1024];
    ssize_t bytesRead;
    while((bytesRead = read(fd_out[0], outputBuffer, sizeof(outputBuffer)-1)) > 0){
      result.append(outputBuffer, bytesRead);
    }
    close(fd_out[0]);
    int status;
    waitpid(pid, &status, 0);
  }else{
    cout<<"Error fork failed..."<<endl;
    return "";
  }

  return result;

}
