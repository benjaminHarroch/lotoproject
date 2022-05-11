# lotoproject

# purpose of the project:

_A subsidiary of "Mifal Hapayis" is interested in symbolizing the lottery._

_At the entrance to the simulator, a menu will be displayed with 3 options:_
1. Entering the number of participants in the lottery
2. Viewing the latest lottery results
3. Exit_

***Option 1***

_If the first option is selected then after absorbing the number of participants, for each of the participants a name will be entered_
_The participant and after him will be presented with a sub-menu, with 2 options_
1. Manual lottery
2. Automatic lottery

_In each of the sub-options (2,1) the simulator will ask the participant for a desired number of columns to fill in._
_Each column is made up of 6 numbers, between 1 and 15 (inclusive) only, when a number cannot be repeated twice._
_Each participant's columns will be saved in a column of column voters._


_If the participant selects a manual lottery, the user must receive N columns into the list._
_If the participant selects an automatic lottery, N towers must be grilled automatically and included in the list._
_You must define a structure for a participant in which his name and list of columns will appear._


_All participants will be saved in the list of participants._
_After completing the preparation of the list of participants, the simulator will draw a winning column (that is, 6 numbers will be drawn)._
_The simulator will then go through all the columns and look for a match between each column and the winning column. Each column will have a number saved_
_Vulnerability, ie, the number of numbers that appeared in both the column examined and the winning column._


_At the end of the lottery and the test, the following data must be printed on the screen⏬
* The winning column
* For each participant the columns received / drawn for him when the columns are displayed in descending order of the number of vulnerabilities,
When next to each column the number of vulnerabilities will be indicated.
* General summary of the number of columns with 6 vulnerabilities, the number of columns with 5 vulnerabilities) does not include those with 6
Vulnerability ( the number of columns with 4 vulnerabilities) does not include those with 5,6 vulnerabilities (etc.).
The participant with the highest average number of hits (total hits divided by the number of columns).


_After printing the details and getting approval from the user (continue), the latest lottery data must be saved in the file_
_Binary_⏬
* An integer (int) will appear at the beginning of the file, indicating the number of participants, followed by the participants.
* For each participant will appear:
* Integer (int) Indicates the number of letters in the participant's name
* It will be followed by the letters of the name.
* An integer (int) will then appear indicating the number of columns of the participant.
* After that the participant's columns will appear in a compressed form: each column will be saved in only 3 bytes.
* After all participants, the winning column will also appear in a compressed form.
* After saving the lottery data, return to the main menu.


***Option 2***

_If the second option is selected, then the results of the last lottery must be presented to the user in a manner similar to the way it is_
_The lottery result was displayed under option 1._
_Remarks:_
* If option 2 is selected before the lottery rule has taken place, a suitable message must be presented to the user.
* If the symbol ator has been activated and in the current operation the lottery has not yet taken place, the results of the lottery must be displayed
_The last one that took place in the previous operation of the simulator (whose details are stored in the binary file)._
* If the symbol ator has been activated and in the current operation a lottery has already taken place, the results of the lottery must be presented.


⏬⏬⏬⏬⏬⏬⏬⏬⏬⏬⏬⏬⏬⏬⏬⏬⏬⏬⏬

***Tools I used during the project:*** 

  * File Text and binaries (writing and reading from a file) ☑️
  * Linked lists ☑️
  * Recursion ☑️
  * Memory management according to the requirements in C ☑️
  * Working with arrays ☑️
  * Sorting algorithms (MERGE SORT) ☑️
  * Random function ☑️
  * Work with bytes ☑️
  * Generic functions ☑️
 
