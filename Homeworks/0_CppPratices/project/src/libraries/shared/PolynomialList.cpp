#include "PolynomialList.h"
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;


PolynomialList::PolynomialList(const PolynomialList& other) {
    // TODO
    this->m_Polynomial = other.m_Polynomial;
}

PolynomialList::PolynomialList(const string& file) {
    // TODO
    if (!ReadFromFile(file))
    {
        cout << " 打开文件错误！" << endl;
        return;
    }
}

PolynomialList::PolynomialList(const double* cof, const int* deg, int n) {
    // TODO
    for (int i = 0; i < n; i++)
    {
        this->m_Polynomial.push_back(Term(*deg, *cof));
    }
}

PolynomialList::PolynomialList(const vector<int>& deg, const vector<double>& cof) {
    // TODO
    for (int i =0; i < deg.size(); i++)
    {
        this->m_Polynomial.push_back(Term(deg[i], cof[i]));
    }
}

double PolynomialList::coff(int i) const {
    // TODO
    return 0.; // you should return a correct value
}

double& PolynomialList::coff(int i) {
    // TODO
    static double ERROR; // you should delete this line
    return ERROR; // you should return a correct value
}

void PolynomialList::compress() {
    // TODO
}

PolynomialList PolynomialList::operator+(const PolynomialList& right) const {
    // TODO
    PolynomialList Poly(*this);
    for (auto it = right.m_Polynomial.begin(); it != right.m_Polynomial.end(); it++)
    {
        Term T1((*it).deg, (*it).cof);
        Poly.AddOneTerm(T1);
    }
    return Poly; // you should return a correct value
}

PolynomialList PolynomialList::operator-(const PolynomialList& right) const {
    // TODO
    PolynomialList Poly(*this);
    for (auto it = right.m_Polynomial.begin(); it != right.m_Polynomial.end(); it++)
    {
        Term T1((*it).deg, -(*it).cof);
        Poly.AddOneTerm(T1);
    }
    return Poly; // you should return a correct value
}

PolynomialList PolynomialList::operator*(const PolynomialList& right) const {
    // TODO
    PolynomialList Poly;
    for (auto it = this->m_Polynomial.begin(); it != this->m_Polynomial.end(); it++)
    {
        for (auto itt = right.m_Polynomial.begin(); itt != right.m_Polynomial.end(); itt++)
        {
            Poly.AddOneTerm(Term((*it).deg + (*itt).deg, (*it).cof * (*itt).cof));
        }
    }
    return Poly; // you should return a correct value
}

PolynomialList& PolynomialList::operator=(const PolynomialList& right) {
    // TODO
    this->m_Polynomial = right.m_Polynomial;
    return *this;
}

void PolynomialList::Print() const {
    // TODO
    for (auto it = this->m_Polynomial.begin(); it != this->m_Polynomial.end(); it++)
    {
        cout << "第" << (*it).deg << "项数的系数为：" << (*it).cof << endl;
    }
    cout << endl;
}

bool PolynomialList::ReadFromFile(const string& file) {
    // TODO
    ifstream InputFile;
    InputFile.open(file, ios::in);
    if (!InputFile)
    {
        return false;
    }
    string fileCheck;
    int PolyCnt;
    InputFile >> fileCheck;
    InputFile >> PolyCnt;

    if (fileCheck != "P")
    {
        cout << "数据文件格式错误";
        return false;
    }
    if (PolyCnt < 0)
    {
        cout << "多项式的项数不能小于0";
        return false;
    }
    int deg;
    double cof;
    for (int i = 0; i < PolyCnt; i++)
    {
        InputFile >> deg;
        InputFile >> cof;

        Term T1(deg, cof);
        AddOneTerm(T1);
    }

    return true; // you should return a correct value
}

PolynomialList::Term& PolynomialList::AddOneTerm(const Term& term) {
    // TODO
    // cout << "deg:" << term.deg << " cof:" << term.cof << endl;
    static Term ERROR; // you should delete this line
    if (this->m_Polynomial.empty())
    {
        this->m_Polynomial.push_back(term);
    }
    else if (term.deg < this->m_Polynomial.back().deg)
    {
        this->m_Polynomial.push_back(term);
    }
    else 
    {
        for (auto it = this->m_Polynomial.begin(); it != this->m_Polynomial.end(); it++)
        {

            if (term.deg == (*it).deg)
            {
                (*it).cof = (*it).cof + term.cof;
                break;
            }
            else if (term.deg > (*it).deg)
            {
                this->m_Polynomial.insert(it, term);
                break;
            }
        }
    }

    return ERROR; // you should return a correct value
}
