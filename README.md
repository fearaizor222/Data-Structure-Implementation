
# Data Structure
All of the Data structure I'll be implementing is written in C++

## DArray
- Short for Dynamic Array.
- Based on std::vector.
- Most of the methods are based on Python's list.
- Overview:
    - ### Constructors:
        ```C++
        int array[7] = {4, 2, 0, 6, 9};
        DArray<float> array1;                // Example 1
        DArray<int> array2(10);              // Example 2
        DArray<int> array3(10, 6);           // Example 3
        DArray<int> array4(array, 10);       // Example 4
        DArray<int> array5({6, 9, 4, 2, 0}); // Example 5
        DArray<int> array6 = array4;         // Example 6
        ```
        - Ex1 will make an array of type float, with length 0.
        - Ex2 will make an array of type int, length 10 with all elements equal to 0.
        - Ex3 will make an array of type int, length 10 with all elements equal to 6.
        - Ex4 will make an array of type int, length 10 with first 5 elements equal to {4, 2, 0, 6, 9}, 5 last elements will equal to 0.
        - Ex5 will make an array of type int, length 5 with all 5 elements equal to {6, 9, 4, 2, 0}.
        - Ex6 will make an array of type int, length and elements equal to array4.

    - ### Methods:
        #### 1. assign(C-Style array | DArray<type> array | { }): assign an C-style array, DArray, fixed array to a DArray.
        ```C++
        DArray<int> array1 = {2, 5, 9, 2, 0, 0, 3};
        DArray<int> array2;
        array2.assign(array1);    // Example 1

        float array[10] = {1, 2, 3, 4};
        DArray<float> array3;
        array3.assign(array, 4);  // Example 2

        DArray<float> array4;
        array4.assign({1, 2, 3});
        ```
        - Ex1: Assign all elements from array1 to array2, array2's length will equal array1's length.
        - Ex2: Assign all elements from array to array3, array3's length will equal 4.
        - Ex3: Assign all elements from {1, 2, 3} to array4, array4's length will equal 3.
        ---
        #### 2. resize(): resize the array.
        ```C++
        DArray<int> array = {2, 6, 1, 2, 1, 9, 7, 5};
        array.resize(3);
        array.resize(10);
        ```
        - array's size will be 3 and will discard {2, 1, 9, 7, 5}.
        - array's size will be 10 and will look like {2, 6, 1, 0, 0, 0, 0, 0, 0, 0}.
        ---
        #### 3. range(int start, int end): return a modified copy of the array from selected range.
        ```C++
        DArray<int> array = {3, 1, 1, 1, 9, 8, 0};
        DArray<int> array1 = array.range(3, 7);
        ```
        - array1 will look like {1, 1, 9, 8, 0}.
        ---
        #### 4. size(): return size of the array.
        ```C++
        std::cout << array.size;
        ```
        ---
        #### 5. at(int index) and [] operator: return value at chosen index.
        ```C++
        std::cout << array.at(0) <<std::endl;   // Example 1
        std::cout << array.at(3) <<std::endl;   // Example 2
        std::cout << array.at(-1) <<std::endl;  // Example 3
        std::cout << array.at(-2) <<std::endl;  // Example 4
        std::cout << array[3] <<std::endl;      // Example 5
        std::cout << array[-1] <<std::endl;     // Example 6
        ```
        - Ex1 will return value at index 0.
        - Ex2 will return value at index 3.
        - Ex3 will return value at index length - 1.
        - Ex4 will return value at index length - 2.
        - Ex5 will return value at index 3.
        - Ex6 will return an error.
        ---
        #### 6. indexOf(type number): return index of the first occurrence of number, if there is none then return -1.
        ```C++
        std::cout << array.indexOf(7) << std::endl;
        ```
        ---
        #### 7. swap(int dest1, int dest2): swap 2 elements at index dest1 and index dest2.
        ```C++
        array.swap(3, 6);
        ```
        ---
        #### 8. fill(type number): fill in from start to end with the chosen number.
        ```C++
        DArray<int> array = {1, 2, 3};
        array.fill(7);
        ```
        - array will look like {7, 7, 7}.
        ---
        #### 9. fill_n(type number, int time): fill in number of time from start with chose number.
        ```C++
        DArray<int> array = {1, 2, 3, 4, 5};
        array.fill(7, 3);
        ```
        - array will look like {7, 7, 7, 4, 5}.
        ---
        #### 10. extend(DArray<type> array): append DArray to original array.
        ```C++
        DArray<int> array1 = {1, 2, 3};
        DArray<int> array2 = {1, 2, 3};
        array1.extend(array2);
        ```
        - array1 will look like {1, 2, 3, 1, 2, 3}.
        ---
        #### 11. addBack(type number): append value to the back of the array.
        ```C++
        DArray<int> array = {1, 2, 3};
        array.addBack(7);
        ```
        - array will look like {1, 2, 3, 7}.
        ---
        #### 12. addFront(type number): append value to the front of the array.
        ```C++
        DArray<int> array = {1, 2, 3};
        array.addFront(7);
        ```
        - array will look like {7, 1, 2, 3}.
        ---
        #### 13. addIndex(type number, int index): insert value to the chosen index of the array.
        ```C++
        DArray<int> array = {1, 2, 3};
        array.addIndex(7, 1);     // Example 1
        array.addIndex(10, 100);  // Example 2
        ```
        - Ex1: array will look like {1, 7, 2, 3}.
        - Ex2: will throw an error because array doesn't have index 100th.
        ---
        #### 14. deleteBack(): delete value to the back of the array.
        ```C++
        DArray<int> array = {1, 2, 3};
        array.deleteBack();
        ```
        - array will look like {1, 2}.
        ---
        #### 15. deleteFront(): delete value to the front of the array.
        ```C++
        DArray<int> array = {1, 2, 3};
        array.deleteFront();
        ```
        - array will look like {2, 3}.
        ---
        #### 16. deleteIndex(int index): delete value to the chosen index of the array.
        ```C++
        DArray<int> array = {1, 2, 3};
        array.deleteIndex(1);     // Example 1
        array.deleteIndex(100);   // Example 2
        ```
        - Ex1: array will look like {1, 3}.
        - Ex2: will throw an error because array doesn't have index 100th.
        ---
        #### 17. clear(): delete everything and reset length to 0.
        ```C++
        DArray<int> array = {100, 200, 300};
        array.clear();
        ```
        - array won't have any element left.
        ---
        #### 18. print(): simply print all the value of the array (recommend for debugging only).
        ```C++
        DArray<int> array = {1, 2, 3};
        array.print();
        ```
        - Output: 1 2 3 \n
        ---
## LinkedList

### TO BE CONTINUE

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.
