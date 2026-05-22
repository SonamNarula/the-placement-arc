# 🚀 ELITE C++ PLACEMENT PREP — ULTRA IN-DEPTH MASTER NOTES
### CRT / DAT / Placement / Coding Interview / Viva / Debugging Edition
#### Fiat CRT Phase-I | Days 1–4 | Premium Edition

---

> **📌 HOW TO USE THESE NOTES**
> These notes are designed for **mastery, not memorization**. Every concept has intuition, theory, code, traps, MCQs, and viva questions. Read actively — predict every output before looking at the answer. That's how placement toppers are made.

---

# 📘 DAY 1 — C++ BASICS: Data Types · Variables · Operators · I/O

---

## ═══════════════════════════════════════
## SECTION 1 · DATA TYPES
## ═══════════════════════════════════════

### 🧠 1.1 INTUITION + WHY

**Why do data types exist?**

Socho ek box hai. Agar tum usme sand rakhoge, wo ek type ka box hoga. Agar pani rakhoge — different. Computer memory bhi same kaam karta hai. Data type = memory ko batao ki "isme kya rakhunga" aur "kitna jagah chahiye."

| Problem Data Types Solve | Without Data Types |
|---|---|
| Memory allocation | Compiler won't know how many bytes to reserve |
| Operation validation | Can't stop `"hello" * 5` nonsense |
| Value range enforcement | 300 in a `char` = undefined behavior |
| Type safety | Prevents mixing apples and oranges |

**Real-world intuition:**
- `int` = regular count (number of students, score, age)
- `float` = approximate measurement (temperature: 36.6f)
- `double` = precise measurement (GPS coordinates, scientific calculations)
- `char` = single letter (grade 'A', initial 'R')
- `bool` = YES/NO decision (isLoggedIn, isPrime)

**Beginner confusion points:**
- "3.14 is float na?" — **NO! 3.14 is `double` by default. Write `3.14f` for float.**
- "char stores letter, so sizeof = ?" — **1 byte in C++, but 4 bytes in C (stored as int there)**

---

### 📖 1.2 DEEP THEORY

#### Complete Data Type Table with Hidden Facts

| Type | Size | Range | Default Value | Literal Suffix | Hidden Rule |
|------|------|-------|---------------|----------------|-------------|
| `int` | 4 bytes | −2,147,483,648 to 2,147,483,647 | 0 (global/static) | none | Most operations promote to `int` |
| `short` | 2 bytes | −32,768 to 32,767 | 0 | none | Rarely used directly |
| `long` | 4 or 8 bytes | Platform-dependent | 0 | `L` | Use `long long` for safety |
| `long long` | 8 bytes | −9.2×10¹⁸ to 9.2×10¹⁸ | 0 | `LL` | Use for large computations |
| `float` | 4 bytes | ±3.4×10³⁸, ~7 digits precision | 0.0f | `f` or `F` | 3.14 is NOT float |
| `double` | 8 bytes | ±1.7×10³⁰⁸, ~15 digits precision | 0.0 | none (default) | Default floating literal |
| `long double` | 10–16 bytes | Even more precision | 0.0L | `L` | Platform-dependent |
| `char` | 1 byte | −128 to 127 (signed) | 0 | `'x'` | sizeof('A')=1 in C++, 4 in C |
| `unsigned char` | 1 byte | 0 to 255 | 0 | none | No negative values |
| `bool` | 1 byte | true(1) or false(0) | false | `true`/`false` | Any nonzero = true |
| `unsigned int` | 4 bytes | 0 to 4,294,967,295 | 0 | `u` | No negatives! |
| `void` | 0 bytes | No value | — | — | Used for functions returning nothing |

#### Memory Diagram — How Variables Are Stored

```
RAM (Stack Memory)
┌─────────────────────────────────────────────────┐
│  Address  │  Variable  │  Value  │  Bytes Used  │
├───────────┼────────────┼─────────┼──────────────┤
│  1000     │  int a     │  10     │  4 bytes     │
│  1004     │  float f   │  3.14f  │  4 bytes     │
│  1008     │  char c    │  'A'    │  1 byte      │
│  1009     │  bool b    │  true   │  1 byte      │
│  1010     │  double d  │  3.14   │  8 bytes     │
└─────────────────────────────────────────────────┘
```

#### Type Casting — The Critical Distinction

```
IMPLICIT CASTING (done by compiler, data loss possible):
  int → float → double  (safe, widening)
  double → float → int  (UNSAFE, narrowing — data loss!)

EXPLICIT CASTING (done by programmer):
  (float)a    ← casts a to float
  (int)3.9    ← gives 3 (truncates, NOT rounds)
  static_cast<float>(a)  ← C++ style (preferred)
```

**The MOST TESTED casting trap in placements:**

```cpp
int a = 7, b = 2;

float c = a / b;          // Result: 3.0 ← TRAP! Integer division first, THEN stores as float
float d = (float)a / b;   // Result: 3.5 ← CORRECT. Casts a first, then divides
float e = (float)(a / b); // Result: 3.0 ← TRAP! Divides first (=3), then casts 3 to 3.0
```

**Why?** In `a / b`, both are int → int division → result 3. THEN stored in float = 3.0. The cast must happen BEFORE division to get float division.

---

### 📊 1.3 VISUAL EXPLANATION

#### Type Conversion Hierarchy (Widening = Safe, Narrowing = Risky)

```
char → short → int → long → long long → float → double → long double
 ←————————— NARROWING (DATA LOSS RISK) ————————————————————————————
 ————————————— WIDENING (SAFE PROMOTION) ————————————————————————→
```

#### sizeof() Output Table — Frequently Tested

```
sizeof(int)           = 4
sizeof(float)         = 4
sizeof(double)        = 8
sizeof(char)          = 1
sizeof(bool)          = 1
sizeof(long)          = 4 or 8 (platform!)
sizeof(long long)     = 8
sizeof(short)         = 2
sizeof('A') in C++    = 1  ← char
sizeof('A') in C      = 4  ← treated as int in C!
sizeof(true)          = 1
sizeof(3.14)          = 8  ← double literal
sizeof(3.14f)         = 4  ← float literal
```

---

### 💻 1.4 CODE SECTION

#### Beginner Example — Basic Types

