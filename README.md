# Polyfit-Matrix

## Table of contents
* [General info](#general_info)
* [Examples of use](#examples_of_use)
* [Project status](#project_status)

<a name="general_info"/>

## General info
- Inspired by Numpy library in python and Eigen library in c++, we developed our own version of the polyfit and the matrix library for fun. Using least squares method and dynamic memory allocation, our simple c++ project supports matrix operations and one-dimensional polynomial regression.
- Periods of development: 6/2 ~6/5
- NOTE: Sparse matrix representation and Strassen algorithm are not implemented in this project

Written by Dowon Yang, Tianrong Wang 

<a name="examples_of_use"/>

## Examples of use
Write your code in main.cpp
* Polyfit
```C++
	//First define your data in vector<duoble>
	std::vector<double> x_data = { 1,2,3 };
	std::vector<double> y_data = { 0,0,6 };

	//Least Squared Solution: polyfit(x_data, y_data, order)
	Matrix ans = polyfit(x_data, y_data, 1); //polyft() returns the answer in matrix calss(refer matrix.h)
	ans.in_poly(); //For visualization
      	//OUTPUT: (3)X^1 + (-4)X^0

	//Prediction: polyfit(x_be_predicted, x_data, y_data, order);
	double y_hat = polyfit(7, x_data, y_data, 1);
	std::cout << "When x = 7, y is expected to be " << y_hat << "\n";
     	//OUTPUT: When x = 7, y is expected to be 17
```
* Matrix
```C++
	//Creating new matrix: initialized to a zero matrix
	Matrix A(3,3);
	std::cout << A;
	
	// Define content of the matrix you created
	std::vector<double> x = { 1,2,3,4,5,6,7,5,2 };
	A.loadData(x);
	std::cout << A;

	// Identity Matrix: Create a matrix then use identity method
	Matrix I3(3,3);
	I3.to_identity();
	std::cout << I3;
    
	// Inverse Matrix 
	Matrix A_inv = A.inverse(); //A from the example above
	std::cout << A_inv;
    
	// Transpose
	Matrix A_trn = A.transpose(); //A from the example above
	std::cout << A_trn;

	// RREF 
	Matrix A_rref = A.rref();
	std::cout << A_rref;
	
	// Matrix: +, -, * 
	// Scalar:  *,/
	// Boolean : ==
```

<a name="project_status"/>

## Project status
* TODO: Determinant, Eigen Value, QR algorithm, Strassen algorithm for mult
