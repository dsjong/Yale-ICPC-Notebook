/**
 * Author: Dion Ong
 * Source: https://codeforces.com/blog/entry/63257
 * Description: DP on subtrees with bounded size. Example counts number of subtrees of size at most $k$.
 * Time: O(NK)
 */

void dfs(int x, int p){
	sz[x]=1;
	dp[x][0]=dp[x][1]=1;
	for(int y: adj[x]){
		if(y==p) continue;
		dfs(y, x);
		fill(tmp, tmp+k+1, 0);
		for(int i=1; i<=min(k, sz[x]); i++)
			for(int j=0; j<=min(k-i, sz[y]); j++)
				tmp[i+j]+=dp[x][i]*dp[y][j];
		sz[x]+=sz[y];
		for(int i=2; i<=min(k, sz[x]); i++) dp[x][i]=tmp[i];
	}
}
