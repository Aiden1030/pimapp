#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Aiden Sanghyeop Hyun
//260974945


typedef struct PersonalInfoRecord
{ 
	char id[10];
	char ptype;
	char name[31];

	union
	{
		struct
		{
			char dept[31];
			int hireyear;
			char tenured;
		}prof;
		struct
		{
			char faculty[31];
			int admyear;
		}stud;
	}info;

	struct PersonalInfoRecord *next;
} PersonalInfoRecord;


//display(pointer): print one line;
struct PersonalInfoRecord display(PersonalInfoRecord *pir){


	//list format prof
	//

	if(pir->ptype == 'P'){

printf("%.*s,%c,%.*s,%.*s,%i,%c\n",(int)sizeof(pir->id),pir->id,pir->ptype,(int)sizeof(pir->name),pir->name,(int)sizeof(pir->info.prof.dept),pir->info.prof.dept, pir->info.prof.hireyear, pir->info.prof.tenured);
	
	}else if (pir->ptype == 'S'){
	
		printf("%.*s,%c,%.*s,%.*s,%i\n",(int)sizeof(pir->id),pir->id,pir->ptype,(int)sizeof(pir->name),pir->name,(int)sizeof(pir->info.stud.faculty),pir->info.stud.faculty, pir->info.stud.admyear);
	
	}

}


struct PersonalInfoRecord fDisplay(FILE *fp, PersonalInfoRecord *pir){


        //list format prof
        //

        if(pir->ptype == 'P'){

fprintf(fp,"%.*s,%c,%.*s,%.*s,%i,%c\n",(int)sizeof(pir->id),pir->id,pir->ptype,(int)sizeof(pir->name),pir->name,(int)sizeof(pir->info.prof.dept),pir->info.prof.dept, pir->info.prof.hireyear, pir->info.prof.tenured);

        }else if (pir->ptype == 'S'){

                fprintf(fp,"%.*s,%c,%.*s,%.*s,%i\n",(int)sizeof(pir->id),pir->id,pir->ptype,(int)sizeof(pir->name),pir->name,(int)sizeof(pir->info.stud.faculty),pir->info.stud.faculty, pir->info.stud.admyear);

        }}



//printList(headpointer) 
//print whole list
void printList( PersonalInfoRecord *pir){

	int i = 0;

	while(pir != NULL){
	
		display(pir);
		
		pir = pir->next;
	i++;

	}
}



//createNewPerson
PersonalInfoRecord *  createNewPerson(char userInput[], PersonalInfoRecord  *ptr){

	free(ptr);

	PersonalInfoRecord*     pointer1 = (PersonalInfoRecord *) malloc(sizeof(PersonalInfoRecord));

	

//change newPerson to pointer1

	char *fielddata;

	int field = 0;

	char *input;

	input = strdup(userInput);

 while( (fielddata = strsep(&input, ",\n")) != NULL){

	 


                        if(field == 0) {}

                        if(field == 1){

                                strcpy(pointer1->id, fielddata);

                                //printf("\nnewPerson id is : %s\n", newPerson.id);

                        }

                        if(field == 2){

                                pointer1->ptype = *fielddata;

                                //printf("\nptype is %c\n", newPerson.ptype);
                        }


                        if(field == 3){

                                strcpy(pointer1->name,fielddata);

                                //printf("\nname is : %s\n", newPerson.name);
			}                               


			 if(field > 3  && 'S' == pointer1->ptype){


                                if(field == 4){

                                       strcpy(pointer1->info.stud.faculty,fielddata);

                                        //printf("Faculty is : %s\n", newPerson.info.stud.faculty);

                                }

                                else if (field == 5){

                                                pointer1->info.stud.admyear = atoi(fielddata);

                                                //printf("newPerson.info.stud.admyear is %i\n", newPerson.info.stud.admyear);



                                }
                        }
                        else if(field > 3 && 'P' == pointer1->ptype){

                                if(field == 4){

                                        strcpy(pointer1->info.prof.dept,fielddata);

                                        //printf("dept is : %s \n",newPerson.info.prof.dept);

                                }
                                else if (field == 5){

                                        pointer1->info.prof.hireyear = atoi(fielddata);

                                        //printf(" hireyear is : %i \n",newPerson.info.prof.hireyear);

                                }else if(field == 6){


                                        pointer1->info.prof.tenured = *fielddata;

                                        //printf(" tenured is : %c \n",newPerson.info.prof.tenured);

                                }}
 field++;
 }
return pointer1;
}




void addPerson(PersonalInfoRecord  *prevP ,PersonalInfoRecord  *personP){

	if(prevP->next == NULL){
	
		prevP->next = personP;
	
	}else{
	
		PersonalInfoRecord *prevPnext = prevP->next;

		prevP->next = personP;

		personP->next = prevPnext;

	}
}



void updateInfo(PersonalInfoRecord *newInfo ,PersonalInfoRecord *original){


	if(strcmp(newInfo->id, original->id) == 0){
	


		 if(*newInfo->name == '\0'){
		 

		 }else{
			strcpy(original->name ,newInfo->name);

		 }


		 if(newInfo->ptype == 'P'){
		 
			if(*newInfo->info.prof.dept == '\0'){
			
			}else{

				strcpy(original->info.prof.dept,newInfo->info.prof.dept);
			}
				
		
			 if(newInfo->info.prof.hireyear == 0){
			 

			 }else{
			 
				 original->info.prof.hireyear = newInfo->info.prof.hireyear;

			 }
			
			
			 if(newInfo->info.prof.tenured == 0){

			 

			 }else{
			 
				 original->info.prof.tenured = newInfo->info.prof.tenured;
			 }

			 
		 }
		 else if(newInfo->ptype == 'S'){




			 if(*newInfo->info.stud.faculty == '\0'){

                        }else{
			
				strcpy(original->info.stud.faculty ,newInfo->info.stud.faculty);

			}


                         if(newInfo->info.stud.admyear == 0){


                         }else{
			 
			 
				 original->info.stud.admyear = newInfo->info.stud.admyear;
			 }




                         


		 }


	}


}


