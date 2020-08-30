/* ---------------------------------------------------------------------------
 * Created by ulysses on 10/22/2019
 *
 * Problem 10_06
 * Define a Roman_int class for holding Roman numerals (as int s) with a
 * << and >> . Provide Roman_int with an as_int() member that returns the
 * int value, so that if r is a Roman_int , we can write cout << "Roman"
 * << r << " equals " << r.as_int() << '\n'; .
 *
 * ---------------------------------------------------------------------------
 */

#include "../std_lib_facilities.h"

// Global Variables:
// Going on the assuming that any roman number such as ix, xl, dc
int check_numerical_list(char temp);
bool is_valid_roman(char temp);
void to_lower_string(string &temp);
bool is_valid_string(string &temp);
bool has_higher_precedence(char ch1, char ch2);
int romanchar_to_int(char temp);
long int roman_to_int(string temp);

string numerical_list = "ivxlcdm";
char invalid_char = '\a';

class Roman_Integer{
public:
    Roman_Integer()= default;
    Roman_Integer(string str, long int val);
    string repres;
    long int value;
};

istream& operator>>(istream &is, Roman_Integer &r);

Roman_Integer::Roman_Integer(string str, long int val){
    this->repres = str; this->value = value;

}

int roman_table[] = {1, 5, 10, 50, 100, 500, 1000};

int set_precedence(char temp){
    int num = check_numerical_list(temp);

    if (num == -1) {
        string str = "";
        str += temp;
        error(str, " is not a valid roman numeral.");
    }

    return roman_table[num];

}

int check_numerical_list(char temp){
    for (int i = 0; i < numerical_list.length(); i++){
        if (numerical_list[i] == temp) return i;
    }

    return -1; // Not found.
}

bool has_higher_precedence(char ch1, char ch2){
    int test1 = set_precedence(ch1);
    int test2 = set_precedence(ch2);

    return test1 >= test2;

}

int romanchar_to_int(char temp){
    vector<int> table = {1, 5, 10, 50, 100, 500, 1000};
    int index = check_numerical_list(temp);
    if (index == -1){
        string str1 = "";
        str1 += temp;
        error("Cannot convert \"" + str1 + "\" to int.");
    }

    return table[index];

}
long int roman_to_int(string temp){
    long int sum = 0;
    char ch1 = invalid_char;
    int num1;
    bool test;

    for (int i = 0; i < temp.length(); i++){
        num1 = romanchar_to_int(temp[i]);

        if (ch1 != invalid_char){
            test = has_higher_precedence(ch1, temp[i]);
            if (!test){
                // First, it removes the last char's value, and then adds
                // the new char's value minus the old char's value.
                num1 = num1 - 2 * romanchar_to_int(ch1);
            }
        }
        sum = sum + num1;
        ch1 = temp[i];
    }
    return sum;

}

istream& operator>>(istream &is, Roman_Integer &r){
    string temp;
    is >> temp;
    if (!is_valid_string(temp)){
        is.clear(ios_base::failbit);
        return is;
    }
    // If any other issues arise, kill it.
    if (!is) return is;
    r.repres = temp;
    r.value = roman_to_int(temp);

    return is;
}

void to_lower_string(string &temp){
    for (char & i : temp)
        i = tolower(i);
}

bool is_valid_string(string &temp){
    to_lower_string(temp);

    for (const char ch : temp)
        if (!is_valid_roman(ch))
            return false;
        return true;
}

bool is_valid_roman(char temp){
    for (const char ch : numerical_list)
        if (ch == temp) return true;
    return false;
}



int main(void){
    Roman_Integer r;
    cin >> r;
    cout << "Roman Numeral " << r.repres << " is the same as " << r.value << "\n";

}    
