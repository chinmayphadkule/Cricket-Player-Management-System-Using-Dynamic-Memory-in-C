
# Cricket Player Management System Using Dynamic Memory in C

This project is a **Player Management System** developed in C for managing cricket player records. 
It includes features to add, search, update, and delete player records, and also to display sorted player statistics. 
The system utilizes **dynamic memory management** with `malloc` and `realloc` to efficiently handle player data.

## Table of Contents
- Features
- Getting Started
- Usage
- Technologies Used

## Features
- **Add Player**: Add a new player's details.
- **Search Player**: Search for a player by name or ID.
- **Update Player**: Modify an existing player's details.
- **Delete Player**: Remove a player record.
- **Display Statistics**: View sorted player statistics.
- **Dynamic Memory Management**: Efficiently manage memory allocation using `malloc` and `realloc`.

## Getting Started

### Prerequisites
- GCC compiler for C (or any C compiler of your choice)

### Compilation
To compile the project, run:
gcc main.c player.c -o player_management_system

### Running the Program
After compiling, you can run the program with:
./player_management_system

## Usage
1. **Add Player**: Input player details (name, age, team, etc.) to add them to the system.
2. **Search Player**: Enter the player ID or name to retrieve player information.
3. **Update Player**: Update the details of an existing player.
4. **Delete Player**: Remove a player by ID or name.
5. **Display Sorted Statistics**: View the player statistics in a sorted format (by metrics like runs or wickets).
6. **Exit**: Close the application.

## Technologies Used
- **C Language**: For programming logic and functions
- **Dynamic Memory Management**: Implemented using `malloc` and `realloc` functions

