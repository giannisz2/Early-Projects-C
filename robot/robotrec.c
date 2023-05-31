int solve(int i,int j,int **M) {
    if(i == 0 && j == 0)  // Recursive formula
        return M[i][j];
    else if(i == 0 && j > 0) 
       return solve(i,j-1,M) + M[i][j];  
    else if(i > 0 && j == 0) 
       return solve(i-1,j,M) + M[i][j];
    else if(solve(i-1,j,M) > solve(i,j-1,M))
        return solve(i-1,j,M) + M[i][j];
    else
        return solve(i,j-1,M) + M[i][j];
}  