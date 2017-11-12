#include <stdio.h>
#include <string.h>


void combination1 (char []);					 // specifies combination size
void combination2 (char [], int);			    // prints all combinations of the given size

char outc[20];										


int comb_size=0,str_len,fixer_in=0,fixer_movement,comb_num;			

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
		printf ("\nThe combinations of size %d are : \n",comb_size);
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
		printf("%d)\t%s\n",comb_num,outc);
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
