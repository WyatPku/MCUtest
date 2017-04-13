#include "gsmlib.h"

GSM_outCom GSM_send;
GSM_voidFunction GSM_delay100ms;
GSM_printFunction GSM_dprint;
GSM_Do GSM_SetMotorLevel;
char commandStr[50]; //max length is 49
char receivedStr[50]; //with \n as the tail
int receivedCount;
#define GSM_NoConnect 0
#define GSM_Transparent 1
static int state = GSM_NoConnect;

void delay1s() {
    int i = 10;
    while (i--) GSM_delay100ms();
}

void connect() {
    GSM_dprint("setting as transparent TCP");
    sprintf(commandStr, "AT+CIPMODE=1\n");
    GSM_send(commandStr, (int)strlen(commandStr));
    delay1s();
    GSM_dprint("connecting!");
    sprintf(commandStr, "AT+CIPSTART=\"TCP\",\"%s\",%s\n",
            serverIP, serverPort);
    int length = (int)strlen(commandStr);
    GSM_send(commandStr, length);
    delay1s();
}

void GSM_Disconnect() {
    state = GSM_NoConnect;
    //first quit the transparent mode
    delay1s();delay1s();
    GSM_send("+++", 3);
    delay1s();delay1s();
    sprintf(commandStr, "\nAT+CIPSHUT\n");
    GSM_send(commandStr, (int)strlen(commandStr));
    delay1s();
}

void GSM_Initial() {
    GSM_dprint("initializing!!");
    connect();
    GSM_dprint("initial finished");
    //state = GSM_Transparent;
}

void GSM_input(char c) {
    if (state == GSM_NoConnect) {
        if (c == '\n') {
            //one command end
            receivedStr[receivedCount] = 0; //"\r"
            receivedCount = 0;
            GSM_dprint(receivedStr);
            if (strcmp(receivedStr, "CONNECT\r") == 0) {
                GSM_dprint("got a CONNECT into transparent mode");
                state = GSM_Transparent;
            }
        }
        else {
            receivedStr[receivedCount] = c;
            ++receivedCount;
            receivedCount %= 50;
        }
    } else {
        receivedCount = 0;
        receivedStr[0] = 0;
    }
    if (state == GSM_Transparent && c < '9' && c > '0') {
        GSM_SetMotorLevel(c - '0');
    }
}

void GSM_SendString(const char* s) {
    int length = (int)strlen(s);
    GSM_dprint("Send String!");
    while (s[length]) ++length;

}
