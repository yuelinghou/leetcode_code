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
		// ӳ��26��Сд��ĸ���±�[0, 25]֮��Ĺ�ϵ
		UnionFindSet ufs(26);
		// 1���Ȱ�����==��ϵ��Ԫ�ؼ��ϵ�һ��
		for (auto& e : equations)
		{
			if (e[1] == '=')
			{
				ufs.Union(e[0] - 'a', e[3] - 'a');
			}
		}
		// 2����֤�����!=��ϵ��Ԫ����һ�������оͷ���false
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
