#define _CRT_SECURE_NO_WARNINGS 1

// ɾ�������еĽڵ�
* *
* Definition for singly - linked list.
* struct ListNode {
	*int val;
	*ListNode *next;
	*ListNode(int x) : val(x), next(NULL) {}
	*
};
*/
class Solution {
public:
	void deleteNode(ListNode* node)
	{
		// ˫ָ�룬��ǰ�ڵ�ͺ�һ���ڵ�
		ListNode* curnode = node;
		ListNode* nextnode = node->next;
		// ��next�ڵ�val��cur�ڵ��val��Ȼ��һ������Ų
		while (nextnode)
		{
			// �������һ���ڵ��nextΪ��
			if (!nextnode->next)
			{
				curnode->next = NULL;
			}
			curnode->val = nextnode->val;
			curnode = nextnode;
			nextnode = nextnode->next;
		}
		// ɾ��������Ľڵ�
		delete curnode;
	}
};

// ʵ�� strStr()
class Solution {
public:
	int strStr(string haystack, string needle)
	{
		// ����needleΪ�յ����
		if (!needle.size())
		{
			return 0;
		}
		// ��¼haystack���±�
		int cur = 0;
		// ����haystack
		while (cur < haystack.size())
		{
			int src = cur;// haystack��ǰ���±�
			int dest = 0; // needle��ǰ���±�
			while (src < haystack.size() && dest < needle.size() && haystack[src] == needle[dest])
			{
				++src;
				++dest;
			}
			// ���dest��ͷ�˾�һ�����Ӵ�
			if (dest == needle.size())
			{
				return cur;
			}
			// �ߵ��ⲽ�Ļ�˵��src��ͷ�ˣ�dest��û��ͷ��˵���Ӵ���ǰ��Ĳ�����ԭ�ַ�����ĩβ����
			else if (src == haystack.size())
			{
				return -1;
			}
			++cur;
		}
		// �ߵ��ⲽ��Դ�ַ�������������˻���û���ҵ����Ӵ�������
		return -1;
	}
};

// ��תͼ��
class Solution {
public:
	void rotate(vector<vector<int>>& matrix)
	{
		// 1�����²������ݽ���
		for (int i = 0; i < matrix.size() / 2; ++i)
		{
			for (int j = 0; j < matrix.size(); ++j)
			{
				::swap(matrix[i][j], matrix[matrix.size() - 1 - i][j]);
			}
		}
		// 2�������Խ���Ϊ�ֽ磬�������ߵ�����
		for (int i = 0; i < matrix.size(); ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				::swap(matrix[i][j], matrix[j][i]);
			}
		}
	}
};
