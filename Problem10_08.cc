/* -----------------------------------------------------------------------------
 *
 * Created by ulysses on 10/25/2019
 * 
 * Problem10_08
 *
 * Write a program that accepts two file names and produces a new file that
 * is the contents of the first file followed by the contents of the second; that
 * is, the program concatenates the two files.
 * -----------------------------------------------------------------------------
 */
#include "../std_lib_facilities.h"

void set_bad_exception(fstream &fs){
    fs.exceptions(fs.exceptions() | ios_base::badbit);
}

void append_to_file(fstream &source, fstream &destination){
    for (string str; source.good();){
        getline(source, str);
        destination << str << endl;
    }

}

int main(void){
    fstream file01, file02;
    file01.open("../File01.txt", ios_base::in);
    if (!file01) error("Could not open File01.txt.");
    file02.open("../File02.txt", ios_base::in);
    if (!file02) error("Could not open File02.txt.");

    set_bad_exception(file01);
    set_bad_exception(file02);

    fstream output;
    output.open("../File03.txt", ios_base::out);
    if (!output) error("Could not open File03.txt.");

    string temp;
    append_to_file(file01, output);
    append_to_file(file02, output);


    file01.close();
    file02.close();
    output.close();
    cout << "File01.txt and File02.txt were appended to File03.txt.\n";

}
