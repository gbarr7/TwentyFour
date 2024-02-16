#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
/*------------------------------------------------------Structs-----------------------------------------------------------------------*/

struct hand {

    double HandNumOne; //First value out of four for puzzle.

    double HandNumTwo; //second value out of four for puzzle.

    double HandNumThree; //Third value out of four for puzzle.

    double HandNumFour; //Fourth value out of four for puzzle.

}; // This struct is used as the template for assigning sets of 4 values for the puzzels.

struct PossibleSolution {

    int array[3189][4]; //A 2d array that will save 3188 values in sets of 4

};// This struct is used as a quick method to save the data that is considered a possible combination of sets of 4, that equal 24


/*------------------------------------------------------Calculation Functions-----------------------------------------------------------------------*/

double AddFunction(int numOne, int numTwo, double* amount) { //Takes two int values and save thoes two values in a double called amount

    *amount = numOne + numTwo; // two int values are added and are saved in amount

    printf("%d + %d = %d.\n", (int)numOne, (int)numTwo, (int)*amount); // two int values and amount are printed.

    return *amount; //amount is saved with a pointer, and it return to be used in other functions.
}

double SubtractFunction(int numOne, int numTwo, double* amount) { //Takes two int values and save thoes two values in a double called amount

    *amount = numOne - numTwo; // two int values are subtracted and are saved in amount

    printf("%d - %d = %d.\n", (int)numOne, (int)numTwo, (int)*amount); // two int values and amount are printed.

    return *amount; //amount is saved with a pointer, and it return to be used in other functions.

}
double DivideFunction(int numOne, int numTwo, double* amount) { //Takes two int values and save thoes two values in a double called amount

    *amount = numOne / numTwo; // two int values are divided and are saved in amount

    printf("%d / %d = %d.\n", (int)numOne, (int)numTwo, (int)*amount);// two int values and amount are printed.

    return *amount; //amount is saved with a pointer, and it return to be used in other functions.
}

double MultiplyFunction(int numOne, int numTwo, double* amount) { //Takes two int values and save thoes two values in a double called amount

    *amount = numOne * numTwo; // two int values are multiply and are saved in amount

    printf("%d * %d = %d.\n", (int)numOne, (int)numTwo, (int)*amount); // two int values and amount are printed.

    return *amount; //amount is saved with a pointer, and it return to be used in other functions.
}
// These 4 function do around the same thing, they take two int values, and based on what operator(+, -, *, /) is used, it will do that get the amount and return it

double GetOperators(int inputOne, int inputTwo, char OperatorsSelection) { //Takes two int values one char value, that char values is checked to see if it matches, and then the two values are sent to be used other functions.

    double amount; //establishes amount for which is used to save data, and what is retuned depending on operators.

    if (OperatorsSelection == '+') {//checks if OperatorsSelection is a plus

        AddFunction(inputOne, inputTwo, &amount); //if OperatorsSelection is a plus is will used the two int values and send it to the AddFunction to get the sum.

        return amount;//return the sum for later use.

    }

    else if (OperatorsSelection == '-') {//checks if OperatorsSelection is a minus

        SubtractFunction(inputOne, inputTwo, &amount); //if OperatorsSelection is a minus is will used the two int values and send it to the AddFunction to get the difference.

        return amount;//return the difference for later use.

    }

    else if (OperatorsSelection == '*') {//checks if OperatorsSelection is a times

        MultiplyFunction(inputOne, inputTwo, &amount); //if OperatorsSelection is a times is will used the two int values and send it to the AddFunction to get the difference.

        return amount;//return the multiple for later use.
    }

    else if (OperatorsSelection == '/') {//checks if OperatorsSelection is a divisor

        DivideFunction(inputOne, inputTwo, &amount);//if OperatorsSelection is a divisor is will used the two int values and send it to the AddFunction to get the difference.

        return amount;//return the dividend for later use.
    }
    else {
        return amount; //this line of code should not be call at all. It will return 0 if used, but other parts of code would/should prevent that.
    }

}
//This function is used to check which operator are used to run, and then it will call on the 4 function above this one.

