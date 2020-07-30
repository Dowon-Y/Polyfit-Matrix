#include <stdexcept>
#include "matrix.h"

// Constructor
Matrix::Matrix(unsigned int r, unsigned int c)
{
	_row = r;
	_col = c;
	_data = new double* [_row];
	for (unsigned int i = 0; i < _row; i++)
	{
		_data[i] = new double[_col];
		for (unsigned int j = 0; j < _col; j++)
		{
			_data[i][j] = 0;
		}
	}
}

// Destructor
Matrix::~Matrix()
{
	for (unsigned int i = 0; i < _row; i++)
	{
		delete[]_data[i];
		_data[i] = NULL;
	}
	delete[]_data;
	_data = NULL;
}

// Copy Constructor
Matrix::Matrix(const Matrix& mat)
{
	_row = mat._row;
	_col = mat._col;
	double temp;
	_data = new double* [_row];
	for (unsigned int i = 0; i < _row; i++)
	{
		_data[i] = new double[_col];
		for (unsigned int j = 0; j < _col; j++)
		{
			 ;
			_data[i][j] = mat._data[i][j];
		}
	}
}

void Matrix::operator= (const Matrix& mat)
{
	_row = mat._row;
	_col = mat._col;
	for (unsigned int i = 0; i < _row; i++)
	{
		for (unsigned int j = 0; j < _col; j++)
		{
			_data[i][j] = mat._data[i][j];
		}
	}
}

bool operator== (const Matrix& mat1, const Matrix& mat2)
{
	if (mat1._row != mat2._row || mat1._col != mat2._col)
	{
		throw std::invalid_argument("Can't compare different sizes of matrices");
	}
	else
	{
		for (unsigned int i = 0; i < mat1._row; i++)
		{
			for (unsigned int j = 0; j < mat1._col; j++)
			{
				if (mat1._data[i][j] != mat2._data[i][j])
				{
					return false;
				}
			}
		}
		return true;
	}

}
/*************************************************************
					I/O
**************************************************************/
void Matrix::loadData(const std::vector<double>& vect)
{
	if (vect.size() == (_col * _row))
	{
		for (unsigned int i = 0; i < _row; i++)
		{
			for (unsigned int j = 0; j < _col; j++)
			{
				_data[i][j] = vect[i * _col + j];
			}
		}
	}
	else
	{
		throw std::invalid_argument("Data doesn't fit to the matrix");
	}
}

std::ostream& operator << (std::ostream& out, const Matrix& mat)
{
	for (unsigned int i = 0; i < mat._row; i++)
	{
		for (unsigned int j = 0; j < mat._col; j++)
		{
			out << mat._data[i][j] << "          ";
		}
		out << "\n";
	}
	out << "\n";
	return out;
}
/*************************************************************
				Scalar Operators
**************************************************************/
//Scalar Multilplication
Matrix operator* (const Matrix& mat, const double num)
{
	Matrix temp(mat._row, mat._col);
	for (unsigned int i = 0; i < mat._row; i++)
	{
		for (unsigned int j = 0; j < mat._col; j++)
		{
			temp._data[i][j] *= num;
		}
	}
	return temp;	
}
//Scalar Division
Matrix operator/ (const Matrix& mat, const double num)
{
	if (num == 0)
	{
		throw std::invalid_argument("Division by zero");
	}
	else
	{
		Matrix temp(mat._row, mat._col);
		for (unsigned int i = 0; i < mat._row; i++)
		{
			for (unsigned int j = 0; j < mat._col; j++)
			{
				temp._data[i][j] /= num;
			}
		}
		return temp;
	}
}

/*************************************************************
				Matrix Operators
**************************************************************/
//Matrix Addition
Matrix operator+ (const Matrix& mat1, const Matrix& mat2)
{
	if (mat1._row != mat2._row || mat1._col != mat2._col) 
	{
		throw std::invalid_argument("Can't add two different sizes of matrices");
	}
	else
	{
		Matrix temp(mat1._row, mat1._col);
		for (unsigned int i = 0; i < mat1._row; i++)
		{
			for (unsigned int j = 0; j < mat1._col; j++)
			{
				temp._data[i][j] += (mat1._data[i][j] + mat2._data[i][j]);
			}
		}
		return temp;
	}
	
}
//Matrix Subtraction
Matrix operator- (const Matrix& mat1, const Matrix& mat2)
{
	if (mat1._row != mat2._row || mat1._col != mat2._col)
	{
		throw std::invalid_argument("Can't add two different sizes of matrices");
	}
	else
	{
		Matrix temp(mat1._row, mat1._col);
		for (unsigned int i = 0; i < mat1._row; i++)
		{
			for (unsigned int j = 0; j < mat1._col; j++)
			{
				temp._data[i][j] += (mat1._data[i][j] - mat2._data[i][j]);
			}
		}
		return temp;
	}

}
//Matrix Multiplication
Matrix operator* (const Matrix& mat1, const Matrix& mat2)
{
	if (mat1._col != mat2._row)
	{
		throw std::invalid_argument("Can't add two different sizes of matrices");
	}
	else
	{
		Matrix temp(mat1._row, mat2._col);
		for (unsigned int i = 0; i < mat1._row; i++)
		{
			for (unsigned int k = 0; k < mat2._col; k++)
			{
				for (unsigned int j = 0; j < mat1._col; j++)
				{
					temp._data[i][k] += (mat1._data[i][j] * mat2._data[j][k]);
				}
			}
		}
		return temp;
	}
}
/*************************************************************
					Row Operations
**************************************************************/
void Matrix::swap(const int row_i, const int row_j)
{
	double temp=0;
	for (unsigned int j = 0; j < _col; j++)
	{
		temp = _data[row_i][j];
		_data[row_i][j] = _data[row_j][j];
		_data[row_j][j] = temp;
	}


}
void Matrix::row_multi(const int row_i, const double num)
{
	for (unsigned int j = 0; j < _col; j++)
	{
		_data[row_i][j]*= num;
	}

}
void Matrix::add_multi(const int row_i, const int row_j, const double num)
{
	for (unsigned int j = 0; j < _col; j++)
	{
		_data[row_i][j] += (_data[row_j][j] * num);
	}
	
}

