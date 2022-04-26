#include <bits/stdc++.h> 
using namespace std; 
void preProcess(string p, int *table, int n) { 
    // Initialize table[0] as 0 
    table[0] = 0;
    // Initialise i = 0 and j = 1
    int i = 0, j = 1;
    // Run a loop till length of pattern, if p[i] and p[j] matches table[j] = i + 1 else table[j] = 0
    while (j < n) {
        if (p[i] == p[j]) {
            // Match found set table[i] = i + 1, and advance i and j
            table[j] = i + 1;
            i++; 
            j++;
        } else {
            if (i != 0) {
                i = table[i - 1];
                // We do not increment j here
            } else {
                table[j] = 0;
                j++;
            }
        }
    } 
} 
int main() {
    // char s[] = "abcaabcab";
    // char p[] = "abcab";
    string s,p;
    cout<<"\nEnter string= ";
    cin>>s;
    cout<<"\nEnter pattern= ";
    cin>>p;
    int n = s.size();
    int m = p.size();
    
    // Pre-process the pattern
    int table[m];
    preProcess(p, table, m);
    
    // Searching the pattern in the given string
    int i = 0;      // index for string 
    int j = 0;      // index for pattern
    bool found = false; // Boolean variable to indicate that the pattern is found or not
    while (i < n) {
        if (s[i] == p[j]) {
            // Advance forward the characters are same
            i++; 
            j++;
        } else {
            // Characters are not same, revert back the progress in the pattern 
            if (j != 0)  {
                // Reset the position of j in the pattern, do no advance in string  
                j = table[j - 1];
            } else {
                // first character is mis-matched, advance in the string
                i++;
            }
        }
        
        if (j == m) {
            // The pattern is found in the string
            found = true;
            break;
        }
    }
    if (found)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    
    return 0; 
}
