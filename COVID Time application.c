#include<stdio.h>
#include<string.h>
#include <stdlib.h>

// initializing variables 

int nxtpatient , i=0 , process , j=0 , allotment_num=0 ;
struct patient 
{
    int age , symptom_level , oxygen_level , temperature , id  , wish ;
    char patient_name[20] , hospital_alloted[50] ;
     
} p[1000] ;

struct hospital
{
    int  total_seat , occupied_seat , vacant_seat , elgibility_criteria  ;
    char name[50] , status[50] ;
} gh1[100] , gh2[100] , ph1[100] , ph2[100]  ;

void hospital_1 ();
void hospital_11 ();
void hospital_2 ();
void hospital_22 ();
void hospital_3 ();
void hospital_33 ();
void hospital_4 ();
void hospital_44 ();


// main function

void main()
{
    
    hospital_1 ();
    hospital_11 ();
    hospital_2 ();
    hospital_22 ();
    hospital_3 ();
    hospital_33 ();
    hospital_4 ();
    hospital_44 ();   
   
    while(1)
    {
        printf("To add next patient press 1 \n");
        printf("if you need to get the vacent and occupied seat list in hospital press 2 \n");
        printf("if you need to get the patient detials press 3 \n\n");
        scanf("%d",&process);
        switch (process)
        {
            case 1 : 
            {
                printf("\n\n***********WELCOME***********\n");   
                printf("Is there next patient \nis yes press 0 \nif no press any number\n");
                scanf("%d\n",&nxtpatient);
                if (nxtpatient == 0)
                {
                    i++;
                    p[i].id = i;
                    fflush(stdin);
                    printf("\nenter the patient's name : \n");
                    scanf("%[^\n]s",p[i].patient_name);
                    fflush(stdin);
                    printf("enter the patient's age : \n");
                    scanf("%d",&p[i].age);
                    fflush(stdin);
                    printf("enter the patient's temparature in farenheit (97 to 110) [above 98 fever] : \n");
                    scanf("%d",&p[i].temperature);
                    fflush(stdin);
                    printf("enter the patient's oxygen level obtained in pulse oximetry in percent (below 95 critical): \n");
                    scanf("%d",&p[i].oxygen_level);  /* 96 - 98 - 115   95-100*/ 
                    if (p[i].temperature > 98 || p[i].oxygen_level < 95 )
                    {
                        p[i].symptom_level = 1 ;
                    }else
                    if (p[i].temperature <= 98 || p[i].temperature >= 96 || p[i].oxygen_level >= 95 || p[i].oxygen_level <= 100 )
                    {
                        p[i].symptom_level = 2 ;
                    }
                    printf("Ask the patient that he wants to admit in the government or private hospital \n");
                    printf("if government hospital press 1 \n");
                    printf("if private hospital press 2  \n");
                    scanf("%d",&p[i].wish);
                    if (p[i].symptom_level == 1 && p[i].wish == 1 )
                    {
                        allotment_num = 11 ;
                    }else
                    if (p[i].symptom_level == 1 && p[i].wish == 2 )
                    {
                        allotment_num = 12;
                    }
                    else
                    if (p[i].symptom_level == 2 && p[i].wish == 1 )
                    {
                        allotment_num = 21;
                    }else
                    if (p[i].symptom_level == 2 && p[i].wish == 2 )
                    {
                        allotment_num = 22;
                    }
                    
                    switch (allotment_num)
                    {
                        case 11:
                        {
                            printf("This patient has high symptoms and he asks for government hospital \n\n\n");
                            if(gh1[j].vacant_seat == 0)
                            {
                                j++;
                                strcpy(gh1[j-1].status,"closed");
                            }
                            gh1[j].occupied_seat++;
                            gh1[j].vacant_seat--; 
                            puts(p[i].patient_name);                           
                            printf("the patient is admitted in : \n");
                            strcpy(p[i].hospital_alloted,gh1[j].name);
                            printf("%s\n",p[i].hospital_alloted);     
                            printf("He/She will be discharged after 14 days\n\n");
                        }
                            break;
                        case 12:
                        {
                            printf("This patient has high symptoms and he asks for private hospital \n\n\n");
                            if(ph1[j].vacant_seat == 0)
                            {
                                j++;
                                strcpy(ph1[j-1].status,"closed");
                            }
                            ph1[j].occupied_seat++;
                            ph1[j].vacant_seat--;
                            puts(p[i].patient_name);
                            printf("the patient is admitted in : ");
                            strcpy(p[i].hospital_alloted,ph1[j].name);
                            printf("%s\n",p[i].hospital_alloted);
                            printf("He/She will be discharged after 14 days \n\n");
                        }
                            break;
                        case 21:
                        {
                            printf("\nThis patient has less symptoms and he asks for government hospital \n\n\n ");
                            if(gh2[j].vacant_seat == 0)
                            {
                                j++;
                                strcpy(gh2[j-1].status,"closed");
                            }
                            gh2[j].occupied_seat++;
                            gh2[j].vacant_seat--;
                            puts(p[i].patient_name);
                            printf("the patient is admitted in : ");
                            strcpy(p[i].hospital_alloted,gh2[j].name);
                            printf("%s\n",p[i].hospital_alloted);
                            printf("He/She will be discharged after 7 days\n\n");
                        }   
                            break;
                        case 22:
                        {
                            printf("This patient has low symptoms and he asks for private hospital \n\n\n");
                            if(ph2[j].vacant_seat == 0)
                            { 
                                j++;
                                strcpy(ph2[j-1].status,"closed");
                            }
                            ph2[j].occupied_seat++;
                            ph2[j].vacant_seat--;
                 
                            puts(p[i].patient_name);
                            printf("the patient is admitted in : ");
                            strcpy(p[i].hospital_alloted,ph2[j].name);
                            printf("%s\n",p[i].hospital_alloted);
                            printf("He/She will be discharged after 7 days\n\n");
                        }
                            break;
                    default:
                        break;
                    }
                    allotment_num = 0;
                }
            printf("**********************\n");
            }
            break;
            case 2 :
            {                
                printf("\n***********WELCOME***********\n\n");
                j++;
                while(j>=0)
                {
                    fflush(stdin);
                    printf("%s\n",gh1[j].name);
                    printf("vacent seats : %d \n",gh1[j].vacant_seat);
                    printf("occupied seats : %d \n",gh1[j].occupied_seat);
                    printf("%s\n\n",gh1[j].status);
                    printf("%s\n",gh2[j].name);
                    printf("vacent seats : %d \n",gh2[j].vacant_seat);
                    printf("occupied seats : %d \n",gh2[j].occupied_seat);
                    printf("%s\n\n\n",gh2[j].status);
                    printf("%s\n",ph1[j].name);
                    printf("vacent seats : %d\n",ph1[j].vacant_seat);
                    printf("occupied seats : %d \n",ph1[j].occupied_seat);
                    printf("%s\n\n",ph1[j].status);
                    printf("%s\n",ph2[j].name);
                    printf("vacent seats : %d \n",ph2[j].vacant_seat);
                    printf("occupied seats : %d \n",ph2[j].occupied_seat);
                    printf("%s\n",ph2[j].status);
                    j--;
                }
            printf("\n**********************\n\n");
            }
            break;
            case 3 :
            {
                printf("\n***********WELCOME***********\n\n");
                i++;
                while(i--)
                {
                    if(i == 0)
                    break;
                    else
                    {
                        fflush(stdin);
                        printf("ID : %d\n",p[i].id) ;
                        printf("NAME :");
                        puts(p[i].patient_name);
                        printf("AGE :");
                        printf("%d\n",p[i].age);
                        printf("HOSPITAL ALLOTED :");
                        printf("%s\n\n\n",p[i].hospital_alloted);
                    }
                }
            printf("**********************\n\n");
            }
            break;
        default:
            break;
        }
        
    }
}

