#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

void getmemtotal(){

  ifstream file("/proc/meminfo");
  string line;

  if(!file.good()){
	  cerr << "Could not open meminfo.... exiting..." << endl;
	  exit(EXIT_FAILURE);
  }

  while(getline(file, line)){
	  stringstream linestream(line);
    string token;
	  long long unsigned int memtotal;
      
	  getline(linestream, token, ' ');

    if(token == "MemTotal:"){
	    linestream >> memtotal;
	    cout << "Memory Total: " << memtotal/1000 << "MB" << endl;
    }
  }
  file.close();
}

void getmemfree(){
    ifstream file("/proc/meminfo");
  string line;

  if(!file.good()){
	  cerr << "Could not open meminfo.... exiting..." << endl;
	  exit(EXIT_FAILURE);
  }

  while(getline(file, line)){
	  stringstream linestream(line);
    string token;
	  long long unsigned int memfree;
      
	  getline(linestream, token, ' ');

    if(token == "MemFree:"){
	    linestream >> memfree;
	    cout << "Memory Free: " << memfree/1000 << "MB" << endl;
    }
  }
  file.close();
}

void getmemcache(){

  ifstream file("/proc/meminfo");
  string line;

  if(!file.good()){
	  cerr << "Could not open meminfo.... exiting..." << endl;
	  exit(EXIT_FAILURE);
  }

  while(getline(file, line)){
	  stringstream linestream(line);
    string token;
	  long long unsigned int Cached;
      
	  getline(linestream, token, ' ');

    if(token == "Cached:"){
	    linestream >> Cached;
	    cout << "Cached: " << Cached/1000 << "MB" << endl;
    }
  }
  file.close();
}

void getmembuff(){

  ifstream file("/proc/meminfo");
  string line;

  if(!file.good()){
	  cerr << "Could not open meminfo.... exiting..." << endl;
	  exit(EXIT_FAILURE);
  }

  while(getline(file, line)){
	  stringstream linestream(line);
    string token;
	  long long unsigned int buff;
      
	  getline(linestream, token, ' ');

    if(token == "Buffers:"){
	    linestream >> buff;
	    cout << "Buffered: " << buff/1000 << "MB" << endl;
    }
  }
  file.close();
}
