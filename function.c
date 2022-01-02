#pragma once
#include "header.h"

//show the principale menu and start all the program
int principaleMenu(LISTCANDIDAT* lstcandidate,const char* filename,int *numofcandidat,int *counter,int *arrWin) {

	int chooseFromThePrincipaleMenu;
	
	chooseFromThePrincipaleMenu=printMenu();

	switch (chooseFromThePrincipaleMenu) {

	case 1:
		*numofcandidat= buildListOfLIst(lstcandidate);
		*counter = *counter + 1;
		break;
	case 2:
		if (*counter == 0) {

			loadDataFromFile(filename, lstcandidate);
		}
		else if(*counter!= 0 ) {
			
			helperToPrint(*lstcandidate);
			printTheArrayWiner(arrWin);
		}
	
		break;
	case 3:
		exit(-1);
	default:
		;
	}
	return chooseFromThePrincipaleMenu;

}
//show the  second menu and build the list of list 
int  buildListOfLIst(LISTCANDIDAT *lstcandidate){

	int numOfCandidat,i,j,numofcolumns,chooseSeconMenu;
	char* name;
	int arrOfnumber[COL];

	//LISTCANDIDAT lst;
	makeEmptyListCAN(lstcandidate);//

	printf("nums of participant:");
	//get the nums of players
	scanf("%d", &numOfCandidat);


	for (i = 0; i < numOfCandidat; i++) {

		CANDIDATNODE* curCandidatNode;
		LISTCOLUMN CurlstCol;
		makeEmptyListCOL(&CurlstCol);
		

		//get the name of the player
		name = nameOfcandidate();
		chooseSeconMenu=printSecondMenu(name);

	//case 1:
		if (chooseSeconMenu == 1) {

			printf("how many column would you want:  ");
			scanf("%d", &numofcolumns);

			for (j = 0; j < numofcolumns; j++) {

				printf("please enter your %d column: ", j);
				COLUMNNODE* CurcolNode;
				CurcolNode = createColumnNode(NULL);
				chooseSixNumber(CurcolNode->arr, COL);
				//i finish  build a node now insert him to the curcollist;
				insertColToTheListColToTheTail(&CurlstCol, CurcolNode);

			}
			//at this moment i have a list col ready for insert to the list canididat
			curCandidatNode = createCandidatNode(name,numofcolumns, NULL, CurlstCol);
			insertCandidatNodeToTheListToTail(lstcandidate, curCandidatNode);//
		}
		//case 2:
		else if (chooseSeconMenu == 2) {

			printf(" option 2 is automtic ,how many column would you want: \n ");
			scanf("%d", &numofcolumns);

			for (j = 0; j < numofcolumns; j++) {
			
				COLUMNNODE* CurcolNode;
				CurcolNode = createColumnNode(NULL);
				chooseSixNumberAutomatic(CurcolNode->arr, COL);
				//i finish  build a node now insert him to the curcollist;
				insertColToTheListColToTheTail(&CurlstCol, CurcolNode);//

			}
			//at this moment i have a list col ready for insert to the list candidat
			curCandidatNode = createCandidatNode(name,numofcolumns, NULL, CurlstCol);
			insertCandidatNodeToTheListToTail(lstcandidate, curCandidatNode);
		}
		//default:
		
	}
	//printf("%d",lstcandidate->tail->lst.tail->arr[2]);

	return numOfCandidat;
    
}
//print menu
int printMenu() {

	int chooseFromThePrincipaleMenu;

	printf("  please choose a option:\n");
	printf(" 1. Enter the number of participants\n");
	printf(" 2. Displays the latest lottery results\n");
	printf(" 3. exit\n");


	scanf(" %d", &chooseFromThePrincipaleMenu);

	while (chooseFromThePrincipaleMenu > 3 || chooseFromThePrincipaleMenu < 1) {
		printf("please enter a possible option: \n");
		printf("  please choose a new option:\n");
		printf(" 1. Enter the number of participants\n");
		printf(" 2. Displays the latest lottery results\n");
		printf(" 3. exit\n");
		scanf(" %d", &chooseFromThePrincipaleMenu);
	}

	return chooseFromThePrincipaleMenu;
}
int printSecondMenu(char *name) {

	int choose;

	printf(" hey %s ,please choose a option: \n" ,name);
	printf(" 1.manuele loto \n");
	printf(" 2.ataumatic loto \n");

	scanf(" %d", &choose);

	while (choose != 2 && choose != 1) {

		printf(" please enter a number that the possibilities exite:  \n");
		printf(" hey,please choose a option: \n");
		printf(" 1.manuele loto \n");
		printf(" 2.ataumatic loto \n");
		
		scanf(" %d", &choose);
	}

	return choose;

}
//make empty list to the col list
void makeEmptyListCOL(LISTCOLUMN* lst) {

	lst->head = lst->tail = NULL;
}
//make empty list to the candidate list
void makeEmptyListCAN(LISTCANDIDAT* lst) {

	lst->head = lst->tail = NULL;
}
//chek if the candidate list is empty
int isEmptyList(LISTCANDIDAT *lst)
{
	return(lst->head == NULL);
}
//cheke if the col list is empty
int isEmptyListCol(LISTCOLUMN* lst)
{
	return(lst->head == NULL);
}
//cheke alloction 
int checkalloction(void* ptr) {

	if (ptr == NULL) {
		printf("the allocation faile ");
		exit(-1);
	}
	else
		return 1;
}

