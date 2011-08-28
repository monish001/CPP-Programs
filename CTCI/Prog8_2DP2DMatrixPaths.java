//Question: Imagine a robot sitting on the upper left hand corner of an NxN grid. The robot can only move in two directions: right and down. How many possible paths are there for the robot?
//FOLLOW UP
//Imagine certain squares are “off limits”, such that the robot can not step on them. Design an algorithm to get all possible paths for the robot.
public class Prog8_2DP2DMatrixPaths{

	//ITERATIVE METHOD1:
	int fac(int n){
		int i=1;
		while(n>0)
			i *= n--;
		return i;
	}
	int findWays1(final int nx, final int ny){
		return fac(nx+ny-2)/(fac(nx-1)*fac(ny-1));//(nx+ny-2)C(nc-1);
	}
	//ITERATIVE METHOD2:
	int findWays2(final int nx, final int ny, int[][] a){
		for(int j=0; j<ny; j++)
			a[0][j]= 1;
		for(int j=0; j<nx; j++)
			a[j][0]=1;
		a[0][0]=0;
		for(int i=1; i<nx; i++)
		for(int j=1; j<ny; j++)
			a[i][j] = a[i][j-1] + a[i-1][j];
		return a[nx-1][ny-1];
	}

	//RECURSIVE METHOD:
	boolean isOffLimit(int x, int y){
		return false;
	}
	int findWays3(final int nx, final int ny, final int x, final int y, int row[][]){
		if(x==0 || y==0)
			return 1;
		if(isOffLimit(x, y) == true)
			return 0;
		if(row[x][y] != 0)	return row[x][y];//if already calculated
		else return row[x][y]=findWays3(nx, ny, x-1, y, row) + findWays3(nx, ny, x, y-1, row);
	}
	static public void main(String[] args){
		Prog8_2DP2DMatrixPaths obj = new Prog8_2DP2DMatrixPaths();
		int n=5, m=6;
		int[][] a = new int[n][m];
		System.out.println(obj.findWays1(n, m));
		System.out.println(obj.findWays3(n, m, n-1, m-1, a));
		a = new int[n][m];
		System.out.println(obj.findWays2(n, m, a));
		//System.out.println("Hello World!!");
	}

}