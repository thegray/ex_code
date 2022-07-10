// DBS DATA ENGINEER CHALLENGE IN HACKERRANK
// there are still rooms for improvement here


void customSort(vector <int> arr) {

    //unordered_map<int,int> freq;
    map<int,int> freq;
    vector<int> result = {};
    //debug
    /*for (int gg : arr)
    {
        printf("unsorted: %d\n", gg);
    }*/
    //end
    sort(arr.begin(), arr.end());
    /*for (int gg : arr)
    {
        printf("sorted: %d\n", gg);
    }*/
    for (int b : arr)
    {
        auto fit = freq.find(b);
        if (fit == freq.end())
        {
            //printf("b: %d\n", b);
            //freq.insert(make_pair(b, 1));
            freq.insert(pair<int,int>(b, 1));
        }
        else
            //freq[b]++;
            fit->second++;
    }
    
    int check = 1;
    while ((arr.size() - result.size()) > 0)
    {
        for (auto it = freq.begin(); it != freq.end(); it++)
        {
            if(it->second == check)
            {
                for(int j = 0; j < check; j++)
                {
                    result.push_back(it->first);
                    //cout << "push: ";
                    cout << it->first << endl;
                }
            }
        }
        check++;
    }
    arr = result;
}