/*  
ELEGIBILITY CRITERIA OF THE HOSPITAL
ELEGIBILITY CRITERIA = 11 MEANS IT CAN HANDLE PATIENTS WITH LOW O2 LEVEL AND ANY TEMPERATURE (private hospitals)
ELEGIBILITY CRITERIA = 21 MEANS IT CAN HANDLE PATIENTS WITH ANY TEMPERATURE (private hospitals)
                         BUT IT CANOT HANDLE THE PATIENTS WITH LOW O2 LEVEL

ELEGIBILITY CRITERIA = 11 MEANS IT CAN HANDLE PATIENTS WITH LOW O2 LEVEL AND ANY TEMPERATURE (government hospitals)
ELEGIBILITY CRITERIA = 21 MEANS IT CAN HANDLE PATIENTS WITH ANY TEMPERATURE (government mini clincs)
                         BUT IT CANOT HANDLE THE PATIENTS WITH LOW O2 LEVEL
*/

void hospital_1 ()
{
    strcpy(gh1[0].name,"AIIMS") ;
    gh1[0].total_seat = 10;
    gh1[0].occupied_seat = 0;
    gh1[0].vacant_seat = 10;
    gh1[0].elgibility_criteria = 11 ;
    strcpy(gh1[0].status,"opened");
}
void hospital_11 ()
{
    strcpy(gh1[1].name,"JIPMER") ;
    gh1[1].total_seat = 10;
    gh1[1].occupied_seat = 0;
    gh1[1].vacant_seat = 10;
    gh1[1].elgibility_criteria = 11 ;
    strcpy(gh1[1].status,"opened");
}
void hospital_2 ()
{
    strcpy(gh2[0].name,"AMMA_CLINIC_1") ;
    gh2[0].total_seat = 10 ;
    gh2[0].occupied_seat = 0;
    gh2[0].vacant_seat = 10;
    gh2[0].elgibility_criteria = 12 ;
    strcpy(gh2[0].status,"opened");
}
void hospital_22 ()
{
    strcpy(gh2[1].name,"AMMA_CLINIC_2") ;
    gh2[1].total_seat = 10 ;
    gh2[1].occupied_seat = 0;
    gh2[1].vacant_seat = 10;
    gh2[1].elgibility_criteria = 12 ;
    strcpy(gh2[1].status,"opened");
}
void hospital_3 ()
{
    strcpy(ph1[0].name,"VELLAMAL_MULTISPECIALITY_HOSPITAL");
    ph1[0].total_seat = 10 ;
    ph1[0].occupied_seat = 0;
    ph1[0].vacant_seat = 10;
    ph1[0].elgibility_criteria = 21 ;
    strcpy(ph1[0].status,"opened");
}
void hospital_33 ()
{
    strcpy(ph1[1].name,"MENAKSHI_MISSION_MULTISPECIALITY_HOSPITAL");
    ph1[1].total_seat = 10 ;
    ph1[1].occupied_seat = 0;
    ph1[1].vacant_seat = 10;
    ph1[1].elgibility_criteria = 21 ;
    strcpy(ph1[1].status,"opened");
}
void hospital_4 ()
{
    strcpy(ph2[0].name,"MANI CLINIC");
    ph2[0].total_seat = 10 ;
    ph2[0].occupied_seat = 0;
    ph2[0].vacant_seat = 10;
    ph2[0].elgibility_criteria = 22 ;
    strcpy(ph2[0].status,"opened");
}
void hospital_44 ()
{
    strcpy(ph2[1].name,"KANI CLINIC");
    ph2[1].total_seat = 10 ;
    ph2[1].occupied_seat = 0;
    ph2[1].vacant_seat = 10;
    ph2[1].elgibility_criteria = 22 ;
    strcpy(ph2[1].status,"opened");
}