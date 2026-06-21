//tle 
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    vector<int>arr;
    int i=0;
    int j=0;
    while(i < m && j < n)
    {
        if(row1[i] <= row2[j])
        {
            arr.push_back(row1[i]);
            i++;
        }
        else if(row1[i] > row2[j])
        {
            arr.push_back(row2[j]);
            j++;
        }
    }
    while(i < m)
    {
        arr.push_back(row1[i]);
            i++;
    }
    while(j < n)
    {
        arr.push_back(row2[j]);
            j++;
    }
    return arr[k-1];

}