//points where input node should be in the list
//returns input when it should be at the very front
//if the element already exist, update it and done.
//otherwise, returns a pointer, one node before *person should be.
PersonalInfoRecord* whereTo(PersonalInfoRecord *head, PersonalInfoRecord *person){


	        PersonalInfoRecord *nextP = head;

                PersonalInfoRecord *prevP = head;	
	
	        if(atoi(nextP->id) == atoi(person->id)){

                             //   printf("person dept is %s\n",person->info.prof.dept);
 
 	
	     		     //	printf("nextP dept is %s\n",nextP->info.prof.dept);
 
                                updateInfo(person,nextP);
                
	
			//	printf("same ID\n");
                                
				free(person);
				nextP = NULL;

                                return nextP;}


                //bigger than head and head is the only element in the list
                if(head->next == NULL && atoi(head->id) < atoi(person->id)){

                        return head;
                      

                }



		//smaller than head, returns itself
                if(atoi(head->id) > atoi(person->id)){

                        return person;

                }




                while(nextP != NULL){

                
			if(atoi(nextP->id) == atoi(person->id)){

                       //         printf("person dept is %s\n",person->info.prof.dept);

                         //       printf("nextP dept is %s\n",nextP->info.prof.dept);

                                updateInfo(person,nextP);

                           //     printf("same ID\n");

				free(person);

                                nextP = NULL;

                                return nextP;
                     
		
		
		
		         }else if (atoi(nextP->id) < atoi(person->id)){

				 if(nextP->next == NULL){

                                
					 return nextP;}
				
				prevP = nextP;

                                nextP = nextP->next;

                        }else if(atoi(prevP->id) < atoi(person->id)){

				return prevP;
                                

                        }
			


			
			

		
		
		}




} 



int findPosition(PersonalInfoRecord *head , int id){

	PersonalInfoRecord *headPointer = head;

	int i = 0;

	while(headPointer != NULL){
	
		if (atoi(headPointer->id) == id){
		
			return i;
		}
		headPointer = headPointer->next;
		i++;
	
	}

	return -1;


}







PersonalInfoRecord* delete(int Id, PersonalInfoRecord* head){

	PersonalInfoRecord *nextNode, *prevNode, *newHead;

	int position = 0;
	nextNode = head;

	prevNode = head;

	newHead = head;



                position = findPosition(head,Id);
		


		if (position == -1){

			
			return head;
			
		}

		for (int c = 0 ; c <= position ; c++){
			
			if(c == 0 && position == 0){
	

				return head->next;
			}

			else if(c == position){
			
			
				prevNode->next = nextNode->next;

				free(nextNode);

				return newHead;

			}else{

				prevNode = nextNode;

			        nextNode = nextNode->next;

				if (nextNode == NULL){
				
				return newHead;}
		}


                        }
}


void freeAll(PersonalInfoRecord *head){

	PersonalInfoRecord *m, *mNext;
while(m != NULL){

	mNext = m->next;
	free(m);
	m = mNext;
}


}




int main(int argc, char *argv[])
{

	

	if(argc != 2 ){
	
	fprintf(stderr,"Error, please pass the database filename as the argument. \nUsage ./pimapp <dbfile>\n");

	return 1;
	}



	char *filename; 
		
	filename = argv[1];

	PersonalInfoRecord  *head , *prev, *nextP ,*fnext;

	int i = 0, j =0;	
      
	char userInput[100];

	char *found, *deletingId, *userInputP;
	
	while(1 == 1){i+=1; 
        
		fgets(userInput,100,stdin);
        
		if (strncmp("END",userInput,3) == 0){


			if(head == NULL){
			
			return 0;}
	
			FILE* output;

			output = fopen(filename, "w");

			if(!output){
   
				fprintf(stderr, "Error, unable to open %s for writing.\n",filename);
  
			       freeAll(head);	
				return 3;

			}
			fnext = head;

			while(fnext != NULL){

				

			fDisplay(output,fnext);
		
			fnext = fnext->next;

			}


			freeAll(head);
                return 0;
        
		}

		if(strncmp("LIST",userInput,4) == 0){
	
		printList(head);

		continue;
		}

        
		if(strncmp("D",userInput,1) == 0){



			if(head != NULL){
			
				deletingId = strtok(userInput,"D,");
			
				head = delete(atoi(deletingId),head);

				continue;

			}else{i=0;continue;}


		}
		
		
		PersonalInfoRecord* ptr = (PersonalInfoRecord *) malloc(sizeof(PersonalInfoRecord));

        
		ptr = createNewPerson(userInput, ptr);


	

	
		//initialize list
	
		if(i == 1 || head == NULL){

		head = ptr;
	
		prev = ptr;

		nextP = NULL;
	
	
		//search 
	
		}else{
	
	
	
		
			PersonalInfoRecord *P = whereTo(head, ptr);


		
			if(P == NULL){continue;}	

		//	printf("location Found %s\n", P->id);

			//ptr id is the smallest

			//becomes head
	
		
			if(P == ptr){
	
		
			
				addPerson(ptr,head);
	
		
			
				head = ptr;
	
		
	
		
			}else{

		
			   	if(P->next == NULL){

                        
					P->next = ptr;
                
				}else{

                        
					ptr->next = P->next;
                        
					P->next = ptr;
                
				}


		
			}
	
		}

	}
return 0;
}


	







