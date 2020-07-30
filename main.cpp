#include<iostream>
#include "polyfit.h"

int main()
{
	try
	{
		/* Beginning of your code*/

		// First define your data in vector<duoble>
		std::vector<double> x_data = { 1,2,3 };
		std::vector<double> y_data = { 0,0,6 };

		// EX1) Getting Least Squared Solution
		Matrix ans = polyfit(x_data, y_data, 1); //polyft() returns the answer in matrix calss(refer matrix.h)
		ans.in_poly(); //For visualization

		// EX2) For Prediction. Say we are looking for the prediction when x=7, 
		double y_hat = polyfit(7, x_data, y_data, 1);
		std::cout << "When x = 7, y is expected to be " << y_hat << "\n";

		/* End of your code*/
		system("pause"); // for a graceful shutdown
	}
	catch(std::invalid_argument& msg)
	{
		std::cout << "Error! " << msg.what() << "\n";
	}
	return 0;
}
