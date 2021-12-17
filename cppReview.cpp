#include <iostream>
#include <stdio.h> // for C style
#include <cmath> // Math functions

using namespace std;

void basics()
{
    string characterName = "John";
    int characterAge = 40;
    cout << "Hello, " << characterName << "!" << endl;
    cout << "You are " << characterAge <<" years old." <<endl;

    // C style
    char characterName2[] = "John";
    printf ("Hello, %s!\nYou are %d years old.\n", characterName2, characterAge);

    // String functions
    string phrase = "Test Phrase";
    int len = phrase.length(); // Length
    char letter = phrase[0]; // Return the i-th char
    cout << "The length of " << phrase << " is " << len << endl;
    cout << "It's first letter is " << letter << endl; 
    cout << phrase.find("Phrase", 0) << endl; // Return in which position the word appears
    cout << phrase.substr(8, 3) << endl; // 8 is where starts and 3 is length

    // Math functions: pow, sqrt, round, ceil, floor, fmax, fmin

    cout << pow(2, 5) << endl; // 2^5
    cout << sqrt(2) << endl;
    cout << round(4.6) << endl;
    cout << ceil(3.4) << endl;
    cout << floor(3.4) << endl;
    cout << fmax(3, 5) << endl;
    cout << fmin(3, 5) << endl;

    // User input
    /* int age;
    cout << "Enter your age: ";
    cin >> age;
    cout << "You are " << age << " years old" << endl; */

    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Hello " << name << endl;

    /* double num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2; */

    // Arrays
    int luckyNums[] = {4, 8, 15, 16, 23, 42};
    cout << luckyNums[0] << endl;
    luckyNums[0] = 19;
    cout << luckyNums[0] << endl;
    int luckyNums2[20];
}

int getMax(int num1, int num2, int num3)
{
    int result;

    if (num1 >= num2 && num1 >= num3) {
        result = num1;
    } else if (num2 >= num1 && num2 >= num3) {
        result = num2;
    } else {
        result = num3;
    }

    return result;
}

double calculator(int num1, int num2, char op) {
    if(op == '+') {
        return num1 + num2;
    } else if (op == '-') {
        return num1 - num2;
    } else if (op == '*') {
        return num1 * num2;
    } else if (op == '/') {
        return num1 / num2;
    } else {
        cout << "Invalid Operator";
        return 0;
    }
}

string getDayOfWeek(int dayNum) {
    string dayName;
    switch(dayNum) {
        case 0:
            dayName = "Sunday";
            break;
        case 1:
            dayName = "Monday";
            break;
        case 2:
            dayName = "Tuesday";
            break;
        case 3:
            dayName = "Wednesday";
            break;
        case 4:
            dayName = "Thursday";
            break;
        case 5:
            dayName = "Friday";
            break;
        case 6:
            dayName = "Saturday";
            break;
        default:
            dayName = "Invalid Day Number";
    }
    return dayName;
}

void doWhile() {
    int index = 6;
    do {
        cout << index << endl;
        index++;
    } while (index <= 5);
}

void guessingGame() {
    int secretNum = 7;
    int guess;
    int guessCount = 0;
    int guessLimit = 3;
    bool outOfGuesses = false;

    while(secretNum != guess && !outOfGuesses) {
        if(guessCount < guessLimit) {
            cout << "Enter guess: ";
            cin >> guess;
            guessCount++;
        } else {
            outOfGuesses = true;
        }
    }
    if(outOfGuesses) {
        cout << "You lose!" << endl;
    } else {
        cout << "You win!" << endl;
    }
}

void twoDArray() {
    int numberGrid[3][2] = {
        {1, 2},
        {3, 4},
        {5, 6}
    };

    // Prints all elements
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cout << numberGrid[i][j];
        }
        cout << endl;
    }
}

void pointers() {
    // Pointers: is a data which points to where the data is allocated
    // & prints the memory address
    // * indicates a pointer variable and is also used for
    // Dereferencing a pointer: take the value inside it

    int age = 19;
    int *pAge = &age; 
    double gpa = 2.7;
    double *pGpa = &gpa;
    string name = "Mike";
    cout << age << endl;
    cout << &age << endl;
    cout << pAge << endl;
    cout << *pAge << endl;
    cout << *&age << endl;
}

