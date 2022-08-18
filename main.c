#include <stdio.h>
#include "slre.h"
#include <winsock2.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>

#pragma comment (lib, "ws2_32.lib")

//i dont know why but after i select back in aftersearch function i go to timeline so i should define a variable to prevent it
int sureForAfterSearch;

char *client (char *command);
void mainMenu (void);
void signUpMenu (void);
void loginMenu (void);
void intheapplication (void);
void timeLine (void);
void sendTweet (void);
void refresh (void);
void afterRefresh (void);
void likeOrComment (void);
void showCommentsAfterRefresh (void);
void search (void);
void afterSearch (void);
void showCommentsAfterSearch (void);
void likeOrCommentAfterSearch (void);
void tweetProfrle (void);
void showCommentsAfterTweetProfile (void);
void personalArea (void);
void setBio (void);
void changePassword (void);
void logOut (void);
void searchForTheSecondTime (void);
void delay (unsigned int value);
void deleteTweet (void);
void retweet (void);
void retweetAfterSearch (void);
void tweetSearch (void);
void addFavorite (void);
void showFavorite (void);
void afterShowFavorite (void);
void deleteFavorite (void);
void showNotification (void);




//string to display
const char rocket[] = "\n\
                /^\\\n\
                |S|\n\
                |H|\n\
                |A|\n\
                |R|\n\
                |I|\n\
                |F|\n\
               /| |\\\n\
              / | | \\\n\
             |  | |  |\n\
              -\"\"\"-\n\
              LOADING...\n\
";
//string to display






char authToken[1000];




