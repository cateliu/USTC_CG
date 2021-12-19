#pragma once

template<class T1>
class DArray
{
	T1* m_pData;				//	the pointer to the array memory
	int m_nSize;				// the size of the array
	int m_nMax;					// double the m_nSize
	void Init();				// initial the array
	void Free();				// free the array
	void Reserve(int nSize);	// allocate enough memory
public:
	DArray();					// default constructor
	DArray(int nSize, T1 dValue);	
	DArray(const DArray& arr);	// copy constructor
	~DArray();

	void Print() const;
	void SetSize(int nSize);

	const T1& GetAt(int nIndex) const;
	void SetAt(int nIndex, T1 dValue); // set the value of an element
	
	T1& operator[](int nIndex); // overload operator '[]'
	const T1& operator[](int nIndex) const; // overload operator '[]'

	void PushBack(T1 dValue); // add a new element at the end of the array
	void DeleteAt(int nIndex); // delete an element at some index
	void InsertAt(int nIndex, T1 dValue); // insert a new element at some index

	DArray& operator = (const DArray& arr); //overload operator '='

};