CANDIDATNODE* createCandidatNode(char* name,int numofcolumns, CANDIDATNODE* next, LISTCOLUMN lstcol) {

	CANDIDATNODE* newNode = (CANDIDATNODE*)malloc(sizeof(CANDIDATNODE));
	checkalloction(newNode);

	newNode->name = name;
	newNode->next = next;
	newNode->avg = 0.0;
	newNode->sizeOfname = strlen(name);
	newNode->lst = lstcol;
	newNode->numOfColumns = numofcolumns;

	return newNode;
}

//GET THE NAME OF THE THE PLAYERS
char* nameOfcandidate() {

	char* name;
	char c;
	int logic, phisic;
	logic = 0;
	phisic = 1;

	name = (char*)malloc(sizeof(char) * phisic);
	checkalloction(name);


	printf("please enter the name of the player :");
	
	c = getchar();
	c = getchar();

	while (c != '\n') {

		if (logic == phisic) {
			phisic *= 2;
			name = (char*)realloc(name,(sizeof(char) * phisic));
			checkalloction(name);
		}

		name[logic] = c;
		logic++;
		c = getchar();
	}

	name = (char*)realloc(name, (sizeof(char) * logic+2));
	checkalloction(name);
	name[logic] = '\0';

	return name;
}

COLUMNNODE* createColumnNode(COLUMNNODE* next) {

	COLUMNNODE* newNode = (COLUMNNODE*)malloc(sizeof(COLUMNNODE));

	//newNode->arr=arr;
	//chooseSixNumberAutomatic(newNode->arr, COL);
	newNode->next = next;
	newNode->columnWin = false;
	newNode->numOfTrueNums = 0;

	return newNode;
}

