int ways(const string& A, int s)
{
    if(s == A.size())
        return 1;
    else if(A[s] == '0')
        return 0;
    else if(A[s] > '2')
        return ways(A,s+1);
    else if(s+1 >= A.size())
        return ways(A,s+1);
    else if(A[s] == '1' 
            || (A[s] == '2' && A[s+1] < '7'))
        return ways(A,s+1) +  ways(A,s+2);
    else
        return ways(A,s+1);
}


int Solution::numDecodings(string A) {
    return ways(A,0);
}

