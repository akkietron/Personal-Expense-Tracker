# 📜 Personal-Expense-Tracker
Hello everyone!! 👋<br>
[***AkkieTron***](https://linktr.ee/akkietron) this side and This is my first real-project.
<br>
A Personal Expense Tracker that will allow you to calculate and regulate your daily expenses according to your budget for the each and every comodity you'll need.
<br>
<br>

A lightweight, persistent command-line application built in C++ to help track personal daily expenses. Features auto-saving, formatted terminal output, and simple data parsing using a delimiter-based text storage format.

---

## Features

- **Add Expenses:** Log new spending with an auto-incremented ID, category, numerical amount, and multi-word descriptions.
- **Persistent Data:** Save expenses automatically to `Expenditures.txt` and load historical data seamlessly on application start.
- **View Expense History:** Display logged expenses in a structured column layout right in the terminal.
- **Spending Summary:** Compute and display total expenditure with accurate floating-point formatting.
- **Input Validation:** Guard against invalid user inputs to prevent crashes.

---

## File Format

Data is preserved in `Expenditures.txt` using a pipe-delimited format (`|`):

```text
1|Food|12.50|Lunch at cafe
2|Transport|5.00|Bus pass ticket
3|Utilities|45.20|Monthly internet bill