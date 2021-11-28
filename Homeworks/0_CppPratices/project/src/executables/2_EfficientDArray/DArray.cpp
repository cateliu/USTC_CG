// implementation of class DArray
#include "DArray.h"

// default constructor
DArray::DArray() {
	Init();
}

// set an array with default values
DArray::DArray(int nSize, double dValue) {
	//TODO
	m_nSize = nSize;
	m_nMax = 2*m_nSize;
	m_pData = new double[m_nMax];
	for (int i = 0; i < m_nMax; i++)
		m_pData[i] = dValue;
}

DArray::DArray(const DArray& arr) {
	//TODO
	m_nSize = arr.m_nSize;
	m_nMax = arr.m_nMax;
	m_pData = new double [m_nMax];
	for (int i = 0; i < m_nMax ; i++)
		m_pData[i] = arr.m_pData[i];
}

// deconstructor
DArray::~DArray() {
	Free();
}

// display the elements of the array
void DArray::Print() const {
	//TODO
	for (int i = 0; i < m_nSize ; i++){
		cout << i << "th address is:" << m_pData + i << endl;
		cout << i << "th element is:" << m_pData[i] << endl;
	}
	cout << endl;
}

// initilize the array
void DArray::Init() {
	//TODO
	m_pData = NULL;
	m_nSize = 0;
	m_nMax = 0;
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
	if (nSize < m_nSize)
		cout << "Size is smaller than the value of DArray." << endl;
	else
		cout << "The size is normal." << endl;

	double* m_pData_new = new double[2*nSize];
	for (int i = 0; i < 2*nSize ; i++)
		if(i < m_nSize)
			m_pData_new[i] = m_pData[i];
		else
			m_pData_new[i] = 0;

	m_pData = m_pData_new;
	m_nSize = nSize;
}

// get an element at an index
const double& DArray::GetAt(int nIndex) const {
	//TODO
	//static double ERROR; // you should delete this line
	//return ERROR; // you should return a correct value	
	
	static double element;
	if(nIndex <= m_nSize)
		element = m_pData[nIndex];
	else {
		element = NULL;
		cout << "index is out of range"<< endl;
	}
	return element;
}

// set the value of an element 
void DArray::SetAt(int nIndex, double dValue) {
	//TODO
	if(nIndex > m_nSize)
		cout << "Failed to set the value" << endl;
	else
		m_pData[nIndex] = dValue;
}

// overload operator '[]'
double& DArray::operator[](int nIndex) {
	// TODO
	// static double ERROR; // you should delete this line
	// return ERROR; // you should return a correct value
	if(nIndex > m_nSize){
		cout << "index is out of range!" << endl;
		return m_pData[0];
	} else
		return m_pData[nIndex];
}

// overload operator '[]'
const double& DArray::operator[](int nIndex) const {
	//TODO
	static double ERROR; // you should delete this line
	return ERROR; // you should return a correct value
}

// add a new element at the end of the array
void DArray::PushBack(double dValue) {
	//TODO
	m_nSize ++;
	if(m_nSize >= m_nMax)
		
	else if()
}

// delete an element at some index
void DArray::DeleteAt(int nIndex) {
	//TODO
}

// insert a new element at some index
void DArray::InsertAt(int nIndex, double dValue) {
	//TODO
}

// overload operator '='
DArray& DArray::operator = (const DArray& arr) {
	//TODO
	return *this;
}