/*************************************************************
					Making Identity
**************************************************************/
Matrix Matrix::to_idenrity()
{
	if(_row != _col)
	{
		throw std::invalid_argument("This is nor a suqare matrix.");
	}
	else
	{
		for (unsigned int i = 0; i < _row; i++)
		{
			for (unsigned int j = 0; j < _col; j++)
			{
				if (i == j) _data[i][j] = 1;
				else _data[i][j] =0;
			}
		}
		return *this;
	}
}
/*************************************************************
					Matrix Properties
**************************************************************/
Matrix Matrix::transpose()
{
	Matrix temp(_col, _row);
	for (unsigned int i = 0; i < _row; i++)
	{
		for (unsigned int j = 0; j < _col; j++)
		{
			temp._data[j][i] = _data[i][j];
		}
	}
	return temp;
}

Matrix Matrix::argumented(const Matrix& mat)
{
	if (_row != mat._row)
	{
		throw std::invalid_argument("Number of rows must be same");
	}
	else
	{
		unsigned new_col = _col + mat._col;
		Matrix temp(_row, new_col);
		for (unsigned int i = 0; i < _row; i++)
		{
			for (unsigned int j = 0; j < new_col; j++)
			{
				if (j < _col)
				{
					temp._data[i][j] = _data[i][j];
				}
				else
				{
					temp._data[i][j] = mat._data[i][j-_col];
				}
			}
		}
		return temp;
	}
}

Matrix Matrix::rref()
{
	Matrix temp = *this;
	unsigned rank = 0;
	while(rank < _row)
	{
		for (unsigned int j = 0; j < _col; j++)
		{
			for (unsigned int i = 0; i < _row; i++)
			{
				if (temp._data[i][j] != 0 && i >= rank) //found a number during column-wise-search
				{
					double d = 1 / temp._data[i][j];
					temp.row_multi(i, d); //making a povit column
					for (unsigned int k = 0; k < _row; k++) // column-wise-searching through all the rows
					{
						if (k != i)
						{
							double m = -1 * temp._data[k][rank];
							temp.add_multi(k, i, m); //eliminating any other numbers 
						}
					}
					temp.swap(i, rank);
					break;
				}
			}
			rank++;  //Done with one column. Moving to the next column
		}
	}
	return temp;
}




Matrix Matrix::inverse()
{
	if (_row != _col)
	{
		throw std::invalid_argument("This is nor a suqare matrix.");
	}
	else
	{
		Matrix I(_row, _row);
		I.to_idenrity();
		Matrix temp = *this;
		Matrix AI = temp.argumented(I);
		AI = AI.rref();

		//checking the front half became identity. 
		for (unsigned int i = 0; i < _row; i++)
		{
			for (unsigned int j = 0; j < _row; j++)
			{
				temp._data[i][j] = AI._data[i][j];
			}
		}

		if (temp == I)
		{
			Matrix inv(_row, _col);
			for (unsigned int i = 0; i < _row; i++)
			{
				for (unsigned int j = 0; j < _row; j++)
				{
					inv._data[i][j] = AI._data[i][j + _row];
				}
			}
			return inv;
		}
		else
		{
			throw std::invalid_argument("The matrix is not invertible");
		}
	}
}

/*************************************************************
					Methods for Polyfit
**************************************************************/
void Matrix::in_poly()
{
	if (_col != 1)
	{
		throw std::invalid_argument("Currently Only supporting one dimensional polynomial regression");
	}
	else
	{
		for (unsigned int i = 0; i < _row; i++)
		{
			std::cout <<"(" << _data[i][0] << ")X^" <<(_row-1-i);
			if (i != _row - 1)
			{
				std::cout << " + ";
			}
		}
		std::cout << "\n";
	}
}
double Matrix::predict(const double& num)
{
	if (_col != 1)
	{
		throw std::invalid_argument("Currently Only supporting one dimensional polynomial regression");
	}
	else
	{
		double y = 0;
		for (unsigned int i = 0; i < _row; i++)
		{
			y += _data[i][0] * pow(num, _row - 1 - i);
		}
		return y;
	}
}
