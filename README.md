# PA1-fifth-project
The task is to create a program that will search the phone book.
Consider a phone book where we remember the corresponding name for each number. We want to implement a program that can efficiently search such a list. When searching, we enter either the number we are looking for or the name we are looking for. Moreover, we do not have to enter the name or number in full, just its prefix. The program scans the phone book and finds all records that match the specified criteria.

When entering, we always assume only numeric queries. Such a numeric query can either mean the prefix of the number being searched for directly, or it can be a name entered using T9 (to search for records beginning with the letters Vagner, the input would be the sequence 824637).
The search will work interactively. Each line of input represents one processing instruction. The instruction is either to insert the record into the phone book or to search. Instruction entry ends when the entire input is read (EOF is reached). Instructions take the form of:
    + number name This command adds an entry to the tel. This command is used to add a phone number to the phonebook. The number is a sequence of characters from 0 to 9, the length of the number is at least one and at most 20 digits, care must be taken to store the              leading zeros correctly. A name is any sequence of upper and lower case letters and spaces. The name cannot be empty and cannot begin or end with a space. The + sign, number and name on the input line are separated by just one space.
    ? number This command searches the phone book. The number is a sequence of characters 0 through 9, and the length of the number is at least one character (there is no limit on the length). The character ? and number are separated by just one space.
    

The output of the program is the resolution of queries. 3 answers are possible for insertion into the list:
      error, the command is not formatted correctly,
      error, an entry is being inserted into the list that already exists in the list (complete match of number and name, including case matching),
      ok, the record has been inserted into the list.
There are 3 possible answers for the search:
      error, the command is not formatted correctly,
      finding records that match the query, displaying the records searched, and displaying the number of records found. This type of response will be used if no more than 10 records match the search,
      search for records that match the query, display the number of records found. This response will be used if more than 10 records match the query in tel. list.
If the input is invalid, the program must detect this and display an error message. Display the error message on the standard output (not on the error output). When an error is detected, the program will move on to process the next input line. Consider the following as an error:

      An unknown command entered (the command must begin with either a + sign or a ? sign),
      missing number or name in the input,
      missing number in search,
      the number is not made up of digits,
      the name is not made up of alphabetic characters and spaces,
      the name begins or ends with a space,
      command/number/name separators are missing or missing,
      the number being entered has more than 20 digits.
      Before implementing the program, think about how you will represent the phone book. The number of entries can be high, name lengths are not limited from above. Dynamic allocation and structures are useful in the design.

Searches can take a long time, especially if the phone book is long. Time limits are set so that a reasonably implemented basic search algorithm passes all tests except the bonus test. The bonus test requires an advanced search algorithm.



Ukázka práce programu:
+ 123456 Vagner Ladislav
OK
+ 987654321 Vanerka Jiri
OK
+ 824637 Vagner Jiri
OK
+ 8244278 Balik Miroslav
OK
+ 8243245 Vaclavik
OK
+ 192837 Taggart John
OK
+ 98244212 Bird Josef
OK
? 824
123456 Vagner Ladislav
824637 Vagner Jiri
8244278 Balik Miroslav
8243245 Vaclavik
192837 Taggart John
Celkem: 5
? 82
123456 Vagner Ladislav
987654321 Vanerka Jiri
824637 Vagner Jiri
8244278 Balik Miroslav
8243245 Vaclavik
192837 Taggart John
Celkem: 6
? 37
Celkem: 0
+ 1000001 Vacatko
OK
+ 1000002 Vaclavek
OK
+ 1000003 Vaclavkova
OK
+ 1000006 Vagner Ladislav
OK
+ 1000007 Vacek
OK
+ 1000008 Vachek
OK
+ 1000009 Varga
OK
? 824
123456 Vagner Ladislav
824637 Vagner Jiri
8244278 Balik Miroslav
8243245 Vaclavik
192837 Taggart John
1000006 Vagner Ladislav
Celkem: 6
? 82
Celkem: 13
+ 123456 Novakova
OK
? 123
123456 Vagner Ladislav
123456 Novakova
Celkem: 2
? 123456
123456 Vagner Ladislav
123456 Novakova
Celkem: 2
? 1234567
Celkem: 0
? 10000
1000001 Vacatko
1000002 Vaclavek
1000003 Vaclavkova
1000006 Vagner Ladislav
1000007 Vacek
1000008 Vachek
1000009 Varga      
Total: 7
+ 123456 Novakova Jana
OK
+ 234567 Novakova Jana
OK
+ 123456 Novakova Jana
The contact already exists.
+ 123456 Novakova Jana
Contact now.
+ 123456 Novakova Jana
OK
? 123456
123456 Vagner Ladislav
123456 Novakova
123456 Novakova Jana
123456 novakova Jana
Total: 4
+ 123456 test
OK
+ 1234567 test
OK
+ 123456 testtest
OK
+ 123456 test
The contact already exists.
+ 123456 test
Incorrect input.
+ 123456789012345678901234567890 foo
Incorrect entry.
? test
Incorrect input.
?
Incorrect input.
Test
Incorrect input.
