/* -----------------------------------------------------------------------------
 * Created by Ulysses on 10/31/2019
 *
 * Problem 10_11
 *
 * Write a program that produces the sum of all the whitespace-seperated 
 * integers in a text file. For example, bears: 17 elephants 9 end should 
 * output 26.
 * -----------------------------------------------------------------------------
 */

#include "../std_lib_facilities.h"
#define SUM_N(x) (((x) * ((x) + 1)) / (2))
int counter = 0;

void set_bad_exceptions(fstream &fs){
    fs.exceptions(fs.exceptions() | ios_base::badbit);

}

void read_to_file(fstream &source, fstream &dest){

    for (String str; source >> str;){
        if (counter > 0 && !(counter % 10))
            dest << str << " " << ++counter << "\n";
        else
            dest << str << " " << ++counter << " ";
    }
    // End file

}

bool string_isdigit(string &temp){
    for (const char &ch : temp)
        if (!isdigit(ch)) return false;

    return true;
}

long int sum_numbers_in_file(fstream &source){
    long int sum = 0;
    // ALWAYS REMEMBER TO SET YOUR POINTERS TO NULL.
    char **pointer = nullptr;
    long int temp;
    for (String str; source >> str;){
        if (str.empty()) break;
        if (string_isdigit(str)){
            //stringstream(str) >> temp; // Alternative
            temp = strtol(str.c_str(), pointer, 10);
            sum += temp;
        }
    }

    return sum;
}

int main(void){
    fstream fs;

    fs.open("../File10.txt", ios_base::out);
    if (!fs) error("Cannot open File10.txt.");
    fstream input {"../File09.txt"};
    if (!input) error("Cannot open File09.txt.");
    // Now populate File10.txt
    set_bad_exceptions(fs);
    set_bad_exceptions(input);

    read_to_file(input, fs);
    fs.close();
    // For detecting errors:
    cout << "Expected Sum: " << SUM_N(counter) << "\n";


    // Now reopen file:
    fs.open("../File10.txt", ios_base::in);
    if (!fs) error("Cannot open File10.txt.");
    cout << "Actual Sum: " << sum_numbers_in_file(fs);
    fs.close();


}
