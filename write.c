#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#define _OPEN_SYS_ITOA_EXT

int main()
{	
	int shmid;                        //char *shared_memory[8];
	unsigned int encoder_value[8];    //struct enco_struct * shmPtr;
	char temp0[5], temp1[5], temp2[5], temp3[5], temp4[5], temp5[5], temp6[5], temp7[5];
	struct encoder
	{
	 	char * encoder_value_str;	
	};
	struct encoder * shmPtr;
	struct encoder dummy[8];

	
	/** Generate a unique key q**/
	int key =12;

	/** shmget returns a identifier in shmid **/
	if((shmid = shmget(key, 2048 , 0666|IPC_CREAT)) < 0)            //1024
	{
		printf("Error while getting shared memeory id");
		exit(1);	
	}

	/** shmat attaches to shared memeory **/
	if((shmPtr = (struct encoder *)shmat(shmid, (void*)0, 0)) == (char *) -1)
	{
		printf("Error attaching shared memeory id");
		exit(1);
	}			

int while_loop = 0;
while(1)
{
	/** Loop value of wile **/
	while_loop = while_loop +1;
	printf("==========Loop value of while loop is %d:===========",  while_loop);
	
	
	/** Get the encoder value as a unsigned integer **/
	encoder_value[0] = 0;
	encoder_value[1] = 11;
	encoder_value[2] = 999;
	encoder_value[3] = 5690;
	encoder_value[4] = 8096;
	encoder_value[5] = 9999;
	encoder_value[6] = 5680;
	encoder_value[7] = 7890;

	/** Convert Unsigned Integer into str  **/

	//~ printf("\n encoder_value0 is %d", encoder_value[0]);
	sprintf(temp0,"%04d", encoder_value[0]);	
	dummy[0].encoder_value_str = temp0;
	//~ printf("\n value of temp0 is %s", temp0);
	//~ printf("\n encoder_value_in_str0 is %s \n", dummy[0].encoder_value_str);

	//printf("\n encoder_value1 is %d", encoder_value[1]);
	sprintf(temp1,"%04d", encoder_value[1]);	
	dummy[1].encoder_value_str = temp1;
	//~ printf("\n value of temp1 is %s", temp1);
	//~ printf("\n encoder_value_in_str1 is %s \n", dummy[1].encoder_value_str);

	//~ printf("\n encoder_value2 is %d", encoder_value[2]);
	sprintf(temp2,"%04d", encoder_value[2]);	
	dummy[2].encoder_value_str = temp2;
	//~ printf("\n value of temp2 is %s", temp2);
	//~ printf("\n encoder_value_in_str2 is %s \n", dummy[2].encoder_value_str);

	//~ printf("\n encoder_value3 is %d", encoder_value[3]);
	sprintf(temp3,"%04d", encoder_value[3]);	
	dummy[3].encoder_value_str = temp3;
	//~ printf("\n value of temp3 is %s", temp3);
	//~ printf("\n encoder_value_in_str3 is %s \n", dummy[3].encoder_value_str);

	//~ printf("\n encoder_value4 is %d", encoder_value[4]);
	sprintf(temp4,"%04d", encoder_value[4]);	
	dummy[4].encoder_value_str = temp4;
	//~ printf("\n value of temp4 is %s", temp4);
	//~ printf("\n encoder_value_in_str4 is %s \n", dummy[4].encoder_value_str);

	//~ printf("\n encoder_value5 is %d", encoder_value[5]);
	sprintf(temp5,"%04d", encoder_value[5]);	
	dummy[5].encoder_value_str = temp5;
	//~ printf("\n value of temp5 is %s", temp5);
	//~ printf("\n encoder_value_in_str5 is %s \n", dummy[5].encoder_value_str);

	//~ printf("\n encoder_value6 is %d", encoder_value[6]);
	sprintf(temp6,"%04d", encoder_value[6]);	
	dummy[6].encoder_value_str = temp6;
	//~ printf("\n value of temp6 is %s", temp6);
	//~ printf("\n encoder_value_in_str6 is %s \n", dummy[6].encoder_value_str);

	//~ printf("\n encoder_value7 is %d", encoder_value[7]);
	sprintf(temp7,"%04d", encoder_value[7]);	
	dummy[7].encoder_value_str = temp7;
	//~ printf("\n value of temp7 is %s", temp7);
	//~ printf("\n encoder_value_in_str7 is %s \n", dummy[7].encoder_value_str);


	/** Write in the Shared Memory **/
	int j;
	for (j=0; j<8; j++)
	{
		//shared_memory[j] = encoder_value_in_str[j];
		//memcpy(shmPtr + j, dummy[j].encoder_value_str, sizeof(struct encoder));

		memcpy(shmPtr + 5*j*sizeof(* dummy[j].encoder_value_str), dummy[j].encoder_value_str, 5*sizeof(* dummy[j].encoder_value_str));
		printf("\n loop value is %d", j);
		//memcpy(&shmPtr[j], dummy[j].encoder_value_str, sizeof(dummy[j].encoder_value_str));
		printf("\n value stored in encoder is: %s", dummy[j].encoder_value_str);
		printf("\n value stored in shmptr is: %s", (char *) (shmPtr+(j*5*sizeof(* dummy[j].encoder_value_str))));
		printf("\n address of shmptr is: %p", shmPtr+j*5*sizeof(* dummy[j].encoder_value_str));
		printf("\n");			
	}

	printf("\n I have written in the shared memeory \n");
    sleep(0.0001);	
}

	/** Sleep so there is enough time for the reader**/
	sleep(10);
	
	/** Detach from shared memory **/
	shmdt(shmPtr);
	//shmdt(shared_memory);
	//shmdt(str);
	
	/** Remove shared Memory **/
	shmctl(shmid, IPC_RMID, NULL);

	
	return 0;
}
