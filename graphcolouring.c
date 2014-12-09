#include <stdio.h>
#include <stdlib.h>

#define maxColour 3
#define max 10


int C[max], n, flag = 0, AM[max][max];
FILE *in, *out;


void printSol(int C[], int n){
	int i;
	for(i=1;i <=n; i++){
		printf(" %d", C[i]);
	}
	printf("\n");
}


int validColour(int C[], int v){
	int i;
	for(i=1; i<=v; i++){
		if(C[i] == C[v]){
			if(AM[i][v]) return 0;
		}
	}
	return 1;
}

void graphColour(int v){
	int colour;	
	for(colour = 1; colour <= maxColour; colour++){
		// if(flag) return; // uncomment if only one sol is desired
		C[v] = colour;
		if(validColour(C,v)){			
			if(v == n){				
				flag = 1;
				printSol(C,n);
			}else{				
				graphColour(v+1);
			}
		}
	}
}


void graphColourIT(){
	int v = 1;
	C[v] = 0;

	while(v >= 1){
		while(C[v] < maxColour){
			// if(flag) return; // uncomment if only one sol is desired
			C[v] = C[v] + 1;			
			if(validColour(C,v)){
				if(v == n){					
					flag = 1;
					printSol(C,n);
				}else{
					v +=1;
					C[v] = 0;
				}
			}
		}
		v -=1;
	}
}



int main()
{	
	in =fopen("input.txt", "r");
	out = fopen("output.txt", "r");

	fscanf(in,"%d", &n);
	int i, j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			fscanf(in,"%d", &AM[i][j]);
		}
	}

	graphColourIT();
	// graphColour(1);

	fclose(in);
	fclose(out);
	
	return 0;
}