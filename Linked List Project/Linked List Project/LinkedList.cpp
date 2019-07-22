

#include "LinkedList.h"

Course * LinkedList::InsertHelper(Course * head, Course * newCourse)
{
    RecursionCounter rcTmp;   // used for testing purposes
    // add your code here...
    if (head->next == nullptr) {
        return head;
    } else if (head->courseNumber > newCourse->courseNumber) {
        return nullptr;
    } else if (head->courseNumber < newCourse->courseNumber && head->next->courseNumber > newCourse->courseNumber){        // base case
        return head;
    } else {                                                                // recursive case
        return InsertHelper(head->next, newCourse);
    }
}

int LinkedList::SizeHelper(Course const * cursor) const
{
    RecursionCounter rcTmp;   // used for testing purposes
    
    if (cursor->next == nullptr){       // base case
        return 1;
    } else {                            // recursive case
        int count = SizeHelper(cursor->next);
        count += 1;
        return count;
    }
}

void LinkedList::PrintListHelper(Course const * cursor) const
{
    RecursionCounter rcTmp;   // used for testing purposes
    
    if (cursor->next == nullptr){       // base case
        std::cout << "cs" << cursor->courseNumber << " " << cursor->courseName
        << " Grade:" << cursor->grade << " Credit Hours: " << cursor->credits << std::endl;
        
        return;
        
    } else {                            // recursive case
        std::cout << "cs" << cursor->courseNumber << " " << cursor->courseName
        << " Grade:" << cursor->grade << " Credit Hours: " << cursor->credits << std::endl;
        
        PrintListHelper(cursor->next);
        return;
    }
}

void LinkedList::DestructorHelper(Course * cursor)
{
    RecursionCounter rcTmp;   // used for testing purposes
    
    if (cursor->next == nullptr){       // base case
        delete cursor;
    } else {                            // recursive case
        DestructorHelper(cursor->next);
        delete cursor;
    }
}

double LinkedList::CalculateTotalGradePoints(Course const * cursor) const
{
    RecursionCounter rcTmp;   // used for testing purposes
    
    if (cursor->next == nullptr){       // base case
        return cursor->grade * cursor->credits;
    } else {                            // recursive case
        double gPoints = CalculateTotalGradePoints(cursor->next);
        gPoints += cursor->grade * cursor->credits;
        return gPoints;
    }
}

unsigned int LinkedList::CalculateTotalCredits(Course const * cursor) const
{
    RecursionCounter rcTmp;   // used for testing purposes
    
    if (cursor->next == nullptr){       // base case
        return cursor->credits;
    } else {                            // recursive case
        int creds = CalculateTotalCredits(cursor->next);
        creds += cursor->credits;
        return creds;
    }
}

double LinkedList::CalculateGPA() const{
    double points = CalculateTotalGradePoints(head);
    double credits = CalculateTotalCredits(head);
    return points/credits;
}

int LinkedList::Size() const{
    if (head == nullptr){
        return 0;
    } else {
        return SizeHelper(head);
    }
}

LinkedList::~LinkedList(){
    DestructorHelper(head);
}

void LinkedList::PrintList() const {
    std::cout << "Current List: (" << Size() << ")" << std::endl;
    PrintListHelper(head);
}

void LinkedList::Insert(Course *newCourse){
    if (head == nullptr){
        head = newCourse;
    } else {
        Course * insPo = InsertHelper(head, newCourse);
        if (insPo == nullptr){
            newCourse->next = head;
            head = newCourse;
        } else {
            newCourse->next = insPo->next;
            insPo->next = newCourse;
        }
    }
}
