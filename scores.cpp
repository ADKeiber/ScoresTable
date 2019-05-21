/*
  File: scores.cpp
  Created by: Austin Keiber
  Creation Date: 11/25/2017
  Synopsis: ??
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// FUNCTION PROTOTYPES GO HERE:

int num_students(string x);

void read_exams(string string, int scores1[], int scores2[], int scores3[], int students);

void sum_arrays(int scores1[],int scores2[],int scores3[],int totals[],int students);
	
double avg_scores(int totals[], int students);
	
int find_min(int totals[], int students);

int find_max(int totals[], int students);

int find_above( int totals[], int students, int avg);

void tabel(int scores1[],int scores2[],int scores3[],int totals[],int students,const double avg,const int min,const int max,const int above);

void top_table(char line, string A, string B, string C, string D, string E); 

void data_table(int scores1[], int scores2[], int scores3[], int totals[], int students, int avg);

void end_table(int students,double avg, int max, int min, int above);

int main()
{
	int * scores1;
	int * scores2;
	int * scores3;
	int * totals;
	int students(0);
	double avg(0.0);
	int min, max, above;
	
	// Prompt for the number of students
	
	students = num_students("Enter number of students: ");
	
	// Allocate arrays to hold exam scores and totals
	
	scores1 = new int[students];
	scores2 = new int[students];	
	scores3 = new int[students];
	totals = new int[students];

		
	// Prompt and read exams for each student

	read_exams("Enter the three exam scores for students #", scores1, scores2, scores3, students);

	
	// Compute exam totals for each student

	sum_arrays(scores1, scores2, scores3, totals, students);


	// Compute the average of the total scores
	
	avg = avg_scores(totals, students);


	// Find the minimum total score

	min = find_min(totals, students);


	// Find the maximum total score

	max = find_max(totals,students);

	
	// Compute the number of students with total scores at or average of the total scores

	above = find_above(totals,students,avg);


	// Display table
	tabel(scores1, scores2, scores3, totals, students, avg, min, max, above);
	
	// De-allocate arrays

	return 0;
}
		 
// FUNCTION DEFINITIONS GO HERE:


int num_students(string x)
{
	int students = 0;
	
	cout << x;
	cin >> students;

	while( students < 0 ){
		cout << "Sorry, you must enter a positive value." << endl;
		cin >> students;
	}

	return (students);
		
}


void read_exams(string string,int scores1[], int scores2[], int scores3[], int students)
{ 	
	int i = 0;
	int k = 1;
	int x = 0;
	int arrayNum1 = 0;
	int arrayNum2 = 0;
	int arrayNum3 = 0;

	for( k = 1; k <= students; k++){
		cout << string << k << ": ";
		for( i = 0; i < 3; i++) {
			cin >> x;
			if( i == 0){
				scores1[arrayNum1] = x; 
				arrayNum1++;}		
			if( i == 1){
				scores2[arrayNum2] = x; 
				arrayNum2++;}
			if( i == 2){
				scores3[arrayNum3] = x;
				arrayNum3++;}


		}  
	}
}


void sum_arrays(int scores1[],int scores2[],int scores3[],int totals[],int students)
{
	int i = 0;
	int k = 1;
	int sum = 0;

	for( i = 0;  i < students; i++){
		for( k = 0; k < 3; k++){
			if (k == 0){
				sum = sum + scores1[i];
			}
			if(k == 1){
				sum = sum + scores2[i];
			}
			if(k == 2) {
				sum = sum + scores3[i];
			}
		}	
	
		totals[i] = sum;
		sum = 0;
	}
	

}


double avg_scores(int totals[], int students)
{
	int i = 0;
	int sum = 0;
	int avg = 0;
	
	for(i = 0; i < students; i++){
		sum = sum + totals[i];
	}	

	avg = sum / students;
	
	return(avg);
}

int find_min(int totals[], int students)
{

	int i = 0;
	int min = 100;

	for( i = 0; i < students; i++ ){
		if ( totals[i] <= min){
			min = totals[i];
		}
	}	
	
	return(min);
}


int find_max(int totals[], int students)
{
	int i = 0;
	int max = 0;
	
	for(i = 0; i < students; i++){
		if( totals[i] >= max){
			max = totals[i];
		}
	}
	
	return(max);
}


int find_above( int totals[], int students, int avg)
{
	int i = 0;
	int above = 0;

	for( i = 0; i < students; i++){
		if(totals[i] >= avg){
			above++;
		}
	} 

}


void tabel(int scores1[],int scores2[],int scores3[],int totals[],int students,const double avg,const int min,const int max,const int above)
{
	char line = '-';
	top_table(line, "Student","Score 1" , "Score 2", "Score 3", "Total");
	data_table( scores1, scores2, scores3, totals, students, avg);
	end_table(students, avg, max, min, above);

}

void top_table(char line, string A, string B, string C, string D, string E) 
{
	int i = 0;
	
	for(i = 0; i < 48; i++){
		cout << line;
	}
	cout << endl;
	
	cout <<  A << "   " << B << "   " << C << "   " << D << "   " << E << "   " << endl;

		 i = 0;
	
	for(i = 0; i < 48; i++){
		cout << line;
	}	
	
	cout << endl;
	
}


void data_table(int scores1[], int scores2[], int scores3[], int totals[], int students, int avg)
{
	int i = 0;
	int studentNum = 1;

	for(i = 0; i < students; i++){
		cout << "     " << studentNum << "  " << scores1[i] << "        " << scores2[i] << "        " << scores3[i] << "        " << totals[i];
		if ( totals[i] > avg){
			cout << "     +";
		}
		if ( totals[i] == avg){
			cout << "     =";
		}
		if( totals[i] < avg){
			cout << "     -";
		}
		cout << endl;
	}
	
	
}


void end_table(int students,double avg, int max, int min, int above)
{

	char line = '-';
	int i = 0;
	
	for(i = 0; i < 48; i++){
		cout << line;
	}
	
	cout << endl;

	cout << "The number of students is:              " << students << endl;
	cout << "The avg total scores(rounded) is:       " << avg << endl;
	cout << "The maximum total score is:             " << max << endl;
	cout << "The minimum total score is:             " << min << endl;
	cout << "Total scores at or above the avg is:    " << above << endl;
	
	i = 0;
	for(i = 0; i < 48; i++){
		cout << line;
	}
	
	cout << endl;	
	

} 