int chooseSixNumber(int *arr,int size) {

	int i, num, flag;

	for (i = 0; i < size; i++) {
		printf("enter your %d number", i+1);
		scanf("%d", &num);

		flag = chekeIfTheNumsIsAlreadyExist(arr, COL, num);

		while (flag) {

			printf("this number is already exist please choose another between 1-15: \n");
			scanf("%d", &num);
			flag = chekeIfTheNumsIsAlreadyExist(arr, COL, num);

		}

		while (num > 15 || num < 1) {
			printf("please enter a new number between 1-15: \n");
			scanf("%d", &num);

			flag = chekeIfTheNumsIsAlreadyExist(arr, COL, num);

			while (flag) {

				printf("this number is already exist please choose another between 1-15: \n");
				scanf("%d", &num);
				flag = chekeIfTheNumsIsAlreadyExist(arr, COL, num);

			}
		}
		arr[i] = num;
	}
}
//insert to de list of  col every node to the tail
void insertColToTheListColToTheTail(LISTCOLUMN *CurlstCol,COLUMNNODE *CurcolNode) {

	CurcolNode->next = NULL;

	if (isEmptyListCol(CurlstCol)) {
		CurlstCol->head = CurlstCol->tail = CurcolNode;
	}
	else {

		CurlstCol->tail->next = CurcolNode;
		CurlstCol->tail = CurcolNode;

	}


}
//inser to the list of canididat every node to the tail
void insertCandidatNodeToTheListToTail(LISTCANDIDAT* CurlstCandidat, CANDIDATNODE* curCandidatNode) {


	curCandidatNode->next = NULL;
	if (isEmptyList(CurlstCandidat)) {
		CurlstCandidat->head = CurlstCandidat->tail = curCandidatNode;
	}
	else {

		CurlstCandidat->tail->next = curCandidatNode;
		CurlstCandidat->tail = curCandidatNode;

	}
}
//automatice choose with srcan() for every num in the col 
void chooseSixNumberAutomatic(int* arr, int size) {

	int i, num,flag;
	

	for (i = 0; i < size; i++) {

		num = (rand() % 14) + 1;
		flag = chekeIfTheNumsIsAlreadyExist(arr, COL, num);
		//the first numberr is allways put into the array

		while (flag) {

			num = (rand() % 14) + 1;
			flag = chekeIfTheNumsIsAlreadyExist(arr, COL, num);
		}
		arr[i] = num;
	}
}
//function for chek if the number is already existe
int chekeIfTheNumsIsAlreadyExist(int* arr, int size,int num) {

	int i, fleg;
	fleg = 0;

	for (i = 0; i < size; i++) {
		if (arr[i] == num) {
			fleg = 1;
			return fleg;
		}
	}

	return fleg;

}

int* columnWin() {

	int* arrWin = (int*)malloc(sizeof(int) * COL);
	int i,num,flag;

	for (i = 0; i < COL; i++) {

		num = (rand() % 14) + 1;
		flag = chekeIfTheNumsIsAlreadyExist(arrWin, COL, num);
		//the first numberr is allways put into the array

		while (flag) {

			num = (rand() % 14) + 1;
			flag = chekeIfTheNumsIsAlreadyExist(arrWin, COL, num);
		}
		arrWin[i] = num;
	}

	return arrWin;
}

void printTheArrayWiner(int* arr){

	int i;
	printf(" the winnig column is : \n");
	for (i = 0; i < COL; i++) {
		printf(" %4d ", arr[i]);
	}
	printf(" \n");
}

void searchHowManyfindForEveryCandidate(LISTCANDIDAT* lst, int* arrwin) {

	int i = 0;
	CANDIDATNODE* currentlstc;
	currentlstc = lst->head;

	while (currentlstc != NULL) {

		COLUMNNODE* currentlstcolumn;
		currentlstcolumn = currentlstc->lst.head;

		while (currentlstcolumn != NULL) {

			for (i =0; i < COL; i++) {

				if (chekeIfTheNumsIsAlreadyExist(arrwin, COL, currentlstcolumn->arr[i])) 
					(currentlstcolumn->numOfTrueNums)++;
			}

			currentlstcolumn = currentlstcolumn->next;
		}

		currentlstc = currentlstc->next;
	}

}

void sortTheColumn(LISTCANDIDAT* lst) {

	COLUMNNODE* i; 
	COLUMNNODE* j;
	CANDIDATNODE* currentlstc;
	COLUMNNODE* temp;

	currentlstc = lst->head;

	while (currentlstc != NULL) {

		COLUMNNODE* currentcolumn;
		COLUMNNODE* next;

		currentcolumn = currentlstc->lst.head;
	

		for (i = currentcolumn; i !=NULL; i=i->next) {


			for (j = i->next; j!=NULL; j=j->next) {


				if (i->numOfTrueNums < j->numOfTrueNums) {

					temp = (COLUMNNODE*)malloc(sizeof(COLUMNNODE));

					temp->columnWin = i->columnWin;
					temp->numOfTrueNums = i->numOfTrueNums;
					i->columnWin = j->columnWin;
					i->numOfTrueNums = j->numOfTrueNums;
					copyArr(i->arr, j->arr, COL);
					j->columnWin = temp->columnWin;
					j->numOfTrueNums = temp->numOfTrueNums;

					free(temp);
				}



			}
			
		}
		currentlstc = currentlstc->next;
		
	}

}

