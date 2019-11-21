/* Author: Giovanni Pinna
   Type: esercizio_04.1
   Object: Implement a class Date. This class must meet the following requirements:
                     it has three private attributes to represent day, month and year
                     use a scoped enum for month
                     it has the following public functions:
                     constructor that takes as arguments a day, a month and a year.
                                 day() function that returns the day
                                 month() function that returns the month
                                 year() function that returns the year
                                 add_days(const unsigned int n) which adds n days. You have to take care to increment months and years accordingly.
   Compiler: gcc
   Language:c++ 11
   Date:19/11/2019
*/

#include <iostream>

class Date {
	private:
		int day;
		int month;
		int year;

	public:
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

int main (){
	int day, month, year;
	std::cout<< "insert the day"<<std::endl;
	std::cin>> day;
	std::cout<<"insert the month (number)"<<std::endl;
	std::cin>> month;
	std::cout<<"insert the year " <<std::endl;
	std::cin>> year;
	Date dat;
	dat = Date(day, month, year);


	std::cout<< "the day is: " << dat.Day() << std::endl;
	std::cout << dat.Month(month) << std::endl;
	std::cout<< "the year is: " << dat.Year()  << std::endl;
	int ggadd;
	std:: cout << "how many days you want add? " << ggadd << std::endl; 
	std::cin>> ggadd;
	dat.add_Days(ggadd);
	std::cout<< "the new day is: " << dat.Day() << std::endl;
	std::cout << dat.Month(month) << std::endl;
	std::cout<< "the new year is: " << dat.Year()<< std::endl;
}
