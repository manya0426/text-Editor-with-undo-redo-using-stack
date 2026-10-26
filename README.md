Text Editor with Undo/Redo Using Stack in C
Project Description

This project implements a simple text editor in C using the Stack data structure. It allows users to add text, display the current text, undo the last operation, redo an undone operation, and clear the text.

Objectives
To understand the Stack data structure.
To implement Undo and Redo operations using stacks.
To manage text changes efficiently.
To develop a menu-driven application using C programming.
Features
Add text to the editor.
Display the current text.
Undo the previous operation.
Redo the undone operation.
Clear all text.
Menu-driven interface.
Technologies Used
Programming Language: C
Data Structure: Stack
Concepts: Arrays, Structures, Functions, LIFO (Last In, First Out)
Data Structure Used

Two stacks are used:

Undo Stack: Stores previous text states so changes can be reversed.
Redo Stack: Stores text states that can be restored after undoing.

When a new edit is performed, the redo stack is cleared.

How to Run
Download or clone this repository.
Open a terminal in the project folder.
Compile the program using GCC:

gcc main.c -o text_editor

Run the program:

./text_editor

On Windows, use:

text_editor.exe

Menu Options
Add Text
Display Text
Undo
Redo
Clear Text
Exit
Example
Add text: Hello
Add text: World
Current text: Hello World
Undo: Hello
Redo: Hello World
Applications
Text editors
Document editing systems
Undo/Redo functionality in software applications
Learning stack operations in data structures
Future Enhancements
Delete selected text.
Save and load text files.
Add cursor-based editing.
Implement a graphical user interface.
Author

Student Project

License

This project is intended for educational purposes.
