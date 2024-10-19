#include "bits/stdc++.h"
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

namespace math {
	const int mxn = 1e6+5;
	int mod; //CHANGE mod to const if known
	int ft[mxn]; //factorial
	int ift[mxn];//inverse factorial
	int ksm(int a, int b=mod-2) {
		int res=1,aux=a;
		for (int i=1; i<=b; i*=2) {
			if (i&b) res=res*aux%mod;
			aux=aux*aux%mod;
		}
		return res;
	}
	void init(int mod_val) {
		mod = mod_val;
		ft[0] = ift[0] = 1;
		for (int i=1; i<mxn; i++) {
			ft[i] = i*ft[i-1]%mod;
			ift[i] = ksm(ft[i]); //use more efficient if necessary
		}
	}
	int nck(int n, int k) {
		return ft[n]*ift[k]%mod*ift[n-k]%mod;
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	math::init(998244353);
	cout<<math::nck(10,5);
	
	return 0;
}