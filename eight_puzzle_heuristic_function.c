#include<stdio.h>
#include<malloc.h>
struct node
{
	int puzzle[3][3];
	int heuristic;
	struct node *firstChild;
	struct node *secondChild;
	struct node *thirdChild;
	struct node *fourthChild;
}*start,*final;
struct queuenode
{
	struct node *puzzleNode;
	struct queuenode *next;
}*front , *rear, *currentProcessedNode;
struct node * createNewNode(int puzzle[][3]){
	int i,j;
	struct node *newNode = (struct node *)malloc(sizeof(struct node *)*48);
	for(i = 0; i<3 ; i++){
		for(j = 0; j<3 ; j++){
			newNode -> puzzle[i][j] = puzzle[i][j];
		}
	}
	newNode -> heuristic = 0; 
	newNode -> firstChild = NULL;
	newNode -> secondChild = NULL;
	newNode -> thirdChild = NULL;
	newNode -> fourthChild  = NULL;
	return newNode;
}
struct queuenode * createNewQueueNode(struct node *currentNode){
	struct queuenode *newQueueNode = (struct queuenode*)malloc(sizeof(struct queuenode*));
	newQueueNode -> puzzleNode = currentNode;
	newQueueNode -> next = NULL;
	return newQueueNode;
}
void insertChildNode(struct node *currentNode, struct node *ChildNode){
	if(currentNode -> firstChild == NULL){
		currentNode -> firstChild = ChildNode;
	}
	else if(currentNode -> secondChild == NULL){
		currentNode -> secondChild = ChildNode;
	}
	else if(currentNode -> thirdChild == NULL){
		currentNode -> thirdChild = ChildNode;
	}
	else{
		currentNode -> fourthChild = ChildNode;
	}
}
void insertQueueNodeInQueue(struct queuenode *currentQueueNode){
	if(front == NULL){
		front = rear = currentQueueNode;
	}
	else{
		rear -> next = currentQueueNode;
		rear = currentQueueNode;
	}
}
void insertHeuristic(struct node *childNode){
	int heuristicCount = 0;
	int i,j;
	for(i = 0; i<3 ; i++){
		for(j = 0; j<3 ;j++){
			if(childNode -> puzzle[i][j] != final -> puzzle[i][j]){
				heuristicCount = heuristicCount + 1;
			}
		}
	}
	childNode -> heuristic = heuristicCount;
}
int checkInQueue(struct node *currentNode){
	struct queuenode *traverseNode = front;
	int i,j, flag;
	while(traverseNode != NULL){
		flag = 0;
		for(i = 0; i < 3; i++){
			for(j = 0; j < 3; j++){
				if(traverseNode -> puzzleNode -> puzzle[i][j] != currentNode -> puzzle[i][j]){
					flag = 1;
					break;
				}
			}
			if(flag == 1){
				break;
			}
		}
		if(flag == 1){
			traverseNode = traverseNode -> next;
			continue;
		}
		else{
			return 0;
		}
	}
	return 1;
}
int checkFinalWin(struct node *currentNode){
	int i,j;
	for(i = 0; i<3 ;i++){
		for(j = 0; j<3 ; j++){
			if(currentNode -> puzzle[i][j] != final -> puzzle[i][j]){
				return 0;
			}
		}
	}
	return 1;
}
void displayNode(struct node *currentNode){
	int i,j;
	for(i = 0; i<3; i++){
		for(j = 0; j<3; j++){
			printf("%d\t",currentNode -> puzzle[i][j]);
		}
		printf("\n");
	}
	printf("----------------------\n");
}
void createChildNode(struct node *currentNode, int counter){
	//find position of 0 in array
	int i,j,k,l,m,n,swapInteger, chooseHeuristic = 9;
	int f = 0;
	int tempPuzzle[3][3];
	struct node *ChildNode;
	struct node *selectedChildNode = NULL;
	for(i = 0; i<3 ;i++){
		for(j = 0; j<3 ; j++){
			if(currentNode -> puzzle[i][j] == 0){
				f = 1;
				m = i;
				n = j;
				break;
			}
		}
		if(f == 1){
			break;
		}
	}
	// copy the current node puzzle into tempPuzzle;
	for(k = 0; k<3 ; k++){
		for(l = 0; l<3 ;l++){
			tempPuzzle[k][l] = currentNode -> puzzle[k][l];
		}
	}
	i = i - 1;
	if(i >= 0){
		swapInteger = tempPuzzle[i][j];
		tempPuzzle[i][j] = tempPuzzle[i+1][j];
		tempPuzzle[i+1][j] = swapInteger;
		ChildNode = createNewNode(tempPuzzle);
		insertChildNode(currentNode,ChildNode);
		insertHeuristic(ChildNode);
		if(checkInQueue(ChildNode)){
			if(ChildNode -> heuristic <= chooseHeuristic){
				chooseHeuristic = ChildNode -> heuristic;
				selectedChildNode = ChildNode;
			}
		}
	}
	// copy the current node puzzle into tempPuzzle;
	for(k = 0; k<3 ; k++){
		for(l = 0; l<3 ;l++){
			tempPuzzle[k][l] = currentNode -> puzzle[k][l];
		}
	}
	i = i + 2;
	if(i <= 2){
		swapInteger = tempPuzzle[i][j];
		tempPuzzle[i][j] = tempPuzzle[i-1][j];
		tempPuzzle[i-1][j] = swapInteger;
		ChildNode = createNewNode(tempPuzzle);
		insertChildNode(currentNode,ChildNode);
		insertHeuristic(ChildNode);
		if(checkInQueue(ChildNode)){
			if(ChildNode -> heuristic <= chooseHeuristic){
				chooseHeuristic = ChildNode -> heuristic;
				selectedChildNode = ChildNode;
			}
		}
	}
	// copy the current node puzzle into tempPuzzle;
	for(k = 0; k<3 ; k++){
		for(l = 0; l<3 ;l++){
			tempPuzzle[k][l] = currentNode -> puzzle[k][l];
		}
	}
	i = i - 1;
	j = j - 1;
	if(j >= 0){
		swapInteger = tempPuzzle[i][j];
		tempPuzzle[i][j] = tempPuzzle[i][j+1];
		tempPuzzle[i][j+1] = swapInteger;
		ChildNode = createNewNode(tempPuzzle);
		insertChildNode(currentNode,ChildNode);
		insertHeuristic(ChildNode);
		if(checkInQueue(ChildNode)){
			if(ChildNode -> heuristic <= chooseHeuristic){
				chooseHeuristic = ChildNode -> heuristic;
				selectedChildNode = ChildNode;
			}
		}
	}
	// copy the current node puzzle into tempPuzzle;
	for(k = 0; k<3 ; k++){
		for(l = 0; l<3 ;l++){
			tempPuzzle[k][l] = currentNode -> puzzle[k][l];
		}
	}
	j = j + 2;
	if(j <= 2){
		swapInteger = tempPuzzle[i][j];
		tempPuzzle[i][j] = tempPuzzle[i][j-1];
		tempPuzzle[i][j-1] = swapInteger;
		ChildNode = createNewNode(tempPuzzle);
		insertChildNode(currentNode,ChildNode);
		insertHeuristic(ChildNode);
		if(checkInQueue(ChildNode)){
			if(ChildNode -> heuristic <= chooseHeuristic){
				chooseHeuristic = ChildNode -> heuristic;
				selectedChildNode = ChildNode;
			}
		}
	}
	currentProcessedNode = createNewQueueNode(selectedChildNode);
	insertQueueNodeInQueue(currentProcessedNode);
	displayNode(selectedChildNode);
	if(checkFinalWin(selectedChildNode)){
		printf("Solution Found in %d steps.....Hence Terminating\n",counter);
	}
	else{
		counter = counter + 1;
		createChildNode(selectedChildNode , counter);
	}
}
int main(){
	int i,j;
	int counter = 0;
	int puzzleArray[3][3];
	front = rear = NULL;
	struct queuenode *queue = NULL;
	printf("Please Enter Initial State\n");
	for(i = 0; i<3; i++){
		for(j = 0; j<3; j++){
			scanf("%d",&puzzleArray[i][j]);
		}
	}
	start = createNewNode(puzzleArray);
	queue = createNewQueueNode(start);
	insertQueueNodeInQueue(queue);
	printf("Please Enter Final State\n");
	for(i = 0; i<3; i++){
		for(j = 0; j<3; j++){
			scanf("%d",&puzzleArray[i][j]);
		}
	}
	final = createNewNode(puzzleArray);
	insertHeuristic(start);
	displayNode(start);
	createChildNode(start, counter);
	return 0;
}