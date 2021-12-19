#include "DArray.h"
#include<iostream>
using namespace std;

template<class T1>
DArray<T1>::DArray()
{
	Init();
}

template<class T1>
DArray<T1>::DArray(int nSize, T1 dValue)
{
}
template<class T1>
DArray<T1>::DArray(const DArray<T1>& arr)
{
	m_nSize = arr.m_nSize;
	m_nMax = arr.m_nMax;
	m_pData = new T1[m_nMax];
	for (int i = 0; i < m_nMax; i++)
		m_pData[i] = arr.m_pData[i];
}

template<class T1>
DArray<T1>::~DArray()
{
	Free();
}

template<class T1>
void DArray<T1>::Print() const
{
	for (int i = 0; i < this->m_nSize; i++)
	{
		cout << this->m_pData[i] << endl;
	}
	cout << endl;
}
template<class T1>
void DArray<T1>::SetSize(int nSize)
{
	if (nSize < m_nSize)
	{
		cout << "Size is smaller than the value of DArray." << endl;
		return;
	}
	else
		cout << "The size is normal." << endl;

	Reserve(nSize);
}
template<class T1>
const T1& DArray<T1>::GetAt(int nIndex) const
{
	static T1 element;
	if (nIndex <= this->m_nSize)
		element = this->m_pData[nIndex];
	else
	{
		element = static_cast<T1>(0);
		cout << "index is out of range" << endl;
	}
	return element;
}
template<class T1>
void  DArray<T1>::SetAt(int nIndex, T1 dValue) // set the value of an element
{
	if (nIndex > this->m_nSize)
		cout << "Indexn is out of range" << endl;
	else
		this->m_pData[nIndex] = dValue;
}
template<class T1>
T1& DArray<T1>::operator[](int nIndex) // overload operator '[]'
{
	T1 element = static_cast<T1>(0);
	if (nIndex >= this->m_nSize)
	{
		cout << "Index is out of range!" << endl;
		return element;
	}
	element = this->m_pData[nIndex];

	return element;
}

template<class T1>
const T1& DArray<T1>::operator[](int nIndex) const // overload operator '[]'
{
	static T1 element;
	if (nIndex >= this->m_nSize)
	{
		cout << "Index is out of range!" << endl;
		return;
	}
	element = this->m_pData[nIndex];

	return element;
}

template<class T1>
void DArray<T1>::PushBack(T1 dValue) // add a new element at the end of the array
{
	if ((this->m_nSize + 1) >= this->m_nMax)
		Reserve(this->m_nSize + 1);
	else
		this->m_nSize++;
	this->m_pData[this->m_nSize - 1] = dValue;

}

template<class T1>
void DArray<T1>::DeleteAt(int nIndex) // delete an element at some index
{
	if (nIndex > m_nSize)
	{
		cout << "Index is out of range!" << endl;
		return;
	}
	for (int i = nIndex; i < m_nSize; i++)
	{
		this->m_pData[i] = this->m_pData[i + 1];
	}
	this->m_nSize--;
}

template<class T1>
void DArray<T1>::InsertAt(int nIndex, T1 dValue) // insert a new element at some index
{
	if ((this->m_nSize + 1) >= this->m_nMax)
	{
		Reserve(this->m_nSize + 1);
	}
	else
	{
		this->m_nSize++;
	}

	if (nIndex < 0)
	{
		return;
	}

	if (nIndex < this->m_nMax)
	{
		if (nIndex < this->m_nSize)
		{
			for (int i = this->m_nSize; i >= nIndex; i--)
			{
				if (i == nIndex)
					this->m_pData[i] = dValue;
				else
					this->m_pData[i] = this->m_pData[i - 1];
			}
		}
		else
		{
			for (int i = nIndex; i >= this->m_nSize; i--)
			{
				if (i == nIndex)
					this->m_pData[i] = dValue;
				else
					this->m_pData[i] = static_cast<T1>(0);
			}
			this->m_nSize = nIndex + 1;
		}
	}
	else
	{
		Reserve(nIndex);
		for (int i = nIndex; i >= this->m_nSize; i--)
		{
			if (i == nIndex)
				this->m_pData[i] = dValue;
			else
				this->m_pData[i] = static_cast<T1>(0);
		}
		this->m_nSize++;
	}

}

template<class T1>
DArray<T1>& DArray<T1>::operator = (const DArray& arr) //overload operator '='
{
	delete[] this->m_pData;
	this->m_pData = new T1[arr.m_nSize];
	this->m_nSize = arr.m_nSize;
	this->m_nMax = 2 * this->m_nSize;
	for (int i = 0; i < this->m_nSize; i++)
	{
		m_pData_new[i] = arr.m_pData[i];
	}
	return *this;
}


template<class T1>
void DArray<T1>::Init()
{
	this->m_pData = NULL;
	this->m_nSize = 0;
	this->m_nMax = 0;
}

template<class T1>
void DArray<T1>::Free()
{
	delete[] m_pData;
}

// allocate enough memory
template<class T1>
void DArray<T1>::Reserve(int nSize)
{
	this->m_nMax = 2 * nSize;
	T1* m_pData_new = new T1[this->m_nMax];
	if (m_nSize == 0)
	{
		for (int i = 0; i < nSize; i++)
			m_pData_new[i] = static_cast<T1>(0);
	}
	else
	{
		for (int i = 0; i < this->m_nSize; i++)
		{
			m_pData_new[i] = m_pData[i];
		}
	}
	this->m_nSize = nSize;
	delete[] m_pData;
	m_pData = m_pData_new;
}