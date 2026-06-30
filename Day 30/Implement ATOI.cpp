int createAtoi(string s) {
    long long ans=0;
    int i=0;
    int sign=+1;
    int n=s.length();

    while(i < n && s[i]==' ')
    {
        i++;
    }

    if(s[i]=='-' || s[i]=='+')
    {
        if(s[i]=='-')
        {
            sign=-1;
        }
        i++;
    }
    while(i < n && isdigit(s[i]))
    {
        ans = ans * 10 + (s[i]-'0');
         if(ans * sign > INT_MAX)return INT_MAX;
        if(ans * sign < INT_MIN)return INT_MIN;
        i++;
    }
    return (int)ans*sign;

}
