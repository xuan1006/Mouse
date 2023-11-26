#include <stdlib.h>
#include <stdio.h>
#define ROW 15
#define COL 11
typedef struct {
    int x; 
    int y;
} Point;						/*定義Point來表示座標*/

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
/*   printf("請輸入起點座標 (x y): ");
    scanf("%d %d", &start.x, &start.y);
    printf("請輸入終點座標 (x y): ");
    scanf("%d %d", &end.x, &end.y);
*/
    if(!Wake(maze, start, end)) {
        printf("\n沒有找到出口\n");
    }
    Print(maze);
    
    return 0; 
}

Point pt(int x, int y) {
    Point p = {x, y};
    return p;						/*創建座標*/
}

int Wake(int maze[][ROW], Point start, Point end) {

	if(start.x >= COL || start.y >= ROW){
		return 1;
	}
    if(maze[start.x][start.y] == 0) {
    	maze[start.x][start.y] = 1;
        if(maze[end.x][end.y] == 0 && 
            (Wake(maze, pt(start.x, start.y + 1), end) || 			/*右*/
            Wake(maze, pt(start.x + 1, start.y + 1), end) ||		/*右下*/
            Wake(maze, pt(start.x + 1, start.y), end) ||			/*下*/
            Wake(maze, pt(start.x + 1, start.y - 1), end) ||		/*左下*/
            Wake(maze, pt(start.x, start.y - 1), end) ||			/*左*/
			Wake(maze, pt(start.x - 1, start.y - 1), end) || 		/*左上*/
            Wake(maze, pt(start.x - 1, start.y), end) ||			/*上*/
			Wake(maze, pt(start.x - 1, start.y + 1), end)) == 0)	/*右上*/
			{					/*判斷8個方向*/
                maze[start.x][start.y] = 0;					/*如果[start.x][start.y]為0將該位置標記為1*/
        }
    }

    return maze[end.x][end.y];									/*回傳函式，表示是否找到路徑*/   
    
}

void Print(int maze[][ROW]) {
    int i = 0, j = 0;
    for(i = 0; i < COL; i++) { 
        for(j = 0; j < ROW; j++){
//			switch(maze[i][j]) {
//	            case 0 :
//					printf("(     )");		/*印出路徑*/
//					break;
//	            case 1 :
//					printf("(#####)");		/*印出牆壁*/
//					break;
//				case 2:
//					printf("(%2d,%2d)",i,j);
			printf("(%2d,%2d,%2d)",i,j,maze[i][j]);
        }
        printf("\n"); 
    } 
}
