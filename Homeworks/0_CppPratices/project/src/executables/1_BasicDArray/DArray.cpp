// implementation of class DArray
#include "DArray.h"
#include<iostream>
using namespace std;

// default constructor
DArray::DArray() {
	Init();
}

// set an array with default values
DArray::DArray(int nSize, double dValue) {
	//TODO
	m_nSize = nSize;
	m_pData = new double[m_nSize];
	for (int i = 0; i < m_nSize; i++)
		m_pData[i] = dValue;
}

DArray::DArray(const DArray& arr) {
	//TODO
	m_nSize = arr.m_nSize;
	m_pData = new double [m_nSize];
	for (int i = 0 ; i < m_nSize; i ++)
		m_pData[i] = arr.m_pData[i];
}

// deconstructor
DArray::~DArray() {
	Free();
}

// display the elements of the array
void DArray::Print() const {
	//TODO
	for (int i = 0; i < m_nSize; i++) {
		cout << i << "th address is:" << m_pData + i << endl;
		cout << i << "th element is: " << m_pData[i] << endl;
	}
	cout << endl;
}

// initilize the array
void DArray::Init() {
	//TODO
	DArray::m_pData = NULL;
	DArray::m_nSize = 0;
}

// free the array
void DArray::Free() {
	//TODO
	delete [] m_pData;
}

// get the size of the array
int DArray::GetSize() const {
	//TODO
	return m_nSize; // you should return a correct value
}

// set the size of the array
void DArray::SetSize(int nSize) {
	//TODO
	double* m_pData_new = new double[nSize];
	for (int i = 0; i < nSize; i++)
		if (i < m_nSize)
			m_pData_new[i] = m_pData[i];
		else if (i >= m_nSize)
			m_pData_new[i] = 0;
	m_pData = m_pData_new;
	m_nSize = nSize;
}

// get an element at an index
const double& DArray::GetAt(int nIndex) const {
	//TODO
	static double ERROR; // you should delete this line
	return ERROR; // you should return a correct value
}

// set the value of an element 
void DArray::SetAt(int nIndex, double dValue) {
	//TODO
	if(nIndex <= m_nSize)
		m_pData[nIndex] = dValue;
	else
		cout << "Index is out of range!" << endl;
}

// overload operator '[]'
const double& DArray::operator[](int nIndex) const {
	//TODO
	// static double ERROR; // you should delete this line
	// return ERROR; // you should return a correct value
	if (nIndex > m_nSize) {
		cout << "index is out of range!" << endl;
		return m_pData[0];
	} else
		return m_pData[nIndex];

}

// add a new element at the end of the array
void DArray::PushBack(double dValue) {
	//TODO
	m_nSize++;
	double * m_pData_new = new double [m_nSize];
	for (int i = 0; i < m_nSize; i ++)
		if(i < m_nSize - 1)
			m_pData_new[i] = m_pData[i];
		else if(i == m_nSize - 1)
			m_pData_new[i] = dValue;
	m_pData = m_pData_new;
	//m_nSize++;
//	delete [] m_pData_new;
}

// delete an element at some index
void DArray::DeleteAt(int nIndex) {
	//TODO 
	double* m_pData_new = new double [m_nSize - 1];
	for (int i = 0; i < m_nSize - 1; i++)
		if(i < nIndex)
			m_pData_new[i] = m_pData[i];
		else if(i >= nIndex)
			m_pData_new[i] = m_pData[i+1];
	m_pData = m_pData_new;
	m_nSize--;
//	delete [] m_pData_new;
}

// insert a new element at some index
void DArray::InsertAt(int nIndex, double dValue) {
	//TODO
	double* m_pData_new = new double [m_nSize + 1];
	for (int i = 0; i < m_nSize + 1; i ++)
		if(i < nIndex)
			m_pData_new[i] = m_pData[i];
		else if(i == nIndex)
			m_pData_new[i] = dValue;
		else
			m_pData_new[i] = m_pData[i - 1];
	m_pData = m_pData_new;
	m_nSize++;
}

// overload operator '='
DArray& DArray::operator = (const DArray& arr) {
	//TODO
	double* m_pData_new = new double[arr.m_nSize];
	m_nSize = arr.m_nSize;
	for (int i = 0; i < m_nSize; i++)
		m_pData_new[i] = arr.m_pData[i];
	m_pData = m_pData_new;
	return *this;
}
