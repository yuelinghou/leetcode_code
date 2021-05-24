#define _CRT_SECURE_NO_WARNINGS 1

// 删除链表中的节点
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
		// 双指针，当前节点和后一个节点
		ListNode* curnode = node;
		ListNode* nextnode = node->next;
		// 把next节点val给cur节点的val，然后一起往后挪
		while (nextnode)
		{
			// 处理最后一个节点的next为空
			if (!nextnode->next)
			{
				curnode->next = NULL;
			}
			curnode->val = nextnode->val;
			curnode = nextnode;
			nextnode = nextnode->next;
		}
		// 删除多出来的节点
		delete curnode;
	}
};

// 实现 strStr()
class Solution {
public:
	int strStr(string haystack, string needle)
	{
		// 处理needle为空的情况
		if (!needle.size())
		{
			return 0;
		}
		// 记录haystack的下标
		int cur = 0;
		// 遍历haystack
		while (cur < haystack.size())
		{
			int src = cur;// haystack当前的下标
			int dest = 0; // needle当前的下标
			while (src < haystack.size() && dest < needle.size() && haystack[src] == needle[dest])
			{
				++src;
				++dest;
			}
			// 如果dest到头了就一定有子串
			if (dest == needle.size())
			{
				return cur;
			}
			// 走到这步的话说明src到头了，dest还没到头，说明子串仅前面的部分在原字符串的末尾部分
			else if (src == haystack.size())
			{
				return -1;
			}
			++cur;
		}
		// 走到这步，源字符串遍历到最后了还是没有找到，子串不存在
		return -1;
	}
};

// 旋转图像
class Solution {
public:
	void rotate(vector<vector<int>>& matrix)
	{
		// 1、上下部分数据交换
		for (int i = 0; i < matrix.size() / 2; ++i)
		{
			for (int j = 0; j < matrix.size(); ++j)
			{
				::swap(matrix[i][j], matrix[matrix.size() - 1 - i][j]);
			}
		}
		// 2、以主对角线为分界，交换两边的数据
		for (int i = 0; i < matrix.size(); ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				::swap(matrix[i][j], matrix[j][i]);
			}
		}
	}
};
