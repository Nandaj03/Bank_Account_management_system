🎵 MP3 Tag Reader and Editor
📌 Overview

MP3 Tag Reader and Editor is a C-based application designed to read and modify metadata (ID3 tags) of MP3 files.
The project allows users to view and edit essential audio metadata such as Title, Artist, Album, Year, Genre, and Comments.

This tool works directly with the binary structure of MP3 files and demonstrates low-level file handling, string manipulation, and structured data processing in C.

🚀 Features

📖 Read ID3v2 tags from MP3 files

✏️ Edit metadata fields:

Title

Artist

Album

Year

Genre

Comments

🛠 Binary file processing using fread() and fwrite()

📂 Command-line based interface

🧠 Efficient memory management

🛠 Technologies Used

C Programming Language

File Handling (fopen, fread, fwrite)

Structures

Bitwise Operations

String Handling Functions

Modular Programming

📂 Project Structure
├── main.c
├── tag_reader.c
├── tag_editor.c
├── common.h
├── types.h
└── README.md

🧠 Working Principle

MP3 files store metadata in ID3 format.
This project:

Opens the MP3 file in binary mode.

Locates the ID3 header.

Reads frame headers (e.g., TIT2, TPE1, TALB).

Extracts frame size and content.

Displays or modifies the selected tag.

Writes the updated data back into the file.

▶️ How to Compile
gcc main.c tag_reader.c tag_editor.c -o mp3_tag_editor

▶️ How to Run
./mp3_tag_editor -v song.mp3


To edit a tag:

./mp3_tag_editor -e title "New Title" song.mp3

📈 Learning Outcomes

Deep understanding of binary file structures

Working with ID3v2 metadata format

Handling dynamic memory safely

Improving debugging and error handling skills

Designing modular and maintainable C programs

🔍 Future Improvements

Add support for ID3v1 tags

GUI-based version

Batch editing multiple files

Support for album art extraction

Cross-platform build system using Makefile