#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

void getCPUnum(){
  
  int CPUnum;
  CPUnum=-1;

  ifstream file("/proc/stat");
  string line;

  if(!file.good()){
	  cerr << "Could not open meminfo.... exiting..." << endl;
	  exit(EXIT_FAILURE);
  }

  while(getline(file, line)){
	  stringstream linestream(line);
    string token;
      
	  getline(linestream, token, ' ');
  
    string s = line;
    if (s.find("cpu") != std::string::npos){
      CPUnum++;
    }
  }
  cout << "--------------------------------------------------" << endl;
  
  cout << "CPU Threads: " << CPUnum << endl;
  file.close();

  cout << "--------------------------------------------------" << endl;
}

void getCPUActivity(){
  string token;
	float user;
  float userpercent;
	float nice;
  float nicepercent;
	float system;
  float systempercent;
	float idle;
  float idlepercent;
  float total;

  ifstream file("/proc/stat");
  string line;

  if(!file.good()){
	cerr << "Could not open file.... exitting..." << endl;
	exit(EXIT_FAILURE);
  }

  cout << "CPU" << setw(10)<< right << "Busy" << setw(10)<< right << "Nice" << setw(10)<< right << "System" << setw(8)<< right << "Idle" << endl;

	while(getline(file, line)){
	  stringstream linestream(line);

    getline(linestream, token, ' ');

    if (line.find("cpu") != string::npos){
      if(token!="cpu"){
        
        linestream >> user >> nice >> system >> idle;
        total=user+nice+system+idle;
        userpercent=((user/total)*100);
        nicepercent=((nice/total)*100);
        systempercent=((system/total)*100);
        idlepercent=(idle/total)*100;
      
      cout<< token << setw(9) << right << fixed << setprecision(1) << userpercent << "%" << setw(8)<< right << nicepercent << "%" << setw(8)<< right << systempercent << "%" << setw(9)<< right  << idlepercent << "%" << endl;

      }
	  }
  } 

  cout << "--------------------------------------------------" << endl;
  
  file.close();

}

void getotherstats(){

  ifstream file("/proc/stat");

  string line;

  if(!file.good()){
	  cerr << "Could not open stat.... exiting..." << endl;
	   exit(EXIT_FAILURE);
  }

  while(getline(file, line)){
	  stringstream linestream(line);
    string token;
	  float temp;
    float temp2;
      
	  getline(linestream, token, ' ');

    if(token == "ctxt"){
	    linestream >> temp;
	    cout << "Context Switch Counts: " << setprecision(2) << temp/1000000000 << " Billions" << endl;
    }
    
    if(token == "intr"){
	    linestream >> temp;
	    cout << "Interrupts: " << setprecision(2) << temp/1000000000 << " Billions"<< endl;
    }

    if(token == "page"){
	    linestream >> temp >> temp2;
	    cout << "Page IN/OUT Ratio: " << setprecision(10) << temp/temp2 << endl;
    }

    if(token == "swap"){
	    linestream >> temp >> temp2;
	    cout << "Swap IN/OUT Ratio: " << setprecision(10) << temp/temp2 << endl;
    }
    
  }
  cout << "--------------------------------------------------" << endl;
}
