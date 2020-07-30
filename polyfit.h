#ifndef POLYFIT_H
#define POLYFIT_H

#include "matrix.h"

Matrix polyfit(std::vector<double>& x_data, std::vector<double>& y_data, unsigned int order);
double polyfit(double predict_x, std::vector<double>& x_data, std::vector<double>& y_data, unsigned int order);

#endif