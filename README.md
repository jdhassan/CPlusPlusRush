# CPlusPlusRush
Explain our project
For our project, we created a system to organize our fraternity rush process, although this can be applied to many other organizations' recruitment processes. Our fraternity has always had an issue with member involvement in our rush process stemming from a feeling of not being able to voice their opinions. Our rush process is run by an elected official and his appointed rush committee. One of the main goals of this program was to enable all members, and not just the committee, to be active in making comments and adding their opinions on certain applicants. We separate the different members of our organization by “clearance” level, allowing anonymity for commenters to a majority of the chapter. All members are able to comment given they follow the correct format: their name, the applicant's name, whether the comment is positive or negative, and then the comment. This format allows for brothers to easily make comments, and for the members of the rush committee, to easily search through the comments by the commenter or the commentee, and further can sort them by positive or negative comments, or can just get a list of all comments. Given that people are voicing their opinions on potential new members of the fraternity, brothers often do not want their comments to be available to everyone, especially if they are negative, so only the members with high enough clearance levels (people on the rush committee and our president/vice president) are able to see the comments. Members with the highest clearance level will be able to edit/delete other members, applicants, and files. Once the rush process is over, we make it very easy for the higher level clearance members to delete all of the files with an option in the main directory in order to help maintain peace of mind to the commenters and the fraternity as a whole. We believe that with this program we can get more of our brothers to take an active role in the rush process, and make sure they feel their opinions are being heard. 


Design overview
The library we used to manage our data is fstream. We wrote our data onto several .txt files and manipulated them using fstream. Our project consists of 4 classes: Validate.hpp, Comments.hpp, CreateEdit.hpp and Search.hpp. Our main functions can be seen in the classes Comments, CreateEdit and Search while we used Validate as a parent class that contains validation/verification methods that are used in all of our other classes. We opted to use Validate.hpp to store all of the validation methods because we realized that all of the classes were using the same methods and we did not want to repeat our code over and over. Our main.cpp handles all of the delegation to these different classes through switch-statement “directories”. The home screen of our project consists of 5 options: 1. Applicant, 2. Member, 3. Comment, 4. Delete, 5. Exit. The first option, Applicants, delegates to the applicant directory containing all functionality relating to our applicants, or potential recruits, the second delegates to the member, the third option delegates to the comment directory, the fourth option is to delete applicants, members and comments, and 5 exits the program. All of these features are demonstrated in our video (we changed the order for aesthetic reasoning, along with enforcing more clearance restrictions on editing and deleting, since taking the video). Our main function uses a switch statement on the user input to determine which option has been selected, and goes to the corresponding menu. In our main, there are methods for menus of applicants, members, comments and one more for searching all of the above: applicantOptionDirectory(), memberOptionDirectory(), commentDirectory(), and searchDirectory(int option) which takes in an int to determine what the user is searching for (members or applicants). The methods applicantOptionDirectory() and memberOptionDirectory() create an instance of our class CreateEdit, and use its methods to write to the .txt files’ data. The method commentDirectory() creates an instance of a Comment object and uses its methods to write to the data while checking to see if members’ clearance levels are high enough to comment. When the delete option is selected, a CreateEdit object in main is used to call deleteFile() which will delete all of the data in the .txt files. The functions that access the members/applicants/comments all use fstream, whether it is the ifstream for searching, or the ofstream for editing/creating. When adding to one of the text files, each line of the file is either a new applicant/member/comment, which allows for easy iteration, and when adding, each object-string is added to a new line.  

In our video, we demonstrated how our project functions and how we tested our code. The first part of our video is a correct usage of our program, while the end is incorrect usage and how the program responds. For example, enter invalid name types, invalid years/clearance/status levels, trying to access areas without high enough clearance, and testing the break methods in the search/edit functions.
While we did not include all the testing we did in our project in the video, we included the major test cases and the method in which we tested which is by running through all of the program’s functionality. Here are the following test cases we used in the video:
Beginning part (showing functionality):
Make 2 applicants 
Make 2 members
Display all applicants
Search by year
Search by status
Search by name
Search member by year
Search member by name
Search member by clearance
Add comment
Try to access comment from both members -- one won't be able to
Trying to access with invalid clearance
Edit member
Edit applicant 
Delete all

Ending part (showing tests/fail-safes):
Invalid name types
Invalid year types
Invalid stat/clearance types
Trying to access with invalid clearance
Trying to comment with a false member name
Trying to comment on a non applicant name
Break ability

