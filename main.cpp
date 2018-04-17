/**************************************************************\
*                                                              *
* Name: main.c                                                 *
* Purpose:                                                     *
* This program will accumlate different grades for different   *
* class sections, and will calculate the average for every     *
* section, then calculate the average for the entire course    *
*                                                              *
*                                                              *
****************************************************************
* MODIFICATION HISTORY:                                        *
* 5/1/2017: Andrew Barsoom - created                           *
\**************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

/**************************************************************\
*                                                              *
* Name       : flushKeyBoard()                                 *
* Parameters : none                                            *
* Returns    : none                                            *
* Description:                                                 *
* This module empties the keyboard buffer so that the next     *
* time input is required there is no "old" data still present. *
*                                                              *
****************************************************************
* MODIFICATION HISTORY                                         *
*                                                              *
* 5/1/2017 - Andrew Barsoom - Created                          *
*                                                              *
\**************************************************************/
void flushKeyBoard(void)
{
	int ch;  // A dummy variable to read data into

	while ((ch = getc(stdin)) != EOF && ch != '\n')
		;
}

/**************************************************************\
*                                                              *
* Name       : section()                                       *
* Parameters : none                                            *
* Returns    : the section number by the user                  *
* Description:                                                 *
* This module reads an input value from the user through the   *
* keyboard. It will valdiate that the section code is between  *
* 1-4 and valdiate that its numeric.                           *
****************************************************************
* MODIFICATION HISTORY                                         *
*                                                              *
* 5/1/2017: Andrew Barsoom - created                           *
*                                                              *
\**************************************************************/
int section() {
	int num = 0; //Variable for section input

	//int count = 0;
	bool valid = false;//Boolean to be able to escape out of the while loops
	bool entersec = true; //Boolean to only execture the first printf enter section once

	/* ask the user to enter the section code */
	do {
		while (entersec == true) {
			printf("Enter the section code:"); //Ask for section code
			scanf(" %d", &num);//Input it into num variable
			flushKeyBoard(); //call to flush the input buffer
			entersec = false; //Exit out of the loop
		}
		while ((num < 1 || num > 4) && valid == false ) { // loop If number is NOT within range

			printf("Invalid value entered. Must be 1 to 4, please re-enter: ", num);
			scanf(" %d", &num);
			flushKeyBoard();
			valid = false; //exit out of this lopo
			entersec = false; //set entersec to false so original loop does not get run again for this iteration
		}
		do { //do while to check that number inputter after first invalid input is true, this is the final validation to leave this function, and is created
			 //using a post-loop function as required.
			entersec = true;
			return num;
		} while ((num >= 1 || num <= 4)); //if the numbers are still not in range, loop continues and invalid value entered is printed again.
		return 0;
	} while (1);//run forever
}

/********************************************************************\
*                                                                   *
* Name       : numstud()                                            *
* Parameters : none                                                 *
* Returns    : None - this is a struct                              *
* Description:                                                      *
* This struct was made to be able to return two different variables *
* from the id() function, that being the current total number of    *
* students and the totalgrade average for that section, so it could *
* be calculated later on the total class average                    * 
*********************************************************************
* MODIFICATION HISTORY                                              *
*                                                                   *
* 5/1/2017: Andrew Barsoom - created                                *
*                                                                   *
\********************************************************************/
struct numstud {
	float total;
	float total2;
	float total3;
	float total4;
	float totalGrade;


};

/********************************************************************\
*                                                                   *
* Name       : id()                                                 *
* Parameters : section   - the current class section number         *
* Returns    : returns type of struct numstud                       *
* Description:                                                      *
* This struct was made to be able to return two different variables *
* from the id() function, that being the current section number     *
* and the totalgrade average for that section, so it could be       *
* calculated later on the total class average                       *
*********************************************************************
* MODIFICATION HISTORY                                              *
*                                                                   *
* 5/1/2017: Andrew Barsoom - created                                *
*                                                                   *
\********************************************************************/

