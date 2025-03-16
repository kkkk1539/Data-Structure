class Date
{
public:
	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
private:
	int _year;
	int _month;
	int _day;
};
// 以下测试函数能通过编译吗？

int main() {
	Date d1(1, 2, 3);
	Date d2 = d1;
	return 0;
}