#include <stdio.h>
#define no_ofStudents 12

//declare struct
struct studentResults{
    char firstName[20];
    char lastName[20];
    int score;
} ;

//declare function for array of struct to be passed to it
void largest_score(struct studentResults results[]); 

int main(){

    //open and read file
    FILE*in = fopen("results.txt", "r"); 

    //error message if file is not found
    if(in == NULL){
        printf("Data file not found.\n");
    }

    //declare array of struct 
    struct studentResults aResult[no_ofStudents];
    
    //scan and store data from file opened into array of struct
    for(int a = 0; a < no_ofStudents; a++){
        fscanf(in, "%s %s %d", aResult[a].firstName, aResult[a].lastName, &aResult[a].score);
    }
    
    //call to funtcion passing array of struct to it
    largest_score(aResult);
    
    //close file that was opened
    fclose(in);

    return 0;
}

//function to find student/students with the highest score
void largest_score(struct studentResults results[]){
    
    //declare integer variable and assign to -1 as this is used to store the value of the highest score
    int highestScore = -1;

    //loop to find and store the highest score in integer variable
    for (int a = 0; a < no_ofStudents; a++) {
        if (results[a].score > highestScore) {
            highestScore = results[a].score;
        } 
    }
    
    //declare integer variable and assign to 0 as this will be used to count how many students have the highest score
    int count = 0;

    //loop to find the amount of students with the highest score
    for(int a = 0; a < no_ofStudents; a++){
        if(results[a].score == highestScore){
            count++;
        }
    }

    //if statement used to print singular(grammatically correct) text if one student have the highest score
    if(count == 1){
        printf("This is the student with the highest score:\n");
        //loop to find and print the student(singular as this is in the if statement if one student has the highest score) with the highest score
        for (int a = 0; a < no_ofStudents; a++) {
            if (results[a].score == highestScore) {
                printf("%s %s with a score of %d.\n", results[a].firstName, results[a].lastName, results[a].score);
            }
        }
    }
    //else if statement used to print plural(grammatically correct) text if multiple students have the highest score
    else if(count > 1){
        printf("These are the students with the highest score:\n");
        //loop to find and print the students(plural as this is in the if statement if multiple students has the highest score) with the highest score
        for (int a = 0; a < no_ofStudents; a++) {
            if (results[a].score == highestScore) {
                printf("%s %s with a score of %d.\n", results[a].firstName, results[a].lastName, results[a].score);
            }
        }
    }
}