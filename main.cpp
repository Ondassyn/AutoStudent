#include <iostream>
#include "csci152_student.h"
 
int tests_run = 0;
int tests_correct = 0;

void checkBool( const std::string &s, const bool&  given, const bool& correct )
{
   tests_run++;	
   if( given != correct )
   {
      std::cout << "~INCORRECT " << s << " : " << given <<
                   " SHOULD HAVE BEEN " << correct << "\n";
   } else {
      std::cout << "~CORRECT " << s << " : " << given <<
                   " SHOULD HAVE BEEN " << correct << "\n";
      tests_correct++;
   }
}

void checkSizet( const std::string &s, const size_t&  given, const size_t& correct )
{
   tests_run++;	
   if( given != correct )
   {
      std::cout << "~INCORRECT " << s << " : " << given <<
                   " SHOULD HAVE BEEN " << correct << "\n";
   } else {
      std::cout << "~CORRECT " << s << " : " << given <<
                   " SHOULD HAVE BEEN " << correct << "\n";
      tests_correct++;
   }
}

void checkDouble( const std::string &s, const double&  given, const double& correct )
{
   tests_run++;	
   if( abs(given - correct) > 0.1 )
   {
      std::cout << "~INCORRECT " << s << " : " << given <<
                   " SHOULD HAVE BEEN " << correct << "\n";
   } else {
      std::cout << "~CORRECT " << s << " : " << given <<
                   " SHOULD HAVE BEEN " << correct << "\n";
      tests_correct++;
   }
}

void checkString( const std::string s, const std::string&  given, const std::string& correct )
{
   tests_run++;	
   if( given != correct )
   {
      std::cout << "~INCORRECT " << s << " : " << given <<
                   " SHOULD HAVE BEEN " << correct << "\n";
   } else {
      std::cout << "~CORRECT " << s << " : " << given <<
                   " SHOULD HAVE BEEN " << correct << "\n";
      tests_correct++;
   }
}

void print(const csci152_student& student) {
	std::cout << student.get_name() << ": " << student.calculate_course_perc() << std::endl;
}

// This is a minimal testing file.... we will use something more complete
// for grading!!!
int main() {

	std::string message = "ARGUMENT CONSTRUCTOR";

	unsigned int good_asmts[] = {100, 100, 100, 100};
	unsigned int seven_good_quizzes[] = {15, 15, 15, 15, 2, 15, 15};	
	
	unsigned int bad_asmts[] = {0, 35, 2, 10};
	unsigned int six_bad_quizzes[] = {10, 0, 4, 2, 1, 5};

	unsigned int med_asmts[] = {41, 79, 55, 65};
	unsigned int two_med_quizzes[] = {10, 10};

	csci152_student agood("Agood Stutante",
					good_asmts,
					7, seven_good_quizzes,
					100);

	csci152_student abads("Abads Tudant",
					bad_asmts,
					6, six_bad_quizzes,
					35);

	csci152_student ameds("Amedi Ocres-Tudant",
					med_asmts,
					2, two_med_quizzes,
					61);

	//print(agood);  // should print: Agood Stutante: 100
	//print(abads);  // should print: Abads Tudant: 28.0833

	message = "COPY CONSTRUCTOR";
	
	csci152_student acheater = agood;

	message = "GET_NAME";

	checkString(message, agood.get_name(), "Agood Stutante");
	checkString(message, abads.get_name(), "Abads Tudant");
	checkString(message, ameds.get_name(), "Amedi Ocres-Tudant");
	checkString(message, acheater.get_name(), "Agood Stutante");

	message = "GET_FINAL_EXAM_PERC";

	checkDouble(message, agood.get_final_exam_perc(), 100);
	checkDouble(message, abads.get_final_exam_perc(), 35);
	checkDouble(message, ameds.get_final_exam_perc(), 61);
	checkDouble(message, acheater.get_final_exam_perc(), 100);	

	message = "CALCULATE_ASSIGNMENT_PERC";

	checkDouble(message, agood.calculate_assignment_perc(), )	
/*
	seven_good_quizzes[0] = 0;
	seven_good_quizzes[1] = 0;

	print(agood);  // should print: Agood Stutante: 100

	csci152_student abads_clone(abads);

	abads = agood;

	print(abads);        // should print: Agood Stutante: 100
	print(abads_clone);  // should print: Abads Tudant: 28.0833
*/
	std::cout << "\nTESTS RUN: " << tests_run << std::endl;
	std::cout << "\nTESTS CORRECT: " << tests_correct << std::endl;		
	return 0;
}
