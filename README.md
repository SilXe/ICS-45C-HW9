# ICS 45C Homework 9

Revisiting STL containers and iterators

## Getting the assignment

1. Accept the assignment by clicking the link in Canvas
2. Once you accept the invite, you will reach a page that says "You're ready to go"
3. Click the URL from that page that looks similar to this: `https://github.com/klefstad-teaching/ics-45c-hw9-<YourGitHubUsername>`. It may take a bit of time for the repo to be ready.
4. Click the green `<> Code` Button on the top right, and then click the middle tab `SSH`
5. Copy that link
6. Go to your hub and go into the ICS45C folder, and open up the terminal and type in the following command:
```bash
git clone git@github.com:klefstad-teaching/ics-45c-hw9-<YourGitHubUserName>.git HW9
```
7. Go to VSCode and open up the `HW9` Folder


## Overview and Objectives

For Homework 9, you write another version of `mapset` from your Homework 8 Program 2, but this time you write your own implementations of **`std::set`** and **`std::map`**, in order to understand STL containers and iterators in a deeper level of detail. Homework 9’s `mapset` has the same behavior as your Homework 8 `mapset`, that counts the frequency of words in an input file, while excluding stop words in a stopwords file. But for Homework 9, you write your own implementations that replace `std::set` and `std::map` with class `SetList` and class `MapArray` (as well as their respective iterators).

Class `SetList` holds the excluded stop words, as did `std::set`. `SetList` is implemented as a **singly-linked list of type `T`**.

Class `MapArray` is a dictionary that holds the frequencies of words, instead of using `std::map`. Class MapArray is implemented as an **`std::vector` of `std::pairs`**.

### Relation to Course Objectives

Homework 9 implements containers with their iterators to work with the STL. Substituting your containers and iterators into your previously written `mapset.cpp` program demonstrates the interchangeability of implementations, and shows how the STL can be extended and customized.

Homework 9 also provides one more opportunity to practice coding a singly-linked list 🙂 and to use an `std::vector`, which behaves much like an array, but can grow larger when necessary. Fluency in C++ programming with singly-linked list and with arrays is a prerequisite skill for ICS 46 Data Structures.

### Further Resources:

