/*  Name: cmatmul.cpp
	Description: Two matrices A and B with dimensions (m*n) and (n*m) respectively.
	Resulting matrix C has dimension (m*m) 
	C(i, j) = SUM(A(i, k), (B(k, j)))
	This C++ program is an object-oriented way of matrix multiplication 
*/
#include<iostream>
#include<sstream>
#include<vector>
#include<fstream>

using namespace std;

class row {
    friend class Matrix;
    public:
    	row(vector<double> d) { r = d; }
 	int size() {return r.size();}
    private:
    	vector<double> r;
};

class Matrix {
    public:
	Matrix(int rows, int columns);
	Matrix multiply(Matrix B);
	void addRow(vector<double> num);
	void printMatrix();
    private:
	vector<row> M;
	int rows;
	int cols;
};

Matrix::Matrix(int rows, int columns) {
	this->rows=rows;
	this->cols=columns;
}

void Matrix::addRow(vector<double> num) {
    M.push_back(row(num));
}

void Matrix::printMatrix() {
    string line, num;
    for(int i = 0; i < rows; i++) {
   	for(int j = 0; j < cols; j++) {
	     cout << M[i].r[j] << " ";
	}
	cout << endl;
    }
    cout << "rows: " << rows << "\ncolumns: " << cols << "\n";
}

//This function multiplies the matrix it belongs to with the matrix in the parameter and returns the resulting matrix.  
Matrix Matrix::multiply(Matrix B) { 
    //C(i, j) = Sum(A(i,k)*B,j)) for all k in (0 .. m-1)
    Matrix C(this->rows, B.cols);

    if(this->cols != B.rows)
    {
	cout << "Incompatible dimensions for matrices!\n";
	cout << "Matrix one has " << this->cols << " columns and matrix two has "
	<< B.rows << " rows.\n";
	return B;
    }
   
    for(int i = 0; i < this->rows; i++)  //i = row of matrix a
    {
	vector<double> cRow;
	for(int j = 0; j < B.cols; j++) //j = column of matrix b
	{
	    double n = 0;
	    for(int k = 0; k < B.rows; k++) //k = row of matrix b
	    	n += this->M[i].r[k] * B.M[k].r[j];
	    cRow.push_back(n);
	}
    	C.addRow(cRow);
    }
    return C;
}

int main() {
    string sRow, RC;
    ifstream afile, bfile;
    istringstream is;
    afile.open("A.txt");
    int rows, columns;
    getline(afile, RC);
    istringstream rc(RC);
    rc >> rows >> columns; //for first line read in as rows then columns
    Matrix A(rows, columns);
    getline(afile, sRow);
    while(afile.good()) //read each line as string until end of file
    {
	istringstream is(sRow); //reinterpret string as a row of numbers
	vector<double> row;
 	double n;
	is >> n;
	while(is)
	{
	    row.push_back(n);
	    is >> n;
	}
	A.addRow(row); //then insert new row
	getline(afile, sRow);
    }
    afile.close();
    cout << "Values of A:\n";
    A.printMatrix();
    bfile.open("B.txt");
    getline(bfile, RC);
    istringstream rc2(RC);
    rc2 >> rows >> columns;
    Matrix B(rows, columns);
    getline(bfile, sRow);
    while(bfile.good()) //repeat for matrix b
    {
	istringstream is(sRow);
	vector<double> row;
	double n;
	is >> n;
	while(is)
	{
	    row.push_back(n);
	    is >> n;
	}
	B.addRow(row);
	getline(bfile, sRow);
    }
    bfile.close();
    cout << "Values of B:\n";
    B.printMatrix(); 
    cout << "Multiplying ... \n";
    Matrix C = A.multiply(B);
    cout << "Values of C:\n";
    C.printMatrix();
}
