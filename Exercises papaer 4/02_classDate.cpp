/* Author: Giovanni Pinna
   Type: esercizio_04.1
   Object: Implement the class Date. Implement the following external helper functions:
                     bool operator==(const Date& lhs, const Date& rhs);
                     bool operator!=(const Date& lhs, const Date& rhs);
                     std::ostream& operator<<(std::ostream& os, const Date& d);
                     bool is_leap(const int y);
   Compiler: gcc
   Language:c++ 11
   Date:19/11/2019
*/

#include <iostream>

class Date {
	public:
		int day;
		int month;
		int year;

															//the enum start form 1 infact january is the first month
		enum  mese { January =1, February=2, March=3, April=4, May=5, June=6, July=7, Augurst=8, September=9, October=10, November=11, December=12 };
		
		Date(){												//empty constructor
		}
		Date (int d,int m, int y){							//memorize the variable
			day = d;
			month = m;
			year = y;
		}		
		
		int Day(){
			return day;
		};
		
		int Month(int mm){
			switch(mese(mm)){
				case January:
					std::cout<<" the month is gennaio " ;
					break;
				case February:
					std::cout<<" the month is February ";
					break;	
				case March:
					std::cout<<" the month is March " ;
					break;
				case April:
					std::cout<<" the month is April " ;
					break;
				case May:
					std::cout<<"the month is May " ;
					break;
				case June:
					std::cout<<"the month is June " ;
					break;
				case July:
					std::cout<<"the month is July " ;
					break;
				case Augurst:
					std::cout<<"the month is Augurst " ;
					break;
				case September:
					std::cout<<"the month is September " ;
					break;
				case October:
					std::cout<<"the month is October " ;
					break;
				case November:
					std::cout<<"the month is November " ;
					break;
				case December:
					std::cout<<"the month is December " ;
					break;
				default:
					std::cout<<"the entered month is incorrect, enter a number between 1 and 12"<<std::endl;
					return 11;												//retur error
					break;
			}
			return month;
		};
		int Year () {
			return year;
		};
		
		int add_Days ( unsigned int n){
			int gg_afinemese = 0;										//calculate the day to the end of the month
			while (n!=0){												//if the user want add some day
				switch (month){
					case 1: case 3: case 5: case 7: case 8: case 10:	//if the month has 31 days
						if (n+day >31){
							gg_afinemese = 31- day;
							n = n - gg_afinemese;
							month ++;
							day =0;
						}
						else {
							day = day+n;
							n=0;
						}
					break;
				
					case 4: case 6: case 9: case 11:					//if the month has 30 days
						if (n+day>30){
							gg_afinemese = 30- day;
							n = n - gg_afinemese;
							month ++;
							day = 0;
						}
						else{
							day = day +n;
							n=0;
						}
					break;
				
					case 2:
						if (n+day>28){									//if the month has 28 days
							gg_afinemese = 28- day;
							n = n - gg_afinemese;
							month ++;
							day = 0;
						}
						else{
							day = day +n;
							n=0;
						}
					break;
				
					case 12:											//if the month is december we have to add one year and come back with the months and days
						if (n+day>31){
							gg_afinemese = 31- day;
							n = n - gg_afinemese;
							month = 1;
							year ++;
							day=0;
						}
						else{
							day = day +n;
							n=0;
						}
					break;
				}
			}			
		}
};


bool operator==(const Date& lhs, const Date& rhs) {
    return (lhs.day == rhs.day && lhs.month == rhs.month && lhs.year == rhs.year);
}

bool operator!=(const Date& lhs, const Date& rhs) {
    return (lhs.day != rhs.day || lhs.month != rhs.month || lhs.year != rhs.year);
}

std::ostream& operator<<(std::ostream& os, const Date& d){
	  os << "you entered the day  "<<d.day << " the month  " << d.month << " and the year  " <<d.year << std::endl;
  return os;
}



bool is_leap(const int year){

		if (!(year%4))
			if (year%100)
				std::cout<<"the year is a leap year";
			else std::cout<<"the year is not a leap year";
		else{	
			if (!(year%400))
				std::cout<<"the year is a leap year";
			else std::cout<<"the year is not a leap year";		
		}
}



int main (){
	int day, month, year;
	Date dat2;
	Date dat;
	dat = Date(1, 1, 2013); //programmer choose the date
	dat2 = Date(1,1,2020);
	//test function
	is_leap(dat.year);
	if (dat == dat2) std::cout<<"equal";			
	if (dat != dat2) std::cout<<"different";			
}

