
//***********************************************************************
//*																		*
//* Company:	Miltronics, Inc.									 	*
//*				115 Industrial East										*
//*				Clifton, NJ  07012										*
//*																		*
//*				Phone: (973) 471-7700									*
//*																		*
//* Engineer:	Daniel L. & Jesus E.									*
//* 																	*
//* Create Date:    12:00:00 10/27/2018	 								*
//* Module Name:    main.c												*
//* Project Name:   Custome Contact Management Database					*
//* Target Devices: 32/64 Bit x86 Architectures							*
//* Tool versions:  Code::Blocks/Sublime 3/GCC GDB/						*
//*																		*
//* Dependencies: 														*
//*																		*
//* Revision:		0.001												*
//* Additional Comments:  Set your tab stops to 4.						*
//*																		*
//* (C) Miltronics, Inc. (2018)											*
//* Miltronics, Inc. owns the sole copyright to this					*
//* software. Under international copyright laws you (1) may not make	*
//* a copy of this software except for the purposes of maintaining a	*
//* single archive copy, (2) may not derive works herefrom, (3) may not	*
//* distribute this work to others. These rights are provided for		*
//* information clarification, other restrictions of rights may apply	*
//* as well.															*
//*																		*
//***********************************************************************


#include <stdio.h>
#include <stddef.h>
#include <string.h>


//Global MACRO's
#define PHONEBUFFER 11                                          	//SIZE OF THE PHONEBUFFER, 10 digits plus 1 extra for fgets/printf string requirement
#define UIDBUFFER    8												//SIZE OF THE UIDBUFFER, 7 digits plus 1 extra for fgets/printf string requirement

//Global Variable Definitions/Initializations
int  PNoffset = 0;                                                  //Phone number offset used to calculate UID
char PhoneNumber[PHONEBUFFER];
char UniqueID[UIDBUFFER];

//Global Pointer Definitions/Initializations;
char *ptrUID  = &UniqueID[0];
char *ptrPN   = &PhoneNumber[0];

//Function prototypes

//PhoneToUniqueID: Converts phone number to unique id value
void PhoneToUniqueId(char *UID,char *PN)
{
//POINTER ARGUMENTS: UID --> UniqueID  & PB --> PhoneBuffer

//Intialize UniqueID index # 7 to EOL character '\0', forces printf to terminate line after printing id
*(UID + 7) = '\0';

//Loop through phone number buffer to extract area code and last 4 digits (973)897-8742 --> unique id = 9738742
    for(int j = 0; j<UIDBUFFER-1;j++)
    {
        *(UID + j) = *(PN+j+PNoffset);                                   //koffset = 0 initially , koffset = 3 when pointer reaches 4th digit in phone number
        if(j==2)                                                        //4th digit of phone number = index value # 3
        {
            PNoffset=3;                                                  //Initiate offset to forward pointer to 7th digit
        }
    }

    printf("\n\nThis is your unique ID number: %s\n\n",(UID));          //***This Line only used for development*** MUST REMOVE

    for(int i = 0;i <UIDBUFFER-1;i++)                               	//***This Line only used for development*** MUST REMOVE
    {
        printf("\npointer = %p",(UID+i));                               //***This Line only used for development*** MUST REMOVE
        printf("\t\tvalue = %c", *(UID+i));                             //***This Line only used for development*** MUST REMOVE
    }

}

//**********************************************************************//
void UserPromptInit(void)
{
//This is the initialization prompt for the user
    printf("Welcome to the CCMD: Customer Contact Management Database\n\n");

//***This is a sample prompt*** Must be replaced by true console menu options # 0-9


    printf("\nEnter a phone number:\n");                                //Prompt the user for a phone number
    fgets(PhoneNumber,PHONEBUFFER,stdin);                               //Reads one less char limited by PHONEBUFFER from stream
                                                                        //stores them into the buffer pointed to by PhoneNumber

    //***Next Line only used for development*** MUST REMOVE
    printf("\nThis is your phone number: %s\n",PhoneNumber);            //Re-print the phone number contained in the phone buffer

    //***Next Loop only used for development*** MUST REMOVE
    for(int i = 0;i<sizeof(PhoneNumber)-1;i++)
    {
        printf("\npointer = %p",(ptrPN+i));
        printf("\t\tvalue = %c", *(ptrPN+i));
    }
}



int main(char argc, char* argv[])
{
    UserPromptInit();
    PhoneToUniqueId(ptrUID,ptrPN);

    char eol;

    printf("\nDo you want to end? (Press Return): ");

    while(scanf("%c",&eol)>0)
	{
	    scanf("%c", &eol);
	    if(eol == '\n')
        	{
            	break;
        	}
	}

	return 0;
    }

