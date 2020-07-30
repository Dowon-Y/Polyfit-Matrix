#ifndef MATRIX_H
#define MATRIX_H
#include <iostream> 
#include <vector>
#include <cmath>

class Matrix
{
private:
	unsigned int _row, _col =0;
	double** _data;

public:
	// Constructor, distructor
	Matrix(unsigned int r, unsigned int c);
	~Matrix();
	Matrix(const Matrix& mat);
	void operator= (const Matrix& mat);
	friend bool operator== (const Matrix& mat1, const Matrix& mat2);

	// I/O
	void loadData(const std::vector<double>& vect);
	friend std::ostream& operator << (std::ostream& out, const Matrix& mat);

	// Scalar Operations
	friend Matrix operator* (const Matrix& mat, const double num);
	friend Matrix operator/ (const Matrix& mat, const double num);
	// Matrix Operators
	friend Matrix operator+ (const Matrix& mat1, const Matrix& mat2);
	friend Matrix operator- (const Matrix& mat1, const Matrix& mat2);
	friend Matrix operator* (const Matrix& mat1, const Matrix& mat2);

	// Row Opeartions
	void swap(const int row_i, const int row_j);
	void row_multi(const int row_i, const double num);
	void add_multi(const int row_i, const int row_j, const double num);
	
	//Making identity funcion (existing class should be a square matrix)
	Matrix to_idenrity();
	
	// Matrix Properties
	Matrix transpose();
	Matrix argumented(const Matrix& mat);
	Matrix rref();
	Matrix inverse();
	
	// Methods for Polyfit
	void in_poly();
	double predict(const double& num);
	// TODO: Determinant, Eigen Value, QR algorithm, Strassen algorithm for mult

};


#endif
