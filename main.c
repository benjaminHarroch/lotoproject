
#include "header.h"

void main() {

	srand(time(NULL));

	LISTCANDIDAT lst;
	int permission=0;
	int numsOfcandidate,choose;
	const char* filename;
	int counter;
	filename = "binaryFile.bin";
	counter = 0;

	int* arrWin = (int*)malloc(sizeof(int) * COL);
	checkalloction(arrWin);

	while (permission != 1) {


	    choose= principaleMenu(&lst,filename,&numsOfcandidate,&counter,arrWin);

		if (choose != 2) {

			arrWin = columnWin();
			//at this point i have the column winner and the list of list
			searchHowManyfindForEveryCandidate(&lst, arrWin);
			getAvg(&lst);
			getTheCandidateWithTheHigherAvg(lst);

			//helperToPrint(lst);
			sortTheColumn(&lst);
			printTheArrayWiner(arrWin);
			getTheNumsOfEvryGoodChoiseForAllThePlayers(lst);
			helperToPrint(lst);

			printf("there was %d candidate at this round \n", numsOfcandidate);
			printf("please press any key for continue \n");
			getchar();
			
			saveDataToMyFile(lst, numsOfcandidate, arrWin, filename);
		}
		
	}

	
}