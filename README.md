# 🧙‍♂️ Word Count Wizard

This C++ project is a **command-line tool** for analyzing word frequency from a `.txt` file using a custom-built **hash table** with **chaining**, **max-heap tracking**, and **six different hash functions**. It calculates:

- Total number of words
- Number of unique words
- Number of collisions
- Most frequent word

---

## 📁 File Structure

📦 Project/ ├── main.cpp # CLI interface ├── hashtable.h/.cpp # Hash table with 6 hash functions ├── linkedlist.h/.cpp # Singly linked list for collision chaining ├── maxheap.h/.cpp # MaxHeap to track the most frequent word ├── makefile # Build configuration └── Report.pdf # Full documentation and analysis


---

## 🚀 Features

- 📂 Import and process `.txt` files
- ⚙️ Choose from 6 different hash functions
- 🔍 Find frequency of any word
- 📈 Track the most frequent word using a heap
- 📊 View statistics: total words, unique words, collisions

---

## 🔢 Available Hash Functions

| Index | Hash Function                     | Description                               |
|-------|-----------------------------------|-------------------------------------------|
| 0     | PolyCyclicHash (Default)          | Polynomial + Cycle Shift Hash (MAD method)|
| 1     | PolynomialHash                    | Traditional polynomial hash               |
| 2     | SummationHash                     | Basic ASCII sum hash                      |
| 3     | CycleShiftHash                    | Bitwise cyclic shift hash                 |
| 4     | SumCyclicHash                     | Summation + Cycle Shift                   |
| 5     | SumPolyHash                       | Summation + Polynomial                    |

> 📘 Full explanations and pseudocode are available in [`Report.pdf`](./Report.pdf)

---

## 🧪 Experimental Results (from Report.pdf)

| Hash Function                 | Compression | Collisions |
|------------------------------|-------------|------------|
| PolyCyclicHash (default)     | MAD         | 652        |
| SumPolyHash                  | MAD         | 663        |
| CycleShiftHash               | Division    | 667        |
| Others                       | -           | Varies     |

---

## 💻 How to Compile and Run

### 🛠️ Compile

```bash
make

How to run
./main
