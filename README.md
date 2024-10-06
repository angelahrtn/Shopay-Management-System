# Shopay-Management-System
# Project Overview
This project, titled Shopay Management System, was developed as part of my first-semester coursework for the "Algorithm and Programming" class. It was a collaborative group project that aimed to create an application using the C programming language to manage customer and product data efficiently. The project encompasses various key programming concepts, including file handling, sorting algorithms, data validation, and recursion, allowing us to apply our theoretical knowledge in a practical setting.

# Case Description
The Shopay Management System is an application designed to manage customer and product information for a small-scale shop. The system handles customer information such as names, addresses, contact numbers, email addresses, and gender. Additionally, it manages product information, including product names, quantity, weight, price, and payment methods. The application allows users to insert, sort, search, and view data with an easy-to-use command-line interface.

The system is divided into two main modules: Customer Management and Product Management. Each module performs operations such as data entry, data viewing, sorting in ascending or descending order, and file handling to ensure the data persists between sessions. The project aimed to build a functional program that could assist the shop owner in managing business operations effectively, emphasizing user-friendly functionality.

# Objectives
- Implement a management system for customers and products - Develop a program to store, manage, sort, and display customer and product data.
- Practice file handling in C programming - Read and write customer and product data to/from files to ensure data persistence across program runs.
- Implement sorting and searching algorithms - Enable sorting by name, weight, and price, and perform key-based searching to make data retrieval efficient.
- Create a user-friendly interface - Provide an easy-to-use command-line interface to interact with customer and product data, catering to the needs of shop administrators.

# Project Features
The Shopay Management System consists of several features:
1. Main Menu: The user is provided with a menu to select from the following options:
- View Customer Data
- Insert Customer Data
- Search Customer Data
- View Product Data
- Insert Product Data
- Exit

2. Customer Management:
- Users can add new customers by providing validated inputs for names, - addresses, email addresses, gender, and phone numbers.
- Sorting functionality allows customers to be sorted by name in ascending or descending order.
- Search functionality allows users to search for customers by their name.

3. Product Management:
- Users can add new products by providing details such as product name, quantity, weight, price, and payment method.
- Sorting functionality allows products to be sorted by weight or price, both in ascending and descending order.
- The system uses recursion to calculate product quantity in a specific context.

4. Data Persistence:
- Customer and product data are saved to text files (customer.txt and product.txt) to ensure that all information is retained even after the program is closed.

# Implementation Details
- Data Structures: Structures (struct) are used to hold information for both customers and products, ensuring that related information is stored together and easily accessible.
- Sorting Algorithms: The project implements Bubble Sort to sort customer names, product weights, and prices in both ascending and descending orders.
- File Handling: The application reads from and writes to text files to ensure data persistence. This feature allows users to continue managing data without losing previously entered information.
- Validation: Input validation is applied to ensure data integrity, including checks for alphabet-only names, valid email formats, gender selection, and 12-digit phone numbers.
- User Interaction: The program includes a command-line interface that provides clear instructions and feedback to users, making the system accessible for non-technical users.

# Tools and Technologies Used
- Language: C Programming
- Libraries: Standard C libraries such as stdio.h, stdlib.h, string.h, ctype.h

# Challenges
- Input Validation: Ensuring that all inputs met the criteria (e.g., valid phone number, valid gender) required careful implementation of loops and conditions.
- File Handling: Managing file I/O operations to read, write, and append data accurately was a challenge that improved our understanding of persistent storage in C.
- Sorting Efficiency: Implementing sorting algorithms manually helped us understand their efficiency and limitations, especially when working with larger datasets.

# Conclusion
The Shopay Management System project successfully implements a basic system for managing customer and product information for a small shop. It utilizes file handling for data persistence, sorting algorithms for efficient data management, and input validation for data integrity. This project was a valuable learning experience that enhanced my understanding of data structures, file handling, sorting algorithms, and user interaction in C programming. It showcases a practical application of algorithmic thinking to solve real-world problems related to data management.
