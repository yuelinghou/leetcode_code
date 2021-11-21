#define _CRT_SECURE_NO_WARNINGS 1

// 一周中的第几天 
//class Solution
//{
//private:
//	string getWeek[7] =
//	{ "Sunday",
//	 "Monday",
//	 "Tuesday",
//	 "Wednesday",
//	 "Thursday",
//	 "Friday",
//	 "Saturday" };
//public:
//	string dayOfTheWeek(int day, int month, int year)
//	{
//		// 1、处理好各个参数
//		if (month == 1 || month == 2)
//		{
//			--year;
//			month += 12;
//		}
//		int century = year / 100;
//		year %= 100;
//		// 2、直接把对应参数套进蔡勒公式得到星期
//		int week = year + (year / 4) + (century / 4) - 2 * century + 26 * (month + 1) / 10 + day - 1;
//		week = (week % 7 + 7) % 7;
//		return getWeek[week];
//	}
//};

// 
