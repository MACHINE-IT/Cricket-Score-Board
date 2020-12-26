#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<windows.h>
#include<winbase.h>
#include<stdlib.h>


struct team
{
       char teamA[20];
       char teamB[20];
       char ground[20];
       int scoreA,scoreB,wicketsA,wicketsB;
       float oversA,oversB,runrateA,runrateB;
}s1,s2,s3;

void add();
void view();
void display(int);
void update();
void Delete();
int search();
void sort();
void addupdate();

int main()
{
	char option;
	system("color ff");
	
	  
                 printf("                                     =================================\n");                                                                                 /////////
                 printf("                                    || WELCOME TO mycricinfo (V 1.0) ||\n"); 
				 printf("                                     =================================");       
	printf("\n\n\nPlease choose your desired option : ");
	printf("\n\n\n\n1. Add a new record");
	printf("\n\n2. View the records");	
	printf("\n\n3. Delete a record");
	printf("\n\n4. Update a record");
	printf("\n\n5. Search");
	printf("\n\n6. Exit\n\n=> "); 

    scanf("%d",&option);
    
    
    switch(option)
	{
		case 1:add();   break;
		case 2:view();   break;
		case 3:Delete();   break;
		case 4:update();   break;
		case 5:search();   break;
		case 6:{
			      system("cls");   exit(0);
		         }     break;
			 	   break;

		default :
		printf("wrong choice!!!!");		
	}
	
}
void add()
{       
                                                                                                                         
	  system("cls");                                                                                                             
	int n;                                                                                                                                                                                                                                 ////////                                                                                                      /////////
      int option;                                                                            
	FILE *matchfile;                                                                                                      
	matchfile=fopen("record.txt","a");
while (1)
{	
	
                 printf("                                     ============================\n");                                                                                 /////////
                 printf("                                    || Adding new match details ||\n"); 
				 printf("                                     ============================");      
	
	
	 printf("\nTeam which won toss");
	 printf("\n\n                        NAME OF THIS TEAM : ");  fflush(stdin); gets(s1.teamA);
	 printf("                        SCORE OF THIS TEAM :");  fflush(stdin); scanf("%d",&s1.scoreA);
	 printf("                        OVERS PLAYED BY THIS TEAM : "); fflush(stdin); scanf("%f",&s1.oversA);	
	  s1.runrateA=s1.scoreA/s1.oversA; 
	 printf("                        RUNRATE OF THIS TEAM : %.2f",s1.runrateA); 
	 	 printf("\n                        WICKETS LOST :");  fflush(stdin); scanf("%d",&s1.wicketsA);

	 
	
	
	
	printf("\nOpposition team  ");
	 printf("\n\n                        NAME OF THIS TEAM : ");  fflush(stdin); gets(s1.teamB);
	 printf("                        SCORE OF THIS TEAM :");  fflush(stdin); scanf("%d",&s1.scoreB);
	 	 printf("                        OVERS PLAYED BY THIS TEAM : "); fflush(stdin); scanf("%f",&s1.oversB);

	 s1.runrateB=s1.scoreB/s1.oversB; 
	 printf("                        RUNRATE OF THIS TEAM : %.2f",s1.runrateB);
	 	 	 printf("\n                        WICKETS LOST :");  fflush(stdin); scanf("%d",&s1.wicketsB);

	 
	 printf("\n\nNAME OF THE GROUND : "); fflush(stdin); gets(s1.ground);
	fwrite(&s1,sizeof(s1),1,matchfile);
		fclose(matchfile);

	exit :
		printf("\n\nPress 1 to Go back\n\n=> ");
	scanf("%d",&option);
	switch(option)
	{
		case 1: system("cls"); main();
		default :{			
		                printf("Incorrect input\n\n");
		                goto exit;		                
	             }
	}
}

}

