/* -----------------------------------------------------------------------------
 * 
 * Created by Ulysses on 10/25/2019
 * 
 * Problem10_09
 * 
 * Write a program that takes two files containing sorted whitespace-seperated
 * words and merges them, preserving order.
 *
 * -----------------------------------------------------------------------------
 */
#include "../std_lib_facilities.h"
void set_bad_exception(fstream &fs);


void set_bad_exception(fstream &fs){
    fs.exceptions(fs.exceptions() | ios_base::badbit);
}


void read_file(fstream &fs, vector<String> &list){
    for (String temp; fs >> temp;){
	    list.push_back(temp);
    }

    // Just in case file is unsorted.
    sort(list.begin(), list.end());
}

void append_to_file(fstream &fs, vector<String> &list){
    int count = list.size();
    for (unsigned int i = 0; i < list.size(); i++, count++){
        if ((count > 0) && !(count % 10))
            fs << list[i] << "\n";
        else
            fs << list[i] << " ";
    }

}

int main(void){
    fstream file01{"../File04.txt"};
    if (!file01) error("File04.txt could not be opened.");
    fstream file02{"../File05.txt"};
    if (!file02) error("File05.txt could not be opened.");

    fstream output {"../File06.txt"};
    if (!output) error("File06.txt could not be opened.");

    set_bad_exception(file01);
    set_bad_exception(file02);
    set_bad_exception(output);

    puts("Writing the contents of File04.txt and File05.txt into File06.txt");
    vector<String> list;
    read_file(file01, list);
    read_file(file02, list);

    append_to_file(output, list);
    puts("Done.");

}
