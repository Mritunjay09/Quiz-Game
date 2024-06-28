#include <iostream>
using namespace std;

int score = 0;

// Function to display performance result
void result()
{
    if (score <= 10 && score >= 8)
    {
        cout << "Excellent Performance" << endl;
    }
    else if (score <= 7 && score >= 5)
    {
        cout << "Average Performance" << endl;
    }
    else
    {
        cout << "Poor Performance" << endl;
    }
}

// Function to check the answer
void check(int correct)
{
    int ans;
    cout << "Enter the answer\n";
    cin >> ans;
    if (ans == correct)
    {
        score++; // Increment score if the answer is correct
    }
    cout << "\033[2J\033[H"; // Clear the screen
}

// Function to ask questions
void askque()
{
    cout << "\033[2J\033[H"; // Clear the screen
    cout << "Which of the following is a Palindrome number?" << endl;
    cout << "1) 42042 2) 101010 3) 23232 4) 01234" << endl;
    check(4); // Check answer for the first question
    cout << "The country with the highest environmental performance index is..." << endl;
    cout << "1) France 2) Denmark 3) Switzerland 4) Finland" << endl;
    check(3);
    cout << "Which animal laughs like human being?" << endl;
    cout << "1) Polar Bear 2) Hyena 3) Donkey 4) Chimpanzee" << endl;
    check(2);
    cout << "Who was awarded the youngest player award in Fifa World Cup 2006?" << endl;
    cout << "1) Wayne Rooney 2) Lucas Podolski 3) Lionel Messi 4) Christiano Ronaldo" << endl;
    check(2);
    cout << "Which is the third highest mountain in the world?" << endl;
    cout << "1) Mt. Kanchanjungha 2) Mt. Makalu 3) Mt. Kilimanjaro 4) Mt. K2" << endl;
    check(1);
    cout << "What is the group of frogs known as?" << endl;
    cout << "1) A traffic 2) A toddler 3) A police 4) An army " << endl;
    check(4);
    cout << "What is the National Game of England?" << endl;
    cout << "1) Football 2) Basketball 3) Cricket 4) Baseball" << endl;
    check(3);
    cout << "Study of Earthquake is called............," << endl;
    cout << "1) Seismology 2) Cosmology 3) Orology 4) Etimology" << endl;
    check(1);
    cout << "Among the top 10 highest peaks in the world, how many lie in Nepal?" << endl;
    cout << "1) 6 2) 7 3) 8 4) 9" << endl;
    check(3);
    cout << "The Laws of Electromagnetic Induction were given by?" << endl;
    cout << "1) Faraday 2) Tesla 3) Maxwell 4) Coulomb" << endl;
    check(1);
}

int main()
{
    // Display welcome message and options
    cout << "\033[2J\033[H"; // Clear the screen
    cout << "\t\t\tC PROGRAM QUIZ GAME\n";
    cout << "\n\t\t________________________________________";
    cout << "\n\t\t\t    WELCOME ";
    cout << "\n\t\t\t      to ";
    cout << "\n\t\t\t   THE GAME ";
    cout << "\n\t\t________________________________________";
    cout << "\n\t\t________________________________________";
    cout << "\n\t\t > Press S to start the game";
    cout << "\n\t\t > press H for help            ";
    cout << "\n\t\t > press Q to quit             \n\n";

    char ch;
    cin >> ch; // Input choice from the user

    if (ch == 's' || ch == 'S')
    {
        askque(); // Start asking questions
        result(); // Display performance result
    }

    // Help section
    if (ch == 'h' || ch == 'H')
    {
        cout << "\033[2J\033[H"; // Clear the screen
        cout << "\n\n                              HELP";
        cout << "\n -------------------------------------------------------------------------";
        cout << "\n ......................... C program Quiz Game............................";
        cout << "\n >> Your game starts with the CHALLENGE ROUND. In this round you will be asked";
        cout << "\n    total 10 questions each right answer will be awarded 1 point";
        cout << "\n    By this way you can win upto 10 points...............";
        cout << "\n >> You will be given 4 options and you have to press 1, 2, 3 or 4 for the";
        cout << "\n    right option";
        cout << "\n >> You will be asked questions continuously if you keep giving the right answers.";
        cout << "\n >> No negative marking for wrong answers";
        cout << "\n\n\t*********************BEST OF LUCK*********************************";
        cout << "\n\n\tPress Any Key To Go Back\n\n";
        char x;
        cin >> x; // Wait for user input to go back to the main menu
        if (x)
        {
            main(); // Go back to the main menu
        }
        return 0;
    }
}
