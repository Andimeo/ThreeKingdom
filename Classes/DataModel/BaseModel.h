#pragma once

//游戏时间  1年=12月 * 30 天 * 24小时
class GameTime
{
public:
	int year;
	int month;
	int day;
	int hour;

	void set_time(int year, int month, int day, int hour) {
		this->year = year;
		this->month = month;
		this->day = day;
		this->hour = hour;
	}

	void addhours(int hours)
	{
		hour += hours;
		auto deltaDay = hour/24;
		hour = hour % 24;
		adddays(deltaDay);
	}

	void adddays(int days)
	{
		long allDays = GameTime::toLong(*this);
		allDays += days;
		GameTime newTime = GameTime::toGameTime(allDays);
		this->year = newTime.year;
		this->month = newTime.month;
		this->day = newTime.day;
	}

	void addmonths(int months)
	{
		long allDays = GameTime::toLong(*this);
		allDays += months * 30;
		GameTime newTime = GameTime::toGameTime(allDays);
		this->year = newTime.year;
		this->month = newTime.month;
		this->day = newTime.day;
	}

	// Return Days From Common era, Every month has 30 days, Every Year has 12 months
	static long toLong(GameTime gameTime){
		long days = gameTime.year * (12 * 30) + (gameTime.month - 1) * 30 + gameTime.day;
		return days;
	}

	static GameTime toGameTime(long days){
		GameTime mDefaultTime;
		mDefaultTime.day = 1;
		mDefaultTime.month = 1;
		mDefaultTime.year = 0;

		if (days <= 0){
			return mDefaultTime;
		}

		mDefaultTime.year = (days - 1) / (12 * 30);

		days %= 12 * 30;
		if (0 == days){
			days = 12 * 30;
		}

		mDefaultTime.month = 1 + (days - 1) / 30;
		mDefaultTime.day = days - 30 * (mDefaultTime.month - 1);
		return mDefaultTime;
	}
};