```cpp
#include <iostream>
using namespace std;

int main() {
    int age = 20;          // 4 bytes
    float gpa = 8.5f;      // 4 bytes — NOTE: 'f' suffix!
    double pi = 3.14159;   // 8 bytes
    char grade = 'A';      // 1 byte
    bool isPass = true;    // 1 byte

    cout << age << endl;   // Output: 20
    cout << gpa << endl;   // Output: 8.5
    cout << pi << endl;    // Output: 3.14159
    cout << grade << endl; // Output: A
    cout << isPass << endl;// Output: 1 (NOT "true")
    return 0;
}
```

**Line-by-line explanation:**
- `float gpa = 8.5f` — the `f` tells compiler this is float, not double
- `cout << isPass` — bool prints as 1 or 0, NOT "true"/"false" (placement trap!)
- `cout << grade` — prints character 'A', not its ASCII value 65

#### Intermediate Example — Type Casting

```cpp
int a = 7, b = 2;

cout << a/b;              // Output: 3       ← int/int = int
cout << (float)a/b;       // Output: 3.5     ← float/int = float
cout << (float)(a/b);     // Output: 3       ← int/int first = 3, then (float)3 = 3.0 → prints 3

int x = (int)3.99;
cout << x;                // Output: 3       ← truncation, NOT rounding!

unsigned char uc = 300;   // 300 % 256 = 44 (wraps around!)
cout << (int)uc;          // Output: 44
```

#### Tricky Example — The #1 Placement Trap

```cpp
int a = 257;
unsigned char b = a;       // 257 % 256 = 1 (overflow wraps)
cout << (int)b;            // Output: 1

// Memory: char is 1 byte = 8 bits
// 257 in binary = 1 0000 0001
// unsigned char takes last 8 bits: 0000 0001 = 1
```

**Common student mistake:** Thinking `unsigned char b = 257` stores 257. It stores `257 % 256 = 1`.

#### Interview-Style Example

```cpp
// What is the output?
int x = 3;
cout << (x << 2 + 1);  // Answer: 24

// Step-by-step:
// + has higher precedence than <<
// 2 + 1 = 3 first
// Then x << 3 = 3 * 2^3 = 3 * 8 = 24
```

---

### ❓ 1.5 OUTPUT-BASED QUESTIONS

**Q1:**
```cpp
float f = 3.14;
cout << f;
```
> **Output:** `3.14` BUT with a warning! `3.14` is a `double` literal being assigned to `float` — narrowing conversion. The value may not be exact. (In practice, usually prints `3.14`)

---

**Q2:**
```cpp
int a = 5;
cout << (float)(a/2);
cout << " ";
cout << (float)a/2;
```
> **Output:** `2 2.5`
> **Dry Run:**
> - `(float)(a/2)` → `a/2 = 5/2 = 2` (int division), then cast → `2.0` → prints `2`
> - `(float)a/2` → cast `a` to `5.0f` first, then `5.0f/2 = 2.5` → prints `2.5`

---

**Q3:**
```cpp
unsigned int a = 3;
int b = -5;
cout << (a + b > 0 ? "Yes" : "No");
```
> **Output:** `Yes`
> **Dry Run:**
> - Mixing unsigned and signed → `b` is promoted to `unsigned int`
> - `-5` as unsigned int = `4294967291` (wraps around: 2³²−5)
> - `3 + 4294967291 = 4294967294` which is `> 0`
> - So output: `Yes`

**💡 This is the CLASSIC UNSIGNED TRAP. Never mix signed and unsigned!**

---

**Q4:**
```cpp
int a = ~0;
cout << a;
```
> **Output:** `-1`
> **Dry Run:**
> - `~0` flips all bits of 0: `00...0` → `11...1`
> - In 2's complement: `11...1` = `-1`
> - **Formula:** `~n = -(n+1)`, so `~0 = -(0+1) = -1`

---

**Q5:**
```cpp
char c = 'A' + 32;
cout << c;
```
> **Output:** `a`
> **Dry Run:**
> - ASCII of 'A' = 65
> - 65 + 32 = 97
> - ASCII 97 = 'a'
> - **Rule:** Add 32 to uppercase → lowercase. Subtract 32 for reverse.

---

### 🐛 1.6 DEBUGGING SECTION

#### Bug 1 — Float Literal Without Suffix

```cpp
// BUGGY:
float price = 19.99;    // Warning: double → float narrowing

// FIXED:
float price = 19.99f;   // Correct: explicit float literal
```

#### Bug 2 — Integer Division Surprise

```cpp
// BUGGY:
int total = 7, count = 2;
float avg = total / count;  // avg = 3.0 (WRONG!)

// FIXED:
float avg = (float)total / count;  // avg = 3.5 (CORRECT)
```

#### Bug 3 — Overflow in char

```cpp
// BUGGY:
char c = 200;    // signed char max is 127, this overflows!
cout << (int)c;  // Implementation-defined behavior

// FIXED:
unsigned char c = 200;  // 200 fits in 0-255 range
```

#### Bug 4 — sizeof on char literal

```cpp
// In C++ (correct understanding):
cout << sizeof('A');   // Output: 1 ← char type in C++
// In C:
// cout << sizeof('A'); would print 4 ← int type in C
```

---

### 🎤 1.7 INTERVIEW + VIVA SECTION

**Q: What is the difference between float and double?**
> Float = 4 bytes, ~7 decimal digits precision, needs `f` suffix. Double = 8 bytes, ~15 digits precision, default for floating-point literals.

**Q: What happens when you assign 257 to an `unsigned char`?**
> Overflow wraps around: `257 % 256 = 1`. Result is 1.

**Q: sizeof('A') in C vs C++ — why different?**
> In C, character literals are of type `int` (4 bytes). In C++, they are of type `char` (1 byte). A key language distinction.

**Q: Is `float f = 3.14` correct?**
> It compiles but generates a warning. `3.14` is a `double` literal. Use `3.14f` for float or `double f = 3.14` for double.

**Q: What does `(int)3.9` give — 3 or 4?**
> `3`. C++ truncates (cuts toward zero), it does NOT round. `(int)(-3.9)` gives `-3`, not `-4`.

**Q: What is the output of `cout << true`?**
> `1`. Not `"true"`. Use `boolalpha` manipulator to print "true"/"false".

**Tricky Follow-up:** What does `cout << boolalpha << true << noboolalpha` print?
> `true`

**Q: What is implicit type promotion?**
> When operands are of different types, the lower type is promoted to the higher type before operation. E.g., `int + float → float + float`.

