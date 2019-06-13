/*
 * csci152_student.h
 *
 * Header file for Assignment 2
 */

#ifndef CSCI152_STUDENT_H_
#define CSCI152_STUDENT_H_

#include <ostream>

class csci152_student {

	std::string name; // name of student

	unsigned int *assignment_scores; // let's assume we will have and array of size 4, 
									 // each score out of 100
	unsigned int num_of_quizzes;   	 // between 2 and 7, depends on students' spravkas
	unsigned int *quiz_scores;	     // array of size num_of_quizzes, each out of 15
	unsigned int final_exam_score;   // out of 100

public:

	/*
	 * Standard argument constructor -- you must copy the arrays!
	 *
	 * Do not worry about illegal inputs for this assignment - you do not need
	 * to throw an exception, or even try to handle them
	 */
	csci152_student(
			std::string nm,
			unsigned int *asmts,
			unsigned int num_qs,
			unsigned int *quizzes,
			unsigned int final_exam
	);

	/*
	 * Copy constructor
	 */
	csci152_student(const csci152_student& other);

	/*
	 * Copy assignment - be careful to properly dispose of allocated memory for this
	 * before overwriting with values from other
	 */
	csci152_student& operator=(const csci152_student& other);


	/*
	 * Name getter
	 */
	std::string get_name() const;

	/*
	 * Calculates the average assignment score, between 0.0 and 100.0
	 */
	double calculate_assignment_perc() const;

	/*
	 * Calculates the total quiz percentage, where the lowest score is dropped from
	 * from the calculation.  Between 0.0 and 100.0
	 */
	double calculate_quiz_perc() const;


	/*
	 * Returns the value stored in final_exam_score
	 */
	unsigned int get_final_exam_perc() const;

	/*
	 * Calculates the total course grade as a percent, using the weighting from
	 * the syllabus
	 */
	double calculate_course_perc() const;

	/*
	 * Destructor - don't forget you need to delete anything you explicitly allocated
	 */
	~csci152_student();

};


#endif /* CSCI152_STUDENT_H_ */

