#include <stdio.h>
#include <string.h>

///////////////// GLOBAL ///////////////////
struct ArrayTable 
{
	char name[10];
	char size[5];
	char type[10];
};
struct ArrayTable AT[20];

int ATCounter=0;

FILE *fp;
char filename[]="write.c";

////////////////////////////////////////// FUNCTIONS //////////////////////////////////////////////////////

void declare(char* arrayName, char* arraySize, char* arrayType)
{
	strcpy( AT[ATCounter].name, arrayName);
	strcpy( AT[ATCounter].size, arraySize);
	strcpy( AT[ATCounter].type, arrayType);

	printf ("deced %s %s %s\n", AT[ATCounter].name, AT[ATCounter].size, AT[ATCounter].type);	
	
	ATCounter++;
	
	

	
	//******************************************
	//CREATE EXPANDED CODE AND WRITE TO NEW FILE
	//******************************************
	
	
	
	//fputs(code,fp);
}



void read(char* fileName, char* arrayName1)
{

}



void print(char* arrayName1)
{
	int flag=0;
	int index=0;
	//////////////// CHECK WHETHER ARRAY IS IN AT[] //////////////////
	for(int i=0; i<=ATCounter-1; i++)
	{
		if(!(strcmp(AT[i].name, arrayName1)))
		{
			flag=1;
			index=i;
			break;
		}
		else 
			printf (" \n");
			index=i;
	}
	
	
	if(flag == 1)
	{
		
		printf ("array printed %s %s\n",AT[index].size, AT[index].name);
		
		
		//////////////////// SEPERATED CODE PARTS //////////////////////
		char code1[50] = "for (int i=0; i<";
		char code2[] = "; i++)printf(\" %d \", ";
		char code3[50] = {'[','i',']',')',';','p','r','i','n','t','f','(','"','\\','n','"',')',';','\0' };
		// '\n' f*cks up line order, monkey solution is above
		
		
		//////// MERGE SEPERATED CODE PARTS //////
		strcat(code1,AT[index].size);
		strcat(code1,code2);
		strcat(code1,AT[index].name);
		strcat(code1,code3);
		
		
		///// WRITE MERGED CODE TO NEW FILE //////
		fputs(code1,fp);
		
	}
	else
	{
		printf ("No array named %s\n",arrayName1);
	}
}



void copy(char* arrayName1, char* arrayName2)
{
	
}




void initialize(char* arrayName1, char* Number)
{

}




void arithmetic(char* arrayName1, char* arrayOrNumber1, char* operation, char* arrayOrNumber2)
{	

}





/////////////////////////////////////////////// MAIN ///////////////////////////////////////////////////////
int main()
{
	
	
	
	////////////////////// TRY TO OPEN FILE ////////////////////
	char const* const fileName = "test.txt";



	FILE* file = fopen(fileName, "r"); 
	fp = fopen(filename,"w+");
	
	
	if(!file)
	{
		printf("\n Unable to open : %s ", fileName);
		return -1;
	}
	
	
	/////////// VARIABLES ////////////
	char line[50];
	char lineCpy[50];
	

	
	char* token0;
	char* token1;
	char* token2;
	char* token3;
	char* token4;
	
	fputs("#include <stdio.h> \n",fp);
	
	///////////////////// READ FILE LINE BY LINE //////////////////////
	while (fgets(line, sizeof(line), file))
	{
	
		int flag = 0;
		int index=0;
		
		
		
		///////// SEARCH IF LINE CONTAINS '$' SIGN ////////
		for(int i=0; i < sizeof(line); i++)
		{
			if('$' == line[i])
			{
				flag = 1;
				index = i;
				break;
			}
			else
				index=i;
		}



		/////////// PASS NON-FUCTION LINES //////////////
		if(flag == 0)
		{
			//printf ("'%s' \n",line);
			
			fputs(line,fp);

		}


		
		/////////// IF LINE CONTAINS '$' SIGN ///////////
		if(flag == 1)
		{
			
			
			//////////// DELETE BLANK SPACES //////////////
			memmove(lineCpy, line+(index), strlen (line));



			////// TOKENIZE LINE COPY ////////
			token0 = strtok (lineCpy," (,);");
			token1 = strtok (NULL," (,);");
			token2 = strtok (NULL," (,);");
			token3 = strtok (NULL," (,);");
			token4 = strtok (NULL," (,);");



			//////////////////////////////// FUNCTION NAME CHECK ////////////////////////////////
			if(!(strcmp(token0, "$dec")))
			{
				declare(token1, token2, token3);
			}
			else if(!(strcmp(token0, "$read")))
			{
				read(token1, token2);
			}
			else if(!(strcmp(token0, "$print")))
			{
				print(token1);
			}
			else if('$' == token0[0])
			{
				if(('$' == token2[0])&&(token4 == NULL))
				{
					copy(token0, token2);
				}
				else if(('$' != token2[0])&&(token4 == NULL))
				{
					initialize(token0, token2);
				}
				else
				{
					arithmetic(token0, token2, token3, token4);
				}
			}
		}
		
		
		
		//////////// ARRAY RESET ////////////
		memset(line, ' ', 50);
		memset(lineCpy, ' ', 50);
		token0 = NULL;
		token1 = NULL;
		token2 = NULL;
		token3 = NULL;
		token4 = NULL;
	}
fclose(fp);
fclose(file);
}