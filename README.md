# 📘 Quiz Game – README

<p align="center">
  <img width="465" height="342" alt="image" src="https://github.com/user-attachments/assets/c8876f5b-c26d-438d-b6a9-d4c17c8d9f16" />
</p>

## 🧩 Overview

This is a simple command-line **Quiz Game** written in C.
The program loads questions from a file, presents them to the player, accepts their answers, and finally stores the score in a separate file.

This project demonstrates basic file handling, loops, condition checking, and user input in C.

---

## 🚀 How to Compile and Run

### **1️⃣ Compile the Program**

Make sure you have GCC installed.
Run the following command in your terminal:

```bash
gcc Quizgame.c -o quizgame
```

### **2️⃣ Run the Program**

After compiling successfully, run:

```bash
./quizgame
```

---

## 📂 Project Structure

```
├── Quiz_Game.c
├── questions.txt
├── score.txt
└── README.md
```

---

## 📄 File Descriptions

### **questions.txt**

This file contains all the quiz questions.
Each question typically includes:

- the question text
- multiple-choice options
- the correct answer

**Example format:**

```
Which of the following is a Palindrome number?
1) 42042 2) 101010 3) 23232 4) 01234
23232
```

The program reads this file line by line to generate questions during the quiz.

---

### **score.txt**

This file stores the score after each game session.
Each entry usually includes:

- player name (optional depending on your implementation)
- the score achieved

**Example format:**

```
Player Score
John 8
Emma 10
```

The program appends new scores after every completed game.

---

## 🛠 Technologies Used

- **C Programming Language**
- **GCC Compiler**
- **File I/O Handling**

---

## 📝 Future Improvements

- Add difficulty levels
- Add timed questions
- Add high-score leaderboard

---
