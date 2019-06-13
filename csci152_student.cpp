#include "csci152_student.h"

/*
 * Standard argument constructor -- you must copy the arrays!
 *
 * Do not worry about illegal inputs for this assignment - you do not need
 * to throw an exception, or even try to handle them
 */
static unsigned int NUM_OF_ASMTS = 4;

csci152_student::csci152_student(
		std::string nm,
		unsigned int *asmts,
		unsigned int num_qs,
		unsigned int *quizzes,
		unsigned int final_exam
):name(nm), num_of_quizzes(num_qs), final_exam_score(final_exam)
{
	assignment_scores = new unsigned int[NUM_OF_ASMTS];
	for(size_t i = 0; i < NUM_OF_ASMTS; i++) assignment_scores[i] = asmts[i];
	//delete [] asmts;
	quiz_scores = new unsigned int[num_qs];
	for(size_t i = 0; i < num_qs; i++) quiz_scores[i] = quizzes[i];
	//delete [] quizzes; 
}

/*
 * Copy constructor
 */
csci152_student::csci152_student(const csci152_student& other)
:name(other.name), num_of_quizzes(other.num_of_quizzes),final_exam_score(other.final_exam_score){
	assignment_scores = new unsigned int[NUM_OF_ASMTS];
	for(size_t i = 0; i < NUM_OF_ASMTS; i++) assignment_scores[i] = other.assignment_scores[i];
	quiz_scores = new unsigned int[num_of_quizzes];
	for(size_t i = 0; i < num_of_quizzes; i++) quiz_scores[i] = other.quiz_scores[i];
}

/*
 * Copy assignment - be careful to properly dispose of allocated memory for this
 * before overwriting with values from other
 */
csci152_student& csci152_student::operator=(const csci152_student& other){
	name = other.name;
	for(size_t i = 0; i < NUM_OF_ASMTS; i++) 
		assignment_scores[i] = other.assignment_scores[i];
	if(other.num_of_quizzes > num_of_quizzes){
		delete [] quiz_scores;
		quiz_scores = new unsigned int[other.num_of_quizzes];
	}
	num_of_quizzes = other.num_of_quizzes;
	for(size_t i = 0; i < num_of_quizzes; i++)
		quiz_scores[i] = other.quiz_scores[i];
	final_exam_score = other.final_exam_score;
}


/*
 * Name getter
 */
std::string csci152_student::get_name() const {return name;}

/*
 * Calculates the average assignment score, between 0.0 and 100.0
 */
double csci152_student::calculate_assignment_perc() const {
	double sum = 0;	
	for(size_t i = 0; i < NUM_OF_ASMTS; i++) sum += assignment_scores[i];
	return sum / NUM_OF_ASMTS;
}

/*
 * Calculates the total quiz percentage, where the lowest score is dropped from
 * from the calculation.  Between 0.0 and 100.0
 */
double csci152_student::calculate_quiz_perc() const {
	if(num_of_quizzes == 0) return 100;
	double sum = 0;
	unsigned int min = quiz_scores[0];
	for(size_t i = 0; i < num_of_quizzes; i++){
		sum += quiz_scores[i];
		if(min > quiz_scores[i]) min = quiz_scores[i];
	}
	return (sum - min)/(num_of_quizzes - 1)*100/15;
} 


/*
 * Returns the value stored in final_exam_score
 */
unsigned int csci152_student::get_final_exam_perc() const {
	return final_exam_score;
}

/*
 * Calculates the total course grade as a percent, using the weighting from
 * the syllabus
 */
double csci152_student::calculate_course_perc() const {
	return calculate_assignment_perc()*.2 + calculate_quiz_perc()*.4 + get_final_exam_perc()*.4;
}

/*
 * Destructor - don't forget you need to delete anything you explicitly allocated
 */
csci152_student::~csci152_student(){
	delete [] quiz_scores;
	delete [] assignment_scores;
}

