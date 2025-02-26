#include <iostream>
#include <cmath>

void brandedmath(double x, double y, double z) {
	std::cout << std::endl << std::endl;
	double rrrsquard = ((pow(x, 2)) + (pow(y, 2)) + (pow(z, 2)));
	double r = sqrt(rrrsquard);
	double theta = atan(y / x);
	double aluber = acos(z / r);
	std::cout << "The point is as follows. Angles are in radians:" << std::endl;
	std::cout << "Spherical Coordinates: (" << r << ", " << theta << ", " << aluber << ")" << std::endl;
	std::cout << "Cartesian Coordinates: (" << x << ", " << y << ", " << z << ")" << std::endl;
}

void circlemath(double r, double theta, double aluber) {
	std::cout << std::endl << std::endl;
	double x = (r * cos(theta) * sin(aluber));
	double y = (r * sin(theta) * sin(aluber));
	double z = (r * cos(aluber));
	std::cout << "The point is as follows. Angles are in radians:" << std::endl;
	std::cout << "Spherical Coordinates: (" << r << ", " << theta << ", " << aluber << ")" << std::endl;
	std::cout << "Cartesian Coordinates: (" << x << ", " << y << ", " << z << ")" << std::endl;
}

void user_defined_values(double &x, double &y, double &z) {
	std::cout << std::endl << std::endl;
	std::cout << "Enter your coordinates, separated by spaces:" << std::endl;
	std::cin >> x;
	std::cin >> y;
	std::cin >> z;
}

void invalidinput(std::string inputerror) {
	using namespace std;
	cout << endl << "You have entered in an invalid " << inputerror << ". Please try again..." << endl;
}

int main()
{
	int useranswer;
	double x;
	double y;
	double z;
	using namespace std;
	cout << "Welcome to Cartesian-Spherical Conversion Program!" << endl << endl;
	bool validateuserinput = true;
	while (validateuserinput) {
		cout << "Do you want to enter your coordinates in:" << endl;
		cout << "(1) Spherical Coordinates" << endl << "(2) Cartesian Coordinates" << endl << endl << "Your answer: ";
		cin >> useranswer;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			invalidinput("character");
		}
		else if (useranswer > 2 || useranswer < 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			invalidinput("number");
		}
		else if (useranswer == 2) {
			validateuserinput = false;
			user_defined_values(x, y, z);
			brandedmath(x, y, z);
		}
		else if (useranswer == 1) {
			validateuserinput = false;
			user_defined_values(x, y, z);
			circlemath(x, y, z);
		}
		else {
			//catch branch
			cerr << "An error has occoured, somehow the end of the if/else statment was reached without fuffiling the condtions of any branch..." << endl << "Program will now close...";
			return 0;
		}
	}
	cout << endl << "Thank you for using the Cartesian-Spherical Conversion Program!" << endl;
	return 0;
}