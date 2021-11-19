#define _CRT_SECURE_NO_WARNINGS 1

class UnionFindSet
{
public:
	UnionFindSet(int n)
	{
		_ufs.resize(n, -1);
	}

	int FindRoot(int index)
	{
		while (_ufs[index] >= 0)
		{
			index = _ufs[index];
		}
		return index;
	}

	void Union(int x1, int x2)
	{
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);
		if (root1 != root2)
		{
			_ufs[root1] += _ufs[root2];
			_ufs[root2] = root1;
		}
	}

	int GetSet()
	{
		int count = 0;
		for (auto e : _ufs)
		{
			if (e < 0)
			{
				++count;
			}
		}
		return count;
	}
private:
	vector<int> _ufs;
};

class Solution {
public:
	bool equationsPossible(vector<string>& equations)
	{
		// 映射26个小写字母和下标[0, 25]之间的关系
		UnionFindSet ufs(26);
		// 1、先把所有==关系的元素集合到一起
		for (auto& e : equations)
		{
			if (e[1] == '=')
			{
				ufs.Union(e[0] - 'a', e[3] - 'a');
			}
		}
		// 2、反证：如果!=关系的元素在一个集合中就返回false
		for (auto& e : equations)
		{
			if (e[1] == '!' && (ufs.FindRoot(e[0] - 'a') == ufs.FindRoot(e[3] - 'a')))
			{
				return false;
			}
		}
		return true;
	}
};
