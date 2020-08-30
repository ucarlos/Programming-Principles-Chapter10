//------------------------------------------------------------------------------
// Created by Ulysses Carlos on 10/20/19 using Ulysses-H270-HD3.
//
// Problem10_01
//
// Write a program that produces the sum of all the numbers in a file of
// whitespace-separated integers.
//------------------------------------------------------------------------------
#include "../std_lib_facilities.h"
void end_of_file(istream &is, char terminator, string message){



}	

void set_bad_exception(ifstream &is){
    is.exceptions(is.exceptions() | ios_base::badbit);
}

long long read_file(istream &is){
    long long sum = 0;
    for (int temp; is >> temp;){
	sum += temp;
    }

    if (!is) return sum;

}	

int main(void){
    string filename = "../Problem10_01_Input.txt";
    ifstream is;
    is.open(filename, ios_base::in);
    if (!is) error("Cannot open file ", filename);
    set_bad_exception(is);
    cout << "Result: " << read_file(is) << endl;
    is.close();

}	
