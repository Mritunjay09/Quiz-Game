#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

// Define a struct for the quiz questions
struct Node
{
    char question[85]; // Question text
    char answer[2];    // Answer (assuming single character answer)
    char options[85];  // Options for the question
    Node *next;        // Pointer to the next question
};

const int N = 10000; // Maximum number of questions
Node *table[N];      // Array of pointers to questions
int ans_count = 0;   // Counter for correct answers

// Function to display result based on the score
void result()
{
    if (ans_count <= 10 && ans_count >= 8)
    {
        cout << "\t\t\t  Excellent Performance" << endl;
    }
    else if (ans_count <= 7 && ans_count >= 5)
    {
        cout << "\t\t\t  Average Performance" << endl;
    }
    else
    {
        cout << "\t\t\t  Poor Performance" << endl;
    }
}

// Function to check the user's answer against the correct answer
void check(int i)
{
    char answer[2]; // Increase size to accommodate null terminator
    Node *cursor = table[i];
    cout << cursor->answer;
    cin >> answer;
    if (strcmp(answer, cursor->answer) == 0) // Compare strings using strcmp
    {
        ans_count++;
        cout << "your Score is " << ans_count << endl; // Display current score
        for (long long int k = 0; k < 178400000; k++)  // Delay for visualization
        {
        }
    }
    else
    {
        cout << "\n\nINCORRECT ANSWER\n";
        cout << cursor->answer << " is the correct answer ";
        cout << "your Score is " << ans_count << endl; // Display current score
        for (long long int k = 0; k < 1784000000; k++) // Delay for visualization
        {
        }
    }
}

// Function to load questions from a file
bool load()
{
    ifstream file("C++_questions.txt"); // Open the file
    if (!file.is_open())            // Check if file is opened successfully
    {
        return false;
    }
    int sw = 0;                    // Switch variable to track loading state
    char word[85];                 // Temporary buffer for reading lines
    int h = 0;                     // Index for the question array
    while (file.getline(word, 82)) // Read lines from the file
    {
        switch (sw)
        {
        case 0:
        {
            Node *cursor = new Node;        // Create a new question node
            strcpy(cursor->question, word); // Copy question text
            sw = 2;                         // Move to next state
            table[h] = cursor;              // Store the question node in the array
            break;
        }
        case 2:
        {
            Node *cursor = table[h];       // Get the current question node
            strcpy(cursor->options, word); // Copy options text
            sw = 90;                       // Move to next state
            break;
        }
        case 90:
        {
            Node *cursor = table[h];      // Get the current question node
            strcpy(cursor->answer, word); // Copy answer text
            if (h == 0)
            {
                cursor->next = nullptr; // If it's the first question, set next to null
            }
            else
            {
                cursor->next = table[h]; // Otherwise, link it to the previous question
            }
            h++;    // Move to the next question
            sw = 0; // Reset switch state
            break;
        }
        }
    }
    file.close(); // Close the file
    return true;
}

// Function to release memory allocated for questions
bool unload()
{
    for (int i = 0; i < N; i++) // Loop through the question array
    {
        Node *cursor = table[i];  // Get the current question node
        while (cursor != nullptr) // Loop through the linked list of questions
        {
            Node *temp = cursor;   // Temporary pointer to current node
            cursor = cursor->next; // Move to the next node
            delete temp;           // Delete the current node
        }
    }
    return true;
}

// Main function
int main()
{
    srand(time(nullptr)); // Seed the random number generator with current time

    char ch;              // Variable to store user input
    bool loaded = load(); // Load questions from file
    if (!loaded)          // Check if loading was successful
    {
        unload();                   // Unload questions
        cout << "Could not load\n"; // Display error message
        return 1;                   // Return error code
    }
    // Display welcome message and menu options
    cout << "\033[2J\033[H";
    cout << "\033[2J\033[H";
    cout << "\t\t\tC PROGRAM QUIZ GAME";
    cout << "\n\t\t________________________________________\n";
    cout << "\n\t\t\t      WELCOME ";
    cout << "\n\t\t\t        to ";
    cout << "\n\t\t\t     THE GAME ";
    cout << "\n\t\t________________________________________";
    cout << "\n\t\t________________________________________";
    cout << "\n\t\t > Press S to start the game";
    cout << "\n\t\t > press H for help            ";
    cout << "\n\t\t > press Q to quit             ";
    cout << "\n\t\t________________________________________\n\n";

    cin >> ch; // Read user's choice from input

    // Handle user's choice
    if (ch == 'S' || ch == 's') // If user chooses to start the game
    {
        cout << "\033[2J\033[H";         // Clear the screen
        int q = 1;                       // Counter for question number
        int a = rand() % 18;             // Generate a random starting index for questions
        for (int i = a; i < a + 10; i++) // Loop through 10 questions
        {
            cout << "\033[2J\033[H";          // Clear the screen
            Node *cursor = table[i];          // Get the current question node
            cout << "Que " << q << " ";       // Display question number
            cout << cursor->question << endl; // Display question text
            cout << cursor->options << endl;  // Display options
            cout << "What is your Answer\n";  // Prompt for user's answer
            check(i);                         // Check user's answer
            q++;                              // Increment question number
        }
        cout << "\033[2J\033[H"; // Clear the screen
        // Display options for playing next game or quitting
        cout << "\n\t\t\t____________________________________________________\n";
        cout << "\n\t\t\t Press Y And Enter If You Want To Play The Next Game\n ";
        cout << "\n\t\t\t Press Any Other Key And Enter To Quit ";
        cout << "\n\t\t\t____________________________________________________\n\n";
        char ch;
        cin >> ch;
        if (ch == 'y' || ch == 'Y') // If user wants to play the next game
        {
            ans_count = 0; // Reset the score
            main();        // Restart the game
        }
        else // If user wants to quit
        {
            cout << "\033[2J\033[H"; // Clear the screen
            cout << "\n\t\t\t_______________________\n";
            cout << "\n\t\t\t  The Game Has Ended";
            cout << "\n\t\t\t  Your Score Was " << ans_count << endl;
            result(); // Display the performance result
            cout << "\n\t\t\t_______________________\n\n";
            for (long long int k = 0; k < 178400000; k++) // Delay for visualization
            {
            }
            return 0; // Exit the program
        }
    }
    else if (ch == 'h' || ch == 'H') // If user wants to view help
    {
        cout << "\033[2J\033[H"; // Clear the screen
        cout << "\n\n                              HELP";
        cout << "\n -------------------------------------------------------------------------";
        cout << "\n ......................... C program Quiz Game............................";
        cout << "\n >> Your game starts with the CHALLENGE ROUND. In this round, you will be asked";
        cout << "\n    a total of 10 questions. Each correct answer will be awarded 1 point.";
        cout << "\n    By this way you can win up to 10 points...............";
        cout << "\n >> You will be given 4 options and you have to press 1, 2, 3, or 4 for the";
        cout << "\n    right option.";
        cout << "\n >> You will be asked questions continuously if you keep giving the right answers.";
        cout << "\n >> There is no negative marking for wrong answers.";
        cout << "\n\n\t*********************BEST OF LUCK*********************************";
        cout << "\n\n\tPress Any Key To Go Back\n\n";
        char x;
        cin >> x; // Wait for user input to go back to the main menu
        if (x)
        {
            main(); // Go back to the main menu
        }
    }
    else if (ch == 'q' || ch == 'Q') // If user wants to quit
    {
        cout << "\033[2J\033[H";        // Clear the screen
        cout << "The Game Has ended\n"; // Display end message
        return 0;                       // Exit the program
    }
}