/* -----------------------------------------------------------------------------
 * Created by ulysses on 10/20/2019
 *
 * Problem 10_03
 *
 * Write a program that reads the data from raw_temps.txt created in 
 * exercise 2 into a vector and then calculates the mean and median 
 * temperatures in your data set. Call this program temp_stats.cpp.
 *
 * -----------------------------------------------------------------------------
 */

#include "../std_lib_facilities.h"

// Read file from raw_temps.txt
// Make sure format is num << reading
// Make sure temperature is plausable:
// And then calculate mean -- sum() / vector.size
// Get vector of temps, find median = if vector.size % 2 == 1, then
// med = vector[vector.size / 2] else med = (vector[vector.size / 2]
#define c_to_f(x) (((x) * 9.0 / 5) + 32)

struct Reading{
    Reading()= default;;
    Reading(int hour, double temp){this->hour = hour, this->temp = temp;}
    int hour;
    double temp;
    char temp_unit;
};

bool is_valid_temp(double temp, double min_temp, double max_temp){
    return (min_temp <= temp && temp <= max_temp);
}

bool is_valid_unit(char temp){
    return temp == 'f' || temp == 'c';
}
void set_bad_exception(istream &is){
    is.exceptions(is.exceptions() | ios_base::badbit);
}

constexpr float to_fahrenheit(double c){
    return (c * 9.0/5) + 32;
};

istream& operator>>(istream &is, Reading &r){
        int hour;
        double temp;
        char unit;
        is >> hour >> temp >> unit;
        if (!is)
            return is;

        if (!is_valid_temp(temp, 0, 150) || !is_valid_unit(unit)){
            is.clear(ios_base::failbit);
            return is;
        }

        r.hour = hour;
        r.temp_unit = unit;
        r.temp = (unit == 'c') ? to_fahrenheit(temp) : temp;

        return is;
}

void read_file(ifstream &is, Vector<Reading> &list){

    for (Reading r; is >> r;){
        list.push_back(r);

    }
    if (!is) return;
}

double get_median(const vector<Reading> &list){
    int med = list.size() / 2;
    bool is_odd = list.size() % 2;

    return (is_odd)? list[med].temp
	: (list[med].temp + list[med + 1].temp) / 2.0;

}

double get_mean(const vector<Reading> &list){
    double sum = 0.0;

    for (const Reading &r : list)
        sum += r.temp;

    return sum / list.size();
}

int main(void){
    string file_name = "../raw_temps.txt";
    ifstream is;
    is.open(file_name, ios_base::in);

    if (!is)
        error(file_name, " could not be opened.\n");
    set_bad_exception(is);

    vector<Reading> list;
    read_file(is, list);
    cout << "Median: " << get_median(list) << "\n";
    cout << "Mean: " << get_mean(list) << "\n";
}
