#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the longestCommonSubsequence function below.
vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {
    int lcs[a.size()][b.size()];

    if(a[0]==b[0]) {
        lcs[0][0]=1;
    } else {
        lcs[0][0]=0;
    }
    
    for(int i=1;i<a.size();i++) {
        if(a[i]==b[0]) {
            lcs[i][0]=1;
        } else {
            lcs[i][0]=lcs[i-1][0];
        }
    }

    for(int i=1;i<b.size();i++) {
        if(a[0]==b[i]) {
            lcs[0][i]=1;
        } else {
            lcs[0][i]=lcs[0][i-1];
        }
    }

    for(int i=1;i<a.size();i++) {
        for(int j=1;j<b.size();j++) {
            if(a[i]==b[j]) {
                lcs[i][j]=1+lcs[i-1][j-1];
            } else {
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
    }

    // for(int i=0;i<a.size();i++) {
    //     for(int j=0;j<b.size();j++) {
    //         cout<<lcs[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // backtrack through matrix to get result
    int x=a.size()-1,y=b.size()-1;
    vector<int> v;

    while(x>=0 && y>=0) {
        // printf("%d,%d\n",x,y);
        if(x<0 || y<0)
            continue;

        if(a[x]==b[y]) {
            v.push_back(a[x]);
            x-=1;
            y-=1;
        } else {
            int left= y>0 ? lcs[x][y-1] : 0;
            int top= x>0 ? lcs[x-1][y] : 0;

            if(left>top) {
                y-=1;
            } else {
                x-=1;
            }
        }
    }

    reverse(v.begin(),v.end());
    return v;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    string b_temp_temp;
    getline(cin, b_temp_temp);

    vector<string> b_temp = split_string(b_temp_temp);

    vector<int> b(m);

    for (int i = 0; i < m; i++) {
        int b_item = stoi(b_temp[i]);

        b[i] = b_item;
    }

    vector<int> result = longestCommonSubsequence(a, b);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
