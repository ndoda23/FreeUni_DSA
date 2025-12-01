https://szkopul.edu.pl/problemset/problem/n986eRgmdL0DsqT2Hn5aFDRs/site/?key=statement


# 🎄 WYB - Selective Bajtazar

> **Polish Olympiad in Informatics (OI)** - Stage III, Day 1  
> Memory Limit: 256 MB | Date: April 6, 2022

## 📋 Problem Description

Bajtazar is decorating his house for Christmas with a garland of **n** light bulbs. Each bulb can be one of five colors (represented by letters `a` through `e`). He wants to modify the colors of bulbs through a series of operations.

### Operation Rules

Each modification operation:
1. Selects two colors `a` and `b`
2. Specifies a count `p`
3. Replaces the **first p occurrences** of color `a` with color `b`

Your task is to simulate the garland's appearance after `m` modifications.

## 🔢 Input Format
```
n m
<string of n characters from a-e>
p₁ a₁ b₁
p₂ a₂ b₂
...
pₘ aₘ bₘ
```

- **Line 1:** Two integers `n` and `m` (1 ≤ n, m ≤ 1,000,000)
  - `n` = number of bulbs
  - `m` = number of operations
- **Line 2:** String of `n` lowercase letters (`a-e`) representing initial bulb colors
- **Next m lines:** Each contains three values separated by spaces:
  - `pᵢ` = number of bulbs to change
  - `aᵢ` = source color
  - `bᵢ` = target color

## 📤 Output Format

Single line containing `n` letters (`a-e`) representing final bulb colors after all operations.

## 💡 Example

### Input
```
10 3
acabbabbac
3 b c
4 a b
3 c a
```

### Output
```
babaabcbbc
```

### Step-by-Step Transformation
```
acabbabbac  (initial state)
    ↓
acaccacbac  (change first 3 'b' to 'c')
    ↓
bcbccbcbbc  (change first 4 'a' to 'b')
    ↓
babaabcbbc  (change first 3 'c' to 'a')
```

## 🧪 Test Cases

| Test | Constraints | Description |
|------|-------------|-------------|
| **1ocen** | n=1000, m=1000 | Alternating changes between colors a↔b (250 bulbs each) |
| **2ocen** | n=90000, m=100000 | Cyclic color rotations (a→b→c→a) with 10000 bulbs each |
| **3ocen** | n=1000000, m=1000000 | Pattern `abcde` repeated 200K times with cyclic transformations |


