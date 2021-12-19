#include "DArray.cpp"

int main()
{
	DArray<int> a;
	for (int i = 0; i < 5; i++)
	{
		cout << "插入" << i << endl;
		a.PushBack(i);
		cout << "数组中的数值为：" << endl;
		a.Print();
		cout << "-------------" << endl;
	}

	DArray<char> c;
	c.InsertAt(5, 's');
	cout << "数组值为：" << endl;
	c.Print();
	for (int i = 0; i < 6; i++)
	{
		char f = 'a';
		cout << "插入" << f + i << endl;
		c.InsertAt(i, i + f);
		 char s = c.GetAt(i);
		cout << "数组中的数值为：" << s <<endl;
		cout << "-------------" << endl;
	}
	for (int i = 0; i < 6; i++)
	{
		cout << endl;
		c.Print();
		cout << "删除第" << 0 << "个元素：" << c.GetAt(0) << endl;
		c.DeleteAt(0);
		c.Print();
		cout << "-------------" << endl;

	}


	return 0;
}