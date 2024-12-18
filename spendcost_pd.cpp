//Ilana Macy
//Cs 477
//HW6
//my runtime is slow fair warning
//This code is my own work, it was written without consulting a tutor or code written by other students.

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int A[4] = {3500, 1500, 2000, 1500};
    int B[4] = {2500, 1000, 3500, 2000};
    int CA[5] = {3500,0,0,0,0};
    int CB[5] = {2500,0,0,0,0};
    int fuel = 200;
    int DA = 500;
    int DB = 400;
    int optimal[5] = {0,0,0,0,0};
    char path[4] = {'d','d','d','d'};
    char decB[4] = {'-','-','-','-'};
    char decA[4] = {'-','-','-','-'};
    int prevB = 0;
    int prevA = 0;
    int nowA = 0;
    int nowB = 0;
    int AB = 0;
    int AA = 0;
    int BA = 0;
    int BB = 0;
    for(int i = 1; i < 5; i++){
        AA = A[i] + CA[i-1] - DA;
        AB = B[i] + CA[i-1] + fuel;
        prevA = min(AA, AB);
        BA = A[i] + CB[i-1] + fuel;
        BB = B[i] + CB[i-1] - DB;
        prevB = min(BA, BB);
        CA[i] = min(BA, AA);
        CB[i] = min(AB, BB);
        if(prevB < prevA){
            optimal[i] = prevB;
            path[i-1] = 'B';
            if(i==1){
                optimal[i-1] = B[i-1];
            }
        }
        else{
            optimal[i] = prevA;
            path[i-1] = 'A';
            
            if(i==1){
                optimal[i-1] = A[i-1];
            }
        }
        if(i < 4){
            int nowA = min(AA, BA);
            int nowB = min(AB, BB);
            if(nowA == AA){
                decA[i] = 'A';
            }
            else if (nowA == BA){
                decA[i] = 'B';
            }
            if(nowB == BB){
                decB[i] = 'B';
            }
            else if(nowB == AB){
                decB[i] = 'A';
            }
        }
        
    }
    ofstream MyFile("spendcost_pd_out.txt");
    MyFile << "A | ";
    for(int i = 0; i < 4; i++){
        MyFile << CA[i];
        if(i != 3){
            MyFile << "| ";
        }
    }
    MyFile << "\nB | ";
    for(int i = 0; i < 4; i++){
        MyFile << CB[i];
        if(i != 3){
            MyFile << "| ";
        }
    }
    MyFile << "\n\nThe optimal solution is: ";
    MyFile << optimal[3];
    /*for(int i = 0; i < 4; i++){
        printf("%d ", optimal[i]);
    }*/
    MyFile << "\n\nA: ";
    for(int i = 0; i < 4; i++){
        MyFile << decA[i];
        if(i != 3){
            MyFile << "| ";
        }
    }
    MyFile << "\nB: ";
    for(int i = 0; i < 4; i++){
        MyFile << decB[i];
        if(i != 3){
            MyFile << "| ";
        }
    }
    MyFile << "\n\nThe optimal path is: ";
    for(int i = 0; i < 4; i++){
        MyFile << path[i];
    }
    return 0;
}

//b the table i have + opp
//c the table i have + diff table + opp
//d is everything plus + path