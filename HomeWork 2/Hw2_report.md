# 2024 Data Structure - Homework 2: Transpose

A1115530 劉柏均

## Introduce

Given a sparse matrix A, transpose it by the following three methods:

- Using traditional 2-dimensional array representation
- Using the “Transpose” method in the textbook
- Using the “FastTranspose” method in the textbook

## Implement

![Untitled](2024%20Data%20Structure%20-%20Homework%202%20Transpose%2008122834878546428b268b9913da1668/Untitled.png)

將測資傳入A vector 以及 term存入terms vector，並得到terms的大小建立SpareseMatrixy。

再將terms拿出來再放進A_Matrix。

### Traditional 2-dimensional

![Untitled](2024%20Data%20Structure%20-%20Homework%202%20Transpose%2008122834878546428b268b9913da1668/Untitled%201.png)

### Transpose

![Untitled](2024%20Data%20Structure%20-%20Homework%202%20Transpose%2008122834878546428b268b9913da1668/Untitled%202.png)

### Fast Transpose

![Untitled](2024%20Data%20Structure%20-%20Homework%202%20Transpose%2008122834878546428b268b9913da1668/Untitled%203.png)

## Result

### 7_9.out

![Untitled](2024%20Data%20Structure%20-%20Homework%202%20Transpose%2008122834878546428b268b9913da1668/Untitled%204.png)

### 15_12.out

![Untitled](2024%20Data%20Structure%20-%20Homework%202%20Transpose%2008122834878546428b268b9913da1668/Untitled%205.png)

### 60_74.out

![Untitled](2024%20Data%20Structure%20-%20Homework%202%20Transpose%2008122834878546428b268b9913da1668/Untitled%206.png)

### 100_100.out

![Untitled](2024%20Data%20Structure%20-%20Homework%202%20Transpose%2008122834878546428b268b9913da1668/Untitled%207.png)

### 256_512.out

![Untitled](2024%20Data%20Structure%20-%20Homework%202%20Transpose%2008122834878546428b268b9913da1668/Untitled%208.png)

### 721_850.out

![Untitled](2024%20Data%20Structure%20-%20Homework%202%20Transpose%2008122834878546428b268b9913da1668/Untitled%209.png)

## Discussion

各測資使用這三種方法所花費的時間，單位毫秒(ms)

|  | 7_9 | 15_12 | 60_74 | 100_100 | 256_512 | 721_850 |
| --- | --- | --- | --- | --- | --- | --- |
| Traditional 2-dimensional | $0.006$ | $0.004$ | $0.42$ | $0.085$ | $1.177$ | $6.017$ |
| Transpose | $0.001$ | $0.001$ | $0.164$ | $0.394$ | $36.234$ | $211.933$ |
| Fast Transpose | $<1 \mu s$ | $0.001$ | $0.031$ | $0.055$ | $1.094$ | $3.285$ |

由上表可知大部分時候所耗時間Fast Transpose快於traditional 2-dimensional快於Transpose，但在$7*9$  和 $15*12$ 中，Transpose快於traditional 2-dimensional，我執行了很多次結果也是一樣