bool CheckOperators(char OperatorsSelection) {


    if (OperatorsSelection == '+') { //checks if OperatorsSelection is a plus

        return true;//return true if plus symbol is typed.

    }
    else if (OperatorsSelection == '-') {//checks if OperatorsSelection is a minus

        return true;//return true if minus symbol is typed.

    }
    else if (OperatorsSelection == '*') {//checks if OperatorsSelection is a times

        return true;//return true if times symbol is typed.

    }
    else if (OperatorsSelection == '/') {//checks if OperatorsSelection is a divid

        return true; //return true if divid symbol is typed.

    }
    else {

        return false;//return false if there is no match

    }

}
//This bool function is used to check if any operator was typed by the user, it will return true if 1 of the 4 operators is type, and false if anything else was type.
double ApplyDebugOperators(double a, double b, char operator) {

    switch (operator) {

        case '+': return a + b;//if its a plus it will add.

        case '-': return a - b;//if its a minus it will subtract.

        case '*': return a * b;//if its a times it will multiply.

        case '/': return a / b;//if its a divid it will divid.

    }
    return 0;
}
//This function is used only in debug to quickly find the values for the puzzle. It is used only for debug because hard mode requires different inputs.
/*------------------------------------------------------Randomizers Functions-----------------------------------------------------------------------*/
int ProblemSelector(int* problem) {//Takes one poiunter value

    *problem = rand() % 3188; // poiunter value will be assined a amount that is from 1 through 3188

    return *problem; // poiunter value will be saved is retuned with a random value.

}
int RowSelector(int* Row) {//Takes one poiunter value

    *Row = rand() % 10;// poiunter value will be assined a amount that is from 1 through 10

    return *Row;// poiunter value will be saved is retuned with a random value.

}
//These two fuctions follow the same idea, one selects the amount of rows for the easy version of the game, which is 10. It is the same for the one that has 3188. It will choose a random number for one of the possible puzzle combinations that can happen.

/*------------------------------------------------------Utility functions-------------------------------------------------------------------*/
void display_usage() {

    printf("Welcome to the game of TwentyFour.\n");

    printf("Use each of the four numbers shown below exactly once,\n");

    printf("combining them somehow with the basic mathematical operators (+,-,*,/)\n");

    printf("to yield the value twenty-four.\n \n");

}
//This function will display the message at the start of the game.

/*------------------------------------------------------Data Functions-----------------------------------------------------------------------*/





