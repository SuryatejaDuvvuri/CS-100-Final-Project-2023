<!-- [![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=10884261&assignment_repo_type=AssignmentRepo)
 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\>"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets).  -->
# SkyTrack
 <!-- > Your author list below should include links to all members GitHub (remove existing author). -->
 
 > Authors: [Randy Garcia](https://github.com/RandyG66), [Suryateja Duvvuri](https://github.com/SuryatejaDuvvuri), 
 [Nicholas Wong](https://github.com/NiWong03), [Yujie Kang](https://github.com/kangyuj526498)
<!-- 
 > You will be forming a group of **FOUR** students and working on an interesting project. The project has 4 phases, each one with specific requirements. A list of proposed project ideas that have been successful in previous quarters is listed in the project specifications document on Canvas. You can select an idea from the list and start thinking about the features you will implement. If you want to propose your own original idea, you will have to contact your instructor to discuss the project and obtain written permission before you submit your project proposal (Phase 1). The project work should be divided almost equally among team members. You can of course help each other, but it needs to be clear who will be responsible for which features. Additionally, you are expected to follow Scrum patterns, specifically the use of a Scrum (Project) board, Sprints, and Scrum meetings. -->
<!-- 
 > ## Expectations
 > * The backend of your project should be implemented in C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.
 > * **Each member of the group must actively participate in the Github Project board, writing unit tests, and reviewing commited code.**
> * All project phases are to be submitted to this GitHub repository. You should modify this README file to reflect the different phases of the project. In addition, you should regularly hold sprint meetings with your group. You will need to hold two to three scrum/check-in meetings with your lab TA/reader at different times in addition to the final demo. -->

## Project Description
 <!-- > Your project description should summarize the project you are proposing. Be sure to include:
 > * Why is it important or interesting to you?
 > * What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
 > * What will be the input/output of your project?
 > * What are the features that the project provides?
 > This description should be in enough detail that the TA/instructor can determine the complexity of the project and if it is sufficient for the team members to complete in the time allotted. 
 > 
 > You also need to set up an empty project board using GitHub projects (board view). Make sure you add the board under your project repository. You should also have a Product Backlog and In testing columns added. -->
#### General Description:
 > Our project is based on recreating the main component features that come with a regular weather app but also 
 implementing some of our own unique features that don’t come with usual weather apps.
#### Why is it important/interesting?
>The weather app not only has the ability to display weather information but it allows us to be creative when it comes 
 to implementing other useful features such as setting up personalized suggestions for the user, and allowing the user 
 to share weather pictures to connect with others which becomes very interactive, compared to the usual weather apps. 
 Simultaneously, we’ll be able to learn the graphical library and other new libraries, along with using the api to 
 extract and display information.<br>
 #### Languages/Tools/Technologies used:
 > We will be focusing on [C++](cplusplus.com) as our primary language. Some tools we will be using would be a free provided weather API 
 that gathers information regarding the weather from a specific location.
 In addition, we will also be using the [QT](https://www.qt.io/)graphical framework implemented into C++ to develop the features graphically.
 We will be using [Github](https://www.github.com), [Git](https://git-scm.com/), and [VS Code](https://code.visualstudio.com/) to develop and test most of our code <br>
 #### Input/Output of the Project: 
 >The input of our project will revolve around the username and password that allows the user to log in to their own 
 account. The input will also contain user location that contributes to the weather api to 
 display accurate information regarding the weather. The output will consist of the weather conditions, 
 weather forecast, recommendation on clothing wear, and activities for that specific day depending on weather conditions.<br>
#### The features in this project would be:
> * Regular weather app(displays time, date, location, temperature)
> * the state of the weather(sunny, cloudy etc..)
>   * clothes suggestions based off of weather
> * log in with username and password
> * calendar for user to add events
> * quote bar generator
> * music button to change background into a moving lofi image
> * a Pomodoro timer & to-do list
> * to convert the temperature to their desired unit.

 
 
 > ## Phase II
 > In addition to completing the "User Interface Specification" and "Class Diagram" sections below, you will need to:
 > * Create an "Epic" (note) for each feature. Place these epics in the `Product Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Break down the "Epics" into smaller actionable user stories (i.e. smaller development tasks). Convert them into issues and assign them to team members. Place these in the `TODO` column.
 >   * These cards should represent roughly 7 days worth of development time for your team. Then, once the sprint is over you should be repeating these steps to plan a new sprint, taking you until your second scrum meeting with the reader in phase III.
 > * Schedule two check-ins using Calendly. You need to pick both time slots during your lab on week 6. Your entire team must be present for both check-ins.
 >   * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
 >   * The second check-in should be scheduled with a reader. During that meeting you will discuss:
 >     * The tasks you are planning for the first sprint
 >     * How work will be divided between the team members
## User Interface Specification
 > Include a navigation diagram for your screens and the layout of each of those screens as desribed below. For all the layouts/diagrams, you can use any tool such as PowerPoint or a drawing program. (Specification requirement is adapted from [this template](https://redirect.cs.umbc.edu/~mgrass2/cmsc345/Template_UI.doc))

### Navigation Diagram
> [Navigation Diagram.pdf](https://github.com/cs100/final-project-sduvv003-rgarc217-ykang063-nwong066/files/11427320/Navigation.Diagram.pdf)
> The navigation diagram shows how users will interact with our software. This diagram includes the features that our software will have, bringing a visual representation.

### Screen Layouts

Main Menu(after login): [Weather Home Page](https://github.com/cs100/final-project-sduvv003-rgarc217-ykang063-nwong066/blob/master/Designs/Screenshot%202023-05-08%20at%202.15.43%20PM.png)
* Displays features such as
> * quote bar generator, hourly weather forecast, clothes suggestions, and to-do list
* Buttons to redirect to other pages to show more features
> * Includes a page for timer, temperature converter, calendar, and login


Menu(before login): [Menu without logging](https://github.com/cs100/final-project-sduvv003-rgarc217-ykang063-nwong066/blob/master/Designs/Screenshot%202023-05-08%20at%202.17.27%20PM.png)
> * Application is started off with a mere home page without any info
> * Exit button is there to terminate the application itself

Login page: [Login](https://github.com/cs100/final-project-sduvv003-rgarc217-ykang063-nwong066/blob/master/Designs/Screenshot%202023-05-08%20at%202.18.50%20PM.png)
> * Username and password prompts the user. 
> * Uses location api everytime the user is logged in.

Menu with alerts and notifications: [Notifications popup and night theme](https://github.com/cs100/final-project-sduvv003-rgarc217-ykang063-nwong066/blob/master/Designs/Screenshot%202023-05-08%20at%202.22.31%20PM.png)
> * Notifications popup to prompt the user 
> * Alerts popup depending on the weather condition
> * Different theme is shown according to the time(or the button response from the user in the timer page)

Timer: [Timer page](https://github.com/cs100/final-project-sduvv003-rgarc217-ykang063-nwong066/blob/master/Designs/Screenshot%202023-05-08%20at%202.19.37%20PM.png)
> * Change theme button is for changing the background, affecting all other pages of the application
> * Start & Reset button is there for using the timer

Calendar: [Calendar page](https://github.com/cs100/final-project-sduvv003-rgarc217-ykang063-nwong066/blob/master/Designs/Screenshot%202023-05-08%20at%202.20.12%20PM.png)
> * Dates and weeks are shown in a google calendar format
> * user is prompted with textboxes to add event details(name, date, time, location)

Temperature converter: [Converter page](https://github.com/cs100/final-project-sduvv003-rgarc217-ykang063-nwong066/blob/master/Designs/Screenshot%202023-05-08%20at%202.20.52%20PM.png)
> * user is prompted to put a fahrenheit degree value(or celsius value
> * result is shown in either textbox once the user clicks convert button

## Class Diagram
[SkyTrack UML Diagram - UML Class.pdf](https://github.com/cs100/final-project-sduvv003-rgarc217-ykang063-nwong066/files/11427421/SkyTrack.UML.Diagram.-.UML.Class.pdf)

 
 > Description: The UML diagram represents the structure and representation for our project. In this UML diagram we use a login screen that uses two private variables and one public function to gather information from the user input. The login screen is the main interface that allows the user to enter our application and be shown the features that are provided. In addition, the user menu is the second main component. This is due to the fact of displaying all possible features in our project. That being weather info, calendar, alert messages, location status and a log out button. Due to the user menu being the second main component of our project, the features provide are all connected to one another in some sort of way. For example, the location and calendar class are both aggregation types towards the use user menu class. While the To-Do list and notification class are compositions to the claendar and weather information class.
 
 > ## Phase III
 > [SkyTrack UML Diagram - Revised UML Class.pdf](https://github.com/cs100/final-project-sduvv003-rgarc217-ykang063-nwong066/blob/b7f87741d7271d61e181be59a74f367cbceb6dd1/UML%20Diagram.pdf)
 > 
> Description: From the creation of our new UML diagram and through the help of our TA Garrett, sevral major changes were made. These changes allowed our team to fully understand the functions needed and which classes belong to one another. For example, the differences in this uml diagram from the other would be the surplus of several functions and the composition relation with several classes. In accordance to the SOLID principles, we can see that the main menu function is heavily focused on the display and the gui buttons that basically allow these display features to work. This follows the SOLID principle through the single responsibility principle. This change allowed us to write better code because it allows us to create display functions in one signle class rather than several classes where it can cause a lot of confusion. Some other changes that were made were the surplus of several new classes . These classes will benefit other classes due to composition. The composition displayed in the UML diagram would be the weather, tasks, date, time and calendar class. As mentioned previously, new classes were created to allow us to know what functions belong in those classes. This follows the SOLID principles due to each class having its own responsibility. In adittion, we can also apply the dependency inversion principle. The reason for this is because of our login menu. We know that this principle makes entities depend on abstractions not on concretions. Due to our login menu, we give the user the ability to choose their own username and password. Because of this it abides to the dependancy inversion principle because the login menu connects to the main menu where one can see the enitre ui/ data being displayed.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > <img src = "Screenshot 2023-06-09 at 6.00.24 PM.png">
 > <img src = "Screenshot 2023-06-09 at 6.00.35 PM.png">
 > <img src = "Screenshot 2023-06-09 at 6.00.41 PM.png">
 > <img src = "Screenshot 2023-06-09 at 6.00.55 PM.png">
 > <img src = "Screenshot 2023-06-09 at 6.00.55 PM.png">
 > <img src = "Screenshot 2023-06-09 at 6.01.07 PM.png">
 > <img src = "Screenshot 2023-06-09 at 6.01.16 PM.png">
 > <img src = "Screenshot 2023-06-09 at 6.01.25 PM.png">
 ## Installation/Usage
 > Instructions on installing and running your application
 > Steps to install and run Skytrack:
1) https://www.qt.io/download click link to go to qt page and install qt. 
2) Make account and click link on the left with appropriate device to install qt. 
3) After installation, open Qt Maintenance tool and set configuratioins to download Qt Creator. 
5) After Qt Creator is installed, perform git pull of this repository. 
7) Open Qt Creator and select open Project, select files for Skytrack. 
8) Qt Creator has its own ide, therefore the application can be run through Qt instead of the terminal. Select build option on the bottom left corner or right click the project files and clicking run cmake. 
9) After the project has been buit, run by selecting the run/play icon in the bottom left corner. 
 ## Testing
  In regards to our unit testing, we used QTest to build and create our unit test. Due to error confrontation, we were only able to hard code the unit test.The unit test are the converter.cpp, the api test.cpp and several more.  We were not able to use functions within these tests. In addition, QT has a built in memcheck, when running this memcheck, it gave us no error. But due to not displaying the data, it does not verify it accuratley. 
