#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>   // bool、true、false
#include "leetcode_testing.h"

/** 
 * #1 -- Two Sum
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target. You may assume that each input would have exactly one solution, and you may not use the same element twice. You can return the answer in any order.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int nums[], int numsSize, int target, int* returnSize)
{
    int* array = (int*)malloc(2*sizeof(int));
    array[0] = array[1] = 0;

    if ((NULL == nums) || (numsSize < 0) || (NULL == returnSize))
    {
        return NULL;
    }

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i+1; j < numsSize; j++)
        {
            if (target - nums[i] == nums[j])
            {
                array[0] = i;
                array[1] = j;
                *returnSize = 2;
                return array;
            }
        }
    }
    return array;
}

/** 
 * #9 -- Palindrome
 * Given an integer x, return true if x is a palindrome, and false otherwise.
 */
bool isPalindrome(int x) 
{
    if (x < 0)
    {
        return false;
    }

    int array[32] = {0};
    int count = 0;

    while (x > 0)
    {
        array[count] = x % 10;
        x = x / 10;
        count++;
    }

    int front = 0;
    int back = count - 1;

    while (front < back)
    {
        if (array[front] != array[back])
        {
            return false;
        }
        front++;
        back--;
    }

    return true;
}

bool isPalindrome_fast(int x) 
{
    if (x < 0)
    {
        return false;
    }

    int rev_x = 0;
	int original_x = x;
    while (x > 0)
    {
        rev_x = 10 * rev_x + (x % 10);
        x = x / 10; 
    }

    return rev_x == original_x;
}

int mySqrt(int x) 
{
    int sqr = 1;

    if (x <= 0)
    {
        return 0;
    }

    while ((1.0 * sqr * sqr) < x*1.0)
    {
        sqr++;
    }

    if ((1.0 * sqr * sqr) == x*1.0)
    {
        return sqr;
    }
    else
    {
        return sqr - 1;
    }
}

/** 
 * #27 -- Remove Element
 * Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. 
 * The order of the elements may be changed. 
 * Then return the number of elements in nums which are not equal to val.
 */
int removeElement(int* nums, int numsSize, int val) 
{
    if (NULL == nums || numsSize <= 0)
        return 0;
        
    int newNums[numsSize];
    int count = 0;
    int indexOfNewNums = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == val)
        {
            count += 1;
        }

        if (nums[i] != val)
        {
            newNums[indexOfNewNums] = nums[i];
            indexOfNewNums += 1;
        }
    }

    for (int i = 0; i < indexOfNewNums; i++)
    {
        nums[i] = newNums[i];
    }

    return (numsSize - count);
}

int main()
{
	twoSumTesting();
	isPalindromeTesting();
	mySqrtTesting();

	return 0;
}
