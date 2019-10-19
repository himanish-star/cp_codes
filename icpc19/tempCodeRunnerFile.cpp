#include <bits/stdc++.h> 
using namespace std; 

int min(int a, int b) 
{ 
	return (a < b) ? a : b; 
} 

int findOverlappingPair(string str1, string str2, string &str) 
{ 
	int max = INT_MIN; 
	int len1 = str1.length(); 
	int len2 = str2.length(); 

	for (int i = 1; i <= min(len1, len2); i++) 
	{ 
		if (str1.compare(len1-i, i, str2, 0, i) == 0) 
		{ 
			if (max < i) 
			{ 
				max = i; 
				str = str1 + str2.substr(i); 
			} 
		} 
	} 

	for (int i = 1; i <= min(len1, len2); i++) 
	{ 
		if (str1.compare(0, i, str2, len2-i, i) == 0) 
		{ 
			if (max < i) 
			{ 
				max = i; 
				str = str2 + str1.substr(i); 
			} 
		} 
	} 

	return max; 
} 

string findShortestSuperstring(string arr[], int len) 
{ 
	while(len != 1) 
	{ 
		int max = INT_MIN; 
		int l, r; 
		string resStr;  

		for (int i = 0; i < len; i++) 
		{ 
			for (int j = i + 1; j < len; j++) 
			{ 
				string str; 

				int res = findOverlappingPair(arr[i], arr[j], str); 

				if (max < res) 
				{ 
					max = res; 
					resStr.assign(str); 
					l = i, r = j; 
				} 
			} 
		} 

		len--; 

		if (max == INT_MIN) 
			arr[0] += arr[len]; 
		else
		{ 
			arr[l] = resStr; 
			arr[r] = arr[len]; 
		} 
	} 
	return arr[0]; 
} 

int findMinInsertionsDP(string str, int n)  
{  
    int table[n][n], l, h, gap;  
  
    memset(table, 0, sizeof(table));  
  
    for (gap = 1; gap < n; ++gap)  
        for (l = 0, h = gap; h < n; ++l, ++h)  
            table[l][h] = (str[l] == str[h])?  
                        table[l + 1][h - 1] :  
                        (min(table[l][h - 1],  
                             table[l + 1][h]) + 1);  
  
    return table[0][n - 1];  
}

int main() 
{ 

    int t;
    cin>>t;

    while(t--) {
        string arr[2];
	
        string s1,s2;
        cin>>s1>>s2;

        arr[0]=s1;
        arr[1]=s2;

	    string shortSuper = findShortestSuperstring(arr, 2); 

        int ans1=shortSuper.size()+findMinInsertionsDP(shortSuper,shortSuper.size());    

        reverse(arr,arr+2);
        shortSuper = findShortestSuperstring(arr, 2);
        int ans2=shortSuper.size()+findMinInsertionsDP(shortSuper,shortSuper.size());    

        cout<<min(ans1,ans2)<<endl;

    }

	return 0; 
} 
