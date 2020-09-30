#include <unistd.h>
#include <sys/stat.h>
#include <sstream>
#include <iostream>
using namespace std;
int64_t now(){
    time_t nowTs;
    time(&nowTs);
    nowTs = nowTs - nowTs%60;
    return nowTs * 1000;
}
int main(){
    cout << now();
}