class Book {
    // Classes and Objects
    // Used to create new data types
    // Collection of atributes 
    // Class is a specification, a blueprint, a template of a data type 
    // Object is an instance of that class
    public:
        string title;
        string author;
        int pages;
};

class Book2 {
    public:
        string title;
        string author;
        int pages;
        // Constructor: a function that runs every time a new object is created
        Book2(string aTitle, string aAuthor, int aPages) {
            title = aTitle;
            author = aAuthor;
            pages = aPages;
        }
};

class Student {
    public:
        string name;
        string major;
        double gpa;
        
        // Constructor 
        Student(string aName, string aMajor, double aGpa) {
            name = aName;
            major = aMajor;
            gpa = aGpa;
        }

        // Object functions
        bool hasHonors() {
            if(gpa >= 3.5) {
                return true;
            }
            return false;
        }
};

void objects() {
    Book book1; // Instance/Object
    book1.title = "Mathematical Logic";
    book1.author = "Elliot Mendelson";
    book1.pages = 500;

    Book book2; // Instance/Object
    book2.title = "Lord of the Rings";
    book2.author = "JRR Tolkien";
    book2.pages = 700;

    cout << book1.title << endl;
    cout << book2.author << endl;

    // With constructor
    Book2 book3("Mathematical Logic", "Elliot Mendelson", 500);
    cout << book3.title << endl;

    //
    Student student1("Jim", "Mathematics", 4.0);
    Student student2("Pam", "Physics", 2.9);

    cout << student1.hasHonors() << endl;
    cout << student2.hasHonors() << endl;
}

class Movie {
    private: // Cannot be accessed outside the class
        string rating;
    public: // Any code outside of the class can access this info
        string title;
        string director;
        Movie(string aTitle, string aDirector, string aRating) {
            title = aTitle;
            director = aDirector;
            setRating(aRating);
        }
        // Setter: controls access to elements and atributes
        void setRating(string aRating) {
            if(aRating == "G" || aRating == "PG" || aRating == "PG-13" || aRating == "NR") {
                rating = aRating;
            } else {
                rating = "NR";
            }
        }
        // Getter
        string getRating() {
            return rating;
        }
};

void gettersAndSetters() {
    Movie karateKid("Karate Kid", "John G. Avildsen", "PG-13");
    // cannot access karateKid.rating
    cout << karateKid.title << endl;
    karateKid.setRating("Dog");
    cout << karateKid.getRating() << endl;
}

// Superclass
class Chef {
    public:
        void makeChicken() {
            cout << "The chef makes chicken" << endl;
        }
        void makeSalad() {
            cout << "The chef makes salad" << endl;
        }
        void makeBbq() {
            cout << "The chef makes BBQ" << endl;
        }
};

// Subclass
class ItalianChef : public Chef {
    public: 
        void makePasta() {
            cout << "The chef makes Pasta" << endl;
        }
        void makeSalad() {
            cout << "The chef makes Caesar Salad" << endl;
        }
};

void inheritance() {
    ItalianChef italianChef;
    italianChef.makeChicken(); // Inherits all chef habilities
    italianChef.makePasta(); // New function
    italianChef.makeSalad(); // Overwrites the original funcion
}

int main()
{
    // Basics
    cout << "1. Basics" << endl;
    basics();
    int result = getMax(5,6,2);
    cout << result  << endl;

    // Calculator
    cout << endl << "---------------------" << endl;
    cout << "2. Calculator" << endl;
    double num1, num2;
    char op;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter operator: ";
    cin >> op;
    cout << "Enter second number: ";
    cin >> num2;
    int calculatorResult = calculator(num1, num2, op);
    cout << num1 << op << num2 << "=" << calculatorResult << endl;

    // Switch and Loops
    cout << endl << "---------------------" << endl << endl;
    cout << "3. Switch and Loops" << endl;
    cout << getDayOfWeek(3) << endl; // Switch
    doWhile();
    guessingGame();
    twoDArray();

    // Pointers
    cout << endl << "---------------------" << endl << endl;
    cout << "4. Pointers" << endl;    
    pointers();

    // Classes and Objects
    cout << endl << "---------------------" << endl << endl;
    cout << "5. Classes and Objects" << endl;
    objects();
    gettersAndSetters();
    inheritance();

    return 0;
}