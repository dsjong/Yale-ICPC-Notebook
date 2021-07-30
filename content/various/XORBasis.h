/**
 * Author: Dion Ong
 * Source: https://codeforces.com/blog/entry/68953
 * Description: The set of xor sums of all subsets is a vector space!
 * Time: O(d)
 * Status: Tested on AGC45A
 */

struct XOR{
	vector<ll> masks; //masks[i] has its first set bit at i
	set<ll> basis;
	int d; //number of bits
	XOR(int d): masks(d), d(d) {}
	void addVector(ll mask){
		for(ll i=0; i<d; i++){
			if((mask & 1ll<<i)==0) continue;
			if(!masks[i]){
				masks[i]=mask;
				basis.insert(mask);
				return;
			}
			mask^=masks[i];
		}
	}
	bool inSpan(ll mask){
		for(ll i=0; i<d; i++){
			if((mask & 1ll<<i)==0) continue;
			if(!masks[i]) return false;
			mask^=masks[i];
		}
		return true;
	}
};