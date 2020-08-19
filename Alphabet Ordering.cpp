// Devang Sharma- Google Developers Group, Singapore


/* 

Approach:
(1) Staright Forward Greedy Approach
(2) Find the max length Monotonous Substring 
(3) This way, We will get minimum number of broken substrings

*/


#include <bits/stdc++.h>
using namespace std;

int main() 
{
    // Author: Devang Sharma
	string s;
	cin >> s;
	int n = s.size();
	
	int sol = 0;

	for (int idx = 0; idx < n;) 
    {
		sol++;
		int incr = idx, decr = idx;

        //Check Increasing Substring
		while (incr + 1 < n && s[incr] <= s[incr + 1]) 
        incr++;

        //Check Decreasing Substring
		while (decr + 1 < n && s[decr] >= s[decr + 1]) 
        decr++;

        //End of String-Check
		if (max(incr, decr) + 1 == n) break;

        // Min Broken Substrings
		idx = max(incr, decr) + 1;
	}

	cout << sol;
	return 0;
}
