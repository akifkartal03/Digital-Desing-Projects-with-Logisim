
#include <stdio.h>
#include <string.h>


int main() {
 	//it was written based on project game rules in the pdf file.
  char word[8];
  printf("Enter word: ");
  fflush(stdout);
  scanf(" %s", word);
  int number = strlen(word); //get number of character
  printf("Number of character =%d\n",number);
  int found[number];
  for (int i=0; i < number; ++i) {
    found[i] = 0;
  }
  int user=0;
  int machine = 0;
  int led_number = 0;
  int is_win = 0;
  while (is_win==0 && led_number!=10) {
    // Print word 
    printf("The word is : ");
    for(int j=0; j < number; ++j) {
      if (found[j]) {
        printf("%c", word[j]);
      }
      else {
        printf("*");
      }
    }
    printf("\n");
    char input;
    printf("Your Letter? ");
    fflush(stdout);
    scanf(" %c", &input);
    int is_in =0;
 
    for(int k=0; k < number; ++k) {
      if (word[k] == input) {
	      found[k] = 1;
	      is_in = 1;
      }
    }
    if (is_in==0)
    {
    	led_number++;
    }
    is_win = 1;
    for(int i = 0;i<number;i++){
      if(found[i] == 0){
        is_win = 0;
      }
    }
    
  }//end of game

  //determine who is win?
  if (is_win)
  {
  	printf("Congratulations! The word is \"%s\".\n", word);
  	user++;
  }
  else{
  	printf("You losed!! The word is \"%s\".\n", word); //print word even if the user lose
  	machine++;
  }
  printf(" Score:\n User: %d\n Machine: %d\n",user,machine );

  return 0;
}
