#include "A4_sort_helpers.h"
sem_t* array[27];

// Function: read_all() 
// Provided to read an entire file, line by line.
// No need to change this one.
void read_all( char *filename ){
    
    FILE *fp = fopen( filename, "r" );
    int curr_line = 0;
	
    while( curr_line < MAX_NUMBER_LINES && 
           fgets( text_array[curr_line], MAX_LINE_LENGTH, fp ) )
    {
        curr_line++;
    }
	
    text_array[curr_line][0] = '\0';
    fclose(fp);
}

// Function: read_by_letter() 
// Provided to read only the lines of a file staring with first_letter.
// No need to change this one.
void read_by_letter( char *filename, char first_letter ){

    FILE *fp = fopen( filename, "r" );
    int curr_line = 0;
    text_array[curr_line][0] = '\0';
	
    while( fgets( text_array[curr_line], MAX_LINE_LENGTH, fp ) ){
        if( text_array[curr_line][0] == first_letter ){
            curr_line++;
        }

        if( curr_line == MAX_NUMBER_LINES ){
            sprintf( buf, "ERROR: Attempted to read too many lines from file.\n" );
            write( 1, buf, strlen(buf) );
            break;
        }
    }
	
    text_array[curr_line][0] = '\0';
    fclose(fp);
}

void sort_words()
{
	for(int i=0; i<MAX_NUMBER_LINES; i++)
	{
		char value[MAX_LINE_LENGTH];
		strcpy(value, text_array[i]);

		int hole = i;

		if(text_array[i][0]=='\0')
			break;

		while((hole>0) && (strcmp(text_array[hole-1], value)>0))
		{
			for(int k=0; k<MAX_LINE_LENGTH; k++)
			{
				text_array[hole][k] = text_array[hole-1][k];
			}
			hole--;
		}
		for(int q=0; q<MAX_LINE_LENGTH; q++)
		{
			text_array[hole][q] = value[q];
		}
	}
}

int initialize( ){
    // Remove the current place-holder code, and write your own.
    sem_t *(a);sem_t *(b);sem_t *(c);sem_t *(d);sem_t *(e);sem_t *(f);sem_t *(g);
    sem_t *(h);sem_t *(i);sem_t *(j);sem_t *(k);sem_t *(l);sem_t *(m);sem_t *(n);sem_t *(o);sem_t *(p);sem_t *(q);
    sem_t *(r);sem_t *(s);sem_t *(t);sem_t *(u);sem_t *(v);sem_t *(w);sem_t *(x);sem_t *(y);sem_t *(z);sem_t *(watch);

    sem_t* array[27] = {a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z, watch};

    char *name[27] = {"Benny_a","Benny_b","Benny_c","Benny_d","Benny_e","Benny_f","Benny_g","Benny_h","Benny_i","Benny_j","Benny_k","Benny_l","Benny_m","Benny_n","Benny_o","Benny_p","Benny_q","Benny_r","Benny_s","Benny_t","Benny_u","Benny_v","Benny_w","Benny_x","Benny_y","Benny_z", "Bennysp"};
    array[0] = sem_open("Benny_a", O_CREAT, 0666, 1);
    for(int i=1; i<27; i++)
    {
    	sem_unlink(name[i]);
    	array[i] = sem_open(name[i], O_CREAT, 0666, 0);
    }
    //watch = sem_open("Benny_watch", O_CREAT, 0666, 1);
    return 0;
}

int process_by_letter( char* input_filename, char first_letter ){
    // For Q2, keep the following 2 lines in your solution (maybe not at the start).
    // Add lines above or below to ensure the "This process will sort..." lines
    // are printed in the right order (alphabetical).

   	int order = first_letter-'a';
   	int value = -1;
    sem_wait(array[order]);
    sem_getvalue(array[order], &value);
    sprintf(buf, "This process will sort the letter %c. %d\n",  first_letter, value);
    write(1,buf,strlen(buf));
    sem_post(array[order+1]);

    // For Q3, uncomment the following 2 lines and integrate them with your overall solution.
    // read_by_letter( input_filename, first_letter );
    // sort_words( );

    return 0;
}

int finalize( ){
    // For Q2, keep the following 2 lines in your solution (maybe not at the start).
    // Add lines above or below to ensure the "Sorting complete!" line
    // is printed at the very end, after all letter lines.
	sem_wait(array[0]);
    sprintf( buf, "Sorting complete!\n" );
    write( 1, buf, strlen(buf) );

    // For Q3, come up with a way to accumulate the sorted results from each
    // letter process and print the overall sorted values to standard out.
    // You are not allowed to read from the input file, or call sort_words
    // directly from this function.

    return 0;
}

