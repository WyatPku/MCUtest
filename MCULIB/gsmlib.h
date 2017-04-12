#ifndef GSMLIB_H
#define GSMLIB_H
#include <string.h>
typedef void (*GSM_outCom)(const char* c);
typedef void (*GSM_voidFunction)();
typedef void (*GSM_printFunction)(const char* s);

//below things need to modify constant

const char serverIP[] = "60.205.187.189";
const char serverPort[] = "12002";

//below thing need to set value
extern GSM_outCom GSM_send; //crowded
extern GSM_voidFunction GSM_delay100ms;
extern GSM_printFunction GSM_dprint;

void GSM_input(char c);
void GSM_Initial();
void GSM_SendString(const char* s);

#endif // GSMLIB_H
