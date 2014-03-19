#pragma once

//游戏时间  1年=12月 * 30 天 * 24小时
class GameTime
{
public:
	int year;
	int month;
	int day;
	int hour;

	void addhours(int hours)
	{
		hour += hours;
		auto deltaDay = hour/24;
		hour = hour % 24;
		adddays(deltaDay);
	}

	void adddays(int days)
	{
		day += days;
		auto deltaMonth = day/30;
		day = day % 24;
		addmonths(deltaMonth);
	}

	void addmonths(int months)
	{
		month += months;
		auto deltayear = month/12;
		month = month % 24;
		year += deltayear;
	}
};