void swap(CANDIDATNODE* lst,COLUMNNODE* prev,COLUMNNODE* a, COLUMNNODE* b)
{
	COLUMNNODE* temp;

	if (prev == NULL) {

		temp = b->next;
		b->next = a;
		a->next = temp;
		lst->lst.head = b;
	}

	else if (b->next == NULL) {

		temp = b->next;
		b->next = a;
		a->next = temp;
		prev->next = b;
		lst->lst.tail = a;
	}
	else {

		temp = b->next;
		b->next = a;
		a->next = temp;
		prev->next = b;
	}		
}

void helperToPrint(LISTCANDIDAT lst) {

	CANDIDATNODE* cur;
	cur = lst.head;
	printf("\n");

	while (cur != NULL) {
		printf("this is the columns of %s \n", cur->name);
		printf(" %s have average of good choise : %f  \n ", cur->name, cur->avg);
		printTheSortedColumns(cur->lst.head);
		cur = cur->next;
	}
}

void printTheSortedColumns(COLUMNNODE *lst) {

	int i;
	if (lst == NULL)
		return;

	else {

		for (i = 0; i < COL; i++) {

			printf("%4d ", lst->arr[i]);
		}
		printf(" : this column have %d good choise", lst->numOfTrueNums);
		printf("\n");
		printTheSortedColumns(lst->next);
	}
}

void copyArr(int *arr, int *arr2,int size ) {
	
	int i;
	int temp;

	for (i = 0; i < size; i++) {

		temp = arr[i];
		arr[i] = arr2[i];
		arr2[i] = temp;

	}

}

void getAvg(LISTCANDIDAT *lst) {

	CANDIDATNODE* curcandidatlst;
	curcandidatlst = lst->head;
	int avg;

	COLUMNNODE* curcolumn;

	while (curcandidatlst != NULL) {

		curcolumn = curcandidatlst->lst.head;
		avg = 0;
		while (curcolumn != NULL) {

			avg += curcolumn->numOfTrueNums;
			curcolumn = curcolumn->next;
		}

		curcandidatlst->avg = avg / curcandidatlst->numOfColumns;
		curcandidatlst = curcandidatlst->next;
	}


}

void getTheNumsOfEvryGoodChoiseForAllThePlayers(LISTCANDIDAT* lst) {
 

	CANDIDATNODE* curcandidatlst;
	curcandidatlst = lst->head;

	COLUMNNODE* curcolumn;

	int* arr = (int*)calloc(sizeof(int),COL+1);
	int i;

	while (curcandidatlst != NULL) {

		curcolumn = curcandidatlst->lst.head;

		while (curcolumn != NULL) {

			arr[curcolumn->numOfTrueNums]++;

			curcolumn = curcolumn->next;

		}
		curcandidatlst = curcandidatlst->next;

	}

	for (i = 1; i <= COL; i++) {

		printf("the column with  %d show  %d times  \n",i, arr[i]);

	}

}

void getTheCandidateWithTheHigherAvg(LISTCANDIDAT lst) {

	CANDIDATNODE* curcandidatlst;
	curcandidatlst = lst.head;
	float max = 0;
	

	COLUMNNODE* curcolumn;

	while (curcandidatlst != NULL) {

		if (curcandidatlst->avg > max) {
			max = curcandidatlst->avg;
		 }

		curcandidatlst = curcandidatlst->next;
	}

	curcandidatlst = lst.head;

	while (curcandidatlst != NULL) {

		if (curcandidatlst->avg == max) {

			printf(" %s have the column with the higher avg in the game \n ", curcandidatlst->name);
		}

		curcandidatlst = curcandidatlst->next;
	}

}

void saveDataToMyFile(LISTCANDIDAT lst,int numOfcandidat,int *arr,const char* filename) {

	CANDIDATNODE *curCandidat;
	COLUMNNODE* curColumn;
	int i;

	FILE* fp = fopen(filename, "wb");
	if (fp == NULL)
	{
		printf("Error opening the file!\n");
		exit(1);
	}

	curCandidat = lst.head;

	fwrite(&numOfcandidat, sizeof(int), 1, fp);

	while (curCandidat != NULL) {

		curColumn = curCandidat->lst.head;

		fwrite(&curCandidat->sizeOfname, sizeof(int), 1, fp);
		fwrite(curCandidat->name, sizeof(char), curCandidat->sizeOfname, fp);
		fwrite(&curCandidat->numOfColumns, sizeof(int), 1, fp);

		while (curColumn != NULL) {

			saveArr3bytes(curColumn->arr, fp);
			curColumn = curColumn->next;
		}
	
		curCandidat = curCandidat->next;
	}
	
	saveArr3bytes(arr, fp);
	fseek(fp, 0, SEEK_CUR);
	fclose(fp);

}

