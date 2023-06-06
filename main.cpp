#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
    //argv[1] = 복구할 mdf path
    ifstream ifs(argv[1]);

    //목표는 이렇게 했을 때 전부 복구되는거
    Fat32 fat32(&ifs);
    return 0;
}