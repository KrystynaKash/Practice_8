#include <stdio.h>
#include <string.h>
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}
unsigned long long countAnagrams(char* word) {
    int length = strlen(word);
    unsigned long long numerator = factorial(length);
    int frequency[256] = {0};  
    for (int i = 0; i < length; i++) {
        frequency[(int)word[i]]++;
    }

    unsigned long long denominator = 1;
    for (int i = 0; i < 256; i++) {
        if (frequency[i] > 1) {
            denominator *= factorial(frequency[i]);
        }
    }

    return numerator / denominator;
}
int main() {
    char word[15];  
    printf("Введіть слово (максимальна довжина 14): ");
    scanf("%14s", word);
    unsigned long long result = countAnagrams(word);
    printf("Кількість можливих анаграм: %llu\n", result);
    return 0;
}
