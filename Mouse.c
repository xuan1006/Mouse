#include <stdlib.h>
#include <stdio.h>
#define ROW 15
#define COL 11
typedef struct {
    int x; 
    int y;
} Point;						/*�w�qPoint�Ӫ�ܮy��*/

Point pt(int, int);
int Wake(int[][ROW], Point, Point);
void Print(int[][ROW]);

int main(void) { 
    int maze[COL][ROW] = {
        {0,1,0,0,0,1,1,0,0,0,1,1,1,1,1},
        {1,0,0,0,1,1,0,1,1,1,0,0,1,1,1},
        {0,1,1,0,0,0,0,1,1,1,1,0,0,1,1},
        {1,1,0,1,1,1,1,0,1,1,0,1,1,0,0},
        {1,1,0,1,0,0,1,0,1,1,1,1,1,1,1},
        {0,0,1,1,0,1,1,1,0,1,0,0,1,0,1},
        {0,1,1,1,1,0,0,1,1,1,1,1,1,1,1},
        {0,0,1,1,0,1,1,0,1,1,1,1,1,0,1},
        {1,1,0,0,0,1,1,0,1,1,0,0,0,0,0},
        {0,0,1,1,1,1,1,0,0,0,1,1,1,1,0},
        {0,1,0,0,1,1,1,1,1,0,1,1,1,1,0}};

    Point start, end;
    start.x=0;
	start.y=0;
	end.x=10;
	end.y=14;
/*   printf("�п�J�_�I�y�� (x y): ");
    scanf("%d %d", &start.x, &start.y);
    printf("�п�J���I�y�� (x y): ");
    scanf("%d %d", &end.x, &end.y);
*/
    if(!Wake(maze, start, end)) {
        printf("\n�S�����X�f\n");
    }
    Print(maze);
    
    return 0; 
}

Point pt(int x, int y) {
    Point p = {x, y};
    return p;						/*�Ыخy��*/
}

int Wake(int maze[][ROW], Point start, Point end) {

	if(start.x >= COL || start.y >= ROW){
		return 1;
	}
    if(maze[start.x][start.y] == 0) {
    	maze[start.x][start.y] = 1;
        if(maze[end.x][end.y] == 0 && 
            (Wake(maze, pt(start.x, start.y + 1), end) || 			/*�k*/
            Wake(maze, pt(start.x + 1, start.y + 1), end) ||		/*�k�U*/
            Wake(maze, pt(start.x + 1, start.y), end) ||			/*�U*/
            Wake(maze, pt(start.x + 1, start.y - 1), end) ||		/*���U*/
            Wake(maze, pt(start.x, start.y - 1), end) ||			/*��*/
			Wake(maze, pt(start.x - 1, start.y - 1), end) || 		/*���W*/
            Wake(maze, pt(start.x - 1, start.y), end) ||			/*�W*/
			Wake(maze, pt(start.x - 1, start.y + 1), end)) == 0)	/*�k�W*/
			{					/*�P�_8�Ӥ�V*/
                maze[start.x][start.y] = 0;					/*�p�G[start.x][start.y]��0�N�Ӧ�m�аO��1*/
        }
    }

    return maze[end.x][end.y];									/*�^�Ǩ禡�A��ܬO�_�����|*/   
    
}

void Print(int maze[][ROW]) {
    int i = 0, j = 0;
    for(i = 0; i < COL; i++) { 
        for(j = 0; j < ROW; j++){
//			switch(maze[i][j]) {
//	            case 0 :
//					printf("(     )");		/*�L�X���|*/
//					break;
//	            case 1 :
//					printf("(#####)");		/*�L�X���*/
//					break;
//				case 2:
//					printf("(%2d,%2d)",i,j);
			printf("(%2d,%2d,%2d)",i,j,maze[i][j]);
        }
        printf("\n"); 
    } 
}