void GetDebugData(double a, double b, double c, double d) {//takes four values to see if they can be used as a possible combination

    char operators[] = { '+', '-', '*', '/' }; //These operators are saved in a array to be selected to find a combination

    static int count = 1; //keep track of count of what combination amount it at, it does this by keeping the value of how many times the if statment has been used, and will stay the same values even if the function ends.

    for (int i = 0; i < 4; i++) {

        for (int j = 0; j < 4; j++) {

            for (int k = 0; k < 4; k++) { //These three for loops are used to go through all possible combinations of operators by using the index of the operators array.

                double result = ApplyDebugOperators(a, b, operators[i]); //goes through two values and all operators

                result = ApplyDebugOperators(result, c, operators[j]); //goes through one values and one result, and all operators

                result = ApplyDebugOperators(result, d, operators[k]); //goes through one values and one result, and all operators

                if ((result - 24.0) < 0.001 && (result - 24.0) >= 0) { //if the above has a possible value, the it will go to the next step, but if not it will keep going untill one is found

                    printf("%d.%.0lf%c%.0lf%c%.0lf%c%.0lf\n", count, a, operators[i], b, operators[j], c, operators[k], d);//if result is found, the value and operators are printed for debug mode
                    count++;//static count that will keep track of how many result have been found no matter what.


                }
            }

        }

    }
}
//This function will get the data for debug mode, it will generate all possible solutions, and only print it out.
void GetData(double a, double b, double c, double d, struct PossibleSolution* combinations) {//takes four values to see if they can be used as a possible combination, and a struct to save all combinations

    char operators[] = { '+', '-', '*', '/' }; //These operators are saved in a array to be selected to find a combination

    static int index = 0; //Saves index so that array struct is is filled up

    static int count = 1; //keep track of count of what combination amount it at, it does this by keeping the value of how many times the if statment has been used, and will stay the same values even if the function ends.

    for (int i = 0; i < 4; i++) {

        for (int j = 0; j < 4; j++) {

            for (int k = 0; k < 4; k++) {//These three for loops are used to go through all possible combinations of operators by using the index of the operators array.

                double result = ApplyDebugOperators(a, b, operators[i]);//goes through two values and all operators

                result = ApplyDebugOperators(result, c, operators[j]);//goes through one values and one result, and all operators

                result = ApplyDebugOperators(result, d, operators[k]);//goes through one values and one result, and all operators

                if ((result - 24.0) < 0.001 && (result - 24.0) >= 0) {//if the above has a possible value, the it will go to the next step, but if not it will keep going untill one is found

                    combinations->array[index][0] = a; //These arrays are pointers, which are saved, and always going up in index.

                    combinations->array[index][1] = b;

                    combinations->array[index][2] = c;

                    combinations->array[index][3] = d;

                    index++; //index permanently go up

                }
            }

        }

    }
}
//This function will get the data for Hard mode, it will generate all possible solutions, and only store that data using pointers and struct PossibleSolution.
int RunData(int YesNO, struct PossibleSolution* result) {

    struct PossibleSolution Value;//Array to temp store pointer to tranfer data out of this function

    double array[6562][4];//Array to store all possible values from 1 - 9.

    int count = 0; //count to keep track of values being index.

    for (int i = 1; i <= 9; i++) {

        for (int j = 1; j <= 9; j++) {

            for (int k = 1; k <= 9; k++) {

                for (int l = 1; l <= 9; l++) {//for loop that goes from value 1 - 9999, to find all possible values.


                    array[count][0] = i;

                    array[count][1] = j;

                    array[count][2] = k;

                    array[count][3] = l;

                    count++;
                }
            }
        }
    }

    for (int i = 0; i < 6561; i++) {//for loop that goes from value 1 - 9999, to find all possible values.

        GetData(array[i][0], array[i][1], array[i][2], array[i][3], &Value);

    }

    if (YesNO == 1) {

        *result = Value;

    }


    return 0;
}
//This function will get the data for Hard mode, it will generate all values from one through nine using for loops, it will then call GetData, and go through all values to find all possible combinations.
int RunDebug() {

    struct hand input;

    double array[6562][4]; //Array to temp store pointer to tranfer data out of this function

    int count = 0;

    for (int i = 1; i <= 9; i++) {

        for (int j = 1; j <= 9; j++) {

            for (int k = 1; k <= 9; k++) {

                for (int l = 1; l <= 9; l++) {//for loop that goes from value 1 - 9999, to find all possible values.


                    array[count][0] = i;

                    array[count][1] = j;

                    array[count][2] = k;

                    array[count][3] = l;

                    count++;
                }
            }
        }
    }

    for (int i = 0; i < 6561; i++) {

        GetDebugData(array[i][0], array[i][1], array[i][2], array[i][3]);

    }


    return 0;
}
//This function will get the data for Debug mode, it will generate all values from one through nine using for loops, it will then call GetDebugData, and go through all values to print all possible combinations.
void get_arguments(

        int   argc, 		  // number of args, including prog. name

        char* argv[],		  // array of strings

        int* startValueEasy,// character value command line parameter

        int* startValueDebug)
{

    if (argc == 1)

        display_usage();

    else {

        while ((argc -= 2) > 0) {

            if (argv[1][0] != '-')

                display_usage();

            switch (argv[1][1]) {

                case 'e':

                    *startValueEasy = atoi(argv[2]);

                    break;

                case 'd':

                    display_usage();

                    *startValueDebug = atoi(argv[2]);

                    break;


            } //end while
            argv += 2;

        }

    } //end else

}//end get_arguments()
//This function will get the data for command line, and then it will used pointers to save the input that can be found in main.
/*------------------------------------------------------ Game+Main Functions-----------------------------------------------------------------------*/
int runGame() {

    static int counter = 0;

    struct hand input;

    bool rightinput = false;

    int result;

    struct PossibleSolution Solution;

    int yesNO = 1;

    if (counter == 0) {

        RunData(yesNO, &Solution);

        counter++;

    }

    int RanProblem;
    do{
        ProblemSelector(&RanProblem);


        input.HandNumOne = Solution.array[RanProblem][0];

        input.HandNumTwo = Solution.array[RanProblem][1];

        input.HandNumThree = Solution.array[RanProblem][2];

        input.HandNumFour = Solution.array[RanProblem][3];


        double amountOne;

        double amountTwo;

        char OperatorsSelection[60];

        printf("The numbers to use are: ");

        printf("%d, %d, %d, %d.\n", (int)input.HandNumOne, (int)input.HandNumTwo, (int)input.HandNumThree, (int)input.HandNumFour);

        printf("Enter the three operators to be used, in order (+,-,*, or /): ");

        scanf(" %[^\n]s", OperatorsSelection);

        if ((OperatorsSelection[0] != '\0') && (OperatorsSelection[1] != '\0') && (OperatorsSelection[2] != '\0') && (OperatorsSelection[3] == '\0')) {

            if (((CheckOperators(OperatorsSelection[0]) == true) && (CheckOperators(OperatorsSelection[1]) == true) && (CheckOperators(OperatorsSelection[2]) == true))) {



                amountOne = GetOperators(input.HandNumOne, input.HandNumTwo, OperatorsSelection[0]);

                amountTwo = GetOperators(amountOne, input.HandNumThree, OperatorsSelection[1]);

                result = GetOperators(amountTwo, input.HandNumFour, OperatorsSelection[2]);

                rightinput = true;
            }

            else {

                printf("Error! Invalid operator entered. Please try again.\n\n");

                rightinput = false;

            }

        }


        else {

            printf("Error! The number of operators is incorrect. Please try again.\n\n");

            rightinput = false;

        }

    } while(rightinput != true);


    if (result == 24) {

        printf("Well done! You are a math genius.\n\n");

        return 0;
    }
    else {

        printf("Sorry. Your solution did not evaluate to 24.\n\n");

        return 0;
    }
}
//This function is hard mode, it will call the on RunData only once, then it will check for the input of the user.
int RunEasyGame() {

    struct hand input;

    int row;

    RowSelector(&row);

    float selectionArr[10][4] = { {3, 9, 4, 1},{8, 5, 8, 1},{ 6, 1, 5, 1},{2, 8, 7, 8},{5, 2, 9, 2}, {2, 6, 8, 4},
                                  {5, 5, 4, 3}, {6, 6, 2, 6}, {8, 4, 2, 6}, {6, 2, 8, 1} };

    input.HandNumOne = selectionArr[row][0];

    input.HandNumTwo = selectionArr[row][1];

    input.HandNumThree = selectionArr[row][2];

    input.HandNumFour = selectionArr[row][3];

    float amountOne;

    float amountTwo;

    float result;

    char OperatorsSelection[50];

    printf("The numbers to use are: ");

    printf("%d, %d, %d, %d.\n", (int)input.HandNumOne, (int)input.HandNumTwo, (int)input.HandNumThree, (int)input.HandNumFour);

    printf("Enter the three operators to be used, in order (+,-,*, or /): ");

    scanf(" %[^\n]s", OperatorsSelection);

    if ((OperatorsSelection[0] != '\0') && (OperatorsSelection[1] != '\0') && (OperatorsSelection[2] != '\0') && (OperatorsSelection[3] == '\0')) {

        if (((CheckOperators(OperatorsSelection[0]) == true) && (CheckOperators(OperatorsSelection[1]) == true) && (CheckOperators(OperatorsSelection[2]) == true))) {

            amountOne = GetOperators(input.HandNumOne, input.HandNumTwo, OperatorsSelection[0]);

            amountTwo = GetOperators(amountOne, input.HandNumThree, OperatorsSelection[1]);

            result = GetOperators(amountTwo, input.HandNumFour, OperatorsSelection[2]);
        }

        else {

            printf("Error! Invalid operator entered. Please try again.\n\n");

            RunEasyGame();

            return 0;

        }

    }

    else {

        printf("Error! The number of operators is incorrect. Please try again.\n\n");

        RunEasyGame();

        return 0;

    }


    if (result == 24) {

        printf("Well done! You are a math genius.\n\n");

        return 0;
    }

    else {
        printf("Sorry. Your solution did not evaluate to 24.\n\n");
        return 0;
    }

}
//This function is easy mode, it will select the row from one through ten, then it will check for the input of the user.
int main(int argc, char* argv[]) {
    srand(1);

    int startValueEasy = 1;

    int startValueDebug = 0;

    char PlayAgain[65];

    get_arguments(argc, argv, &startValueEasy, &startValueDebug);

    if (startValueDebug == 1) {

        RunDebug();

    }
    if (startValueEasy == 1) {

        do {

            RunEasyGame();

            printf("Would you like to play again? Enter N for no and any other character for yes. ");

            scanf(" %[^\n]s", PlayAgain);

            printf("\n");

        } while (strcmp(PlayAgain, "N") != 0);

    }

    else {

        do {

            runGame();

            printf("Would you like to play again? Enter N for no and any other character for yes. ");

            scanf(" %[^\n]s", PlayAgain);

            printf("\n");

        } while (strcmp(PlayAgain, "N") != 0);

    }

    printf("Thanks for playing!");

    return 0;
}