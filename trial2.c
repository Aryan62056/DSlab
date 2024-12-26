#include<stdio.h>
#include<string.h>
char STR[100],PAT[100],REP[100],ans[100];
int i,j,c,m,k,flag=0;
void read( );
void replace( );
void print( );

int main( )
{
	read( );
	replace( );
	print( );
	return 0;
}
void read( )
{
	printf("Enter the MAIN string: \n");
	gets(STR);
	printf("Enter a PATTERN string: \n");
	gets(PAT);
	printf("Enter a REPLACE string: \n");
	gets(REP);
}
void replace()
{
	i = m = c = j = 0;
	while ( STR[c] != '\0')
	{
		// Checking for Match
		if (STR[m] == PAT[i])
		{
			i++;
			m++;
			if ( PAT[i] == '\0')
			{
				//copy replace string in ans string
				for(k=0; REP[k] != '\0';k++,j++)
				{
					ans[j] = REP[k];
					flag=1;
				}
				i=0;
				c=m;
			}
		}
		else //mismatch
		{
			ans[j] = STR[c];
			j++;
			c++;
			m = c;
			i=0;
		}
	}
}
void print()
{
	if(flag==0){
	printf("Pattern not found!!!\n”);
    }
	else
	{
		ans[j] = '\0';
		printf("\nThe RESULTANT string is:\n%s\n",ans);
	}
}
    