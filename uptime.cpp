#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

void getuptime(){
  
  ifstream file("/proc/uptime");
  int uptime;
  long long unsigned int hours;
  long long unsigned int mins;
  long long unsigned int seconds;

  if(!file.good()){
	  cerr << "Could not open Uptime.... exiting..." << endl;
	   exit(EXIT_FAILURE);
  }
  
  file >> uptime;
  hours = uptime/(60*60);
  mins = (uptime/60) - (hours*60);
  seconds = (uptime) - (hours*(60*60)) - (mins*60);

  cout << "--------------------------------------------------" << endl;

  cout << "UP for: " <<  hours << " Hours " << mins << " Mins " << seconds << " Seconds " << endl;
  
  file.close();
}

void getidletime(){

  ifstream file("/proc/uptime");

  if(!file.good()){
	  cerr << "Could not open Uptime.... exiting..." << endl;
	   exit(EXIT_FAILURE);
  }
  
  long long unsigned int hours;
  long long unsigned int mins;
  long long unsigned int seconds;
  string uptime;
  string temp_str;
  file >> uptime;
  
  while(getline(file, temp_str)){
    stringstream linestream(temp_str);
    string token;
    getline(linestream, token, ' ');

    if(temp_str != uptime){
      long long unsigned int idletime = stoi(temp_str);
      long long unsigned int hours;
      long long unsigned int mins;
      long long unsigned int seconds;

      hours = idletime/(60*60);
      mins = (idletime/60) - (hours*60);
      seconds = (idletime) - (hours*(60*60)) - (mins*60);

      cout << "IDLE for: " <<  hours << " Hours " << mins << " Mins " << seconds << " Seconds " << endl;

      cout << "--------------------------------------------------" << endl;

    }
  }
  file.close();
}

void getenergy(){

  ifstream file("/proc/uptime");

  string line;

  if(!file.good()){
	  cerr << "Could not open uptime.... exiting..." << endl;
	   exit(EXIT_FAILURE);
  }

  while(getline(file, line)){
	  stringstream linestream(line);
    float upsec;
    float upj;
    float idlesec;
    float idlej;
    linestream >> upsec >> idlesec;

    upj=(15*upsec)/(1000000); //Based on the Intel® Core™ i5-8265U
    idlej=(3*idlesec)/(1000000); //Based on the Intel® Core™ i5-8265U

    cout << "Uptime Energy: " << upj << " MJoules" << "\n" << "Idletime Energy: " << idlej << " MJoules" << endl;

    cout << "--------------------------------------------------" << endl;
    

  }
}
