#include "../std_lib_facilities.h"


struct Point{
	Point()= default;;
	Point(double x, double y);
	double x{0.0};
	double y{0.0};
};

Point::Point(double x, double y){
	this->x = x;
	this->y = y;

}

istream& operator>>(istream &is, Point &p){
	double x, y;
	char ch1, ch2, ch3;
	
	if ((is >> ch1) && (ch1 != '(')){
		is.unget();
		is.clear(ios::failbit);
		return is;
	}

	is >> x >> ch2 >> y >> ch3;
	if (!is) return is;

	if (ch2 != ',' || ch3!= ')'){
		is.clear(ios::failbit);
		return is;
	}

	p = Point{x, y};
	return is;
}

ostream& operator<<(ostream &os, Point &p){
	return os << "("
		  << p.x << ","
		  << p.y << ")"
		  << "\n";

}
void store_points(vector<Point> &list, int max_input){
	if (max_input < 0) return;

	Point p{};
	for (int i = 0; i < max_input; i++){
		cin >> p;
		list.push_back(p);
		p = Point{};
	}

}

void print_points(ostream &os, vector<Point> &list){
	for (Point &p : list)
		os << p;

}

void set_bad_exception(ifstream &is){
	is.exceptions(is.exceptions()|ios_base::badbit);
}



void read_file(ifstream &is, vector<Point> &list){
	//Assume that input is (x, y)
	for (Point p; is >> p;){
		list.push_back(p);
	}

	if (is.eof()) return;
	// Abort any failbit.
	cout << "Apparently, a failure occurred somewhere.";

}

void test_input(void){
	ifstream is;
	set_bad_exception(is);

	vector<Point> list;
	is.open("../Chapter10_IO.txt", ios_base::in);
	if (!is) error("Error: Cannot open input file. Exiting.");

	read_file(is, list);
	print_points(cout, list);
	is.close();
	


}


void test_output(void){
	int max_input = 7;
	vector<Point> list;

	printf("Please enter %d points (x, y) :\n", max_input);
	store_points(list, max_input);

	ofstream os;
	os.open("../Chapter10_IO.txt", ios_base::out);
	if (!os) error("Cannot create output file. Exiting.");
	print_points(os, list);
	os.close();


}

int main(void){
	test_output();
	test_input();
	return 0;
}
