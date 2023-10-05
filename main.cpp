
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class Date {
 private:
   unsigned month;
   string monthName;
   unsigned day;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
   Date();

   /* parameterized constructor: month number, day, year
      - e.g. (3, 1, 2010) will construct the date March 1st, 2010


      If any of the arguments are invalid (e.g. 15 for month or 32 for day)
      then the constructor will construct instead a valid Date as close
      as possible to the arguments provided - e.g. in above example,
      Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
      In case of such invalid input, the constructor will issue a console error message:


      Invalid date values: Date corrected to 12/31/2010.
      (with a newline at the end).
  */

   Date(unsigned m, unsigned d, unsigned y);




   /* parameterized constructor: month name, day, year
     - e.g. (December, 15, 2012) will construct the date December 15th, 2012


      If the constructor is unable to recognize the string argument as a valid month name,
      then it will issue a console error message:


      Invalid month name: the Date was set to 1/1/2000.
      (with a newline at the end).
      If the day argument is invalid for the given month (but the month name was valid),
      then the constructor will handle this error in the same manner as the other
      parameterized constructor.


      This constructor will recognize both "december" and "December"
      as month name.
  */
  Date(const string &mn, unsigned d, unsigned y);

  /* Outputs to the console (cout) a Date exactly in the format "3/15/2012".
     Does not output a newline at the end.
  */
  void printNumeric() const;

  /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
     The first letter of the month name is upper case, and the month name is
     printed in full - January, not Jan, jan, or january.
     Does not output a newline at the end.
  */
  void printAlpha() const;
  

private:

  /* Returns true if the year passed in is a leap year, otherwise returns false.
  */
  bool isLeap(unsigned y) const;



  /* Returns number of days allowed in a given month
     -  e.g. daysPerMonth(9, 2000) returns 30.
     Calculates February's days for leap and non-leap years,
     thus, the reason year is also a parameter.
  */
  unsigned daysPerMonth(unsigned m, unsigned y) const;




  /* Returns the name of a given month
     - e.g. name(12) returns the string "December"
  */
  string name(unsigned m) const;



  /* Returns the number of a given named month
     - e.g. number("March") returns 3
  */
  unsigned number(const string &mn) const;
};


// Implement the Date member functions here

Date::Date(){
     monthName = "January";
     day = 1;
     month = 1;
     year = 2000;
  }

Date::Date(unsigned m, unsigned d, unsigned y){
    
     int cnt = 0;

     if (m > 12){
        m = 12;
        ++cnt;
     }
     if (m < 1){
        m = 1;
        ++cnt;
     }

     if (d < 1){
        d = 1;
        ++cnt;
     }
     
     unsigned correctNum = daysPerMonth(m,y);

     if (d > correctNum){
        d = correctNum;
        ++cnt;
     }

     if (cnt > 0){
      month = m;
      monthName = name(m);
      day = d;
      year = y;
      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
     }

   month = m;
   monthName = name(m);
   day = d;
   year = y;

  }

  /* parameterized constructor: month name, day, year
     - e.g. (December, 15, 2012) will construct the date December 15th, 2012


      If the constructor is unable to recognize the string argument as a valid month name,
      then it will issue a console error message:


      Invalid month name: the Date was set to 1/1/2000.
      (with a newline at the end).

      If the day argument is invalid for the given month (but the month name was valid),
      then the constructor will handle this error in the same manner as the other
      parameterized constructor.


      This constructor will recognize both "december" and "December"
      as month name.
  */

