#include "DArray.cpp"

int main()
{
	DArray<int> a;
	for (int i = 0; i < 5; i++)
	{
		cout << "����" << i << endl;
		a.PushBack(i);
		cout << "�����е���ֵΪ��" << endl;
		a.Print();
		cout << "-------------" << endl;
	}

	DArray<char> c;
	c.InsertAt(5, 's');
	cout << "����ֵΪ��" << endl;
	c.Print();
	for (int i = 0; i < 6; i++)
	{
		char f = 'a';
		cout << "����" << f + i << endl;
		c.InsertAt(i, i + f);
		 char s = c.GetAt(i);
		cout << "�����е���ֵΪ��" << s <<endl;
		cout << "-------------" << endl;
	}
	for (int i = 0; i < 6; i++)
	{
		cout << endl;
		c.Print();
		cout << "ɾ����" << 0 << "��Ԫ�أ�" << c.GetAt(0) << endl;
		c.DeleteAt(0);
		c.Print();
		cout << "-------------" << endl;

	}


	return 0;
}