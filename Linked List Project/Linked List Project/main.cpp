/********************************************************************************************
 **    Project: Recursive List
 **  Programmer: Dana Doggett
 **  Course:        cs2420
 **    Section:    001
 **    Assignment: 2
 **    Data:        August 27, 2018
 **
 **    I certify that I wrote all code in this project except that which was
 **    provided by the instructor.
 **
 ***********************************************************************************************/

#include <iostream>
#include <fstream>

#include "LinkedList.h"

// following several lines for unit testing purposes
#include "Observer.h"
#include "RecursionCounter.h"
int Observer::numConstructions = 0;
int Observer::numDestructions = 0;
std::set<void *> Observer::allocatedCourses;
int RecursionCounter::currentDepth = 0;
int RecursionCounter::maxDepth = 0;


using namespace std;

// the format for the data file is:
// <Course Number> , <Name> , <Credits>, <Grade>
//
// for example, the following would add four courses to the
// Linked List:
//
//    1400,Introduction to Programming,4,3.6
//    1410,C++ Programming,4,2.6
//    2420,Introduction to Data Structures,4,3.2
//    2810,Computer Architecture,3,3.8

int main()
{
    // specify the input data file (MUST BE HERE. Don't change this location or the grader will have problems!!!!)
    const char dataFileName[] = "/Users/blakewilliams/Desktop/2420/Linked List Project/Linked List Project/data.txt";
    
    // I've got the file name, now try to open the file for reading
    ifstream fileData;
    fileData.open(dataFileName);
    if (fileData.good() == false)
    {
        cout << "ERROR: can't open data file: " << dataFileName << endl;
        
        // wait for the user to press enter to quit
        cout << endl << "Press the [Enter] key to quit...";
        cin.get();
        return -1;
    }
    
    // I've got the data file open.
    // read and use the data
    {
        LinkedList courses;
        //
        //        /*********************************
        //        Psuedo Code (students must implement this)
        //        (hint: this is a comma-separated-file)
        //        1. while NOT end-of-file
        //        2.        read in from data file the course number
        //        3.        read in from data file the course name
        //        4.        read in from data file the course cedit hours
        //        5.        read in from data file the course grade
        //        6.        with this data, create a new Course
        //        7.        insert new Course into the LinkedList
        //        *********************************/
        
        
        string testString;
        
        while (fileData) {
            getline(fileData, testString);
            
            string currString;
            long numPos;
            long coursePos;
            long creditPos;
            long gpaPos;
            
            int courseNumber;
            string courseName;
            unsigned int credits;
            double grade;
            
            
            numPos = testString.find(',');
            currString = testString.substr(0,numPos);       // parse the course number out
            testString = testString.substr(++numPos);       // cut the course number from the line string
            courseNumber = stoi(currString);                // convert the string to an int
            
            coursePos = testString.find(',');
            courseName = testString.substr(0,coursePos);    // parse the course name out
            testString = testString.substr(++coursePos);    // cut the course name from the line string
            
            creditPos = testString.find(',');
            currString = testString.substr(0,creditPos);    // parse the credits out
            testString = testString.substr(++creditPos);    // cut the credits from the line string
            credits = stod(currString);                     // convert the string to a double
            
            gpaPos = testString.find(',');
            currString = testString.substr(0,gpaPos);       // parse the grade out
            grade = stod(currString);                       // convert the string to a double
            
            Course * tempCourse = new Course(courseNumber, courseName, credits, grade);
            
            courses.Insert(tempCourse);
            
            fileData.peek();
        }
        
        fileData.close();
        
        // display the ordered list of courses
        courses.PrintList();
        
        double gpa = courses.CalculateGPA();
        cout.precision(4);
        cout << "\nCumulative GPA: " << gpa << endl;
    }
    return 0;
}