Date::Date(const string &mn, unsigned d, unsigned y){


       monthName = mn;
       monthName.at(0) = toupper(monthName.at(0));
       month = number(mn);
       day = d;
       year = y;
       
   int monthNum = number(mn);
   
   string correctName = name(monthNum); // lose lose because inputs will be capitalized and not capitalized. rn its capitalized
/*
      cout << monthNum << endl;
      cout << correctName << endl;
      cout << mn << endl;
      */

   
      if (toupper(correctName.at(0)) != toupper(mn.at(0))){
         if (correctName != mn){ // for may and May
      // capital vs non capital and vice versa. I need to be able to compare them regardless of first letter capital or not
      monthName = "January";
      month = 1;
      day = 1;
      year = 2000;
      cout << "Invalid month name: the Date was set to 1/1/2000." << endl;
      }
      }
     
     
     unsigned correctNum = daysPerMonth(monthNum,y);

     if (d > correctNum){
        d = correctNum;
        monthName = mn;
        monthName.at(0) = toupper(monthName.at(0));
        month = number(mn);
        day = d;
        year = y;
        cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
     }
     if (d < 1){
      d = 1;
      monthName = mn;
      monthName.at(0) = toupper(monthName.at(0));
      month = number(mn);
      day = d;
      year = y;
      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
     }
  }

void Date::printNumeric() const{
     cout << month << "/" << day << "/" << year;
  }


void Date::printAlpha() const{
     cout << monthName << " " << day << ", " << year;
  }


bool Date::isLeap(unsigned y) const{
     bool leap = false;
    
     if (y % 4 == 0 && y % 100 != 0){
      leap = true;
     }
     else if (y % 400 == 0){
      leap = true;
     }
     
  return leap;
}


unsigned Date::daysPerMonth(unsigned m, unsigned y) const{
   int num;
   bool leap;

   if (m == 1){
        num = 31;
     }
     else if (m == 2){
      leap = isLeap(y);
       if (leap){
         num = 29;
       }
       else {
         num = 28;
       }
     }
     else if (m == 3){
        num = 31;
     }
     else if (m == 4){
        num = 30;
     }
     else if (m == 5){
        num = 31;
     }
     else if (m == 6){
        num = 30;
     }
     else if (m == 7){
        num = 31;
     }
     else if (m == 8){
        num = 31;
     }
     else if (m == 9){
        num = 30;
     }
     else if (m == 10){
        num = 31;
     }
     else if (m == 11){
        num = 30;
     }
     else if (m == 12){
        num = 31;
     }
   
   return num;
}


string Date::name(unsigned m) const{
    
     string mn;
    
     if (m == 1){
        mn = "January";
     }
     else if (m == 2){
        mn = "February";
     }
     else if (m == 3){
        mn = "March";
     }
     else if (m == 4){
        mn = "April";
     }
     else if (m == 5){
        mn = "May";
     }
     else if (m == 6){
        mn = "June";
     }
     else if (m == 7){
        mn = "July";
     }
     else if (m == 8){
        mn = "August";
     }
     else if (m == 9){
        mn = "September";
     }
     else if (m == 10){
        mn = "October";
     }
     else if (m == 11){
        mn = "November";
     }
     else if (m == 12){
        mn = "December";
     }
     else{
      mn = "zib";
     }
    
     return mn;
  }
 

unsigned Date::number(const string &mn) const{
     int num;

     if (mn == "January" || mn == "january"){
        num = 1;
     }
     else if (mn == "February" || mn == "february"){
        num = 2;
     }
     else if (mn == "March" || mn == "march"){
        num = 3;
     }
     else if (mn == "April" || mn == "april"){
        num = 4;
     }
     else if (mn == "May" || mn == "may"){
        num = 5;
     }
     else if (mn == "June" || mn == "june"){
        num = 6;
     }
     else if (mn == "July" || mn == "july"){
        num = 7;
     }
     else if (mn == "August" || mn == "august"){
        num = 8;
     }
     else if (mn == "September" || mn == "september"){
        num = 9;
     }
     else if (mn == "October" || mn == "october"){
        num = 10;
     }
     else if (mn == "November" || mn == "november"){
        num = 11;
     }
     else if (mn == "December" || mn == "december"){
        num = 12;
     }
     else {
      num = 13;
     }

     return num;
  }






// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}
