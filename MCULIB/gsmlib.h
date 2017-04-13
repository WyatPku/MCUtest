#ifndef GSMLIB_H
#define GSMLIB_H
#include <cstring>
#include <cstdlib>
#include <cstdio>
typedef void (*GSM_outCom)(const char* s, int length);
typedef void (*GSM_voidFunction)();
typedef void (*GSM_printFunction)(const char* s);
typedef void (*GSM_Do)(int cmd);

//below things need to modify constant

const char serverIP[] = "60.205.187.189";
const char serverPort[] = "12000";

//below thing need to set value
extern GSM_outCom GSM_send; //crowded
extern GSM_voidFunction GSM_delay100ms;
extern GSM_printFunction GSM_dprint;
extern GSM_Do GSM_SetMotorLevel;

void GSM_input(char c);
void GSM_Initial();
void GSM_SendString(const char* s);
void GSM_Disconnect();

#endif // GSMLIB_H