[set](https://en.cppreference.com/w/cpp/container/set)
[map](https://en.cppreference.com/w/cpp/container/map)
[iterator](https://en.cppreference.com/w/cpp/iterator/iterator)
[iterator_traits](https://en.cppreference.com/w/cpp/iterator/iterator_traits)
[vector](https://en.cppreference.com/w/cpp/container/vector)

## Organization of Classes and Files

> *Be sure to use **exactly** the names given in these instructions and provided on the GitHub hw9 repo for **files**, **functions**, and **classes**, because the autograder will be expecting exactly those names.*

## 1 Class SetList

Class `SetList`, defined in a single file named `set_list.hpp`, is an STL template container that implements the functionality of `std::set` that you used in your own Homework 8.

Class SetList is implemented as a singly-linked list of type T.
- `SetList` has one data member `head`, which is a [std::shared_ptr](https://www.youtube.com/watch?v=UOB7-B2MfwA) to a `ListNode`
- `ListNode` must also be a template, to work with the template `SetList`.
- `ListNode` must be nested inside `SetList`.
- Each `ListNode` has data members data and next, as did your singly linked lists in previous Homeworks.

Implement a class iterator inside class `SetList` that allows [forward iteration](https://cplusplus.com/reference/iterator/ForwardIterator/) through a `SetList`. It must satisfy the assertion
  `static_assert(std::forward_iterator<iterator>);`

### What you do **not** need to implement

You do not need to write all possible methods for a general STL container. You need only write the methods, operators, and iterators given in the screenshots and that you used in your Homework 8 `mapset.cpp`.

`std::set` keeps its items in ascending alphabetical order, but you do not need to implement alphabetical sorting for your class `SetList`.

**Be sure to follow the [Steps of Development](#steps-of-development) below. Some relevant details may be provided only in the Steps.**

set_list.hpp screenshot

![set_list.hpp screenshot](/assets/1-1.png)

## 2 Class MapArray

Class `MapArray`, defined in a single file named `map_array.hpp`, replaces the functionality of `std::map` as used in your Homework 8.

The elements of `MapArray` must be `pair<Key,Value>`, where `Key` and `Value` are typename template parameters.

An iterator inside class `MapArray` allows [random access](https://cplusplus.com/reference/iterator/RandomAccessIterator/) iteration through it.  It must satisfy the assertion  
  `static_assert(std::random_access_iterator<iterator>);`

`std::map` stores items in a binary search tree, which keeps them in ascending alphabetical order by key; yours must keep them sorted as well, because mapset must print out the frequencies in order by key. Do not use `sort()`. Instead, keep the list in sorted order by inserting each new item in its proper place, so that the previous key is less than and the next key is greater than this key being inserted. Note that there is a useful STL algorithm for finding where to insert the new key. Find it and use it, but don’t tell anyone else what it is. Let everyone figure it out for themselves. 🙂

Note: a very similar container was added to the STL in C++23 under the name [std::flat_map](https://en.cppreference.com/w/cpp/container/flat_map).

**Be sure to follow the [Steps of Development](#steps-of-development) for the approach to develop `MapArray`. Some relevant details may be provided only in the Steps.**

map_array.hpp screenshot

![map_array.hpp screenshot](/assets/2-1.png)

## 3 mapset_main.cpp

Homework 9 `mapset_main` has the same functionality as in Homework 8, but uses your implementations of `SetList` and `MapArray`.

> ⚠️ **Do not use** `std::set` or `std::map`.

### Sample input files for testing

Sample input file `sample_doc.txt` and sample `stopwords.txt` are provided in this repo.

> 💡*Tip: Remember the `Bash` command `diff` compares two files to see if they are the same or different:*
> `diff fileA fileB`
> *outputs just the differences. If they are the same, there will be no output.*

mapset_main.cpp screenshot

![mapset_main.cpp screenshot](/assets/3-1.png)

## Steps of Development

>**❗Note:  If asking for help with your program on Ed Discussion, give the Step number you are working on in the Subject line of the post. For example,**
> Step 2 defining local traits

### Define `SetList<T>` implemented as a linked list of `T` to replace `std::set<T>`

1. Create `set_list.hpp` implemented as a linked list of `T`.  Define your class:  data members, constructor, and any methods needed.
2. Define ***local traits*** within class `SetList`. Define the traits types for the container (`value_type`, etc). **Think** carefully about what each type should be; a simple mechanical translation of an example to `SetList` may not work (including the example from Lecture).
3. Define a ***forward iterator*** for `SetList` with its local traits. Define the traits types for the iterator (`value_type`, etc).
4. Create `mapset_main.cpp` as shown above.
5. Compile. Make note of any errors due to missing methods on class `SetList`. (For example, my implementation required `find()` and `insert()`). Be sure that `insert()` adds new items to the **front** of the list, which is more efficient, and does not insert duplicates. You may also want to remove the compile flag `-Wfatal-errors` if you need to see more detail, especially related to `static_assert()` failure.
6. Define in `SetList` each needed method declared in the screenshot.
7. Test until it works and produces the correct output.
8. Write and test the remaining methods given in the screenshot for `SetList` and its iterator, incrementally developing and testing them.

### Define `MapArray<Key,Value>` implemented as an array list of `pair<Key,Value>` to replace `std::map<Key,Value>` 

9. Create `map_array.hpp` as `template<Key,Value>` where `Key` and `Value` are typename template parameters.
10. Define local traits within class `MapArray`. Define the traits for the container (`value_type`, etc). Think carefully about what each type should be; a simple mechanical translation of an example to `MapArray` probably will not work (including the example from Lecture). Remember that `MapArray` contains pairs, requiring that ***each element*** of the pair (first, second) has its own type.
11. Define a **random access iterator** for `MapArray` with its local traits. Define the traits types for the iterator (`value_type`, etc).
12. Define `operator []()` for `MapArray`. Remember, you must keep pairs in ascending order by key within this vector. For the first version, you may want to ignore this requirement, but you must do it eventually.
13. Compile, making note of any errors due to missing methods on `MapArray`.
14. Verify that MapArray stores pairs in ascending alphabetical order by key, so that when `mapset` prints output, the output will be in ascending alphabetical order. Verify the order before submitting to the autograder.
15. Write and test the remaining methods given in the screenshot for MapArray and its iterator, incrementally developing and testing them.
    
### Test, debug, and `valgrind`

16. Test and debug, comparing your output to the expected output.
17. Once your program is functioning correctly, use `valgrind` and/or the sanitizers to help detect and correct memory errors.
18. Cross your fingers and pray 🙏  Submit to the autograder.

## Celebrate

**Celebrate that you have completed all the Homeworks of 45C!** 🎉 (with the latest and greatest features of C++20!)

## Submission

As with previous submissions, submit via `GitHub` by the following steps:

1. `git add .`
2. `git commit -a -m "Commit Message Here"`
3. `git push --set-upstream origin main`

to push your changes to your private GitHub repository, and then submit `hw9` to `Gradescope`.

> ⚠️ Be sure your #includes and using match exactly what is specified, for the autograder to run your submission with our own test programs.

## Grading criteria

Points are allotted for
- Passing tests of functional correctness. **Your output must *exactly* match our output.**
- Preventing memory leaks. Major points are deducted for mismatched `new` and `delete` and other memory errors detected by `valgrind`.
- Programs that do not compile with the autograder testing programs receive no points.
- Crashes due to a segfault means the program is not gradeable or useful, and therefore, the program receives no points.

*We may adjust grades manually when warranted. For example, a submission that attempts to defraud the autograder points by not implementing the requirements may be given a 0*

## Credit

All code moved from [ICS45c](https://github.com/RayKlefstad/ICS45c/tree/hw9)
