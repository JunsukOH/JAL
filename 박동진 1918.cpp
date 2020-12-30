#include <stdio.h>
#include <ctype.h>
#include <algorithm>
#include <vector>
using namespace std;
FILE* in = stdin;
FILE* out = stdout;
vector <vector <char>> v;

int isoper(char a)
{
	if (a == '+' || a == '-' || a == '*' || a == '/')
		return 1;
	return 0;
}

void brac_plus(char val1, char val2)
{
	vector<char>st = { '(' };
	vector<char>ed = { ')' };
	for (int i = 0; i < v.size(); i++)
		if (v[i][0] == val1 || v[i][0] == val2)
		{
			int cnt = 0;
			for (int j = i + 1;; j++)
			{
				if (j == v.size())
				{
					v.push_back(ed);
					i++;
					break;
				}
				if (v[j][0] == '(')
					cnt++;
				else if (v[j][0] == ')')
					cnt--;
				if (cnt == 0)
				{
					v.insert(v.begin() + j + 1, ed);
					break;
				}
			}
			for (int j = i - 1;; j--)
			{
				if (j < 0)
				{
					v.insert(v.begin(), st);
					i++;
					break;
				}
				if (v[j][0] == '(')
					cnt--;
				else if (v[j][0] == ')')
					cnt++;
				if (cnt == 0)
				{
					v.insert(v.begin() + j, st);
					i++;
					break;
				}
			}
		}
}
int brac_del()
{
	int f = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i][0] == ')')
		{
			f = 1;
			v.erase(v.begin() + i);
			i--;
			for (int j = i - 1;; j--)
			{
				if (v[j][0] == '(')
				{
					v.erase(v.begin() + j);
					i--;
					break;
				}
				if (!isalpha(v[j][0]))
					v[i].push_back(v[j][0]);
				else
					for (int k = v[j].size() - 1; k >= 0; k--)
						v[i].insert(v[i].begin(), v[j][k]);

				v.erase(v.begin() + j);
				i--;
			}
		}
	}
	return f;
}


int main()
{
	while (1)
	{
		char c;
		if (fscanf(in, "%c", &c) == EOF)
			break;
		vector<char>a;
		a.push_back(c);
		v.push_back(a);
	}
	brac_plus('*', '/');
	brac_plus('+', '-');
	while (brac_del());

	for (int i = 0; i < v.size(); i++)
		for (int j = 0; j < v[i].size(); j++)
			fprintf(out, "%c", v[i][j]);


	return 0;
}