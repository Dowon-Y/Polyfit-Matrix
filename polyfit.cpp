#include "polyfit.h"

Matrix polyfit(std::vector<double>& x_data, std::vector<double>& y_data, unsigned int order)
{
	if (y_data.size() != x_data.size())
	{
		throw std::invalid_argument("X_data and Y_data in training set must have the same size");
	}
	Matrix b(y_data.size(), 1);
	b.loadData(y_data);
	std::vector<double> A_temp;
	for (double x : x_data)
	{
		for (unsigned int i = 0; i < order + 1; i++)
		{
			A_temp.push_back(pow(x, order - i));
		}
	}
	Matrix A(x_data.size(), order + 1);
	A.loadData(A_temp);
	Matrix x = ((A.transpose() * A).inverse()) * (A.transpose() * b);

	return x;
}

double polyfit(double predict_x, std::vector<double>& x_data, std::vector<double>& y_data, unsigned int order)
{
	if (y_data.size() != x_data.size())
	{
		throw std::invalid_argument("X_data and Y_data in training set must have the same size");
	}
	Matrix b(y_data.size(), 1);
	b.loadData(y_data);
	std::vector<double> A_temp;
	for (double x : x_data)
	{
		for (unsigned int i = 0; i < order + 1; i++)
		{
			A_temp.push_back(pow(x, order - i));
		}
	}
	Matrix A(x_data.size(), order + 1);
	A.loadData(A_temp);
	Matrix x = ((A.transpose() * A).inverse()) * (A.transpose() * b);

	return x.predict(predict_x);
}
