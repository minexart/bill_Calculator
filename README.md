#bill_Calculator
A coursework project on the fundamentals of programming (part 1). Experimented with a type of grocery billing system.
# 🛒 Fresh Mart Bill Calculator

A C++ console application built as a coursework project for **Fundamentals of Programming (Part 1)**. It simulates a grocery billing system for a fictional store called *Fresh Mart*, complete with a shopping cart and GST-inclusive receipt.

## Features

- **Browse grocery menu** — displays 5 available items with prices in RM
- **Add items to cart** — select items by number and specify quantity
- **View cart** — review everything currently in your basket
- **Remove items** — reduce or remove specific item quantities
- **Clear cart** — reset the cart entirely
- **Checkout & itemised bill** — prints a receipt with subtotal, 6% GST, and total payable amount
- **Input validation** — handles invalid menu choices and non-positive quantities gracefully

## Menu Items

| # | Item | Price (RM) |
|---|------|-----------|
| 1 | Orange | 3.50 |
| 2 | Noodle Cup | 5.00 |
| 3 | Egg | 1.50 |
| 4 | Bread | 2.00 |
| 5 | Yogurt | 2.20 |

> GST rate: **6%** applied to the subtotal at checkout.

## How to Run

### Prerequisites
- A C++ compiler (g++, MSVC, Clang, etc.)

### Compile & Run

```bash
g++ "Bill Calculator Added Features.cpp" -o bill_calculator
./bill_calculator
```

On Windows (MSVC):
```
cl "Bill Calculator Added Features.cpp"
bill_calculator.exe
```

## How It Works

1. Launch the program — the **Main Menu** appears.
2. Choose **1** to browse available grocery items.
3. Choose **2** to add items; enter the item number and desired quantity.
4. Use **3** to review your cart, **4** to remove items, or **5** to clear it completely.
5. Choose **6** to proceed to checkout and print the itemized bill.
6. Choose **0** to exit without checking out.

## Project Context

| | |
|---|---|
| **Course** | Fundamentals of Programming (DOP1253N) — Part 1 |
| **Language** | C++ |
| **Concepts practiced** | Arrays, functions, loops, conditionals, input validation |

## Author

**Aminat Olaide** ([@minexart](https://github.com/minexart))
