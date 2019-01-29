int max(int a, int b){
    return (a>b)? a:b;
}

int countPalindromicSubsequences(char* s1) {
    int l = strlen(s1);
    long dp[l][l];
    int num_palindromes;
    int j;
    memset(dp, 0 ,sizeof(dp));

    for(int i =0;i<l;i++){
        dp[i][i] = 1;
    }

    for(int s=2;s<=l;s++){
        for(int i=0; i< (l-s+1) ;i++){
            j = s+i -1;
            if(s1[i] == s1[j] && abs(i-j) > 1){
                int prev = i+1;
                int next = j-1;
                int index = prev;
                int occured = 0;
                while(index < j){
                    if(s1[index] == s1[i]){
                        if(!occured){
                            prev = index;
                            next = index;
                            occured = 1;
                        }
                        else{
                            next = index;
                        }
                    }
                    index++;
                }
                if(!occured){
                    dp[i][j] = ((2*dp[i+1][j-1]) % 1000000007) + 2;
                }
                else if(occured && prev == next){
                    dp[i][j] = ((2*dp[i+1][j-1]) % 1000000007) + 1;
                }
                else{
                    dp[i][j] = ((2*dp[i+1][j-1]) % 1000000007) - (dp[prev+1][next-1] % 1000000007);
                }
            }
            else{
                dp[i][j] = ((dp[i][j-1] % 1000000007) + (dp[i+1][j] % 1000000007) - (dp[i+1][j-1] % 1000000007))% 1000000007;
            }

        }

    }

    int res =  dp[0][l-1] % 1000000007;
    if(res < 0){
        res = (dp[0][l-1] + 1000000007) % 1000000007;
    }
    return res;

}
