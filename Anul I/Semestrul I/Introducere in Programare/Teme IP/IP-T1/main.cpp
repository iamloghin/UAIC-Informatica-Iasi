#include "t1.h"
#include <iostream>
using namespace std;
unsigned long int maxDiv;
int main() {
	vector vec;
	vec.length = 5;
	int valori[] = { 0, 1, 1, 2, 3 };
	for (int i = 0; i < vec.length; i++) {
		vec.values[i] = valori[i];
	}
	cout << areOrderedFibonnaci(vec);
	cin.get();
    return 0;
}

bool isPalindrom (unsigned long long number) {
    unsigned long long numberCopy = number, palindrome = 0;

    while (number) {
        palindrome *= 10;
        palindrome += number % 10;
        number /= 10;
    }

    return palindrome == numberCopy;
}

unsigned char sumBinaryFigure (unsigned long long number) {
    unsigned char sum = 0;

    while (number > 0) {
        sum += number % 2;
        number /= 2;
    }

    return sum;
}

bool isLeapYear (unsigned short year) {
    if (year % 4) {
        return false;
    }

    if (year % 100) {
        return true;
    }

    if (year % 400) {
        return false;
    }

    return true;
}

unsigned char dayOfTheWeek (unsigned short year, unsigned char month, unsigned char day) {
    int q, m, k, j, h;

    if (month == 1) {
        month = 13;
        year--;
    }

    if (month == 2) {
        month = 14;
        year--;
    }

    q = day;
    m = month;
    k = year % 100;
    j = year / 100;
    h = q + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j;
    h = h % 7;
    h += 5;
    return h % 7 + 1;
}

unsigned int fibonnaci (int index) {
    unsigned int fibOne = 0, fibTwo = 1, fibThree, counter;

    switch (index) {
        case 0:
            return fibOne;
			break;
        case 1:
            return fibTwo;
			break;
        default:
            for (counter = 2; counter <= index; counter++) {
                fibThree = fibOne + fibTwo;
                fibOne = fibTwo;
                fibTwo = fibThree;
            }
    }

    return fibThree;
}

unsigned long perfectNumbers (unsigned int number) {
    int index, finalSum = 0, tempSum, divisorIndex;
    bool foundBoth = false, foundOne = false;

    for (index = number; !foundBoth; index-- ) {
        tempSum = 0;
        divisorIndex = 1;

        while (divisorIndex <= index / 2) {
            if (! (index % divisorIndex) ) {
                tempSum += divisorIndex;
            }

            divisorIndex += 1;
        }

        if (tempSum == index) {
            finalSum += tempSum;

            if (foundOne) {
                foundBoth = true;
                return finalSum;
            } else {
                foundOne = true;
            }
        }
    }
}

unsigned short primeDivisors (unsigned int left, unsigned int right) {
	const int upperLimit = right;
	bool ciur[150000];

    for (int index = 0; index <= right; index++) {
        ciur [index] = true;
    }
    int i, j;
    for (i = 2; i <= right; i++)
        if (ciur[i] == 1)
            for (j = 2; j * i <= right; j++)  ciur[i * j] = false;
    int maximum = 0, maxCount = 0, primeDivisorCount;
    unsigned long int index, primeIndex;
    for (index = left; index <= right; index++) {
        primeDivisorCount = 0;
        for (primeIndex = 2; primeIndex <= index / 2; primeIndex++) {
            if (ciur[primeIndex] && (index % primeIndex == 0)) {
                primeDivisorCount++;
            }
        }
        if (primeDivisorCount > maximum) {
            maximum = primeDivisorCount;
			maxDiv = maximum;
            maxCount = 1;
        } else {
            if (primeDivisorCount == maximum) {
                maxCount++;
            }
        }
    }
    return maxCount;
}

matrix primeTwins(unsigned int count, unsigned int lowerBound) {
	unsigned int currentNumber = lowerBound % 2 ? lowerBound + 2 : lowerBound + 1, numberOfPairs = 0;
	bool foundPair = false;
	matrix result;
	result.lines = count;
	result.columns = 2;
	unsigned int sum = currentNumber * 2 + 2, higherPrime = currentNumber + 2, index;
	while (numberOfPairs < count) {
		higherPrime = sum / 2 + 1;
		foundPair = true;
		for (index = 2; index < higherPrime / 2; index++) {
			if (higherPrime % index == 0 || (higherPrime - 2) % index == 0) {
				foundPair = false;
				break;
			}
		}
		if (foundPair) {
			result.values[numberOfPairs][0] = higherPrime - 2;
			result.values[numberOfPairs][1] = higherPrime;
			numberOfPairs++;
		}
		sum += 4;
	}
	return result;
}

bool areOrderedFibonnaci(vector vec) {
	if (vec.values[0] != 0) {
		return false;
	}
	int sum = vec.values[1], index;
	for (index = 1; index < vec.length; index++) {
		if (fibonnaci(index) != vec.values[index]) {
			return false;
		}
	}
	return true;
}