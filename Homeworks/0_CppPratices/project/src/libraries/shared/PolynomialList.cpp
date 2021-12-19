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
        this->m_Polynomial.push_back(Term(deg[i], cof[i]));
    }
    this->compress();
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
    for (auto it : this->m_Polynomial)
    {
        if (it.deg == i)
        {
            return it.cof;
        }
        return 0.0;
    }
    // you should return a correct value
}

double& PolynomialList::coff(int i) {
    // TODO
    //static double ERROR; // you should delete this line
    double t = this->AddOneTerm(Term(i, 0)).cof;
    this->compress();
    return t; // you should return a correct value
}

void PolynomialList::compress() {
    // TODO
    auto it = this->m_Polynomial.begin();
    while (it != this->m_Polynomial.end())
    {
        if (fabs(it->cof) < 1.0e-10)
        {
            it = this->m_Polynomial.erase(it);
        }
        else
        {
            it++;
        }
    }
}

PolynomialList PolynomialList::operator+(const PolynomialList& right) const {
    // TODO
    PolynomialList Poly(*this);

    for (auto it : right.m_Polynomial)
    {
        Term T1((it).deg, (it).cof);
        Poly.AddOneTerm(T1);
    }
    Poly.compress();
    return Poly; // you should return a correct value
}

PolynomialList PolynomialList::operator-(const PolynomialList& right) const {
    // TODO
    PolynomialList Poly(*this);
    for (auto it : right.m_Polynomial)
    {
        Term T1((it).deg, -(it).cof);
        Poly.AddOneTerm(T1);
    }
    Poly.compress();
    return Poly; // you should return a correct value
}

PolynomialList PolynomialList::operator*(const PolynomialList& right) const {
    // TODO
    PolynomialList Poly;
    for (auto it : this->m_Polynomial)
    {
        for (auto itt : right.m_Polynomial)
        {
            Poly.AddOneTerm(Term(it.deg + itt.deg, it.cof * itt.cof));
        }
    }
    Poly.compress();
    return Poly; // you should return a correct value
}

PolynomialList& PolynomialList::operator=(const PolynomialList& right) {
    // TODO
    this->m_Polynomial = right.m_Polynomial;
    return *this;
}

void PolynomialList::Print() const {
    // TODO
    if (this->m_Polynomial.empty())
    {
        cout << 0 << endl;
        return;
    }
    auto it = this->m_Polynomial.begin();
    if (it->cof >= 0)
    {
        cout << it->cof;
    }
    else
    {
        cout << -it->cof;
    }

    cout << "x^";

    if (it->deg >= 0)
    {
        cout << it->deg;
    }
    else
    {
        cout << -it->deg;
    }
    
    it++;
    for (; it != this->m_Polynomial.end(); it++)
    {
        
        if (it->cof >= 0)
        {
            cout << " + " << it->cof;
        }
        else
        {
            cout << " - " << -it->cof;
        }

        cout << "x^" << it->deg;

    }
    cout << endl;
    //for (auto it = this->m_Polynomial.begin(); it != this->m_Polynomial.end(); it++)
    //{
    //    cout << "第" << (*it).deg << "项数的系数为：" << (*it).cof << endl;
    //}
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

    if (this->m_Polynomial.empty() || term.deg < this->m_Polynomial.back().deg)
    {
        static Term T1(term.deg, term.cof); // you should delete this line
        this->m_Polynomial.push_back(term);
        return T1;
    }
    
    else 
    {
        for (auto it = this->m_Polynomial.begin(); it != this->m_Polynomial.end(); it++)
        {

            if (term.deg == (*it).deg)
            {
                static Term T1(term.deg, term.cof + (*it).cof);
                (*it).cof = (*it).cof + term.cof;
                return T1;
            }
            else if (term.deg > (*it).deg)
            {
                static Term T1(term.deg, term.cof);
                this->m_Polynomial.insert(it, term);
                return T1;
            }
        }
    }
    //return ERROR; // you should return a correct value
}