numstud ID(int section) {
	int num = 0; //student id number
	float grade; // grade variable
	float total = 0; //total section variable
	//Continue variables to be able to escape out validation for each grade
	int con = 0; 
	int con2 = 0;
	int con3 = 0;
	int con4 = 0;
	//---------------------------------------------------------------------
	// 7 different booleans created to easily exit out of loops
	bool valid = false; 
	bool cont = false;
	bool incorrect = false;
	bool incorr2 = true;
	bool incorr3 = true;
	bool breakout = true;
	bool zerotoquit = false;
	//----------------------------------------------------------------------
	//variables to hold averages for each section from 1-4
	float avgSecOne = 0; 
	float avgSecTwo = 0;
	float avgSecThree = 0;
	float avgSecFour = 0;
	//----------------------------------------------------------------------
	float numStudents = 0;//number of students in total

	//Variables to calculate the total combined grades of each section
	float totalSecOne = 0;
	float totalSecTwo = 0;
	float totalSecThree = 0;
	float totalSecFour = 0;
	//----------------------------------------------------------------------
	//Created 4 different numstud structs to hold each sections info, including total avg, and number of students in each section
	numstud one = {};
	numstud two = {};
	numstud three = {};
	numstud four = {};
	
	while (1) {
		while (zerotoquit == false) {
			printf("Enter the Student's ID: ");

			
			scanf(" %d", &num);
			flushKeyBoard();
			zerotoquit = true;
			breakout = true;
			while (num <= 0 && breakout == true) {//Student ID Validation
				zerotoquit = false;
				incorr3 = false;
				breakout = false;

			}

		}
		int count = 0; // total number of digits in student id
		/* validation */
		int length = 0; //length of the student id
		int i = 0;//Three utility based variables used for counting.
		int d = 0;
		int q = 0;
		int id = num; //variable for the studentid Number

		while (num > 0) {//Determines the number of digits in the inputted number
			num /= 10;
			count++;
		}
		//Pre-test loops to collect 5 scores 
		while (num < 0) {
			incorr3 = false;
		}

		//If the user inputs more than 10 digits, incorrect format
		while (count > 10 && valid == false) {
			printf("Invalid value entered. Must be 0 to 4, please re-enter\n", num);
			flushKeyBoard();
			num = 0;
			valid = true;

		}

		//if the user inputs the correct parameters for student ID
		while (count <= 10 && i < 5) {


			for (i = 0; i < 5; i++) {//loop to Ask for 5 different marks

				while (incorrect == false) {//As long as the previous number is a valid number, print asking for the next one
					int y = i + 1;
					grade = NULL;
					printf("Enter mark# %d: ", y);
					scanf("%g", &grade);
					flushKeyBoard();
					incorrect = true;

				}

				while (incorr2 == false) { //if the user inputs a number out of range, or non-numeric
					printf("Invalid grade entered.Must be 0.0 to 20.0, please re - enter:");
					scanf("%g", &grade);
					flushKeyBoard();
					incorr2 = true;
				}
				cont = false;
				d = 0;//Reset all variables back to 0
				q = 0;
				con = 0;
				con2 = 0;
				con3 = 0;
				con4 = 0;

				//This block of code is the check that the grade inputted is between 0 and 20, if its within range and meets all requirments, it will add the grade
				//to the previous total (in the same section)
				while ((grade >= 0) && con3 == 0) {
					con3++;
					q++;
				}
				while ((grade <= 20) && con4 == 0) {
					con4++;
					q++;
				}
				while (q == 2) {
					total = total + grade;

					cont = true;
					q = 0;
					incorrect = false;

				}
				//----------------------------------------------------------------------------------------------------------

				//This block of code is the check that the grade is out of range, if any number is not within the parameters, it will set incorr2 to false 
				//which will then print out a message saying it is out of range (line 232 )

				while ((grade > 20) && con == 0 && con4 == 0) {
					con++;
					d++;

				}
				while (grade < 0 && con2 == 0) {
					con2++;
					d++;

				}
				while (d == 1) {
					i--;
					d = 0;

					incorr2 = false;

				}
			}
			//----------------------------------------------------------------------------------------------------------


		}
		//----------------------------------------------------------------------------------------------------------
		//After all 5 marks are inputted and validated, this next area is for calculating the total mark per students 
		//----------------------------------------------------------------------------------------------------------
		
		int sum = 9 - count;//The next 4 lines of code is to print the leading zeros to accumlate 9 total digits for student ID
		printf("\n");
		for (i = 0; i < sum; i++) {
			printf("0");
		}

		printf("%d", id);
		printf("'s total mark is: %.4g\n", total);//Printing the total grade per student
		printf("\n");
		
		numStudents++;
		bool sectionEnter = true;
		zerotoquit = false;

		while (zerotoquit == false) {//This section of code is the second prompt for student ID(gives prompt to exit entering student id by simply inputting 0)
			printf("Enter the Student's ID ['0' to quit]: ");
			scanf(" %d", &num);
			flushKeyBoard();//flush input buffer
			i = 0;
			int b;
			//zerotoquit = true;
			breakout = true;
			while (num == 0 && zerotoquit == false) { //if user inputs 0(to quit), exit out of this loop
				zerotoquit = true;
				
			}
			while (num > 0 && breakout == true && zerotoquit == false) {//Student ID Validation
				zerotoquit = true;
				incorr3 = false;
				breakout = false;

			}
		}



		//Post test loop to determine when the user has finished entering Student ID's 

		do {
			totalSecOne = totalSecOne += total; //accumlate all section ones total marks
			sectionEnter = false;
			avgSecOne = totalSecOne / numStudents; //find the average per section
			while (num == 0) {
				printf("The average for the 1 section is %.4g %% \n", avgSecOne); //print out the avg
				printf("\n");
				one.total = numStudents; //retrieve the number of students from the numstud struct
				one.totalGrade = totalSecOne; //retrieve the totalgrade from the numstud struct
				return one; 
			}
		} while (section == 1 && sectionEnter == true);


		do {
			totalSecTwo = totalSecTwo += total;//accumlate all section ones total marks
			sectionEnter = false;
			avgSecTwo = totalSecTwo / numStudents;//find the average per section

			while (num == 0) {
				printf("The average for the 2 section is %.4g %% \n", avgSecTwo);//print out the avg
				printf("\n");
				two.total2 = numStudents;//retrieve the number of students from the numstud struct
				two.totalGrade = totalSecTwo;//retrieve the totalgrade from the numstud struct
				return two;
			}

		} while (section == 2 && sectionEnter == true);

		do {
			totalSecThree = totalSecThree += total;//accumlate all section ones total marks
			sectionEnter = false;
			avgSecThree = totalSecThree / numStudents;//find the average per section

			while (num == 0) {
				printf("The average for the 3 section is %.4g %% \n", avgSecThree);//print out the avg
				printf("\n");
				three.total3 = numStudents;//retrieve the number of students from the numstud struct
				three.totalGrade = totalSecThree;//retrieve the totalgrade from the numstud struct
				return three;
			}

		} while (section == 3 && sectionEnter == true);

		do {
			totalSecFour = totalSecFour += total;
			sectionEnter = false;
			avgSecFour = totalSecFour / numStudents;

			while (num == 0) {
				printf("The average for the 4 section is %.4g %% \n", avgSecFour);//print out the avg
				printf("\n");
				four.total4 = numStudents;//retrieve the number of students from the numstud struct
				four.totalGrade = totalSecFour;//retrieve the totalgrade from the numstud struct
				return four;
			}
		} while (section == 4 && sectionEnter == true);
		total = 0;
	}
	//return 0;
}

