#include <stdio.h>
#include<string.h>
#include "contact.h"
#include "populate.h"

int j;
/*This function is to print contactList from AddressBook*/
void listContacts(AddressBook *addressBook) 
{
  

    
    printf("-----Contact List-----\n");
    for(int i=0; i < addressBook->contactCount;i++)
    {
        //printf("%d",i+1);
        printf(" %s\t  ",addressBook->contacts[i].name);
        printf(" %s\t ",addressBook->contacts[i].phone);
        printf(" %s\n",addressBook->contacts[i].email);
    }
}

/*This function is to initialise the contactlist*/
void initialize(AddressBook *addressBook) 
{
 //copy contact from file to addressbook
      populateAddressBookFromFile(addressBook);
}

/*This function is to Save contacts to file*/
void saveContactsToFile(AddressBook *addressBook)
 {

    //open a file
    FILE *fp;
    fp=fopen("file.txt","w");
  //check is opening or not
    if(fp == NULL)
    {
        printf("Error opening file");
        
    }

    for(int i=0;i<=addressBook->contactCount;i++)
    {
          fprintf(fp," %s\t   ",addressBook->contacts[i].name);
          fprintf(fp," %s\t ",addressBook->contacts[i].phone);
          fprintf(fp," %s\n",addressBook->contacts[i].email);
    } 
 
  printf("%d\n",addressBook->contactCount);
  fclose(fp);   
}

/*This function is to create a new contact in Addressbook*/
void createContact(AddressBook *addressBook)
{
  //Take input from user with details - Name,Mobile no,Email ID
      printf("Enter Name:");
      scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
      
      printf("Enter Mobile No:");
      scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].phone);
      
      printf("Enter Email ID:");
      scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].email);
      printf("Contact  added successfully!!!\n");
   
    addressBook->contactCount++;
    printf("%d",addressBook->contactCount);
}
/*This function is to search contact from Addressbook*/

void searchContact(AddressBook *addressBook) 
{
    
    char nametobefound[20];
    int flag=0;
    // enter user choice to search contact
    printf("Enter the name to search");
    scanf(" %[^\n]",nametobefound);
   
    for(int i=0;i<addressBook->contactCount;i++)
    {
          if(strcmp(nametobefound,addressBook->contacts[i].name) == 0)
          {
            //if contact is  found
              printf("Contact found!!!\n Here are the details:\n");
              flag=1;
              printf(" Name: %s \t\n MobileNo:%s \t\n emailID:%s \n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
              j=i;
              break;
          }
      
    }
      // if not found
      if(flag==0)
      {
       printf("Contact not found");
      }

} 


/*This function is to Edit a contact*/
void editContact(AddressBook *addressBook)
{
  //read name to be searched
  
      int option;
      searchContact(addressBook);
    
    printf("Enter what you want to edit:\n");
    printf("1.Name\n2.Phone no\n3.Email ID\n");
    printf("Enter your choice:\n");
    scanf(" %d",&option);

    switch (option)
    {
        case 1 :
          //read new name
            printf("Enter new name:");
            scanf(" %[^\n]",addressBook->contacts[j].name);

            printf("Name updated successfully!!! ");
            break;
        case 2 : 
          //read new phone no
             printf("Enter new phone no:");
            scanf(" %[^\n]",addressBook->contacts[j].phone);
           // scanf(" %10[0-9]",addressBook->contacts[j].phone);

            printf("Phone no updated successfully!!! ");
            break;
        case 3 : 
          //read new email id
            printf("Enter Email ID:");
            scanf(" %[^\n]",addressBook->contacts[j].email);

            printf("Email ID updated successfully!!! ");
            break;
        default:
          break;
    }   
}


/*This function is to delete contact from Adress*/
void deleteContact(AddressBook *addressBook)
{
   char nametobedeleted[20];
   int flag=0;
  
  //read name to be searched
   scanf(" %[^\n]",nametobedeleted);
   for(int i=0;i<addressBook->contactCount;i++)
    {
        //compare the name to be deleted if present in contactlist or not
          if(strcmp(nametobedeleted,addressBook->contacts[i].name) == 0)
          {
                printf("Contact found");
                flag=1;
                j=i;
                break;
          }
            
        //if not found      
     }
      if(flag==0)
      {
          printf("Contact not found");
      }

     int index=j;

     for(int i=0;i<addressBook->contactCount;i++)
     {
        strcpy(addressBook->contacts[index+i].name,addressBook->contacts[index+i+1].name);
        strcpy(addressBook->contacts[index+i].phone,addressBook->contacts[index+i+1].phone);
        strcpy(addressBook->contacts[index+i].email,addressBook->contacts[index+i+1].email);

     }
 printf("Contact deleted succesfully!!!");
}