void view()
{  sort();
  char teamA[25],teamB[25];
  int score,wickets;
  float over,runrate;
  
int option;	
	system("cls");
	FILE *matchfile1; 
	             printf("                                               ==================\n");                                                                                 /////////
                 printf("                                              || HIGHEST TOTALS ||\n"); 
				 printf("                                               ==================");                                                                                        /////////
           printf("\n\n\n");
           printf("\n ============================================================================================================");
           printf("\n||\t%-1s\t%-3s\t\t%-1s\t\t%-2s\t\t%-5s\t%-5s \t    ||","NAME OF TEAM WON","SCORE","OVERS","RR","OPPOSITION","GROUND");
	       printf("\n ============================================================================================================");
	      	matchfile1=fopen("record.txt","r");
	      	
	      	if(matchfile1==NULL)
	      	{
	      		puts(" Cannnot open file");
	      		exit(1);
			  }          
           
            while(fread(&s2,sizeof(s2),1,matchfile1))
            {if(s2.scoreA>s2.scoreB)
               {
               	strcpy(teamA,s2.teamA);
               	strcpy(teamB,s2.teamB);
               	score=s2.scoreA;
               	over=s2.oversA;
               	runrate=s2.runrateA;
               	wickets=s2.wicketsA;
			   }
			   else
			   {
               	strcpy(teamA,s2.teamB);
               	strcpy(teamB,s2.teamA);
               	score=s2.scoreB;
               	over=s2.oversB;
               	runrate=s2.runrateB;
               	wickets=s2.wicketsB;
			   }
			   
            printf("\n||\t%-7s ",teamA);       int l,i;  while(i!=0) {   l++; i=i/10;			}
            printf("\t\t%-ld/%d ",score,wickets);
            printf("\t\t%-2.2f ",over);
            printf("\t\t%-2.2f ",runrate);
            printf("\t\t%-5s ",teamB);
            printf("\t%-5s ",s2.ground);
        
        
        }
          // printf("\n||\t%-7s \t%-5s \t%-2s \t%-2s \t%-5s\t%-5s ||",s1.teamA,s1.scoreA,s1.oversA,s1.runrateA,s1.teamB,s1.ground);//printf("\n\n my code worked till here !");  //


            fclose(matchfile1);
              exit :
		printf("\n\nPress 1 to Go back\n\n=> ");
	scanf("%d",&option);
	switch(option)
	{
		case 1: system("cls"); main();
		default :{			
		                printf("Incorrect input\n\n");
		                goto exit;		                
	             }
	}                     
        
            
}
void display(int n)
{
int option;	
	system("cls");
	FILE *matchfile1;                                                                                                      /////////
	       printf("\n =======================================================================================================");
           printf("\n||\t%-1s\t%-3s\t\t%-1s\t\t%-2s\t\t%-5s\t%-5s ||","NAME OF TEAM WON","SCORE","OVERS","RR","OPPOSITION","GROUND");
	       printf("\n =======================================================================================================");
	      	matchfile1=fopen("record.txt","r");
	      	
	      	if(matchfile1==NULL)
	      	{
	      		puts(" Cannnot open file");
	      		exit(1);
			  }          
           fseek(matchfile1,n-sizeof(s2),SEEK_SET);
            while(fread(&s2,sizeof(s2),1,matchfile1))
            {
            printf("\n||\t%-7s ",s2.teamA);
            printf("\t\t%-5d ",s2.scoreA);
            printf("\t%-2f ",s2.oversA);
            printf("\t%-2f ",s2.runrateA);
            printf("\t%-5s ",s2.teamB);
            printf("\t\t%-5s ",s2.ground);
            break;
        }
          // printf("\n||\t%-7s \t%-5s \t%-2s \t%-2s \t%-5s\t%-5s ||",s1.teamA,s1.scoreA,s1.oversA,s1.runrateA,s1.teamB,s1.ground);//printf("\n\n my code worked till here !");  //


            fclose(matchfile1);
              exit :
		printf("\nPress 1 to Go back\n\n=> ");
	scanf("%d",&option);
	switch(option)
	{
		case 1: system("cls"); main();
		default :{			
		                printf("Incorrect input\n\n");
		                goto exit;		                
	             }
	}            	
}
int search()
{   int temp;    int flag=0;         int option;
    system("cls");
               FILE *fp;
    fp=fopen("record.txt","r");
    if(fp==NULL)
    {
    	printf("\n file not found!!!!!!");
    	
	}
	else
{
		
    char teamA[20];
       char teamB[20];
       char ground[20];
       float overs;
    
    int choice;

                 printf("                                     =============================\n");                                                                                 /////////
                 printf("                                    || Search for highest record ||\n"); 
				 printf("                                     =============================");     
	printf("\n\n\n==========MENU===========================\n\n");
	printf("\n 1. On the basis of team who won toss.");
	printf("\n 2. On the basis of opposition team.");
	printf("\n 3. On the basis of ground.");
	printf("\n 4. On the basis of over.");
	printf("\n 5. Go back.");
	printf("\n\n Enter your choice  :  ");
	scanf("%d",&choice);
	                            
	switch(choice)
	{
		case 1 :
			{   
			    system("cls");
			   fflush(stdin);  
               	printf("\nEnter team name  :   ");
               	fflush(stdin);
				gets(teamA);
					       printf("\n =======================================================================================================");
	printf("\n||\t%-1s\t%-3s\t\t%-1s\t\t%-2s\t\t%-5s\t%-5s ||","NAME OF TEAM WON","SCORE","OVERS","RR","OPPOSITION","GROUND");
	       printf("\n =======================================================================================================");
				while(fread(&s2,sizeof(s2),1,fp)!=0)
			{
					if(stricmp(teamA,s2.teamA)==0)
       	        {
	       	        while(1)
	       	        {
						 
	       		   printf("\n||\t%-7s ",s2.teamA);
            printf("\t\t%-5d ",s2.scoreA);
            printf("    \t%-2f ",s2.oversA);
            printf("\t%-2f ",s2.runrateA);
            printf("\t%-5s ",s2.teamB);
            printf("\t%-5s ||",s2.ground); flag=1;
			    break;
					}
				}
				
			}
			                if(flag==0)
			  				printf("\n\nNo record found!!!!!!!");
			  					exit1 :
		printf("\nPress 1 to Go back\n\n=> ");
	scanf("%d",&option);
	switch(option)
	{
		case 1: system("cls"); main();
		default :{			
		                printf("Incorrect input\n\n");
		                goto exit1;		                
	             }
	}
	  
		}
	    break;
		case 2 :
		    {   
                 
			    fflush(stdin);
		    	system("cls");
		    	printf("Enter opposition team name  :  ");
		    	gets(teamB);
		    		       printf("\n =======================================================================================================");
        	printf("\n||\t%-1s\t%-3s\t\t%-1s\t\t%-2s\t\t%-5s\t%-5s ||","NAME OF TEAM WON","SCORE","OVERS","RR","OPPOSITION","GROUND");
	       printf("\n =======================================================================================================");
		    	while(fread(&s2,sizeof(s2),1,fp)!=0)
					{
					if(stricmp(teamB,s2.teamB)==0)
       	        {
	       	        while(1)
	       	        {
						 
	       		   printf("\n||\t%-7s ",s2.teamA);
            printf("\t\t%-5d ",s2.scoreA);
            printf("    \t%-2f ",s2.oversA);
            printf("\t%-2f ",s2.runrateA);
            printf("\t%-5s ",s2.teamB);
            printf("\t\t%-5s ||",s2.ground); flag=1;
			    break;
					}
				}
				
			}
			                if(flag==0)
			  				printf("\n\nNo record found!!!!!!!");
			  					exit2 :
		printf("\nPress 1 to Go back\n\n=> ");
	scanf("%d",&option);
	switch(option)
	{
		case 1: system("cls"); main();
		default :{			
		                printf("Incorrect input\n\n");
		                goto exit2;		                
	             }
	}
}		
		break;
			case 3 :
			{    
              
			    fflush(stdin);
		     	system("cls");
				printf("\nEnter ground name  :   ");
				gets(ground);
					       printf("\n =======================================================================================================");
				printf("\n||\t%-1s\t%-3s\t\t%-1s\t\t%-2s\t\t%-5s\t%-5s ||","NAME OF TEAM WON","SCORE","OVERS","RR","OPPOSITION","GROUND");
	       printf("\n =======================================================================================================");
				  while(fread(&s2,sizeof(s2),1,fp)!=0)
					{
					if(stricmp(ground,s2.ground)==0)
       	        {
	       	        while(1)
	       	        {
						 
	       		   printf("\n||\t%-7s ",s2.teamA);
            printf("\t\t%-5d ",s2.scoreA);
            printf("    \t%-2f ",s2.oversA);
            printf("\t%-2f ",s2.runrateA);
            printf("\t%-5s ",s2.teamB);
            printf("\t\t%-5s ||",s2.ground); flag=1;
			    break;
					}
				}
				
			}
			                if(flag==0)
			  				printf("\n\nNo record found!!!!!!!");
			  					exit3 :
		printf("\nPress 1 to Go back\n\n=> ");
	scanf("%d",&option);
	switch(option)
	{
		case 1: system("cls"); main();
		default :{			
		                printf("Incorrect input\n\n");
		                goto exit3;		                
	             }
	}
							  }
	    break;
	    	case 4 :
			{   float over; 
			    fflush(stdin);
			    system("cls");
				printf("\nEnter over  :   ");
				scanf("%f",&overs);
					       printf("\n =======================================================================================================");
				printf("\n||\t%-1s\t%-3s\t\t%-1s\t\t%-2s\t\t%-5s\t%-5s ||","NAME OF TEAM WON","SCORE","OVERS","RR","OPPOSITION","GROUND");
	       printf("\n =======================================================================================================");
				while(fread(&s2,sizeof(s2),1,fp)!=0)
					{
					if(overs==s2.oversA||overs==s2.oversB)
       	        {
	       	        while(1)
	       	        {
						 
	       		   printf("\n||\t%-7s ",s2.teamA);
            printf("\t\t%-5d ",s2.scoreA);
            printf("   \t%-2f ",s2.oversA);
            printf("\t%-2f ",s2.runrateA);
            printf("\t%-5s ",s2.teamB);
            printf("\t%-5s ||",s2.ground); flag=1;
			    break;
					}
				}
				
			}
			                if(flag==0)
			  				printf("\n\nNo record found!!!!!!!");
			  					exit4 :
		printf("\nPress 1 to Go back\n\n=> ");
	scanf("%d",&option);
	switch(option)
	{
		case 1: system("cls"); main();
		default :{			
		                printf("Incorrect input\n\n");
		                goto exit4;		                
	             }
	}
							  }
	    break;
	    case 5 : {
	    	int option;
	 system("cls"); main();
		
	}    	
			break;
		
	    default :
	    	printf("\nWrong choice entered");
					
	}
	fclose(fp);
	
	
}

}