---

### 📋 1.8 MCQ SECTION

**MCQ 1:**
```cpp
int a = 5, b = 2;
float c = a / b;
```
What is `c`?
- A) 2.5
- B) 2.0
- C) 3.0
- D) Compilation error

> **Answer: B) 2.0**
> Explanation: `a/b` is int/int = `2` (int). Then `2` stored in float = `2.0`. Not `2.5` because division happens before type conversion.

---

**MCQ 2:** `sizeof('A')` in C++ is:
- A) 4
- B) 2
- C) 1
- D) 8

> **Answer: C) 1**
> In C++ character literals are `char` type = 1 byte. (In C it would be 4 — int type.)

---

**MCQ 3:** What is `~5` in C++?
- A) -5
- B) -6
- C) 4
- D) 6

> **Answer: B) -6**
> `~n = -(n+1)`. So `~5 = -(5+1) = -6`

---

**MCQ 4:** Assertion-Reason
- **Assertion:** `float f = 3.14` may cause precision loss.
- **Reason:** `3.14` is a `double` literal being assigned to a narrower `float` type.

> **Answer: Both A and R are correct, R correctly explains A.**

---

**MCQ 5:** Output of:
```cpp
unsigned char x = 260;
cout << (int)x;
```
- A) 260
- B) 4
- C) 0
- D) Undefined

> **Answer: B) 4**
> `260 % 256 = 4`. Unsigned char wraps around.

---

## ═══════════════════════════════════════
## SECTION 2 · VARIABLES & SCOPE
## ═══════════════════════════════════════

### 🧠 2.1 INTUITION + WHY

**Why does scope exist?**

Imagine ek classroom mein ek student ka naam "Raj" hai. School ke bahar bhi ek "Raj" hai. Scope determines — jab main "Raj" bolun, kaun sa Raj? Variables ka bhi same problem tha — isliye scope aaya.

**What problem it solves:**
- Name collision prevention
- Memory management (local vars auto-destroyed)
- Information hiding (encapsulation foundation)

**Real-world usage:**
- Local scope = function-level variables (cleaned up on return)
- Global scope = app-wide settings (use carefully!)

---

### 📖 2.2 DEEP THEORY

#### Variable Naming Rules

| Rule | Valid Examples | Invalid Examples |
|------|---------------|-----------------|
| Start with letter or `_` | `count`, `_total`, `myVar` | `2ndVal`, `3count` |
| No spaces | `my_var`, `myVar` | `my var` |
| No special chars (except `_`) | `total_2`, `is_prime` | `total@`, `a+b` |
| Case-sensitive | `Age` ≠ `age` ≠ `AGE` | — |
| No keywords | `my_int`, `myFor` | `int`, `for`, `class` |
| No length limit | (compiler-specific, typically 255+) | — |

**Reserved keywords you CANNOT use as variable names:**
`int, float, double, char, bool, if, else, while, for, do, switch, case, break, continue, return, void, class, struct, public, private, protected, new, delete, true, false, nullptr, const, static, extern, inline, ...`

#### Scope Rules — The Complete Picture

```
SCOPE HIERARCHY:
┌────────────────────────────────────────────────┐
│  GLOBAL SCOPE (entire file, all functions)      │
│  ┌──────────────────────────────────────────┐  │
│  │  FUNCTION SCOPE (inside main / any func) │  │
│  │  ┌────────────────────────────────────┐  │  │
│  │  │  BLOCK SCOPE { ... }               │  │  │
│  │  │  ┌────────────────────────────┐    │  │  │
│  │  │  │  INNER BLOCK SCOPE { ... } │    │  │  │
│  │  │  └────────────────────────────┘    │  │  │
│  │  └────────────────────────────────────┘  │  │
│  └──────────────────────────────────────────┘  │
└────────────────────────────────────────────────┘
```

**Key rules:**
1. Inner scope can ACCESS outer scope variables
2. Outer scope CANNOT access inner scope variables
3. Inner scope variable SHADOWS (hides) outer scope variable with same name
4. `::variableName` accesses global variable even when shadowed

---

### 💻 2.3 CODE + DRY RUN

```cpp
#include <iostream>
using namespace std;

int x = 50;    // Global x

int main() {
    int x = 25;    // Local x (shadows global x)
    cout << x;     // Output: 25 (local x)
    cout << ::x;   // Output: 50 (global x via ::)

    {
        int x = 10;    // Inner block x (shadows function x)
        cout << x;     // Output: 10
        cout << ::x;   // Output: 50 (still global)
    }
    // Inner x is DESTROYED here

    cout << x;     // Output: 25 (back to local x)
    return 0;
}
// Full output: 25 50 10 50 25
```

**Memory trace:**

```
After entering main():
  Stack: [x=25 (local)]
  Global: [x=50]

After entering inner block:
  Stack: [x=25 (local)] [x=10 (inner)]
  Global: [x=50]

After exiting inner block:
  Stack: [x=25 (local)]    ← x=10 is POPPED (destroyed)
  Global: [x=50]
```

---

### 🎤 VIVA — Scope Questions

**Q: What is shadowing?**
> When a local variable has the same name as an outer variable, the local one "shadows" (hides) the outer one within its scope.

**Q: How do you access a global variable when a local variable has the same name?**
> Using the scope resolution operator `::`. E.g., `::x` accesses global `x`.

**Q: What is the default value of an uninitialized variable?**
> Local variables: **Garbage value** (undefined behavior). Global and static variables: **automatically initialized to 0** (or null for pointers).

---

## ═══════════════════════════════════════
## SECTION 3 · OPERATORS
## ═══════════════════════════════════════

### 🧠 3.1 INTUITION + WHY

Operators = tools for computation. Bina operators ke, variables sirf boxes hain — unhe kuch karne ke liye operators chahiye.

**Why so many types?**
- Arithmetic: basic math
- Relational: comparisons (True/False decisions)
- Logical: combining conditions
- Bitwise: low-level hardware operations (fast!)
- Assignment: storing results
- Ternary: compact if-else

---

### 📖 3.2 DEEP THEORY — ALL OPERATORS

#### Arithmetic Operators

| Op | Name | Example | Result | Hidden Trap |
|----|------|---------|--------|-------------|
| `+` | Addition | `5 + 3` | `8` | char + int = int |
| `-` | Subtraction | `5 - 3` | `2` | Can be negative |
| `*` | Multiply | `5 * 3` | `15` | Overflow risk |
| `/` | Division | `7 / 2` | `3` | Int division truncates! |
| `%` | Modulus | `7 % 2` | `1` | Only for integers! |