int main (void)
{
    //color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_GREEN);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
    //color
    //animation to welcome
    int x; double y;
    char text1[] = "\n\n \t\t\t Welcome To Tweeter";
    char text2[] = "\n\n \t\t\tBy";
    char text3[] = "\n\n \t\t\tAli Nazari";
    printf("\n\n");
    for (x = 0; text1[x] != NULL; x++){
        printf("%c", text1[x]);
        for (y = 0; y<=11111111; y++);
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("\n\n");
    for (x = 0; text2[x] != NULL; x++){
        printf("%c", text2[x]);
        for (y = 0; y<=11111111; y++);
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    printf("\n\n");
    for (x = 0; text3[x] != NULL; x++){
        printf("%c", text3[x]);
        for (y = 0; y<=11111111; y++);
    }
    for (y = 0; y<=888888888; y++);
    system("CLS");
    //animation to welcome
    //animation to loading
    int times=0;
    for (times = 0; times<=3; ++times){
        int jumpControlAtBottom = 0;
        const int someDelay = 7500;
        int shiftControl = 0;
        for (jumpControlAtBottom = 0; jumpControlAtBottom<30; ++jumpControlAtBottom){
            printf("\n");
       }
        fputs(rocket, stdout);
        for (shiftControl = 0; shiftControl<30; ++shiftControl) {
            delay(someDelay);
            printf("\n");
        }
    }
    //animation to loading
    system("CLS");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    printf("Hello there do you want the song to be played for you?(Yes/No)\n");
    char yesOrNo[5];
    scanf("%s", yesOrNo);
    if (strcmp(yesOrNo, "Yes") == 0){
        system("start song.flac &");
    }
    system("CLS");
    mainMenu();
    return 0;
}




//-------------------------------------------------------------------------
char *client (char *command)
{
    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in server;
    char *message, server_reply[2000];
    char *server_replay_last = &server_reply[0];
    int recv_size;
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0){
        return "Matching WSADATA failed";
    }
    //create a socket
    if ((s=socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET){
        return "Could not create socket";
    }
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(88);
    //connect to remote server
    if (connect(s, (struct sockaddr *) &server, sizeof(server)) < 0){
        return "Connection failed";
    }
    //send some data
    message = command;
    if (send(s, message, (int)strlen(message), 0) < 0){
        return "sending failed";
    }
    //recieve a replay from the server
    if ((recv_size = recv(s, server_reply, 2000, 0)) <= 0)
    {
        return "recieve failed";
    }
    //emtehani
    server_reply[recv_size] = '\0';
    return server_replay_last;
}
//-------------------------------------------------------------------------
void mainMenu (void)
{
    //color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_GREEN);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
    //color
    printf("Register menu:\n\n");
    printf("1.Sign up\n");
    printf("2.Log in\n\n\n\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("Please select your desired action:\n");
    int mainMenuVariable;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    scanf("%d", &mainMenuVariable);
    if (mainMenuVariable == 1){
        system("CLS");
        signUpMenu();
    }
    if (mainMenuVariable == 2){
        system("CLS");
        loginMenu();
    }
    else{
        system("CLS");
        mainMenu();
    }
}
//-------------------------------------------------------------------------
void signUpMenu (void)
{
    //color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_GREEN);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    //color
    char userName[20];
    printf("Username:\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    scanf("%s", userName);
    char password[20];
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    printf("Password\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    scanf("%s", password);
    char finalOutPutFromSignup[100] = "signup ";
    strcat(finalOutPutFromSignup, userName);
    strcat(finalOutPutFromSignup, ", ");
    strcat(finalOutPutFromSignup, password);
    strcat(finalOutPutFromSignup, "\n");
    char *serverAnswerForSignup = client(finalOutPutFromSignup);
    //this section regex
    char regex[] = "\"type\":\"([A-Za-z]+)\"";
    int num_caps = 1;
    char caps[num_caps][100000];
    slre_match(regex, serverAnswerForSignup, 100000, caps, num_caps, 0);
    if (strcmp(caps[0], "Error") == 0){
        if (serverAnswerForSignup[28] == 'h') {
            //color
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            //color
            printf("This username is already taken.");
            for (long long int fake = 0; fake <= 1000000000; ++fake);
            system("CLS");
            mainMenu();
        }
        if (serverAnswerForSignup[28] == 'o'){
            //color
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            //color
            printf("Your password should not be more than 16 character.");
            for (long long int fake = 0; fake <= 1000000000; ++fake);
            system("CLS");
            mainMenu();
        }
    }
    else{
        //color
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
        //color
        printf("Your account saved successfully.please login with your account.");
        for (long long int fake = 0; fake <=1000000000; ++fake);
        system("CLS");
        mainMenu();
    }
}
//-------------------------------------------------------------------------
void loginMenu (void)
{
    //color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_GREEN);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    //color
    char userName[30];
    printf("Please enter username which you signed up with before:\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    scanf("%s", userName);
    char password[30];
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    printf("Please enter the password of your account:\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    scanf("%s", password);
    char finalOutPutFromLogin[100] = "login ";
    strcat(finalOutPutFromLogin, userName);
    strcat(finalOutPutFromLogin, ", ");
    strcat(finalOutPutFromLogin, password);
    strcat(finalOutPutFromLogin, "\n");
    char *serverAnswerForLogin = client(finalOutPutFromLogin);
    //this section regex
    char regex[] = "\"type\":\"([A-Za-z]+)\",\"message\":\"([A-Za-z0-9-_ ]+)";
    int num_caps = 2;
    char caps[num_caps][100000];
    slre_match(regex, serverAnswerForLogin, 100000, caps, num_caps, 0);
    if (serverAnswerForLogin[9] == 'E'){
        if (serverAnswerForLogin[27] == 'I') {
            //color
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            //color
            printf("\nPassword is incorrect. Please check it.");
        }
        if (serverAnswerForLogin[27] == 'T' && serverAnswerForLogin[29] == 'i'){
            //color
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            //color
            printf("\nThe username is not exists please singup with it.");
        }
        if (serverAnswerForLogin[27] == 'T' && serverAnswerForLogin[29] == 'e'){
            //color
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            //color
            printf("\nThis username was logged in before.");
        }
        for (long long int fake = 0; fake <=1000000000; ++fake);
        system("CLS");
        mainMenu();
    }
    if (strcmp(caps[0], "Token") == 0){
        strcpy(authToken, caps[1]);
        system("CLS");
        intheapplication();
    }
}
//-------------------------------------------------------------------------
void intheapplication (void)
{
    //color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_GREEN);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    //color
    printf("1.TimeLine\n2.Search\n3.Tweet search\n4.Tweet Profile\n5.Personal area\n6.Log out\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("\n\nPlease enter the number of service which you want:\n");
    if (sureForAfterSearch == 1){
        getchar();
        sureForAfterSearch = 0;
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
    int intheapplicationVariable;
    scanf("%d", &intheapplicationVariable);
    if (intheapplicationVariable == 1){
        system("CLS");
        timeLine();
    }
    if (intheapplicationVariable == 2){
        system("CLS");
        search();
    }
    if (intheapplicationVariable == 3){
        system("CLS");
        tweetSearch();
    }
    if (intheapplicationVariable == 4){
        system("CLS");
        tweetProfrle();
    }
    if (intheapplicationVariable == 5){
        system("CLS");
        personalArea();
    }
    if (intheapplicationVariable == 6){
        system("CLS");
        logOut();
    }
    else{
        system("CLS");
        intheapplication();
    }
}
//-------------------------------------------------------------------------
void timeLine (void)
{
    //color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_GREEN);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    //color
    printf("1.Send tweet\n2.Refresh\n3.show favorite\n4.back\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("\n\nPlease choose the number which you want: \n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
    int timeLineVariable;
    scanf("%d", &timeLineVariable);
    if (timeLineVariable == 1){
        system("CLS");
        sendTweet();
    }
    if (timeLineVariable == 2){
        system("CLS");
        refresh();
    }
    if (timeLineVariable == 3){
        system("CLS");
        showFavorite();
    }
    if (timeLineVariable == 4){
        system("CLS");
        intheapplication();
    }
    else{
        system("CLS");
        timeLine();
    }
}
//-------------------------------------------------------------------------
void sendTweet (void)
{
    //color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_GREEN);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    //color
    printf("Please write your tweet:\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    char sendTweetArray[200];
    getchar();
    gets(sendTweetArray);
    char finalOutPutFromSendTweet[200] = "send tweet ";
    strcat(finalOutPutFromSendTweet, authToken);
    strcat(finalOutPutFromSendTweet, ", ");
    strcat(finalOutPutFromSendTweet, sendTweetArray);
    strcat(finalOutPutFromSendTweet, "\n");
    client(finalOutPutFromSendTweet);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    printf("\nYour tweet sent successfully.\n");
    for (long long int fake = 0; fake <=1000000000; ++fake);
    system("CLS");
    timeLine();
}
//-------------------------------------------------------------------------
char number[100];
char array_for_comments[1000][60];
int comment_variable = 0;
void refresh (void)
{
    //color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_GREEN);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    //color
    char finalOutPutOfRefresh[100] = "refresh ";
    strcat(finalOutPutOfRefresh, authToken);
    strcat(finalOutPutOfRefresh, "\n");
    char *serverAnswerForRefresh = client(finalOutPutOfRefresh);
    char serverAnswerForRefreshStringMode[10000];
    strcpy(serverAnswerForRefreshStringMode, serverAnswerForRefresh);
    //instead of regex i used string.h functions to show refresh answer on the terminal
    char *tokenPtr;
    char xxxyyy[1000][300];
    tokenPtr = strtok(serverAnswerForRefreshStringMode,"\"");
    int i = 0;
    while (tokenPtr != NULL){
        strcpy(xxxyyy[i], tokenPtr);
        tokenPtr = strtok(NULL, "\"");
        ++i;
    }
    int j = 0;
    for (int k = 0; k<i; ++k){
        if (strcmp(xxxyyy[k], "id")==0){
            strcpy(number, xxxyyy[k+1]);
            strcpy(array_for_comments[comment_variable], xxxyyy[k+1]);
            comment_variable +=  1;
        }
        if (strcmp(xxxyyy[k], "author")==0){
            printf("%s ", xxxyyy[k+2]);
            for (int k1 = 1; k1<strlen(number)-1; ++k1){
                printf("%c", number[k1]);
            }
        }
        if (strcasecmp(xxxyyy[k], "content") == 0){
            printf("\n%s", xxxyyy[k+2]);
        }
        if (strcmp(xxxyyy[k], "comments") == 0){
            int number2 = 0;
            for (int k2 = k+1; k2<i; ++k2){
                if (strcmp(xxxyyy[k2], "likes") == 0){
                    break;
                }
                if (strcmp(xxxyyy[k2], ":")== 0){
                    number2 += 1;
                    strcpy(array_for_comments[comment_variable], xxxyyy[k2+1]);
                    comment_variable += 1;

                }
            }
            strcpy(array_for_comments[comment_variable], "***");
            comment_variable += 1;
            printf("\ncomment(s): %d\t", number2);
        }
        if (strcmp(xxxyyy[k], "likes") == 0){
            printf("likes: ");
            char likeNumber[100];
            strcpy(likeNumber, xxxyyy[k+1]);
            if (k+1 == i-2){
                for (int k3 = 1; k3<strlen(likeNumber)-4; ++k3){
                    printf("%c\n\n", likeNumber[k3]);
                }
            }
            else{
                for (int k4 = 1; k4<strlen(likeNumber)-3; ++k4){
                    printf("%c\n", likeNumber[k4]);
                }
            }
        }
    }
    printf("-------------------------------------------------");
    afterRefresh();
}
//-------------------------------------------------------------------------
void afterRefresh (void)
{
    //color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_GREEN);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    //color
    printf("\n\n\n");
    printf("1.Like or comment a tweet!\n2.Show comment(s)\n3.retweet\n4.Back");
    int likeOrCommentVariable;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("\n\nPlease choose one: \n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    scanf("%d", &likeOrCommentVariable);
    if (likeOrCommentVariable == 1){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("-------------------------------------------------");
        likeOrComment();
    }
    if (likeOrCommentVariable == 2){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("\n-------------------------------------------------\n");
        showCommentsAfterRefresh();
    }
    if (likeOrCommentVariable == 3){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("\n-------------------------------------------------\n");
        retweet();
    }
    if (likeOrCommentVariable == 4){
        system("CLS");
        timeLine();
    }
    else{
        afterRefresh();
    }
}
//-------------------------------------------------------------------------
void likeOrComment (void)
{
    //color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_GREEN);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    //color
    printf("\n\n\n1.Like\n2.Comment\n3.Back\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("\n\nPlease enter the number of action which you want: \n");
    int likeOrCommentVariable2;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    scanf("%d", &likeOrCommentVariable2);
    if (likeOrCommentVariable2 == 1){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("-------------------------------------------------");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("\n\n\nPlease enter id of tweet which you want to like: \n");
        char increasingLike[100];
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
        scanf("%s", increasingLike);
        char finalRequestFromLikeSection[150] = "like ";
        strcat(finalRequestFromLikeSection, authToken);
        strcat(finalRequestFromLikeSection, ", ");
        strcat(finalRequestFromLikeSection, increasingLike);
        strcat(finalRequestFromLikeSection, "\n");
        char* server_response_for_like = client(finalRequestFromLikeSection);
        if (server_response_for_like[9] == 'S') {
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            printf("\nLiked:)!\n");
        }
        if (server_response_for_like[9] == 'E' && server_response_for_like[27] == 'T'){
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            printf("\nYour tweet id is out of range");
        }
        if (server_response_for_like[9] == 'E' && server_response_for_like[27] == 'L'){
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            printf("\nYou liked this tweet before :).");
        }
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("-------------------------------------------------");
        afterRefresh();
    }
    if (likeOrCommentVariable2 == 2){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("-------------------------------------------------");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("\n\n\nPlease enter id of tweet which you want to leave a comment: \n");
        char Id_Comment[10];
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
        scanf("%s", Id_Comment);
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("Write your comment:\n");
        char commentText[150];
        getchar();
        gets(commentText);
        char commentRequestToServer[250] = "comment ";
        strcat(commentRequestToServer, authToken);
        strcat(commentRequestToServer, ", ");
        strcat(commentRequestToServer, Id_Comment);
        strcat(commentRequestToServer, ", ");
        strcat(commentRequestToServer, commentText);
        strcat(commentRequestToServer, "\n");
        char* server_response_for_comment = client(commentRequestToServer);
        if (server_response_for_comment[9] == 'S') {
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            printf("\n\nComment saved!\n");
        }
        if (server_response_for_comment[9] == 'E'){
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            printf("\n\nYour tweet id is out of range.\n");
        }
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("-------------------------------------------------\n");
        afterRefresh();
    }
    if (likeOrCommentVariable2 == 3){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("\n-------------------------------------------------\n");
        afterRefresh();
    }
    else{
        likeOrComment();
    }
}
//-------------------------------------------------------------------------
void retweet (void)
{
    //color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_GREEN);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    //color
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("\n\nEnter tweet id which you want to retweet:\n");
    char tweet_id_to_retweet[50];
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    scanf("%s", tweet_id_to_retweet);
    char retweet_request[200] = "retweet ";
    strcat(retweet_request, authToken);
    strcat(retweet_request, ", ");
    strcat(retweet_request, tweet_id_to_retweet);
    strcat(retweet_request, "\n");
    char *server_response = client(retweet_request);
    if (server_response[9] == 'S'){
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
        printf("\n\nRetweeted successfuly.\n");
        afterRefresh();
    }
    if (server_response[9] == 'E' && server_response[27] == 'O'){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("\n\nYour tweet id is out of range.\n");
        afterRefresh();
    }
    if (server_response[9] == 'E' && server_response[27] == 'P'){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("\n\nYou retweeted this tweet before.\n");
        afterRefresh();
    }
}
//-------------------------------------------------------------------------
void showCommentsAfterRefresh (void){
    //color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_GREEN);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
    //color
    printf("Please enter id of tweet which you want to see its comments: \n");
    char comment_id[10];
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
    scanf("%s", comment_id);
    printf("\n\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    char for_findig_range_of_comment[10] = ":";
    strcat(for_findig_range_of_comment, comment_id);
    strcat(for_findig_range_of_comment, ",");
    for (int z1 = 0; z1<comment_variable; ++z1){
        if (strcmp(array_for_comments[z1], for_findig_range_of_comment) == 0){
            for (int z2 = z1+1; z2<comment_variable; ++z2){
                if (strcmp(array_for_comments[z2], "***") == 0){
                    break;
                }
                printf("%s\n", array_for_comments[z2]);
            }
        }
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("\n\nPress 0 to go back to after refresh part\n");
    int comment_to_go_back;
    scanf("%d", &comment_to_go_back);
    if (comment_to_go_back == 0){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("\n-------------------------------------------------\n");
        afterRefresh();
    }
}
//-------------------------------------------------------------------------
char number2[100];
char followingStatusForChangingit[15];
char serchVariableForChangeStatus[20];
char onlyForTheSecondTime[200];
char array_for_comments_2[1000][60];
int comment_variable_2 = 0;
void search (void)
{
    //color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_GREEN);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
    //color
    printf("Please write name of the person whom you want to find: \n");
    char searchVariable[20];
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
    scanf("%s", searchVariable);
    system("CLS");
    char finalSearchRequest[200] = "search ";
    strcat(finalSearchRequest, authToken);
    strcat(finalSearchRequest, ", ");
    strcat(finalSearchRequest, searchVariable);
    strcat(finalSearchRequest, "\n");
    strcpy(onlyForTheSecondTime, finalSearchRequest);
    char *ServerAnswerForSearch = client(finalSearchRequest);
    //
    ServerAnswerForSearch[strlen(ServerAnswerForSearch)] = '\0';
    //
    strcpy(serchVariableForChangeStatus, searchVariable);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    if (strlen(ServerAnswerForSearch) == 56){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("\n\n\nSorry the username which you entered seems not to be exist.");
        for (long long int fake = 0; fake <=1000000000; ++fake);
        system("CLS");
        intheapplication();
    }
    else{
        //
        char instead[5000];
        strcpy(instead, ServerAnswerForSearch);
        //
        if (ServerAnswerForSearch[0] == '['){
            system("CLS");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
            strcpy(instead, instead+1);
            instead[strlen(instead)-1] = '\0';
            for (int r = 0; r<strlen(instead); ++r){
                if (instead[r] != ','){
                    printf("%c", instead[r]);
                }
                if (instead[r] == ','){
                    printf("\n");
                }
            }
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
            printf("\n\nDo you mean these users? If yes please write their whole name.\n\n");
            search();
        }
        else if (ServerAnswerForSearch[0] == '{') {
            char message[2000];
            strcpy(message, ServerAnswerForSearch);
            char *tokenPtr;
            char xxxyyy[300][30];
            tokenPtr = strtok(message, "\"");
            int i = 0;
            while (tokenPtr != NULL) {
                strcpy(xxxyyy[i], tokenPtr);
                tokenPtr = strtok(NULL, "\"");
                ++i;
            }
            for (int k = 0; k < i; ++k) {
                if (strcmp(xxxyyy[k], "username") == 0) {
                    printf("Username: %s\n", xxxyyy[k + 2]);
                }
                if (strcmp(xxxyyy[k], "bio") == 0) {
                    printf("Bio: %s\n", xxxyyy[k + 2]);
                }
                if (strcmp(xxxyyy[k], "numberOfFollowers") == 0) {
                    printf("Followers: ");
                    strcpy(number2, xxxyyy[k + 1]);
                    for (int z1 = 1; z1 < strlen(number2) - 1; ++z1) {
                        printf("%c", number2[z1]);
                    }
                    printf("\t\t");
                }
                if (strcmp(xxxyyy[k], "numberOfFollowings") == 0) {
                    printf("Followings: ");
                    strcpy(number2, xxxyyy[k + 1]);
                    for (int z2 = 1; z2 < strlen(number2) - 1; ++z2) {
                        printf("%c", number2[z2]);
                    }
                    printf("\n");
                }
                if (strcmp(xxxyyy[k], "followStatus") == 0) {
                    printf("%s\n", xxxyyy[k + 2]);
                    strcpy(followingStatusForChangingit, xxxyyy[k + 2]);
                }
                if (strcmp(xxxyyy[k], "allTweets") == 0) {
                    int fromTheMiddle = k + 1;
                    while (fromTheMiddle <= i) {
                        if (strcmp(xxxyyy[fromTheMiddle], "id") == 0) {
                            printf("\n\n\nId: ");
                            strcpy(number2, xxxyyy[fromTheMiddle + 1]);
                            strcpy(array_for_comments_2[comment_variable_2], xxxyyy[fromTheMiddle + 1]);
                            comment_variable_2 += 1;
                            for (int z2 = 1; z2 < strlen(number2) - 1; ++z2) {
                                printf("%c", number2[z2]);
                            }
                            printf("\t");
                        }
                        if (strcmp(xxxyyy[fromTheMiddle], "author") == 0) {
                            printf("Author: %s \n", xxxyyy[fromTheMiddle + 2]);
                        }
                        if (strcasecmp(xxxyyy[fromTheMiddle], "content") == 0) {
                            printf("%s", xxxyyy[fromTheMiddle + 2]);
                        }
                        if (strcmp(xxxyyy[fromTheMiddle], "comments") == 0) {
                            int number2 = 0;
                            for (int k2 = fromTheMiddle + 1; k2 < i; ++k2) {
                                if (strcmp(xxxyyy[k2], "likes") == 0) {
                                    break;
                                }
                                if (strcmp(xxxyyy[k2], ":") == 0) {
                                    number2 += 1;
                                    strcpy(array_for_comments_2[comment_variable_2], xxxyyy[k2 + 1]);
                                    comment_variable_2 += 1;
                                }
                            }
                            strcpy(array_for_comments_2[comment_variable_2], "***");
                            comment_variable_2 += 1;
                            printf("\ncomment(s): %d\t", number2);
                        }
                        if (strcmp(xxxyyy[fromTheMiddle], "likes") == 0) {
                            printf("likes: ");
                            char likeNumber[100];
                            strcpy(likeNumber, xxxyyy[fromTheMiddle + 1]);
                            if (fromTheMiddle + 1 == i) {
                                for (int k3 = 1; k3 < strlen(likeNumber) - 4; ++k3) {
                                    printf("%c", likeNumber[k3]);
                                }
                                printf("\n");
                                break;
                            } else if (fromTheMiddle + 1 < i) {
                                for (int k4 = 1; k4 < strlen(likeNumber) - 3; ++k4) {
                                    printf("%c", likeNumber[k4]);
                                }
                                printf("\n");
                            }
                        }

                        fromTheMiddle += 1;
                    }
                }
            }
        }
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("\n-------------------------------------------------\n");
    afterSearch();
}
//-------------------------------------------------------------------------
void searchForTheSecondTime (void)
{
    //color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_GREEN);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    //color
    char *serverAnswerForTheSecondTimeSearch = client(onlyForTheSecondTime);
    //strcpy(serchVariableForChangeStatus, searchVariable);
    if (strlen(serverAnswerForTheSecondTimeSearch) == 57){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("\n\n\nSorry the username which you entered seems not to be exist.");
        for (long long int fake = 0; fake <=1000000000; ++fake);
        system("CLS");
        intheapplication();
    }
    else{
        char message[2000];
        strcpy(message, serverAnswerForTheSecondTimeSearch);
        char *tokenPtr;
        char xxxyyy[500][30];
        tokenPtr = strtok(message, "\"");
        int i = 0;
        while (tokenPtr != NULL){
            strcpy(xxxyyy[i], tokenPtr);
            tokenPtr = strtok(NULL, "\"");
            ++i;
        }
        for (int k = 0; k<i; ++k){
            if (strcmp(xxxyyy[k], "username") == 0){
                printf("Username: %s\n", xxxyyy[k+2]);
            }
            if (strcmp(xxxyyy[k], "bio")==0){
                printf("Bio: %s\n", xxxyyy[k+2]);
            }
            if (strcmp(xxxyyy[k], "numberOfFollowers")==0){
                printf("Followers: ");
                strcpy(number2, xxxyyy[k+1]);
                for (int z1 = 1; z1<strlen(number2)-1; ++z1){
                    printf("%c", number2[z1]);
                }
                printf("\t\t");
            }
            if (strcmp(xxxyyy[k], "numberOfFollowings")==0){
                printf("Followings: ");
                strcpy(number2, xxxyyy[k+1]);
                for (int z2 = 1; z2<strlen(number2)-1; ++z2){
                    printf("%c", number2[z2]);
                }
                printf("\n");
            }
            if (strcmp(xxxyyy[k], "followStatus") == 0){
                printf("%s\n", xxxyyy[k+2]);
                strcpy(followingStatusForChangingit, xxxyyy[k+2]);
            }
            if (strcmp(xxxyyy[k], "allTweets")==0){
                int fromTheMiddle = k+1;
                while(fromTheMiddle < i){
                    if (strcmp(xxxyyy[fromTheMiddle], "id") == 0){
                        printf("\n\n\nId: ");
                        strcpy(number2, xxxyyy[fromTheMiddle+1]);
                        for (int z2 = 1; z2<strlen(number2)-1; ++z2){
                            printf("%c", number2[z2]);
                        }
                        printf("\t");
                    }
                    if (strcmp(xxxyyy[fromTheMiddle], "author")==0){
                        printf("Author: %s \n", xxxyyy[fromTheMiddle+2]);
                    }
                    if (strcasecmp(xxxyyy[fromTheMiddle], "content") == 0){
                        printf("%s", xxxyyy[fromTheMiddle+2]);
                    }
                    if (strcmp(xxxyyy[fromTheMiddle], "comments") == 0){
                        int number2 = 0;
                        for (int k2 = fromTheMiddle+1; k2<i; ++k2){
                            if (strcmp(xxxyyy[k2], "likes") == 0){
                                break;
                            }
                            if (strcmp(xxxyyy[k2], ":")== 0){
                                number2 += 1;
                            }
                        }
                        printf("\ncomment(s): %d\t", number2);
                    }
                    if (strcmp(xxxyyy[fromTheMiddle], "likes") == 0){
                        printf("likes: ");
                        char likeNumber[100];
                        strcpy(likeNumber, xxxyyy[fromTheMiddle+1]);
                        if (fromTheMiddle+1 == i-1){
                            for (int k3 = 1; k3<strlen(likeNumber)-4; ++k3){
                                printf("%c\n\n", likeNumber[k3]);
                            }
                            break;
                        }
                        else if (fromTheMiddle+1 <i-1){
                            for (int k4 = 1; k4<strlen(likeNumber)-3; ++k4){
                                printf("%c\n\n", likeNumber[k4]);
                            }
                        }
                    }

                    fromTheMiddle += 1;
                }
            }
        }
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("\n-------------------------------------------------\n");
    afterSearch();
}
//-------------------------------------------------------------------------
void afterSearch (void)
{
    //color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_GREEN);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    //color
    printf("\n\n\n");
    printf("1.Change following status\n2.Like or comment\n3.Show comment(s)\n4.Retweet\n5.Back\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("\n\nPlease enter your choice: \n");
    int searchVariableForLastPart;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    scanf("%d", &searchVariableForLastPart);
    if (searchVariableForLastPart == 1){
        if (strcmp(followingStatusForChangingit, "Followed")==0){
            strcpy(followingStatusForChangingit, "NotFollowed");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
            printf("\n\n\nDo you want to unfollow this user?(Yes/No)\n");
            char yesornot[10];
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
            scanf("%s", yesornot);
            if (strcmp(yesornot, "Yes") == 0){
                char changeStatusToUnfollow[100] = "unfollow ";
                strcat(changeStatusToUnfollow, authToken);
                strcat(changeStatusToUnfollow, ", ");
                strcat(changeStatusToUnfollow, serchVariableForChangeStatus);
                strcat(changeStatusToUnfollow, "\n");
                client(changeStatusToUnfollow);
                //afterSearch();
                system("CLS");
                searchForTheSecondTime();
            }
            if (strcmp(yesornot, "No")==0){
                system("CLS");
                searchForTheSecondTime();
            }
        }
        if (strcmp(followingStatusForChangingit, "NotFollowed")==0){
            strcpy(followingStatusForChangingit, "Followed");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
            printf("\nDo you want to follow this user?(Yes/No)\n");
            char yesornot2[10];
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
            scanf("%s", yesornot2);
            if (strcmp(yesornot2, "Yes") == 0){
                char changeStatusToUnfollow2[100] = "follow ";
                strcat(changeStatusToUnfollow2, authToken);
                strcat(changeStatusToUnfollow2, ", ");
                strcat(changeStatusToUnfollow2, serchVariableForChangeStatus);
                strcat(changeStatusToUnfollow2, "\n");
                client(changeStatusToUnfollow2);
                system("CLS");
                searchForTheSecondTime();
            }
            if (strcmp(yesornot2, "No")==0){
                system("CLS");
                searchForTheSecondTime();
            }
        }
    }
    if (searchVariableForLastPart == 2){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("\n-------------------------------------------------\n");
        likeOrCommentAfterSearch();
    }
    if (searchVariableForLastPart == 3){
        showCommentsAfterSearch();
    }
    if (searchVariableForLastPart == 4){
        retweetAfterSearch();
    }
    if (searchVariableForLastPart == 5){
        system("CLS");
        sureForAfterSearch = 1;
        intheapplication();
    }
    else{
        system("CLS");
        searchForTheSecondTime();
    }
}
//-------------------------------------------------------------------------
void retweetAfterSearch (void)
{
    //color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_GREEN);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    //color
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("\n\nEnter tweet id which you want to retweet:\n");
    char tweet_id_to_retweet[50];
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    scanf("%s", tweet_id_to_retweet);
    char retweet_request[200] = "retweet ";
    strcat(retweet_request, authToken);
    strcat(retweet_request, ", ");
    strcat(retweet_request, tweet_id_to_retweet);
    strcat(retweet_request, "\n");
    char *server_response = client(retweet_request);
    if (server_response[9] == 'S'){
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
        printf("\n\nRetweeted successfuly.\n");
        for (long long int fake = 0; fake <=1000000000; ++fake);
        system("CLS");
        searchForTheSecondTime();
    }
    if (server_response[9] == 'E' && server_response[27] == 'O'){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("\n\nYour tweet id is out of range.\n");
        for (long long int fake = 0; fake <=1000000000; ++fake);
        system("CLS");
        searchForTheSecondTime();
    }
    if (server_response[9] == 'E' && server_response[27] == 'P'){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("\n\nYou retweeted this tweet before.\n");
        for (long long int fake = 0; fake <=1000000000; ++fake);
        system("CLS");
        searchForTheSecondTime();
    }
}
//-------------------------------------------------------------------------
void showCommentsAfterSearch (void){
    //color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_GREEN);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
    //color
    printf("Please enter id of tweet which you want to see its comments: \n");
    char comment_id[10];
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    scanf("%s", comment_id);
    printf("\n\n");
    char for_findig_range_of_comment[10] = ":";
    strcat(for_findig_range_of_comment, comment_id);
    strcat(for_findig_range_of_comment, ",");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    for (int z1 = 0; z1<comment_variable_2; ++z1){
        if (strcmp(array_for_comments_2[z1], for_findig_range_of_comment) == 0){
            for (int z2 = z1+1; z2<comment_variable_2; ++z2){
                if (strcmp(array_for_comments_2[z2], "***") == 0){
                    break;
                }
                printf("%s\n", array_for_comments_2[z2]);
            }
        }
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("\n\nPress 0 to go back to after search part\n");
    int comment_to_go_back;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    scanf("%d", &comment_to_go_back);
    if (comment_to_go_back == 0){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("\n-------------------------------------------------\n");
        system("CLS");
        searchForTheSecondTime();
    }
}
//-------------------------------------------------------------------------
void likeOrCommentAfterSearch (void)
{
    //color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_GREEN);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    //color
    printf("\n\n\n1.Like\n2.Comment\n3.Back\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("\n\nPlease enter the number of action which you want: \n");
    int likeOrCommentVariable2;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    scanf("%d", &likeOrCommentVariable2);
    if (likeOrCommentVariable2 == 1){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("\n-------------------------------------------------\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("\n\n\nPlease enter id of tweet which you want to like: \n");
        char increasingLike[50];
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
        scanf("%s", increasingLike);
        char finalRequestFromLikeSection[250] = "like ";
        strcat(finalRequestFromLikeSection, authToken);
        strcat(finalRequestFromLikeSection, ", ");
        strcat(finalRequestFromLikeSection, increasingLike);
        strcat(finalRequestFromLikeSection, "\n");
        char* server_response_for_lile = client(finalRequestFromLikeSection);
        if (server_response_for_lile[9] == 'S') {
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            printf("\nLiked:)!\n");
        }
        if (server_response_for_lile[9] == 'E' && server_response_for_lile[27] == 'T'){
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            printf("\nYour tweet id is out of range");
        }
        if (server_response_for_lile[9] == 'E' && server_response_for_lile[27] == 'L'){
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            printf("\nYou liked this tweet before :).");
        }
        for (long long int fake = 0; fake <=1000000000; ++fake);
        system("CLS");
        searchForTheSecondTime();
    }
    if (likeOrCommentVariable2 == 2){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("\n-------------------------------------------------\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("\n\n\nPlease enter id of user whom you want to comment: \n");
        char Id_Comment[10];
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
        scanf("%s", Id_Comment);
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("Write your comment:\n");
        char commentText[200];
        getchar();
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
        gets(commentText);
        char commentRequestToServer[600] = "comment ";
        strcat(commentRequestToServer, authToken);
        strcat(commentRequestToServer, ", ");
        strcat(commentRequestToServer, Id_Comment);
        strcat(commentRequestToServer, ", ");
        strcat(commentRequestToServer, commentText);
        strcat(commentRequestToServer, "\n");
        char* server_response_for_comment = client(commentRequestToServer);
        if (server_response_for_comment[9] == 'S') {
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            printf("\n\nComment saved!");
        }
        if (server_response_for_comment[9] == 'E'){
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            printf("\n\nYour tweet id is out of range.");
        }
        for (long long int fake = 0; fake <=1000000000; ++fake);
        system("CLS");
        searchForTheSecondTime();
    }
    if (likeOrCommentVariable2 == 3){
        system("CLS");
        searchForTheSecondTime();
    }
    else{
        system("CLS");
        searchForTheSecondTime();
    }
}
//-------------------------------------------------------------------------
void tweetSearch (void)
{
    //color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_GREEN);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
    //color
    printf("Please write the tweet which you looking for:\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    char hashtak[200];
    //
    getchar();
    //
    gets(hashtak);
    char final_request_for_tweetsearch[300] = "tweet search ";
    strcat(final_request_for_tweetsearch, authToken);
    strcat(final_request_for_tweetsearch, ", ");
    strcat(final_request_for_tweetsearch, hashtak);
    strcat(final_request_for_tweetsearch, "\n");
    char* server_response_for_tweet_search = client(final_request_for_tweetsearch);
    if (server_response_for_tweet_search[9] == 'E' && server_response_for_tweet_search[27] == 'B'){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("An error aqured during search please try again later.");
        for (long long int fake = 0; fake <=1000000000; ++fake);
        system("CLS");
        intheapplication();
    }
    //for else part
    char serverAnswerForTweetSearchStringMode[10000];
    strcpy(serverAnswerForTweetSearchStringMode, server_response_for_tweet_search);
    //end of for else part
    if (server_response_for_tweet_search[9] == 'E' && server_response_for_tweet_search[27] == 'N'){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("No such tweet found which contain your request.");
        for (long long int fake = 0; fake <=1000000000; ++fake);
        system("CLS");
        intheapplication();
    }
    else{
        //instead of regex i used string.h functions to show refresh answer on the terminal
        char *tokenPtr;
        char xxxyyy[500][500];
        tokenPtr = strtok(serverAnswerForTweetSearchStringMode,"\"");
        int i = 0;
        while (tokenPtr != NULL){
            strcpy(xxxyyy[i], tokenPtr);
            tokenPtr = strtok(NULL, "\"");
            ++i;
        }
        int j = 0;
        for (int k = 0; k<i; ++k){
            if (strcmp(xxxyyy[k], "id")==0){
                strcpy(number, xxxyyy[k+1]);
                strcpy(array_for_comments[comment_variable], xxxyyy[k+1]);
                comment_variable +=  1;
            }
            if (strcmp(xxxyyy[k], "author")==0){
                printf("%s ", xxxyyy[k+2]);
                for (int k1 = 1; k1<strlen(number)-1; ++k1){
                    printf("%c", number[k1]);
                }
            }
            if (strcasecmp(xxxyyy[k], "content") == 0){
                printf("\n%s", xxxyyy[k+2]);
            }
            if (strcmp(xxxyyy[k], "comments") == 0){
                int number2 = 0;
                for (int k2 = k+1; k2<i; ++k2){
                    if (strcmp(xxxyyy[k2], "likes") == 0){
                        break;
                    }
                    if (strcmp(xxxyyy[k2], ":")== 0){
                        number2 += 1;
                        strcpy(array_for_comments[comment_variable], xxxyyy[k2+1]);
                        comment_variable += 1;

                    }
                }
                strcpy(array_for_comments[comment_variable], "***");
                comment_variable += 1;
                printf("\ncomment(s): %d\t", number2);
            }
            if (strcmp(xxxyyy[k], "likes") == 0){
                printf("likes: ");
                char likeNumber[100];
                strcpy(likeNumber, xxxyyy[k+1]);
                if (k+1 == i-1){
                    for (int k3 = 1; k3<strlen(likeNumber)-2; ++k3){
                        printf("%c", likeNumber[k3]);
                    }
                }
                else{
                    for (int k4 = 1; k4<strlen(likeNumber)-3; ++k4){
                        printf("%c", likeNumber[k4]);
                    }
                }
                printf("\n");
            }
        }
    }
    afterRefresh();
}
//-------------------------------------------------------------------------
char number3[100];
char array_for_comments_3[1000][60];
int comment_variable_3 = 0;
void tweetProfrle (void)
{
    //color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_GREEN);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    //color
    char tweetProfile[50] = "profile ";
    strcat(tweetProfile, authToken);
    strcat(tweetProfile, "\n");
    char *serverAnswerForTweetProfile = client(tweetProfile);
    //showing details
    char message[10000];
    strcpy(message, serverAnswerForTweetProfile);
    char *tokenPtr;
    char xxxyyy[1000][30];
    tokenPtr = strtok(message, "\"");
    int i = 0;
    while (tokenPtr != NULL){
        strcpy(xxxyyy[i], tokenPtr);
        tokenPtr = strtok(NULL, "\"");
        ++i;
    }
    for (int k = 0; k<i; ++k){
        if (strcmp(xxxyyy[k], "username") == 0){
            printf("Username: %s\n", xxxyyy[k+2]);
        }
        if (strcmp(xxxyyy[k], "bio")==0){
            printf("Bio: %s\n", xxxyyy[k+2]);
        }
        if (strcmp(xxxyyy[k], "numberOfFollowers")==0){
            printf("Followers: ");
            strcpy(number3, xxxyyy[k+1]);
            for (int z1 = 1; z1<strlen(number3)-1; ++z1){
                printf("%c", number3[z1]);
            }
            printf("\t\t");
        }
        if (strcmp(xxxyyy[k], "numberOfFollowings")==0){
            printf("Followings: ");
            strcpy(number3, xxxyyy[k+1]);
            for (int z2 = 1; z2<strlen(number3)-1; ++z2){
                printf("%c", number3[z2]);
            }
            printf("\n");
        }
        if (strcmp(xxxyyy[k], "followStatus") == 0){
            printf("%s\n", xxxyyy[k+2]);
            strcpy(followingStatusForChangingit, xxxyyy[k+2]);
        }
        if (strcmp(xxxyyy[k], "allTweets")==0){
            int fromTheMiddle = k+1;
            while(fromTheMiddle < i){
                if (strcmp(xxxyyy[fromTheMiddle], "id") == 0){
                    printf("\n\n\nId: ");
                    strcpy(array_for_comments_3[comment_variable_3], xxxyyy[fromTheMiddle+1]);
                    comment_variable_3 +=  1;
                    strcpy(number3, xxxyyy[fromTheMiddle+1]);
                    for (int z2 = 1; z2<strlen(number3)-1; ++z2){
                        printf("%c", number3[z2]);
                    }
                    printf("\t");
                }
                if (strcmp(xxxyyy[fromTheMiddle], "author")==0){
                    printf("Author: %s \n", xxxyyy[fromTheMiddle+2]);
                }
                if (strcasecmp(xxxyyy[fromTheMiddle], "content") == 0){
                    printf("%s", xxxyyy[fromTheMiddle+2]);
                }
                if (strcmp(xxxyyy[fromTheMiddle], "comments") == 0){
                    int number3 = 0;
                    for (int k2 = fromTheMiddle+1; k2<i; ++k2){
                        if (strcmp(xxxyyy[k2], "likes") == 0){
                            break;
                        }
                        if (strcmp(xxxyyy[k2], ":")== 0){
                            number3 += 1;
                            strcpy(array_for_comments_3[comment_variable_3], xxxyyy[k2+1]);
                            comment_variable_3 += 1;
                        }
                    }
                    strcpy(array_for_comments_3[comment_variable_3], "***");
                    comment_variable_3 += 1;
                    printf("\ncomment(s): %d\t", number3);
                }
                if (strcmp(xxxyyy[fromTheMiddle], "likes") == 0){
                    printf("likes: ");
                    char likeNumber[100];
                    strcpy(likeNumber, xxxyyy[fromTheMiddle+1]);
                    if (fromTheMiddle+1 == i-1){
                        for (int k3 = 1; k3<strlen(likeNumber)-4; ++k3){
                            printf("%c\n\n", likeNumber[k3]);
                        }
                        break;
                    }
                    else if (fromTheMiddle+1 <i-1){
                        for (int k4 = 1; k4<strlen(likeNumber)-2; ++k4){
                            printf("%c\n\n", likeNumber[k4]);
                        }
                    }
                }
                fromTheMiddle += 1;
            }
        }
    }
    printf("\n\n\n1.Show comment(s)\n2.Delete a tweet\n3.Back\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("\n\n\nPlease enter your desired action: \n");
    int inTheTweetProfileVariable;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    scanf("%d", &inTheTweetProfileVariable);
    if (inTheTweetProfileVariable == 1){
        showCommentsAfterTweetProfile();
    }
    if (inTheTweetProfileVariable == 2){
        deleteTweet();
    }
    if (inTheTweetProfileVariable == 3){
        system("CLS");
        intheapplication();
    }
    else{
        tweetProfrle();
    }
}
//-------------------------------------------------------------------------
void showCommentsAfterTweetProfile (void)
{
    //color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_GREEN);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
    //color
    printf("\nPlease enter id of tweet which you want to see its comments: \n");
    char comment_id[10];
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
    scanf("%s", comment_id);
    printf("\n\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    char for_findig_range_of_comment[10] = ":";
    strcat(for_findig_range_of_comment, comment_id);
    strcat(for_findig_range_of_comment, ",");
    for (int z1 = 0; z1<comment_variable_3; ++z1){
        if (strcmp(array_for_comments_3[z1], for_findig_range_of_comment) == 0){
            for (int z2 = z1+1; z2<comment_variable_3; ++z2){
                if (strcmp(array_for_comments_3[z2], "***") == 0){
                    break;
                }
                printf("%s\n", array_for_comments_3[z2]);
            }
        }
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("\n\nPress 0 to go back to tweet profile part\n");
    int comment_to_go_back;
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
    scanf("%d", &comment_to_go_back);
    if (comment_to_go_back == 0){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("\n-------------------------------------------------\n");
        system("CLS");
        tweetProfrle();
    }
}
//-------------------------------------------------------------------------
void deleteTweet (void)
{
    //color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_GREEN);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
    //color
    printf("\nPlease enter id of tweet which you want to delete: \n");
    char comment_id[10];
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
    scanf("%s", comment_id);
    printf("\n\n");
    char delete_tweet_request[50] = "delete ";
    strcat(delete_tweet_request, authToken);
    strcat(delete_tweet_request, ", ");
    strcat(delete_tweet_request, comment_id);
    strcat(delete_tweet_request, "\n");
    char* server_response_for_delete_tweet = client(delete_tweet_request);
    if (server_response_for_delete_tweet[9] == 'S'){
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
        printf("\nTweet deleted successfuly.\n");
        for (long long int fake = 0; fake <=1000000000; ++fake);
        system("CLS");
        tweetProfrle();
    }
    if (server_response_for_delete_tweet[27] == 'T'){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("\nThis tweet is not yours.\n");
        for (long long int fake = 0; fake <=1000000000; ++fake);
        system("CLS");
        tweetProfrle();
    }
    if (server_response_for_delete_tweet[27] == 'N'){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("\nYour tweet number is out of range.\n");
        for (long long int fake = 0; fake <=1000000000; ++fake);
        system("CLS");
        tweetProfrle();
    }
}
//-------------------------------------------------------------------------
void personalArea (void)
{
    //color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_GREEN);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    //color
    printf("1.Set bio\n2.Change password\n3.Back\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("\n\nPlease enter your desired number\n");
    int inThePersonalAreaVariable;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    scanf("%d", &inThePersonalAreaVariable);
    if (inThePersonalAreaVariable == 1){
        system("CLS");
        setBio();
    }
    if (inThePersonalAreaVariable == 2){
        system("CLS");
        changePassword();
    }
    if (inThePersonalAreaVariable == 3){
        system("CLS");
        intheapplication();
    }
    else{
        system("CLS");
        personalArea();
    }
}
//-------------------------------------------------------------------------
void setBio (void)
{
    //color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_GREEN);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
    //color
    printf("Please set your bio. But you should know that you can do it only one time.\n");
    char BioByUser[200];
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
    getchar();
    gets(BioByUser);
    char requestToServer[200] = "set bio ";
    strcat(requestToServer, authToken);
    strcat(requestToServer, ", ");
    strcat(requestToServer, BioByUser);
    strcat(requestToServer, "\n");
    char *serverAnswerForSetBio = client(requestToServer);
    //getting details
    int true_or_false;
    char message[200];
    strcpy(message, serverAnswerForSetBio);
    char *tokenPtr;
    char xxxyyy[300][30];
    tokenPtr = strtok(message, "\"");
    int i = 0;
    while (tokenPtr != NULL){
        strcpy(xxxyyy[i], tokenPtr);
        tokenPtr = strtok(NULL, "\"");
        ++i;
    }
    for (int k = 0; k<i; ++k){
        if (strcmp(xxxyyy[k], "type") == 0){
            if (strcmp(xxxyyy[k+2], "Successful") == 0) {
                true_or_false = 0;
            }
            if (strcmp(xxxyyy[k+2], "Error") == 0){
                true_or_false = 1;
            }
        }
    }
    if (true_or_false == 1){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("\n\n\n\nSorry you set your bio before:)\n");
        for (long long int fake = 0; fake <=1000000000; ++fake);
        system("CLS");
        personalArea();
    }
    if (true_or_false == 0){
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
        printf("\n\n\n\nThe operation was successful.\n");
        for (long long int fake = 0; fake <=1000000000; ++fake);
        system("CLS");
        personalArea();
    }
}
//-------------------------------------------------------------------------
void changePassword (void)
{
    //color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_GREEN);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
    //color
    printf("Please enter your current password:\n");
    char currentPassword[100];
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
    scanf("%s", currentPassword);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("Please enter your new password\n");
    char newPassword[100];
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
    scanf("%s", newPassword);
    char requestFromChangePassword[250] = "change password ";
    strcat(requestFromChangePassword, authToken);
    strcat(requestFromChangePassword, ", ");
    strcat(requestFromChangePassword, currentPassword);
    strcat(requestFromChangePassword, ", ");
    strcat(requestFromChangePassword, newPassword);
    strcat(requestFromChangePassword, "\n");
    char *serverAnswerForChangePassword = client(requestFromChangePassword);
    //getting information
//    int true_or_false;
//    char message[1000];
//    strcpy(message, serverAnswerForChangePassword);
//    char *tokenPtr;
//    char xxxyyy[1000][30];
//    tokenPtr = strtok(message, "\"");
//    int i = 0;
//    while (tokenPtr != NULL){
//        strcpy(xxxyyy[i], tokenPtr);
//        tokenPtr = strtok(NULL, "\"");
//        ++i;
//    }
//    for (int k = 0; k<i; ++k){
//        if (strcmp(xxxyyy[k], "type") == 0){
//            if (strcmp(xxxyyy[k+2], "Successful") == 0){
//                true_or_false = 0;
//            }
//            if (strcmp(xxxyyy[k+2], "Error") == 0){
//                true_or_false = 1;
//            }
//        }
//    }
    int true_or_false;
    if (serverAnswerForChangePassword[9] == 'S'){
        true_or_false = 0;
    }
    if (serverAnswerForChangePassword[9] == 'E'){
        true_or_false = 1;
    }
    if (true_or_false == 1){
        if (serverAnswerForChangePassword[27] == 'T'){
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            printf("\n\n\n\nYour new password should not be more than 16 characters.\n");
            for (long long int fake = 0; fake <= 1000000000; ++fake);
            system("CLS");
            personalArea();
        }
        else {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            printf("\n\n\n\nSorry the entered password for current password is wrong or your new password is equal to previous password\n");
            for (long long int fake = 0; fake <= 1000000000; ++fake);
            system("CLS");
            personalArea();
        }
    }
    if (true_or_false == 0){
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
        printf("\n\n\n\nYour password changed successfully.\n");
        for (long long int fake = 0; fake <=1000000000; ++fake);
        system("CLS");
        personalArea();
    }
}
//-------------------------------------------------------------------------
void logOut (void)
{
    char requestToserverForLogingOut[100] = "logout ";
    strcat(requestToserverForLogingOut, authToken);
    strcat(requestToserverForLogingOut, "\n");
    client(requestToserverForLogingOut);
    system("CLS");
    mainMenu();
}
//-------------------------------------------------------------------------
void delay (unsigned int value)
{
    unsigned  int count1 = 0;
    unsigned  int count2 = 0;
    for (count1 = 0; count1<value; count1++){
        for (count2 = 0; count2<count1; count2++);
    }
}
//-------------------------------------------------------------------------
void addFavorite (void)
{
    //color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_GREEN);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
    //color
    printf("Please write your favorite. Dont forget to put # at first.\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
    char favorite_sentence[200];
    gets(favorite_sentence);
    char final_request_for_add_favorite[500] = "add favorite ";
    strcat(final_request_for_add_favorite, authToken);
    strcat(final_request_for_add_favorite, ", ");
    strcat(final_request_for_add_favorite, favorite_sentence);
    strcat(final_request_for_add_favorite, "\n");
    char* server_response = client(final_request_for_add_favorite);
    if (server_response[9] == 'E' && server_response[27] == 'A'){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("An error aqured please try again later\n");
        for (long long int fake = 0; fake <=1000000000; ++fake);
        system("CLS");
        showFavorite();
    }
    if (server_response[9] == 'E' && server_response[27] == 'Y'){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("Your favorite massage does not have # sign.\n");
        for (long long int fake = 0; fake <=1000000000; ++fake);
        system("CLS");
        showFavorite();
    }
    if (server_response[9] == 'S'){
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
        printf("Your favorite message added successfully.\n");
        for (long long int fake = 0; fake <=1000000000; ++fake);
        system("CLS");
        showFavorite();
    }
}
//-------------------------------------------------------------------------
void showFavorite (void)
{
    //color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_GREEN);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    //color
    char showFavoriteRequest[100] = "show favorite ";
    strcat(showFavoriteRequest, authToken);
    strcat(showFavoriteRequest, "\n");
    char* serverResponse = client(showFavoriteRequest);
    char serverResponseStringMode[10000];
    strcpy(serverResponseStringMode, serverResponse);
    //tokenizing
    char *tokenPtr;
    char xxxyyy[1000][300];
    tokenPtr = strtok(serverResponse,"\"");
    int i = 0;
    while (tokenPtr != NULL){
        strcpy(xxxyyy[i], tokenPtr);
        tokenPtr = strtok(NULL, "\"");
        ++i;
    }
    int q = 1;
    for (int j = 0; j<i; ++j){
        if (j%2 == 1){
            printf("%d-%s\n", q, xxxyyy[j]);
            q += 1;
        }
    }
    printf("\n\n\n");
    afterShowFavorite();
}
//-------------------------------------------------------------------------
void afterShowFavorite (void)
{
    //color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_GREEN);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    //color
    printf("1.Add favorite\n2.Delete favorite\n3.Show notification\n4.Back\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("\nPlease enter your desired action:\n");
    int whichOne;
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
    scanf("%d", &whichOne);
    getchar();
    if (whichOne == 1){
        system("CLS");
        addFavorite();
    }
    if (whichOne == 2){
        deleteFavorite();
    }
    if (whichOne == 3){
        system("CLS");
        showNotification();
    }
    if (whichOne == 4){
        system("CLS");
        timeLine();
    }
    else{
        system("CLS");
        showFavorite();
    }
}
//-------------------------------------------------------------------------
void deleteFavorite (void)
{
    //color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_GREEN);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    //color
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("\n-------------------------------------------------\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("Which one do you want to delete?\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
    int whichone;
    scanf("%d", &whichone);
    char wichone_char[20];
    sprintf(wichone_char, "%d", whichone);
    char request_to_server[100] = "delete favorite ";
    strcat(request_to_server, authToken);
    strcat(request_to_server, ", ");
    strcat(request_to_server, wichone_char);
    strcat(request_to_server, "\n");
    char* server_response = client(request_to_server);
    if (server_response[9] == 'E' && server_response[27] == 'E'){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("Your number is out of range.\n");
        for (long long int fake = 0; fake <=1000000000; ++fake);
        system("CLS");
        showFavorite();
    }
    if (server_response[9] == 'S'){
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
        printf("Your favorite message deleted successfully.\n");
        for (long long int fake = 0; fake <=1000000000; ++fake);
        system("CLS");
        showFavorite();
    }
}
//-------------------------------------------------------------------------
void showNotification (void)
{
    //color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_GREEN);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    //color
    char notificaionRequest[100] = "notification ";
    strcat(notificaionRequest, authToken);
    strcat(notificaionRequest, "\n");
    char* server_response = client(notificaionRequest);
    char server_response_string_mode[10000];
    strcpy(server_response_string_mode, server_response);
    char *tokenPtr;
    char xxxyyy[1000][300];
    tokenPtr = strtok(server_response_string_mode,"\"");
    int i = 0;
    while (tokenPtr != NULL){
        strcpy(xxxyyy[i], tokenPtr);
        tokenPtr = strtok(NULL, "\"");
        ++i;
    }
    int j = 0;
    for (int k = 0; k<i; ++k){
        if (strcmp(xxxyyy[k], "id")==0){
            strcpy(number, xxxyyy[k+1]);
            strcpy(array_for_comments[comment_variable], xxxyyy[k+1]);
            comment_variable +=  1;
        }
        if (strcmp(xxxyyy[k], "author")==0){
            printf("%s ", xxxyyy[k+2]);
            for (int k1 = 1; k1<strlen(number)-1; ++k1){
                printf("%c", number[k1]);
            }
        }
        if (strcasecmp(xxxyyy[k], "content") == 0){
            printf("\n%s", xxxyyy[k+2]);
        }
        if (strcmp(xxxyyy[k], "comments") == 0){
            int number2 = 0;
            for (int k2 = k+1; k2<i; ++k2){
                if (strcmp(xxxyyy[k2], "likes") == 0){
                    break;
                }
                if (strcmp(xxxyyy[k2], ":")== 0){
                    number2 += 1;
                    strcpy(array_for_comments[comment_variable], xxxyyy[k2+1]);
                    comment_variable += 1;

                }
            }
            strcpy(array_for_comments[comment_variable], "***");
            comment_variable += 1;
            printf("\ncomment(s): %d\t", number2);
        }
        if (strcmp(xxxyyy[k], "likes") == 0){
            printf("likes: ");
            char likeNumber[100];
            strcpy(likeNumber, xxxyyy[k+1]);
            if (k+1 == i-2){
                for (int k3 = 1; k3<strlen(likeNumber)-4; ++k3){
                    printf("%c\n\n", likeNumber[k3]);
                }
            }
            else{
                for (int k4 = 1; k4<strlen(likeNumber)-3; ++k4){
                    printf("%c\n", likeNumber[k4]);
                }
            }
        }
    }
    printf("-------------------------------------------------");
    afterRefresh();
}
//-------------------------------------------------------------------------