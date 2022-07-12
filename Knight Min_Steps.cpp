#include<bits/stdc++.h>
using namespace std;

// Problem Statement:
// Given a square chessboard of N x N size, the position of Knight and position of a target is given. 
// We need to find out the minimum steps a Knight will take to reach the target position.

// Examples: 
// In above diagram Knight takes 3 step to reach 
// from (4, 5) to (1, 1) 
// (4, 5) -> (5, 3) -> (3, 2) -> (1, 1)  

// Approach:
// This problem is similar to finding the shortest path in an unweighted graph. 
// As a result, we employ BFS to overcome this issue. 
// We try all 8 spots a Knight can reach from its current position. 
// If a reachable position hasn't been visited yet and is located within the board, we add it to the queue with a distance of one more than its parent state. 
// Finally, when the target position is popped out of the queue, we return its distance.
// The code below uses BFS to search across cells, where each cell has its own coordinate and distance from the starting node. 
// In the worst-case scenario, the code below accesses all of the board's cells, resulting in an O(N^2) time complexity.

void solve()
{
	// All positions are started from 0 index 

	// n amd m are the dimensions of the chessboard
	int n,m;
	cout<<"Enter The Dimensions (n,m) of the Chessboard"<<endl;
	cin>>n>>m;

	// ini_x and ini_y is the initial position of the knight 
	int ini_x;
	int ini_y;
	cout<<"Enter the initial position of the Knight"<<endl;
	cin>>ini_x>>ini_y;

	// fin_x and fin_y in the final destined position of the knight 
	int fin_x;
	int fin_y;
	cout<<"Enter the final destination of the Knight"<<endl;
	cin>>fin_x>>fin_y;

	// dx and dy are the moves that can be taken by the knight at one time
  int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
  int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

  // queue for performing BFS (Breadth First Search)
  queue<pair<int,int>>q;
  q.push({ini_x,ini_y});

  // min steps is the no. of minimum steps require by the knight to reach from ini_x,ini_y
  int min_steps[n][m];
  int i,j;
  int max=1e6;
  for(i=0;i<n;i++)
  {
  	for(j=0;j<m;j++)
  	{
  		min_steps[i][j]=max;
  	}
  }
  min_steps[ini_x][ini_y]=0;

  //performing BFS (Breadth First Search)
  while(!q.empty())
  {
  	int x0,y0;
  	x0=q.front().first;
  	y0=q.front().second;
  	q.pop();

  	// moving to all the possibe steps that can be taken from x0,y0
  	for(i=0;i<8;i++)
  	{
  		int xx = x0 +dx[i];
  		int yy = y0 + dy[i];
  		//checking if xx , yy is a valid position or not 
  		if(!(xx<n && yy<n && xx>=0 && yy>=0))
  			continue;

  		if(min_steps[xx][yy] > (min_steps[x0][y0]+1))
  		{
  			min_steps[xx][yy] = min_steps[x0][y0]+1;
  			q.push({xx,yy});
  		}
  	}
  }

  //printing the minimum steps required for the knight from ini_x,ini_y to fin_x,fin_y
  cout<<"Min steps required for the knight from initial position to final position ";
  cout<<min_steps[fin_x][fin_y];

}



int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
}
 