/**************************************************************\
*                                                              *
* Name       : section2()                                       *
* Parameters : none                                            *
* Returns    : the section number by the user                  *
* Description:                                                 *
* This module reads an input value from the user through the   *
* keyboard. It will valdiate that the section code is between  *
* 1-4 and valdiate that its numeric.                           *
****************************************************************
* MODIFICATION HISTORY                                         *
*                                                              *
* 5/1/2017: Andrew Barsoom - created                           *
*                                                              *
\**************************************************************/

int section2() {
	int num;//Variable for section input
	int count = 0;
	bool valid = false;//Boolean to be able to escape out of the while loops
	bool entersec = true;//Boolean to only execture the first printf enter section once

 /* ask the user to enter the section code */
	do {
		while (entersec == true) {
			printf("Enter the section code ['0' to quit]: "); //Ask for section code
			scanf(" %d", &num);//Input it into num variable
			flushKeyBoard(); //call to flush the input buffer
			entersec = false; //Exit out of the loop
		}
		count = 0;
		/* validation */
		while (num == 0) { //If user inputs 0, quit function
			return 99;
		}


		while ((num < 1 || num > 4) && valid == false && count == 0) { // loop If number is NOT within range
			printf("Invalid value entered. Must be 1 to 4, please re-enter: ", num);
			scanf("%d", &num);
			flushKeyBoard();
			printf("\n");
			valid = false; //exit out of this lopo
			entersec = false; //set entersec to false so original loop does not get run again for this iteration
			count++;
		}

		do {
			//do while to check that number inputter after first invalid input is true, this is the final validation to leave this function, and is created
			//using a post-loop function as required.
			entersec = true;
			return num;
		} while ((num >= 1 || num <= 4) && count == 0);

	} while (1);
}

/**************************************************************\
*                                                              *
* Name       : maint                                           *
* Parameters : none                                            *
* Returns    : int                                             *
* Description:                                                 *
* Driving function that calls upon other functions             *
****************************************************************
* MODIFICATION HISTORY                                         *
*                                                              *
* 5/1/2017: Andrew Barsoom - created                           *
*                                                              *
\**************************************************************/
int main() {
	int n, a = 0, x = 0; // dummy variables to store all return types from functions
	
	numstud k = {};
	float totalFinal = 0; //integer for total course grade
	//srand(time(NULL));
	float totalstudents = 0; //integer for total students
	/* read n and k */
	n = section(); //Prompt section function
	while (n == 0) {
		section();
	}
	printf("\n");
	while (a != 99 && x != 99) { //As long as the return type doesnt return 99(exit out of the program compeletley), keep prompting for ID then section
		k = ID(n); //Prompt ID Function
		totalFinal = totalFinal + k.totalGrade; // add total grade from current section(k) grade
		totalstudents = totalstudents + k.total + k.total2 + k.total3 + k.total4; // accumlate total grades from ALL four sections
		a = section2(); //prompt section2 Function

	}
	totalFinal = totalFinal / totalstudents; //calculate average
	
	printf("The average for the course is %.2f %%\n", totalFinal); //display the course avg
	 

	return 0;
}
