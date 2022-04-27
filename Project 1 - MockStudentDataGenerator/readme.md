# Member
1. Nguyen Hai Dang - ID: 20120049
2. Le Nguyen Khang - ID: 20120113
# How to run the program
1. Select the "Release" folder, run the file "MockDataGenerator.exe".
2. To debug the program, select "Source code.sln" to enter the solution and then press F5 or Ctrl+F5 to run.
# Project 1: Mock Student Data Generator
## Notice
- [x] Completed.
- [ ] Unfinished.
## Content
1. * [x] Read all students saved in the file "students.txt" back into a vector of Student. You can hard-code this file as follow.
2. * [x] Generate randomly a number n in the range of [5, 10]
   1. * [x] Is a integer.
3. * [X] Generate randomly n Students and add to the previous vector.
   1. * [X] Student ID (8 numbers): abcdefgh
      1. * [X] ab = 18->21: random only 1 time.
      2. * [X] cd = 11->28: random only 1 time.
      3. * [X] e = 0,5,6,7: random only 1 time.
      4. * [X] fgh = A ingeter has 3 numbers (start at 001, each student increases by 1 unit).
   2. * [X] Full-name:
      1. * [X] First-name (Vietnamese: Tên).
      2. * [X] Midde-name (Vietnamese: Họ-tên lót).
      3. * [X] Last-name (Vietnamese: Họ).
   3. * [X] GPA: double or float (Round 2 digits after the ".").
   4. * [X] Telephone: Fake VN tels (Mobi, Vina, Viettel, Vietnammobile, ...)
   5. *  [x] Email:
      1. * [x] Ex: Name is Le Van Son.
      2. * [x] Email: lvson@... (1st character of Last-name and Middle-name and all First-name).
      3. * [x] Prepare 10 biggest company domains like  gmail.com, microsoft.com, apple.com, amazon.com....
   6. * [x] Birthday: Random from 01/01/1970 to 31/12/2003.
   7. * [x] Address:
      1. * [x] Apartment number.
      2. * [X] Street names.
      3. * [X] Ward.
      4. * [X] District.
      5. * [X] City (HCM City).
4.  * [X] Overwrite and save and the students in the current vector back to the file "students.txt".
5.  * [X] Print out the average GPA of all students.
6.  * [X] Print out all the students that have a GPA greater than the average GPA.
7.  * [X] Menu (3 functions: Random, calculate average GPA and print out higher list, exit program).
# What should be taken into account for a bonus? 
1. Function Menu (3 fuctions).
2. Use Regex to check user input.
# Expected Grade
| ID | Name | Expect Grade |
| -- | ---- | ------------ |
|20120049|Nguyen Hai Dang|9.5|
|20120113|Le Nguyen Khang|9.5|
# Video demo LINK
- https://youtu.be/mRPizZPL3Yc