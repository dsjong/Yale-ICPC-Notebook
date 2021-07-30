/**
 * Author: Dion Ong
 * Source: https://codeforces.com/blog/entry/45223
 * Description: Given a mask of $n$ bits and an array $A$ of $2^n$ elements. For any $x \in [0, 2^n)$ computes $\sum_{i \subset x} A[i]$.
 * Time: O(N 2^N)
 */
void SumSubsets(int n){
	for(int i=0; i<(1<<n); i++) dp[i]=a[i];
	for(int i=0; i<n; i++)
		for(int mask=0; mask<(1<<n); mask++)
			if(mask & (1<<i)) dp[mask] += dp[mask^(1<<i)];
}
void SumSupersets(int n){
	for(int i=0; i<(1<<n); i++) dp[i]=a[i];
	for(int i=0; i<n; i++)
		for(int mask=0; mask<(1<<n); mask++)
			if(!(mask & (1<<i))) dp[mask] += dp[mask^(1<<i)];
}
