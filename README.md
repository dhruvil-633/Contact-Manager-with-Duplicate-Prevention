
# Contact Management System in C

This program implements a basic contact management system using linked lists in C. It allows users to create, delete, search, and edit contacts interactively.

### Author:
- **Author**: Dhruvil Patel

### License:
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

### Files:
- **ContactManger.c**: Contains the main program logic and function implementations.
- **README.md**: This file. Provides an overview of the program's functionality and usage instructions.

### Compilation:
To compile the program, use a C compiler such as GCC:
```
gcc main.c -o contact_manager
```

### Usage:
Run the compiled executable `contact_manager`. The program presents a menu-driven interface for interacting with the contact list.

### Functionality:

1. **Create new contact** (`Create` function):
   - Prompts the user to enter a name and phone number.
   - Checks for duplicates based on phone number.
   - Adds the new contact to the end of the linked list.

2. **Delete existing contact** (`Delete` function):
   - Prompts the user to enter a phone number to delete.
   - Searches for the contact with the specified phone number and deletes it if found.

3. **Edit existing contact** (`Edit` function):
   - Prompts the user to enter a phone number to edit.
   - Searches for the contact with the specified phone number and allows the user to update the contact's name.

4. **Search existing contact** (`Search` function):
   - Allows searching contacts either by name or phone number.
   - Displays the corresponding contact information if found.

5. **Exit**:
   - Terminates the program.

### Structure:
- **struct contact**: Defines a structure for each contact, containing fields for name, phone number, and a pointer to the next contact (for linking in a linked list).

### Notes:
- The program handles memory allocation for new contacts using `malloc`.
- It includes error handling for memory allocation failures.
- Basic input validation is done for user inputs to handle incorrect data types.

### About Me:
Hello! I am Dhruvil Patel, the developer of this Contact Management System. This project aims to provide a simple yet effective way to manage contacts using the C programming language. It utilizes the concept of linked lists for dynamic memory allocation, ensuring efficient storage and management of contact information. One notable feature is its ability to prevent duplicate entries, which is crucial for modern contact management systems to save space and time. By checking for duplicates based on phone numbers, the program ensures that each contact is unique, thus optimizing the efficiency of the contact database.

### Contributions:
Feel free to contribute to this project by:
- Reporting bugs
- Providing suggestions for improvements
- Adding new features

### Forking:
To contribute, fork this repository, make your changes, and submit a pull request. Your contributions are highly appreciated!

### Example Usage:
```
$ ./contact_manager
Select from the following operations:
1) Create new contact
2) Delete existing contact
3) Edit existing contact
4) Search existing contact
5) Exit
```

### Improvements:
- Add more robust error handling and input validation.
- Implement sorting of contacts by name or number.
- Persist contacts by saving them to a file/database.

