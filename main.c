/*

NAME:PASUPULA DIVYA SAI
DATE: 17/12/2025
DESCRIPTION: AddressBook Project which lists contacts and operation list is as follows

              1.Create contact
              2.Edit contact
              3.Search contact
              4.Delete contact
              5.List contacts
              6.Save contact


*/






#include <stdio.h>
#include "contact.h"
#include "populate.h"

int main() 
{ 

       
        int choice;
        AddressBook var;
        var.contactCount=0;
        initialize(&var);
    //print menu and read choice from user
   
    do
    {
      
       printf("----Address Book Menu-----\n");
       printf("1.Create contact\n");
       printf("2.Edit contact\n");
       printf("3.Search contact\n");
       printf("4.Delete contact\n");
       printf("5.List contacts\n");
       printf("6.Save contact\n");
       printf("7.exit\n");

       
       printf("Enter your choice (1-7): \n");
       scanf("%d",&choice);

   //select choice from the given menu
    

       switch (choice)
       {
       case 1:
              printf("Enter details to add:\n");
              createContact(&var);
              break;
       case 2:
             printf("Enter the name of contact to edit :\n");
              editContact(&var);
              break;
        case 3:
             printf("Enter the contact to search :\n");
             searchContact(&var);
              break;
       case 4:
               printf("Enter name of the contact to delete :\n");
              deleteContact(&var);
              break;
       case 5:
              printf("CONTACT LIST\n");
              listContacts(&var);
              break;
       case 6:
             saveContactsToFile(&var);
              break;
       case 7:
              printf("program exiting");
              break;

       default:
       printf("Invalid choice, enter a value between 1 to 7\n");
              break;
       }


 } while (choice!=7);
       return 0;
}
