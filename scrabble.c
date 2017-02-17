#include <stdio.h>
#include <string.h>


void combination1 (char []);					 // specifies combination size
void combination2 (char [], int);
void permutation (char []);			    // prints all combinations of the given size
void dict(char []);

char outc[20];
char outp[20];
										
char copy[20][20];

int comb_size=0,str_len,fixer_in=0,fixer_movement,comb_num,kp=-1,num=0;			

/*
fixer_in is the place holder for input string.It is basically represents the element of the input string that will go 
in the first position of the output string.
fixer_movement defines the movement of the first elemnt of the output string.(Its a bit tough to explain :/).
comb_num is the serial number for printing combinations of a particular size.
*/



int main()
{
	char a[20];
	
	printf ("Enter the string :\n");
	scanf ("%[^\n]%*c",a);
	printf("\n\n");
	
	str_len=strlen(a);
	
	combination1 (a);

	return 0;
}




void combination1 (char a[])
{
	comb_num =0;
	++comb_size;
	fixer_movement=str_len-comb_size+1; 
	if (comb_size>str_len)
		return;
	else{
		//printf ("\nThe words of size %d are : \n",comb_size);
		combination2 (a,0);
		
		--fixer_in;				// this is done so fixer in return to its original value,i.e, 0.
		
		combination1 (a);
	
		return;	
	}	
		
	
		
}


void combination2 (char a[],int k)		// k represents the fixer movement of the respective elements of output string.
{
	++fixer_in;
	
	int fixer_out=fixer_in,i;			//fixer_out is the place holder for output string.
	if (fixer_in>comb_size){
		++comb_num;
		permutation(outc);
		
		kp=-1;	
		//num=0;
		return;
	}
	
	else{
		for(i=k;i<fixer_movement;i++){
			
			outc[fixer_out-1]=a[i+fixer_out-1];
			combination2 (a,i);
			--fixer_in;
		
		}
	
		return;
	
	}



}


void permutation (char x[])
{
	++kp;
	int i,j,m;										// i,j are for loops.
	m=kp;											// place holder is assigned to m.This is because the value of k changes in each reccursion.
		
	if (x[0]=='\0'){
		dict (outp); 
		//++num;
		//printf ("%d)\t%s\n",num,outp);				//printing of the output string.
		return;
		
	}
		
		
	else{
		
		for (i=0;x[i]!='\0';++i){
			outp[m]=x[i];
			strcpy (copy[m],x);
													//shorten copy[m]
			for (j=i;copy[m][j]!='\0';j++){
				copy[m][j]=copy[m][j+1];
			}
					
			permutation (copy[m]);					//reccursion , passing copy[m] as argument.
			--kp;
			
		}
		
		return;	
			
	}
	
}

void dict(char a[])
{
	int i,str_len,flag=-1;
	//long count=0;
	char ch;
	
	str_len=strlen(a);	
	
	FILE *fp;
	fp = fopen ("Dict.txt","r");
	
	switch (a[0]){
		case 'a':	fseek (fp,0,SEEK_SET);			break;
		case 'b':	fseek (fp,63543,SEEK_SET);		break;
		case 'c':	fseek (fp,119323,SEEK_SET);		break;
		case 'd':	fseek (fp,220027,SEEK_SET);		break;
		case 'e':	fseek (fp,285537,SEEK_SET);		break;
		case 'f':	fseek (fp,331076,SEEK_SET);		break;
		case 'g':	fseek (fp,372468,SEEK_SET);		break;
		case 'h':	fseek (fp,403916,SEEK_SET);		break;
		case 'i':	fseek (fp,440027,SEEK_SET);		break;	
		case 'j':	fseek (fp,488332,SEEK_SET);		break;
		case 'k':	fseek (fp,496969,SEEK_SET);		break;
		case 'l':	fseek (fp,504921,SEEK_SET);		break;
		case 'm':	fseek (fp,533936,SEEK_SET);		break;
		case 'n':	fseek (fp,589755,SEEK_SET);		break;
		case 'o':	fseek (fp,614880,SEEK_SET);		break;
		case 'p':	fseek (fp,644610,SEEK_SET);		break;
		case 'q':	fseek (fp,727977,SEEK_SET);		break;
		case 'r':	fseek (fp,733272,SEEK_SET);		break;
		case 's':	fseek (fp,800198,SEEK_SET);		break;
		case 't':	fseek (fp,913096,SEEK_SET);		break;
		case 'u':	fseek (fp,963706,SEEK_SET);		break;
		case 'v':	fseek (fp,999199,SEEK_SET);		break;
		case 'w':	fseek (fp,1015982,SEEK_SET);	break;
		case 'x':	fseek (fp,1039246,SEEK_SET);	break;
		case 'y':	fseek (fp,1039899,SEEK_SET);	break;
		case 'z':	fseek (fp,1042648,SEEK_SET);	break;
	}
	
	
	
	
	while (1){
		
		for (i=0;i<str_len;i++){
			
			ch = fgetc(fp);
			
	
			if (ch=='\n'){
				flag=2;
			
				break;
			}
				
				
			else{
		
				
				if (ch==EOF){
					printf ("WE reached EOF hence ended\n");
					flag=1;
					break;
					
				
				}
				
				 if (a[i]==ch){
					if ((i==str_len-1)&&(fgetc(fp)=='\n')){
						flag=0;
						break;
					}
				}
				
				
				else if (a[i]>ch){
					flag=3;
					break;	
				}
				
				else if (a[i]<ch){
					flag=1;
					break;
				}
				
				
				
			}
		}
		
		
		if (flag==0){
			++num;
			printf("%d) %s\n",num,a);
			break;
		}
		
	   if (flag==1){
			//printf("This word is not present in the dictionary source.\n");
			break;
		}
		if (flag==2){
		
		}
		
		if (flag==3) {
			
			while (fgetc(fp)!='\n');
		
		
		}	
	}
		
		
	fclose (fp);
	

	
	
	
}