**CRITICAL:** `7/2 = 3` not `3.5` when both are int. This is the #1 tested concept.

#### Pre vs Post Increment — MOST TESTED

```
PRE-INCREMENT (++a):
  1. Increment FIRST
  2. Then use/return value
  Example: a=5, b=++a → a becomes 6, THEN b gets 6
  Result: a=6, b=6

POST-INCREMENT (a++):
  1. Use/return current value FIRST
  2. Then increment
  Example: a=5, b=a++ → b gets 5, THEN a becomes 6
  Result: a=6, b=5
```

**Memory diagram:**
```
int a = 5;
int b = a++;

Step 1: Return a (=5) to b   →  b = 5
Step 2: Increment a          →  a = 6

Final: a=6, b=5

---

int a = 5;
int c = ++a;

Step 1: Increment a          →  a = 6
Step 2: Return a (=6) to c   →  c = 6

Final: a=6, c=6
```

#### Short-Circuit Evaluation — Critical for Placements

**AND (&&):** If LEFT is FALSE, RIGHT is NEVER evaluated
**OR (||):** If LEFT is TRUE, RIGHT is NEVER evaluated

```cpp
int a = 0, b = 5;

// AND short-circuit:
(a && ++b)     // a=0 is FALSE → ++b is SKIPPED → b stays 5!

// OR short-circuit:
(b || ++a)     // b=5 is TRUE → ++a is SKIPPED → a stays 0!

// No short-circuit (bitwise AND):
(a & ++b)      // & is bitwise, NO short-circuit → ++b executes → b=6
```

#### Bitwise Operators — Deep Dive

| Op | Name | How it works | Example | Binary | Result |
|----|------|--------------|---------|--------|--------|
| `&` | AND | 1 only if BOTH bits are 1 | `6 & 3` | `110 & 011` | `010` = 2 |
| `\|` | OR | 1 if EITHER bit is 1 | `6 \| 3` | `110 \| 011` | `111` = 7 |
| `^` | XOR | 1 if bits are DIFFERENT | `6 ^ 3` | `110 ^ 011` | `101` = 5 |
| `~` | NOT | Flip all bits | `~5` | `~0101` | `-6` |
| `<<` | Left Shift | Shift bits left (×2ⁿ) | `3 << 2` | `11 → 1100` | `12` |
| `>>` | Right Shift | Shift bits right (÷2ⁿ) | `12 >> 2` | `1100 → 11` | `3` |

**Quick Formulas:**
- `a << n` = `a × 2ⁿ`
- `a >> n` = `a / 2ⁿ` (integer division)
- `~n = -(n+1)` (always!)
- `n & 1` = check if odd (result 1 = odd, 0 = even)
- `n & (n-1)` = clear rightmost set bit
- `a ^ a = 0` (XOR with self = 0)
- `a ^ 0 = a` (XOR with 0 = same)

**XOR Swap trick:**
```cpp
int a = 5, b = 10;
a ^= b;   // a = 5^10 = 15
b ^= a;   // b = 10^15 = 5
a ^= b;   // a = 15^5 = 10
// Swapped without temp! a=10, b=5
```

---

### 📊 3.3 OPERATOR PRECEDENCE — THE COMPLETE TABLE

> **The single most tested topic in placement exams. Memorize the TOP 3 TRAPS.**

| Priority | Operators | Associativity | Placement Trap? |
|----------|-----------|---------------|-----------------|
| 1 (Highest) | `()` `[]` `->` `.` | Left→Right | — |
| 2 | `++` `--` (postfix) | Left→Right | Post vs Pre |
| 3 | `++` `--` (prefix) `!` `~` `(type)` `sizeof` `-` (unary) | Right→Left | — |
| 4 | `*` `/` `%` | Left→Right | — |
| 5 | `+` `-` | Left→Right | `+` beats `<<`! |
| 6 | `<<` `>>` | Left→Right | `+` beats `<<`! |
| 7 | `<` `<=` `>` `>=` | Left→Right | — |
| 8 | `==` `!=` | Left→Right | `==` beats `&` `^` `\|`! |
| 9 | `&` (bitwise AND) | Left→Right | `==` beats `&`! |
| 10 | `^` (bitwise XOR) | Left→Right | — |
| 11 | `\|` (bitwise OR) | Left→Right | — |
| 12 | `&&` (logical AND) | Left→Right | — |
| 13 | `\|\|` (logical OR) | Left→Right | — |
| 14 | `?:` (ternary) | Right→Left | — |
| 15 | `=` `+=` `-=` `*=` `/=` `%=` `&=` `^=` `\|=` | Right→Left | — |
| 16 (Lowest) | `,` (comma) | Left→Right | Returns LAST value |

#### TOP 3 PRECEDENCE TRAPS 🔴

**Trap 1: `+` beats `<<`**
```cpp
int a = 3;
cout << (a << 1 + 2);    // 1+2=3 first, then a<<3 = 3*8 = 24
// NOT (a<<1)+2 = 6+2 = 8 ← WRONG assumption
```

**Trap 2: `==` beats `&`**
```cpp
int a = 6, b = 3;
cout << (a & b == 2);    // (b==2) first = false(0), then a&0 = 0
// NOT (a&b)==2 = (2)==2 = 1 ← WRONG assumption
```

**Trap 3: `&` beats `|`, both lose to `==`**
```cpp
int a = 5, b = 3;
cout << (a & b | a ^ b);
// Step 1: & first: 5&3 = 001 = 1
// Step 2: ^ next: 5^3 = 110 = 6
// Step 3: | last: 1|6 = 111 = 7
// Output: 7
```

---

### ❓ 3.4 OUTPUT QUESTIONS — OPERATORS

**Q1:**
```cpp
int a = 5;
int b = a++;
int c = ++a;
cout << a << " " << b << " " << c;
```
> **Dry Run:**
> - `b = a++` → b=5, then a=6
> - `c = ++a` → a=7, then c=7
> **Output: `7 5 7`**

**Q2:**
```cpp
int a = 5;
int b = (a *= 2, a + 1);
cout << a << " " << b;
```
> **Dry Run:**
> - Comma operator: evaluate left to right, return last
> - `a *= 2` → a = 10
> - `a + 1` = 11 (this is the returned value)
> - b = 11
> **Output: `10 11`**

