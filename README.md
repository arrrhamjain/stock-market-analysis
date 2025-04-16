📈 Stock Market Analyst
A simple yet powerful command-line based Stock Portfolio Management System built in C++. This application allows users to manage their stock holdings by adding new stocks, updating prices, viewing the portfolio, and calculating the total value of their investments.

🛠️ Features
🔹 Add Stock: Add a new stock to your portfolio or update an existing one.

🔹 Update Stock Price: Modify the current market price of any stock in the portfolio.

🔹 Display Portfolio: View a neatly formatted table of all stocks owned.

🔹 Total Portfolio Value: Calculate the cumulative market value of your portfolio in real-time.

🔹 User Input Validation: Robust checks to ensure accurate data entry.

🚀 Getting Started
Prerequisites
A C++ compiler (e.g., g++)

Basic knowledge of C++ and command-line operations

Compilation
bash
Copy
Edit
g++ -o stock_market stock_market.cpp
Running the Application
bash
Copy
Edit
./stock_market
📋 Usage
Upon running, you’ll be presented with a menu:

mathematica
Copy
Edit
Stock Market Application Menu:
1. Add Stock
2. Update Stock Price
3. Display Portfolio
4. Calculate Total Portfolio Value
5. Exit
Select an option by entering the corresponding number.

Follow the prompts to input stock details or view results.

🧩 Code Structure
Stock Class: Represents individual stock items with attributes like name, price, and quantity.

Portfolio Class: Handles the logic of managing multiple stocks, including adding, updating, displaying, and evaluating total value.

Main Function: Provides a user interface and ties together all functionalities with menu-driven logic.

📦 Example Output
markdown
Copy
Edit
Stock Portfolio:
------------------------------------------------
Name           Current Price     Quantity  
------------------------------------------------
AAPL           182.90            10        
TSLA           695.30            5         
------------------------------------------------
Total Portfolio Value: $7748.00
💡 Future Enhancements
📊 Integrate graphical UI using Qt or ncurses

🌐 Fetch real-time prices from APIs

🧠 Add basic analytics like gain/loss and historical trends

🔐 Implement user authentication and multiple portfolios

👨‍💻 Author
Arham Jain
Student @ VIT Bhopal | Passionate about AI, Finance, and Software Engineering

📜 License
This project is open source and free to use for educational and personal purposes.
