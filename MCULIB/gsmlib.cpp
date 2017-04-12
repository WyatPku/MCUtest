#include "gsmlib.h"

GSM_outCom GSM_send;
GSM_voidFunction GSM_delay100ms;
GSM_printFunction GSM_dprint;

void delay1s() {
    int i = 10;
    while (i--) GSM_delay100ms();
}

void connect() {
    GSM_send("AT+CIPSTART=\"TCP\",\"");
    GSM_send(serverIP);
    GSM_send("\",");
    GSM_send(serverPort);
    GSM_send("\n");
}

void GSM_Initial() {
    GSM_dprint("initializing!!");
    connect();
    delay1s();
    GSM_dprint("initial finished");
}

void GSM_input(char c) {
    c = ' ';
}

void GSM_SendString(const char* s) {
    int length = strlen(s);
    GSM_dprint("Send String!");
    while (s[length]) ++length;

}
