## 1011 个位数统计 (15)
### 题目描述
给定一个k位整数N = dk-1*10k-1 + ... + d1*101 + d0 (0<=di<=9, i=0,...,k-1, dk-1>0)，请编写程序统计每种不同的个位数字出现的次数。例如：给定N = 100311，则有2个0，3个1，和1个3。
### 输入描述:
每个输入包含1个测试用例，即一个不超过1000位的正整数N。
### 输出描述:
对N中每一种不同的个位数字，以D:M的格式在一行中输出该位数字D及其在N中出现的次数M。要求按D的升序输出。

### 输入例子:
100311

### 输出例子:
0:2

1:3

3:1



## 解题思路

1. 设置一个countr[10]，来对每个数字的出现计数；
2. 将input的整数用%和/运算来校验每一位的数字，并记录到counter中所对应的位置；
```ex: 6 -> counter[6]++;```