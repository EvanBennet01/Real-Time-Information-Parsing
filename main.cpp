#include "stats.hpp"
#include "memory.hpp"
#include "uptime.hpp"
#include <ctime>
#include <unistd.h>
#include <iostream>

using namespace std;

int main () {

  while(true){
    getCPUnum();
    getCPUActivity();
    getotherstats();
    getmemtotal();
    getmemfree();
    getmemcache();
    getmembuff();
    getuptime();
    getidletime();
    getenergy();
    usleep(500000); //Waits 0.5 seconds or 500000 microseconds
    cout << "\033[2J\033[1;1H"; //Clears Screen and positions the cursor at row 1, column 1.
  }
}
