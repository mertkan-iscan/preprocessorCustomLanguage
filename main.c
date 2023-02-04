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


////////////////////////////////////////// FUNCTIONS //////////////////////////////////////////////////////

void declare(char* arrayName, char* arraySize, char* arrayType)
{
	strcpy( AT[ATCounter].name, arrayName);
	strcpy( AT[ATCounter].size, arraySize);
	strcpy( AT[ATCounter].type, arrayType);

	printf ("deced %s %s %s\n", AT[ATCounter].name, AT[ATCounter].size, AT[ATCounter].type);	
	
	ATCounter++;
	
	
	//********************************
	//write expanded code to  new file
	//********************************
							
}

void read(char* fileName, char* arrayName1)
{
	int flag=0;
	int index=0;
	
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
			printf ("read %s %s\n",fileName, AT[index].name);
		
		//********************************
		//write expanded code to  new file
		//********************************
		
	}
	else
	{
		printf ("No array named %s\n",arrayName1);
	}
}

void print(char* arrayName1)
{
	int flag=0;
	int index=0;
	
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
		
		//********************************
		//write expanded code to  new file
		//********************************
		
	}
	else
	{
		printf ("No array named %s\n",arrayName1);
	}
}

void copy(char* arrayName1, char* arrayName2)
{
	memmove(arrayName1, arrayName1+1, strlen (arrayName1)); //DELETE '$' AT START (  $Y -> Y  )
	memmove(arrayName2, arrayName2+1, strlen (arrayName2)); //DELETE '$' AT START (  $Y -> Y  )
	
	
	int index=0;
	int index2=0;
	int array1Condition = 0;
	int array2Condition = 0;
	
	for(int i=0; i<=ATCounter-1; i++)
	{
		if(!(strcmp(AT[i].name, arrayName1)))
		{
			array1Condition = 1;
			index=i;
			break;
		}
		else 
			printf (" \n");
		array1Condition = 0;
	}
	
	
	
	for(int j=0; j<=ATCounter-1; j++)
	{
		if(!(strcmp(AT[j].name, arrayName2)))
		{
			array2Condition = 1;
			index2=j;
			break;
		}
		else 
			printf (" \n");
		array2Condition = 0;
	}
	
	
	if((array1Condition = 1) && (array2Condition = 1))
	{
		printf ("array copied %s %s\n",AT[index].name, AT[index2].name);
		
		
		//********************************
		//write expanded code to  new file
		//********************************
	}
	else
		printf ("missing array\n");
}

void initialize(char* arrayName1, char* Number)
{
	memmove(arrayName1, arrayName1+1, strlen (arrayName1)); //DELETE '$' AT START (  $Y -> Y  )

	int flag=0;
	int index=0;
	
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
		printf ("array initialized %s %s\n",AT[index].name, Number);
		
		
		//********************************
		//write expanded code to  new file
		//********************************
	}
	else
	{
		printf ("No array named %s\n",arrayName1);
	}
}

void arithmetic(char* arrayName1, char* arrayOrNumber1, char* operation, char* arrayOrNumber2)
{	
	memmove(arrayName1, arrayName1+1, strlen (arrayName1)); //DELETE '$' AT START (  $Y -> Y  )
	



	// if '$' == token2[0] //is array delete $
		//memmove (token2, token2+1, strlen (token2)); //DELETE '$' AT START		
	// if ('$' == token4[0]) //is array delete $
		//memmove (token4, token4+1, strlen (token4)); //DELETE '$' AT START
}


/////////////////////////////////////////////// MAIN ///////////////////////////////////////////////////////
int main()
{
	
	
	
	////////////////////// TRY TO OPEN FILE ////////////////////
	char const* const fileName = "test.txt";

	FILE* file = fopen(fileName, "r"); 

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
			printf ("%s \n",line);
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
fclose(file);
}