**Q3:**
```cpp
int x = 3;
cout << (x << 2 + 1);
```
> **Dry Run:**
> - `+` has higher precedence than `<<`
> - `2 + 1 = 3` first
> - `x << 3 = 3 * 8 = 24`
> **Output: `24`**

**Q4:**
```cpp
int p = 6, q = 3;
cout << (p & q + 1);
```
> **Dry Run:**
> - `+` has higher precedence than `&`
> - `q + 1 = 4` first
> - `p & 4 = 6 & 4 = 110 & 100 = 100 = 4`
> **Output: `4`**

**Q5:**
```cpp
int a = 5;
cout << (a > 2 ? a < 4 ? 10 : 20 : 30);
```
> **Dry Run:**
> - `a > 2` → `5 > 2` → true
> - Now evaluate `a < 4 ? 10 : 20`
> - `a < 4` → `5 < 4` → false → gives 20
> **Output: `20`**

---

### 📋 3.5 MCQ — OPERATORS

**MCQ 1:** What is the output?
```cpp
int a = 0, b = 10;
cout << (a || ++b);
```
- A) 1 (b becomes 11)
- B) 1 (b stays 10)
- C) 0
- D) 10

> **Answer: B) 1 (b stays 10)**
> `a || ++b`: a=0 is false, so RIGHT side IS evaluated. `++b` makes b=11, and the result is truthy → prints `1`. Wait — actually since `a=0` is false, RIGHT side `++b` IS evaluated (short-circuit only skips in OR when LEFT is TRUE). So b=11, result=1. **Answer: A**

**MCQ 2:** `a & b == 2` where `a=6, b=3` evaluates to:
- A) 1
- B) 0
- C) 2
- D) 3

> **Answer: B) 0**
> `==` has higher precedence than `&`. So: `b==2` = `3==2` = 0. Then `a & 0 = 6 & 0 = 0`.

**MCQ 3:** `~0` in C++ gives:
- A) 0
- B) 1
- C) -1
- D) MAX_INT

> **Answer: C) -1**
> `~n = -(n+1) = -(0+1) = -1`

---

## ═══════════════════════════════════════
## SECTION 4 · INPUT / OUTPUT (cin, cout)
## ═══════════════════════════════════════

### 📖 4.1 DEEP THEORY

#### cout Behavior — Every Case

```cpp
int a = 5;
bool b = true;
char c = 'Z';

cout << a;           // 5          (int prints as number)
cout << b;           // 1          (bool prints as 0 or 1, NOT "true"!)
cout << c;           // Z          (char prints as character)
cout << (int)c;      // 90         (ASCII of 'Z')
cout << (char)65;    // A          (ASCII 65 = 'A')
cout << (a > 3);     // 1          (comparison result is bool = 1 or 0)
cout << (a = 10);    // 10         (assignment returns the assigned value)
cout << (a == 10);   // 1          (comparison: true = 1)
```

#### cin Behavior — Traps

```cpp
int n;
cin >> n;   // Reads an integer, stops at whitespace

char ch;
cin >> ch;  // Reads ONE character, skips leading whitespace

string s;
cin >> s;   // Reads ONE word (stops at space!)
getline(cin, s);  // Reads WHOLE LINE including spaces
```

**Common cin Trap:**
```cpp
int n;
char ch;
cin >> n;       // User types: 5\n
cin >> ch;      // Reads 'c' if user types 'c', but...
// After cin>>n, '\n' stays in buffer!
// cin.ignore() needed between int and char input
```

---

### ❓ 4.2 OUTPUT-BASED QUESTIONS — I/O

**Q1:**
```cpp
cout << (5 > 3);
cout << " ";
cout << (5 < 3);
```
> **Output: `1 0`** (bool as 0/1)

**Q2:**
```cpp
int a = 5;
cout << (a = 10) << " " << a;
```
> **Output: `10 10`** Assignment `a=10` returns 10 and also changes a.

**Q3:**
```cpp
cout << (char)(65 + 25);
```
> **Output: `Z`** (65+25=90, ASCII 90='Z')

---

## ═══════════════════════════════════════
## DAY 1 — QUICK REVISION SHEET
## ═══════════════════════════════════════

```
╔══════════════════════════════════════════════════════════════════╗
║              DAY 1 QUICK REVISION — LAST NIGHT CHEAT SHEET       ║
╠══════════════════════════════════════════════════════════════════╣
║  DATA TYPES                                                       ║
║  • int=4B, float=4B, double=8B, char=1B, bool=1B                 ║
║  • 3.14 is double (not float) — need 3.14f for float             ║
║  • sizeof('A')=1 in C++, 4 in C                                  ║
║  • ~n = -(n+1)  |  ~0 = -1                                       ║
╠══════════════════════════════════════════════════════════════════╣
║  CASTING TRAPS                                                    ║
║  • (float)(a/b) ≠ (float)a/b                                     ║
║  • Left: int division first, then cast                            ║
║  • Right: cast first, then float division (CORRECT)              ║
║  • (int)3.9 = 3 (truncation, not rounding)                       ║
╠══════════════════════════════════════════════════════════════════╣
║  INCREMENT                                                        ║
║  • b = a++  →  b gets old value, then a increments               ║
║  • b = ++a  →  a increments first, then b gets new value         ║
╠══════════════════════════════════════════════════════════════════╣
║  SHORT-CIRCUIT                                                    ║
║  • a && b: if a is false, b is SKIPPED                           ║
║  • a || b: if a is true, b is SKIPPED                            ║
╠══════════════════════════════════════════════════════════════════╣
║  PRECEDENCE TRAPS (Most Tested)                                  ║
║  • + beats <<  →  a<<1+2 = a<<(1+2) = a<<3                      ║
║  • == beats &  →  a&b==2 = a&(b==2)                             ║
║  • & beats |   →  a|b&c = a|(b&c)                               ║
╠══════════════════════════════════════════════════════════════════╣
║  SCOPE                                                            ║
║  • Local vars: garbage value if uninitialized                    ║
║  • Global/static vars: auto-initialized to 0                     ║
║  • :: accesses global variable                                   ║
╚══════════════════════════════════════════════════════════════════╝
```

---

---

# 📗 DAY 2 — CONDITIONAL STATEMENTS: if-else · switch · Ternary · break/continue