void saveArr3bytes(int *array,FILE *file) {

		BYTE one, two, three;
		one = two = three = 0;
		int* arr = array;
		one = one | arr[0] << 4;
		one = one | arr[1];
		two = two | arr[2] << 4;
		two = two | arr[3];
		three = three | arr[4] << 4;
		three = three | arr[5];
		fwrite(&one, sizeof(char), 1, file);
		fwrite(&two, sizeof(char), 1, file);
		fwrite(&three, sizeof(char), 1, file);

}

void loadDataFromFile(const char* filename) {

	LISTCANDIDAT lst;
	makeEmptyListCAN(&lst);
	
	FILE* fp = fopen(filename, "rb");

	if (fp == NULL)
	{
		printf("please first play an around !\n");
		return;
	}
	else {
		
		readFromFileAndLoadData(&lst,fp);
		helperToPrint(lst);
	}
	
}

int isEmptyFile(FILE *fp) {

	int empty;
	fseek(fp, 0, SEEK_END);

	if (ftell(fp) == 0) {
		empty = 1;
		fseek(fp, 0, SEEK_CUR);
		return empty;
	}
	else {
		fseek(fp, 0, SEEK_CUR);
		empty = 0;
		return empty;
	}
}

void readFromFileAndLoadData(LISTCANDIDAT *lst,FILE *fp){
	
	int numsofcolumns,i,j,bytes;
	int numOfCandidat,sizeofname;
	char* name;
	int* array;
	int* arrwinner;
	COLUMNNODE* curColumn;
	LISTCOLUMN lstcol;
	CANDIDATNODE* curCandidat;

	makeEmptyListCOL(&lstcol);
	bytes = 0;

	bytes+=fread(&numOfCandidat, sizeof(int), 1, fp);

	for (i = 0; i < numOfCandidat; i++) {


		bytes += fread(&sizeofname, sizeof(int), 1, fp);
		name = (char*)malloc((sizeofname + 1) * sizeof(char));
		checkalloction(name);
		bytes += fread(name, sizeof(char), sizeofname, fp);
		
		name[sizeofname] = '\0';
	
		bytes += fread(&numsofcolumns, sizeof(int), 1, fp);

		for (j = 0; j < numsofcolumns; j++) {

			array = loadArr3bytes(fp,&bytes);
			printTheArrayWiner(array);
			curColumn = createColumnNode(NULL);
			copyArr(array, curColumn->arr, COL);
			insertColToTheListColToTheTail(&lstcol, curColumn);
		}
		printf("%d", bytes);
		curCandidat=createCandidatNode(name, numsofcolumns, NULL, lstcol);
		insertCandidatNodeToTheListToTail(&lst, curCandidat);

	}
		arrwinner= loadArr3bytes(fp,&bytes);
		printTheArrayWiner(arrwinner);
		printf("%d", bytes);
}


int* loadArr3bytes( FILE* file,int *bytes) {
	
	int* newarray = (int*)malloc(sizeof(int) * COL);

	BYTE maskright, maskleft;
	BYTE one, two, three,curcharvalue;

	maskleft = 0xF0;
	maskright = 0x0F;
		
	*bytes += fread(&one, sizeof(char), 1, file);
	*bytes += fread(&two, sizeof(char), 1, file);
	*bytes += fread(&three, sizeof(char), 1, file);

	curcharvalue = one & maskleft;
	newarray[0] =(int) curcharvalue >> 4;
	newarray[1]= (int)(one & maskright);
	curcharvalue = two & maskleft;
	newarray[2] = (int)(curcharvalue >> 4);
	newarray[3] = (int)(two & maskright);
	curcharvalue = three & maskleft;
	newarray[4] = (int)(curcharvalue >> 4);
	newarray[5] = (int)(three & maskright);
	
	return newarray;
}