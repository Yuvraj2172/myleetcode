class Solution {
public:
vector<int> buildprefxorarr(vector<int> v, int n){
			vector<int> pref(n,0);
			pref[0] = v[0];
			
			for(int i = 1; i<n;i++){
				pref[i] = pref[i-1] ^ v[i];
			}
			return pref;
			
		}
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int q = queries.size();
        vector<int> pref = buildprefxorarr(arr,n);
        vector<int> ans;
        
        for(auto it : queries){
            int l = it[0];
            int r = it[1];
            if(l == 0){
            ans.push_back(pref[r]);
            }
            else {
                ans.push_back(pref[l-1] ^ pref[r]);
            }
        }
        return ans;
    }
};