---

## ═══════════════════════════════════════
## SECTION 5 · IF / ELSE-IF / NESTED IF
## ═══════════════════════════════════════

### 🧠 5.1 INTUITION + WHY

**Why do conditionals exist?**

Real life mein har decision conditional hota hai: "Agar marks >= 60 hai to pass, warna fail." Programs ko bhi decisions lene chahiye — that's what conditionals are for.

**Where used:**
- Validation (is input valid?)
- Game logic (has player won?)
- Business rules (is customer eligible for discount?)
- Error handling (did file open successfully?)

**Beginner confusion:**
- `if` vs `else if` vs separate `if` statements — These are COMPLETELY different!
- Dangling else — which `if` does the `else` belong to?

---

### 📖 5.2 DEEP THEORY

#### Separate if vs else-if Chain — CRITICAL DIFFERENCE

```cpp
// CASE 1: Separate if statements
int x = 100;
if (x >= 50) cout << "A";   // EXECUTES (100 >= 50 is true)
if (x >= 60) cout << "B";   // EXECUTES (100 >= 60 is true)
if (x >= 70) cout << "C";   // EXECUTES (100 >= 70 is true)
// Output: ABC (ALL execute independently)

// CASE 2: else-if chain
if (x >= 50) cout << "A";        // EXECUTES (first match)
else if (x >= 60) cout << "B";   // SKIPPED (first matched already)
else if (x >= 70) cout << "C";   // SKIPPED
// Output: A (ONLY first match executes)
```

**THIS IS THE #1 MOST TESTED TRAP IN PLACEMENT EXAMS.**

#### Dangling Else — The Classic Ambiguity

```cpp
// DANGEROUS (no braces):
if (x > 10)
    if (x > 3)
        cout << "A";
    else
        cout << "B";    // Which if does this belong to?

// ANSWER: else belongs to NEAREST unmatched if (inner if x>3)
// If x=5: x>10 is FALSE → inner if never runs → else NEVER runs → NO output
// If x=15: x>10 TRUE → x>3 TRUE → prints A, else not checked
// If x=11: x>10 TRUE → x>3 TRUE → prints A
// If x=-5: x>10 FALSE → NOTHING prints
```

**Visual Parsing:**
```
if (x > 10)           ← outer if
    if (x > 3)        ← inner if
        cout << "A";
    else              ← belongs to inner if (nearest unmatched)
        cout << "B";
```

#### Assignment (=) vs Comparison (==) in if

```cpp
int x = 0;

// TRAP:
if (x = 5)   // ASSIGNS 5 to x, evaluates to 5 (non-zero = true!)
    cout << "Yes";  // THIS PRINTS! Even though x was 0!

// CORRECT:
if (x == 5)  // COMPARES x with 5
    cout << "Yes";  // Prints only if x is actually 5
```

**How to avoid this bug:** Some compilers warn `if(x = 5)`. Write `if(5 == x)` (Yoda condition) to make it a compile error if you accidentally use `=`.

#### Pre-increment/Post-increment in Conditions

```cpp
int a = 5;
if (++a > 5 && ++a > 6) {  // STEP 1: ++a → a=6, 6>5 TRUE
    cout << a;              // STEP 2: ++a → a=7, 7>6 TRUE
}                           // BOTH true → prints a = 7
// Output: 7

// With post-increment:
int b = 5;
if (b++ > 5 && b++ > 6) {  // STEP 1: b++ → uses 5>5? FALSE (short-circuit!)
    cout << b;              // Not reached
}
// After condition: b=6 (only one increment, right side skipped!)
```

---

### 📊 5.3 VISUAL — IF EXECUTION FLOW

```
if-else-if EXECUTION FLOWCHART:

    START
      │
      ▼
  ┌─────────┐
  │ cond 1? ├──TRUE──→ Execute Block 1 ──→ EXIT
  └─────────┘
      │FALSE
      ▼
  ┌─────────┐
  │ cond 2? ├──TRUE──→ Execute Block 2 ──→ EXIT
  └─────────┘
      │FALSE
      ▼
  ┌─────────┐
  │ cond 3? ├──TRUE──→ Execute Block 3 ──→ EXIT
  └─────────┘
      │FALSE
      ▼
  Execute else block → EXIT

KEY: Once ONE branch executes, ALL others are SKIPPED.
```

---

### 💻 5.4 CODE SECTION

#### Beginner — Grade Calculator

```cpp
int marks = 82;
if (marks >= 90)      cout << "Grade A";
else if (marks >= 80) cout << "Grade B";  // Executes: 82 >= 80 TRUE
else if (marks >= 70) cout << "Grade C";  // Skipped
else if (marks >= 60) cout << "Grade D";  // Skipped
else                  cout << "Fail";     // Skipped
// Output: Grade B
```

#### Intermediate — Leap Year (Nested if)

```cpp
int year = 2000;
if (year % 400 == 0)       cout << "Leap";     // 2000%400=0 → LEAP
else if (year % 100 == 0)  cout << "Not Leap"; // 1900%100=0 but not %400 → NOT LEAP
else if (year % 4 == 0)    cout << "Leap";     // 2024%4=0 but not %100 → LEAP
else                       cout << "Not Leap";  // 2023 → NOT LEAP
```

**Leap year logic table:**

| Year | %400 | %100 | %4 | Result |
|------|------|------|----|--------|
| 2000 | =0 | =0 | =0 | LEAP (400 rule) |
| 1900 | ≠0 | =0 | =0 | NOT LEAP (100 rule) |
| 2024 | ≠0 | ≠0 | =0 | LEAP (4 rule) |
| 2023 | ≠0 | ≠0 | ≠0 | NOT LEAP |

**Critical:** Check `%400` FIRST! If you check `%4` first, 2000 would wrongly enter the 4 branch.

#### Tricky — Assignment in Condition

```cpp
int x = 0;
if (x = 5)      // x is now 5! Non-zero = true
    cout << "Yes";   // Prints: Yes
else
    cout << "No";    // Not reached
cout << x;      // Prints: 5
// Full output: Yes5
```

#### Interview-style — Side Effects in Logical

```cpp
int a = 5, b = 0;
if (b++ || a > 3)
    cout << a << " " << b;

// Step 1: Evaluate b++
//   - b++ returns 0 (post-increment: old value)
//   - Then b becomes 1
// Step 2: 0 is false → check right side of ||
//   - a > 3 → 5 > 3 → true
// Condition true → execute body
// Output: 5 1
```

