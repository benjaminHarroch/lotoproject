#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#define COL 6



typedef struct columnNode {

	int arr[COL];
	struct columnNode* next;
	bool columnWin;
	int numOfTrueNums;

}COLUMNNODE;

typedef struct listcolumn {

	COLUMNNODE* head;
	COLUMNNODE* tail;

}LISTCOLUMN;

typedef struct candidat {
	
	LISTCOLUMN lst;
	char* name;
	int sizeOfname;
	float avg;
	int numOfColumns;
	struct candidat* next;

}CANDIDATNODE;

typedef struct listcandidat {

	CANDIDATNODE* head;
	CANDIDATNODE* tail;
}LISTCANDIDAT;


typedef unsigned char BYTE;

int principaleMenu(LISTCANDIDAT* lst, const char *filename,int *numofcandidat,int* counter,int*arrwin);
int buildListOfLIst(LISTCANDIDAT* lst);
int printMenu();
int printSecondMenu(char *name);
void makeEmptyListCOL(LISTCOLUMN* lst);
void makeEmptyListCAN(LISTCANDIDAT* lst);
int isEmptyList(LISTCANDIDAT* lst);
int isEmptyListCol(LISTCOLUMN* lst);
int checkalloction(void* ptr);
CANDIDATNODE* createCandidatNode(char* name,int numofcolums, CANDIDATNODE* next, LISTCOLUMN lstcol);
char* nameOfcandidate();
COLUMNNODE* createColumnNode(COLUMNNODE* next);
int chooseSixNumber(int* arr, int size);
void insertColToTheListColToTheTail(LISTCOLUMN* CurlstCol, COLUMNNODE* CurcolNode);
void insertCandidatNodeToTheListToTail(LISTCANDIDAT* CurlstCandidat, CANDIDATNODE* curCandidatNode);
void chooseSixNumberAutomatic(int* arr, int size);
int chekeIfTheNumsIsAlreadyExist(int* arr, int size, int num);
void printTheArrayWiner(int *arr);
int* columnWin();
void searchHowManyfindForEveryCandidate(LISTCANDIDAT* lst,int* arrwin);
void sortTheColumn(LISTCANDIDAT* lst);
void swap(COLUMNNODE* a, COLUMNNODE* b);
void printTheSortedColumns(COLUMNNODE* lst);
void helperToPrint(LISTCANDIDAT lst);
void copyArr(int* arr, int* arr2, int size);
void getAvg(LISTCANDIDAT* lst);
void getTheNumsOfEvryGoodChoiseForAllThePlayers(LISTCANDIDAT lst);
void getTheCandidateWithTheHigherAvg(LISTCANDIDAT lst);
void saveDataToMyFile(LISTCANDIDAT lst, int numsofcandidat, int* arr, const char* filename);
void saveArr3bytes(COLUMNNODE* col, FILE* file);
void loadDataFromFile(const char* filename);
int isEmptyFile(FILE* fp);
int* loadArr3bytes(FILE* file,int *bytes);
void readFromFileAndLoadData(LISTCANDIDAT* lst, FILE* fp);