/* -----------------------------------------------------------------------------
 *     
 * Created by Ulysses on 10/20/2019
 * 
 * Problem 10_02
 * Write a program that creates a file of data in the form of the temperature
 * Reading type defined in §10.5. For testing, fill the file with at least 50
 * “temperature readings.” Call this program store_temps.cpp and the file it
 * creates raw_temps.txt.
 *
 * -----------------------------------------------------------------------------
 */

#include "../std_lib_facilities.h"
#include <ctime>
#include <cstdlib>

#define MIN_TEMPERATURE (30)
#define MAX_TEMPERATURE (90)

struct Reading{
    int hour;
    double temperature;
    char temp_unit;
};

void set_bad_expection(ostream &os){
    os.exceptions(os.exceptions() | ios_base::badbit);
}

void write_to_file(ostream &os, int line_num){
    double d;
    int temp;
    int temp2;
    char table[] = {'c', 'f'};
    // Write random numbers as temperatures:
    for (int i = 0; i < line_num; i++){
        // Now randomize b/w d and f:
        temp2 = (rand() % 2);

        temp = (rand() % (MAX_TEMPERATURE - MIN_TEMPERATURE));

        // Create centigrade values from being too high
        temp = (table[temp2] == 'c')? (rand() % (MAX_TEMPERATURE / 2) - (MIN_TEMPERATURE / 2)) + (MIN_TEMPERATURE / 3)
                : ((rand() % MAX_TEMPERATURE - MIN_TEMPERATURE) + MIN_TEMPERATURE);

        d = 1.04 * temp;

        // i % 24 in order to keep hour b/w [0, 23]
        os << (i % 24) << " " << d << " " << table[temp2] << "\n";
    }

    if (!os)
        return;
}


int main(void){
    // C-Style random num
    srand(time(nullptr));
    string file_name = "../raw_temps.txt";
    ofstream os {file_name};
    if (!os) error(file_name, " could not be found.");
    set_bad_expection(os);
    int entries = 50;
    write_to_file(os, entries);
    cout << "Reading entries have been written to " << file_name << "\n";

}