---

### ❓ 5.5 OUTPUT-BASED QUESTIONS

**Q1 — Dangling Else:**
```cpp
int x = 5;
if (x > 10)
    if (x > 3)
        cout << "A";
    else
        cout << "B";
```
> **Output: (nothing)**
> `x > 10` is false (5 > 10 = false). Inner if never executes. The else belongs to inner if, but since we never entered the outer if, nothing runs.

---

**Q2 — Fall-through Ternary:**
```cpp
int a = 5, b = 10;
int c = (a > b) ? ++a : ++b;
cout << a << " " << b << " " << c;
```
> **Dry Run:**
> - `a > b` → `5 > 10` → false
> - Only `++b` executes (ternary evaluates only chosen branch!)
> - `++b` → b=11, returns 11
> - c = 11
> - a is unchanged = 5
> **Output: `5 11 11`**

---

**Q3 — Comma in if:**
```cpp
int a = 5, b = 10;
if (a > 3, b < 8)
    cout << "Yes";
else
    cout << "No";
```
> **Output: `No`**
> Comma operator evaluates LEFT to RIGHT but returns the LAST value. `a > 3` = true (ignored), `b < 8` = `10 < 8` = false. Condition = false → else branch.

---

**Q4 — Assignment Return:**
```cpp
int x = 0;
if (x = 5) cout << "Yes";
cout << x;
```
> **Output: `Yes5`**
> `x = 5` assigns 5 (returns 5, non-zero = true). Condition is true. Then x=5 is printed.

---

**Q5 — else-if vs separate if:**
```cpp
int x = 100;
if (x >= 50) cout << "A";
else if (x >= 60) cout << "B";
else if (x >= 70) cout << "C";
```
> **Output: `A`**
> else-if chain — first true branch executes. `x>=50` is true → prints A. The other conditions are NEVER checked.

---

### 🐛 5.6 DEBUGGING SECTION

#### Bug 1 — Missing Break Thinking It's if-else

```cpp
// BUGGY - Student thinks this is like if-else:
switch (x) {
    case 1: cout << "A";    // FORGOT break!
    case 2: cout << "B";    // Falls through!
    case 3: cout << "C"; break;
}
// If x=1, output: ABC (not just A!)

// FIXED:
switch (x) {
    case 1: cout << "A"; break;
    case 2: cout << "B"; break;
    case 3: cout << "C"; break;
}
```

#### Bug 2 — Float in Switch

```cpp
// BUGGY:
float grade = 8.5;
switch (grade) {    // ERROR: switch needs int/char/enum!
    case 8.5: cout << "A";
}

// FIXED: Convert to int or use if-else
int g = (int)(grade * 10);  // 85
switch (g) {
    case 85: cout << "A"; break;
}
```

#### Bug 3 — Dangling Else Bug

```cpp
// BUGGY (confusing):
if (a > 0)
    if (b > 0)
        cout << "Both positive";
else
    cout << "a not positive";  // This belongs to inner if, not outer!

// FIXED (use braces):
if (a > 0) {
    if (b > 0)
        cout << "Both positive";
} else {
    cout << "a not positive";  // Now correctly belongs to outer if
}
```

---

## ═══════════════════════════════════════
## SECTION 6 · SWITCH-CASE
## ═══════════════════════════════════════

### 🧠 6.1 INTUITION + WHY

Switch is like a multi-floor elevator — you go directly to your floor (case). Without break, you keep going down past all floors! That's fall-through.

**When to use switch vs if-else:**
| Use Switch | Use if-else |
|-----------|-------------|
| Single variable vs constants | Range checks (x > 10) |
| int, char, enum | float/double comparison |
| Day names, menu options | Complex boolean expressions |
| Faster (jump table internally) | Multiple variables |

---

### 📖 6.2 DEEP THEORY — SWITCH RULES

```
SWITCH EXECUTION MODEL:
┌─────────────────────────────────────────────┐
│  switch (expr)                               │
│  ┌──────────────────────────────────────┐   │
│  │ case 1: ──→ if match, START here     │   │
│  │ [no break] ──→ FALL THROUGH ──┐      │   │
│  │ case 2: ──→                   │      │   │
│  │ break; ──→ EXIT switch ←──────┘      │   │
│  │ case 3: ──→                          │   │
│  │ default: ──→ if no match AND present │   │
│  └──────────────────────────────────────┘   │
└─────────────────────────────────────────────┘
```

**Rules table:**

| Rule | Detail |
|------|--------|
| Expression type | `int`, `char`, `enum`, `bool` ONLY. NO `float`, `double`, `string` |
| case labels | Must be compile-time CONSTANTS. No variables! |
| `break` | Optional. Without it: fall-through to next case |
| `default` | Optional. Can be anywhere (top, middle, bottom) |
| Duplicate cases | NOT allowed → compilation error |
| Variable declaration in case | Allowed but needs `{}` block |

#### Fall-Through Dry Run

```cpp
int x = 2;
switch (x) {
    case 1: cout << "A";    // x≠1, SKIP
    case 2: cout << "B";    // x=2, MATCH! Print B
    case 3: cout << "C";    // NO BREAK above → falls through! Print C
    default: cout << "D";   // NO BREAK above → falls through! Print D
}
// Output: BCD

// WHY: Once execution STARTS at a matching case,
// it continues through ALL subsequent cases until a break or end of switch
```

#### break in switch Inside a Loop — TRAP

```cpp
for (int i = 0; i < 3; i++) {
    switch (i) {
        case 0: cout << "A"; break;   // break exits SWITCH only
        case 1: cout << "B"; break;   // break exits SWITCH only
        case 2: cout << "C"; break;   // break exits SWITCH only
    }
    cout << i;    // This still runs every iteration!
}
// Output: A0 B1 C2
// break did NOT exit the for loop!
```

#### Default Placement — Anywhere!

```cpp
int x = 5;
switch (x) {
    default: cout << "D"; break;    // Default can be FIRST!
    case 1: cout << "A"; break;
    case 5: cout << "E"; break;     // x=5 matches here
}
// Output: E (default not used since x=5 matched case 5)

// But if x=9:
// default runs → Output: D
// Even though default is at top, it executes only when no case matches
```

---

### ❓ 6.3 OUTPUT QUESTIONS — SWITCH

