#define _CRT_SECURE_NO_WARNINGS 1

// ������ظ��ַ������ַ���
class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		string tmp;
		size_t maxLength = 0;// ��¼����ظ��Ӵ�����
		size_t index = 0;
		for (auto& e : s)
		{
			index = tmp.find(e);// ������ڷ����±꣬�����ڷ���-1
			if (-1 != index)// �ַ��Ѿ�����
			{
				maxLength = max(maxLength, tmp.size());// ���������
				tmp.erase(0, index + 1);// ɾ��ǰ�������
			}
			tmp += e;// ���ڻ򲻴��ڣ���Ҫβ�嵱ǰ�ַ�
		}
		return max(maxLength, tmp.size());// ���������Ҫ����һ��
	}
};