void Delete()
{   
            system("cls");
                 printf("                                     ============================\n");                                                                                 /////////
                 printf("                                    || Deleting a match details ||\n"); 
				 printf("                                     ============================");  
    char teamA[20],teamB[25],ground[25];
    FILE *fp1,*fp2;
   
    printf("\n\n\n\n Enter team name,opposition team,score and ground : \n ");
    fflush(stdin);
    gets(teamA);
    fflush(stdin);
    gets(teamB);
    fflush(stdin);
    gets(ground);
    fflush(stdin);
     fp1=fopen("record.txt","r");
    fp2=fopen("temp.txt","a");
    int flag=0;
    while(fread(&s2,sizeof(s2),1,fp1))
    {
    	if((stricmp(s2.teamA,teamA)==0||stricmp(s2.teamB,teamA)==0)&&(stricmp(s2.teamA,teamB)==0||stricmp(s2.teamB,teamB)==0)&&stricmp(s2.ground,ground)==0)
    	{
           	flag=1;		continue;
	
	    }
		else
		 fwrite(&s2,sizeof(s2),1,fp2);

    	
	}
	 fclose(fp1);
    fclose(fp2);

    remove("record.txt");
    rename("temp.txt","record.txt");
    if(flag==1)
    printf("\nFile deleted successfully !!");
    else 
    printf("\nFile not found !!");
	getch();
	int option;
		   
			exit :
		printf("\n\nPress 1 to Go back\n\n=> ");
	scanf("%d",&option);
	switch(option)
	{
		case 1: system("cls"); main();
		default :{			
		                printf("Incorrect input\n\n");
		                goto exit;		                
	             }
	}


}
void addupdate()
{       
                                                                                                                         
	  system("cls");                                                                                                             
	int n;                                                                                                                                                                                                                                 ////////                                                                                                      /////////
      int option;                                                                            
	FILE *matchfile;                                                                                                      
	matchfile=fopen("temp2.txt","a");

	
	           printf("                                       ==============================\n");                                                                                 /////////
                 printf("                                      || Updating the match details ||\n"); 
				 printf("                                       =============================="); 
	printf("\n\n\n                                   =====================================\n");			  
   	printf("                                  ||Adding the new details of the match||\n");
	printf("                                   =====================================\n");
	
	
	 printf("\nTeam which won toss");
	 printf("\n\n                        NAME OF THIS TEAM : ");  fflush(stdin); gets(s2.teamA);
	 printf("                        SCORE OF THIS TEAM :");  fflush(stdin); scanf("%d",&s2.scoreA);
	 printf("                        OVERS PLAYED BY THIS TEAM : "); fflush(stdin); scanf("%f",&s1.oversA);	
	  s2.runrateA=s2.scoreA/s2.oversA; 
	 printf("                        RUNRATE OF THIS TEAM : %.2f",s1.runrateA); 
	 	 printf("\n                        WICKETS LOST :");  fflush(stdin); scanf("%d",&s2.wicketsA);

	 
	
	
	
	printf("\nOpposition team  ");
	 printf("\n\n                        NAME OF THIS TEAM : ");  fflush(stdin); gets(s2.teamB);
	 printf("                        SCORE OF THIS TEAM :");  fflush(stdin); scanf("%d",&s2.scoreB);
	 	 printf("                        OVERS PLAYED BY THIS TEAM : "); fflush(stdin); scanf("%f",&s2.oversB);

	 s2.runrateB=s2.scoreB/s2.oversB; 
	 printf("                        RUNRATE OF THIS TEAM : %.2f",s2.runrateB);
	 	 	 printf("\n                        WICKETS LOST :");  fflush(stdin); scanf("%d",&s2.wicketsB);

	 
	 printf("\n\nNAME OF THE GROUND : "); fflush(stdin); gets(s2.ground);
	fwrite(&s2,sizeof(s2),1,matchfile);
		fclose(matchfile);
		
		
}
void update()
{   
system("cls");
    char teamA[20],teamB[25],ground[25];
    FILE *fp1,*fp2;
                 printf("                                       ==============================\n");                                                                                 /////////
                 printf("                                      || Updating the match details ||\n"); 
				 printf("                                       =============================="); 
	printf("\n\n\n                                ============================================\n");			  
   	printf("                               ||Enter the match details you want to update||\n");
	printf("                                ============================================\n");			  

	
	 printf("\nTeam which won toss");
	 printf("\n\n                        NAME OF THIS TEAM : ");  fflush(stdin); gets(s3.teamA);
	 printf("                        SCORE OF THIS TEAM :");  fflush(stdin); scanf("%d",&s3.scoreA);
	 printf("                        OVERS PLAYED BY THIS TEAM : "); fflush(stdin); scanf("%f",&s3.oversA);	
	  s3.runrateA=s3.scoreA/s3.oversA; 
	 printf("                        RUNRATE OF THIS TEAM : %.2f",s3.runrateA); 
	 	 printf("\n                        WICKETS LOST :");  fflush(stdin); scanf("%d",&s3.wicketsA);	
	
	
	printf("\nOpposition team  ");
	 printf("\n\n                        NAME OF THIS TEAM : ");  fflush(stdin); gets(s3.teamB);
	 printf("                        SCORE OF THIS TEAM :");  fflush(stdin); scanf("%d",&s3.scoreB);
	 	 printf("                        OVERS PLAYED BY THIS TEAM : "); fflush(stdin); scanf("%f",&s3.oversB);

	 s3.runrateB=s3.scoreB/s3.oversB; 
	 printf("                        RUNRATE OF THIS TEAM : %.2f",s3.runrateB);
	 	 	 printf("\n                        WICKETS LOST :");  fflush(stdin); scanf("%d",&s3.wicketsB);

	 
	 printf("\n\nNAME OF THE GROUND : "); fflush(stdin); gets(s3.ground);  getch();
     fp1=fopen("record.txt","r");
    fp2=fopen("temp2.txt","a");
    
    while(fread(&s2,sizeof(s2),1,fp1))
    {
    	if(stricmp(s2.teamA,s3.teamA)==0&&stricmp(s2.teamB,s3.teamB)==0&&stricmp(s2.ground,s3.ground)==0&&s2.scoreA==s3.scoreA&&s2.scoreB==s3.scoreB&&s2.wicketsA==s3.wicketsA&&s2.wicketsB==s3.wicketsB&&s2.oversA==s3.oversA&&s2.oversB==s3.oversB)
    	{
    		printf("true");
		addupdate();
		
	    }
		else
		{
			printf("false");   		fwrite(&s2,sizeof(s2),1,fp2);

		}

    	
	}
	 fclose(fp1);
    fclose(fp2);
    remove("record.txt");
    rename("temp2.txt","record.txt");
printf("function completed");
        getch();
	int option;
		system("cls");    
			exit :
		printf("\nPress 1 to Go back\n\n=> ");
	scanf("%d",&option);
	switch(option)
	{
		case 1: system("cls"); main();
		default :{			
		                printf("Incorrect input\n\n");
		                goto exit;		                
	             }
	}


}
void sort()
{ 
   system("cls");
    int score[50],wickets[50];
   float runrate[50];
   int i=0,sum=0,j=0;
	FILE *fp1;
	fp1=fopen("record.txt","r");
	if(fp1==NULL)
	{
		printf("File not exist");
	}
	else
	{
	
	while(fread(&s2,sizeof(s2),1,fp1)!=0)
	{    if(s2.scoreA>s2.scoreB)
		{
		  score[i]=s2.scoreA;
		   runrate[i]=s2.runrateA;
		   wickets[i]=s2.wicketsA;
		   i++;
	    }
	    else
	    {
	    	score[i]=s2.scoreB;
	    	runrate[i]=s2.runrateB;
	    	wickets[i]=s2.wicketsB;
	        i++;	
		}
		sum++;
    }
    int temp1;
	float temp2;
	int temp3;
    
	for(i=0;i<sum;i++)
	{
		for(j=0;j<(sum-1);j++)
		{
			if(score[j]<score[j+1])
			{
				temp1=score[j];
				score[j]=score[j+1];
				score[j+1]=temp1;
				temp2=runrate[j];
				runrate[j]=runrate[j+1];
				runrate[j+1]=temp2;
				temp3=wickets[j];
				wickets[j]=wickets[j+1];
				wickets[j+1]=temp3;
			}
		}
	}
	

}
fclose(fp1);

FILE *f1,*f2;
f1=fopen("record.txt","r");
f2=fopen("temp.txt","a");

	for(i=0;i<sum;i++)
	{   
		while( fread(&s2,sizeof(s2),1,f1)!=0)
		{
          	if((s2.scoreA==score[i]||s2.scoreB==score[i])&&(s2.runrateA==runrate[i]||s2.runrateB==runrate[i])&&(s2.wicketsA==wickets[i]||s2.wicketsB==wickets[i]))
            	{
            	
       	            fwrite(&s2,sizeof(s2),1,f2);
	            }
	      
        }
        printf("\n\n");
        fseek(f1,0,SEEK_SET);
    }
    fclose(f1);
    fclose(f2);

    remove("record.txt");
    rename("temp.txt","record.txt");
    
	

}


