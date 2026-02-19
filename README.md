🏦 Bank Account Management System
📌 Overview

The Bank Account Management System is a C-based application designed to simulate basic banking operations through a command-line interface.

The system allows users to create accounts, deposit and withdraw money, check account details, and manage customer records efficiently.
This project demonstrates structured programming, file handling, and data management using C.

🚀 Features

🆕 Create new bank accounts

💰 Deposit money

💸 Withdraw money

📊 Check account balance

📄 View account details

❌ Delete account

💾 Persistent storage using file handling

🔐 Basic input validation and error handling

🛠 Technologies Used

C Programming Language

Structures (struct)

File Handling (fopen, fread, fwrite)

Conditional Statements

Loops

Functions (Modular Programming)

Basic Data Validation

📂 Project Structure
├── main.c
├── account.c
├── account.h
├── file_operations.c
├── file_operations.h
└── README.md

🧠 Working Principle

User selects an operation from the menu.

Account details are stored using structures.

Data is saved permanently using binary file storage.

When the program runs again, stored data is retrieved from the file.

Transactions update the balance and overwrite the stored data.

The system ensures that account data remains consistent and persistent across executions.

▶️ How to Compile
gcc main.c account.c file_operations.c -o bank_system

▶️ How to Run
./bank_system

📊 Sample Operations
1. Create Account
2. Deposit Money
3. Withdraw Money
4. Check Balance
5. View Account Details
6. Delete Account
7. Exit

📈 Learning Outcomes

Understanding of structured data using struct

Practical use of file handling in C

Implementing real-world logic like banking transactions

Improving modular and maintainable code design

Handling user input validation and error cases

🔮 Future Improvements

Add password authentication

Transaction history tracking

Interest calculation feature

Admin dashboard

Database integration (MySQL)

GUI version