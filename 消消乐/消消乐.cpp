#include <iostream>

using namespace std;

int maxfind(const int numbers[], int len)
{
	int nummax = 0;
	for (int i = 0; i < len; i++)
	{
		if (numbers[i]>nummax)
		{
			nummax = numbers[i];
		}
	}
	return nummax;
}
void initia(int numbers[], int len)
{
	for (int i = 0; i < len; i++)
	{
		numbers[i] = 0;
	}
}
void initia2(int numbers[], int len)
{
	for (int i = 0; i < len; i++)
	{
		numbers[i] = len;
	}
}

void minfind(int **minnum, const int i,const int numbers[],const int len)
{
	minnum[i][0] = 0;
	minnum[i][1] = numbers[0];
	for (int j = len-1; j >= 0; j--)
	{
		if (numbers[j] < minnum[i][1])
		{
			minnum[i][1] = numbers[j];
			minnum[i][0] = j ;

		}
	}
}

int main()
{
	int T, n=0;
	cin >> T;
	int **minact = new int* [T];//二维数组，行数为轮数，列为每轮结果，包括选择数和操作数
	for (int cnt = 0; cnt < T; cnt++)
	{
		minact[cnt] = new int[2];
	}
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		int* block = new int[n];
		for (int j = 0; j < n; j++)
		{
			cin >> block[j];//输入块的编号
		}
		int nummax = maxfind(block, n);//找到编号最大值
		int** numberlocation = new int* [nummax];//设立二维数组，行数为从1到n的所有数（用0到n-1表示），列数组为位置编号（从0 开始计）
		for (int k = 0; k < nummax; k++)
		{
			numberlocation[k] = new int[n];
			initia(numberlocation[k], n);//初始化
			int cnt = 0;//第一次出现在二维数组numberlocation相应行的第0位
			for (int i2 = 0; i2 < n; i2++)
			{
				if (block[i2]==k+1)
				{
					numberlocation[k][cnt] = i2+1;
					cnt++;
				}
			}
		}
		int* numact = new int[nummax];
		initia2(numact,nummax);
		for (int j2 = 0; j2 < nummax; j2++)
		{
			if (numberlocation[j2][0]==0)
			{
				continue;
			}
			else
			{
				numact[j2] = 0;
			}
			for (int k2 = 0; k2 < n; k2++)
			{
				if (!k2)//判断是否为第一个
				{
					if (numberlocation[j2][k2]-1)
					{
						numact[j2]++;
					}
				}
				else
				{
					if (numberlocation[j2][k2])
					{
						if (numberlocation[j2][k2]-numberlocation[j2][k2-1]-1)
						{
							numact[j2]++;
						}
					}
					else//不是第一个为0，说明遍历完毕
					{
						if ((numberlocation[j2][k2-1]-1)!=nummax)
						{
							numact[j2]++;
						}
						break;
					}
				}
			}
		}
		minfind(minact,i, numact, nummax);
		delete []block;
		delete []numberlocation;
		delete []numact;
	}
	for (int cnt2 = 0; cnt2 < T; cnt2++)
	{
		cout << minact[cnt2][0]+1 << " " << minact[cnt2][1]<< endl;
	}
	delete[]minact;
	return 0;
}