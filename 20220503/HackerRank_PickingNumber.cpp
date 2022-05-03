#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define NEXTINDEX(t) t + 1

int pickingNumbers(vector<int> a) {
    vector<vector<int>> vecRes;
    unsigned int iRes = 0;
    sort(a.begin(), a.end());

    int iCheckSameArr = 0;
    bool bChange = false;
    vector<int> vecGroup;

    for (unsigned int i = 0; i < a.size(); ++i)
    {
        if (iCheckSameArr < a[i])
        {
            if (vecGroup.size())
            {
                vecRes.push_back(vector<int>(vecGroup));
                bChange = false;
            }

            vecGroup.clear();
            vecGroup.shrink_to_fit();

            iCheckSameArr = a[i];
            vecGroup.push_back(a[i]);
            bChange = true;
            continue;
        }

        vecGroup.push_back(a[i]);
    }

    if(bChange)
        vecRes.push_back(vector<int>(vecGroup));

    for (unsigned int i = 0; i < vecRes.size(); ++i)
    {
        if (iRes < vecRes[i].size())
            iRes = vecRes[i].size();
    }

    for (unsigned int i = 0; NEXTINDEX(i) < vecRes.size(); ++i)
    {
        if (abs(vecRes[NEXTINDEX(i)].front() - vecRes[i].front()) <= 1)
        {
            if (iRes < vecRes[NEXTINDEX(i)].size() + vecRes[i].size())
                iRes = vecRes[NEXTINDEX(i)].size() + vecRes[i].size();
        }
    }

    return iRes;
}

int main()
{
    cout << pickingNumbers(vector<int>({ 1,3,5,7,7,7 })) << endl;

    return 0;
}