**Q1 — Classic Fall-Through:**
```cpp
int x = 2;
switch(x) {
    case 1: cout<<"A";
    case 2: cout<<"B";
    case 3: cout<<"C"; break;
    default: cout<<"D";
}
```
> **Output: `BC`**
> x=2 matches case 2, prints B. No break → falls to case 3, prints C. Break exits. Default not reached.

**Q2 — Fall-Through Accumulation:**
```cpp
int x = 1, count = 0;
switch(x) {
    case 1: count++;
    case 2: count++;
    case 3: count++; break;
}
cout << count;
```
> **Dry Run:**
> - x=1 matches case 1: count=1
> - No break → case 2: count=2
> - No break → case 3: count=3, then break
> **Output: `3`**

---

## ═══════════════════════════════════════
## SECTION 7 · TERNARY OPERATOR
## ═══════════════════════════════════════

### 📖 7.1 DEEP THEORY

```
SYNTAX: condition ? value_if_true : value_if_false

EVALUATION:
  ┌─────────────┐
  │  condition  │
  └──────┬──────┘
         │
    TRUE ├──→ evaluate and return TRUE-BRANCH
    FALSE└──→ evaluate and return FALSE-BRANCH

CRITICAL: Only ONE branch is evaluated! The other is NEVER touched.
```

**This means side effects in the unexecuted branch DON'T happen:**

```cpp
int a = 5, b = 10;
int c = (a > b) ? ++a : ++b;

// a > b → 5 > 10 → FALSE
// Only ++b executes! ++a is NEVER evaluated
// b = 11, c = 11, a = 5 (unchanged!)
```

#### Nested Ternary — Evaluation Order

```cpp
int marks = 72;
char grade = (marks >= 90) ? 'A' :
             (marks >= 75) ? 'B' :
             (marks >= 60) ? 'C' : 'D';

// Step 1: marks >= 90 → 72 >= 90 → FALSE → go to second
// Step 2: marks >= 75 → 72 >= 75 → FALSE → go to third
// Step 3: marks >= 60 → 72 >= 60 → TRUE → grade = 'C'
// Output: C
```

---

### ❓ 7.2 OUTPUT QUESTIONS — TERNARY

**Q1:**
```cpp
int a = 2, b = 3;
int c = (a > b) ? a++ : (b > 2) ? b++ : 0;
cout << a << " " << b << " " << c;
```
> **Dry Run:**
> - `a > b` → `2 > 3` → false
> - Evaluate: `(b > 2) ? b++ : 0`
> - `b > 2` → `3 > 2` → true
> - `b++` → returns 3 (old value), then b=4
> - c = 3, a unchanged = 2
> **Output: `2 4 3`**

---

## ═══════════════════════════════════════
## SECTION 8 · BREAK & CONTINUE
## ═══════════════════════════════════════

### 📖 8.1 DEEP THEORY

| Feature | `break` | `continue` |
|---------|---------|------------|
| Action | EXITS the loop entirely | SKIPS current iteration, continues loop |
| In switch | Exits switch only | Not applicable in switch |
| In nested loops | Exits ONLY innermost loop | Skips ONLY innermost loop's current iteration |
| After execution | Code after loop runs | Goes back to loop condition check |

#### break in Nested Loops — Memory Map

```cpp
for (int i = 0; i < 3; i++) {      // OUTER loop
    for (int j = 0; j < 3; j++) {  // INNER loop
        if (j == 1) break;          // Exits INNER loop only!
        cout << i << j << " ";
    }
    // Outer loop continues here after inner break
}
// i=0: j=0 prints 00, j=1 breaks
// i=1: j=0 prints 10, j=1 breaks
// i=2: j=0 prints 20, j=1 breaks
// Output: 00 10 20
```

#### Combined break + continue

```cpp
for (int i = 1; i <= 10; i++) {
    if (i % 3 == 0) continue;   // Skip multiples of 3
    if (i % 5 == 0) break;      // Stop at multiples of 5
    cout << i << " ";
}

// i=1: not %3, not %5 → print 1
// i=2: not %3, not %5 → print 2
// i=3: %3==0 → CONTINUE (skip, go to i=4)
// i=4: not %3, not %5 → print 4
// i=5: not %3, %5==0 → BREAK (exit loop)
// Output: 1 2 4
```

---

### 📊 8.2 COMPARISON TABLE

| Feature | `break` | `continue` | `return` | `goto` |
|---------|---------|------------|----------|--------|
| Exits loop | Yes (current) | No | Yes (all) | Depends |
| Continues program | Yes | Yes | To caller | To label |
| Works in switch | Yes | No | Yes | Yes |
| Good practice | Yes | Yes | Yes | AVOID |

---

### DAY 2 — QUICK REVISION SHEET

```
╔══════════════════════════════════════════════════════════════════╗
║              DAY 2 QUICK REVISION — CONDITIONAL STATEMENTS        ║
╠══════════════════════════════════════════════════════════════════╣
║  IF / ELSE-IF TRAPS                                              ║
║  • Separate if = ALL true conditions execute                     ║
║  • else-if = ONLY first true executes                            ║
║  • Dangling else → binds to NEAREST unmatched if                 ║
║  • if(x=5) assigns! Use if(x==5) to compare                     ║
╠══════════════════════════════════════════════════════════════════╣
║  SWITCH TRAPS                                                    ║
║  • No break → FALL-THROUGH (continues to next cases)             ║
║  • break in switch exits SWITCH only (not loop!)                 ║
║  • float/double CANNOT be in switch expression                   ║
║  • default can be anywhere (top/middle/bottom)                   ║
╠══════════════════════════════════════════════════════════════════╣
║  TERNARY TRAP                                                    ║
║  • Only CHOSEN branch executes — other branch has no side effect ║
║  • (a>b)?++a:++b — only ONE of ++a or ++b runs                  ║
╠══════════════════════════════════════════════════════════════════╣
║  BREAK / CONTINUE                                                ║
║  • break: exits CURRENT (innermost) loop/switch                  ║
║  • continue: skips to next iteration of CURRENT loop             ║
║  • break in switch inside loop: exits switch, NOT loop           ║
╠══════════════════════════════════════════════════════════════════╣
║  LEAP YEAR ORDER (MUST): 400 → 100 → 4 → else                   ║
╚══════════════════════════════════════════════════════════════════╝
```
