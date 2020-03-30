#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T, class V>
vector<int> findValues(T vec, V value)
{
    vector<int> index;

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == value)
        {
            index.push_back(i);
        }
    }
    return index;
}

template <class T, class V, class Q>
vector<int> findValuesInVectors(T vec, V indexes, Q value)
{
    vector<int> index;

    for (int i = 0; i < indexes.size(); i++)
    {
        if (vec[indexes[i]] == value)
        {
            index.push_back(indexes[i]);
        }
    }
    return index;
}

int main()
{
    int propNumber = 1;
    string line;
    istringstream ss;

    while (getline(cin, line))
    {
        int n, p;
        vector<string> req;
        vector<string> prop;
        vector<float> price;
        vector<int> reqMet;
        vector<float> compliance;

        ss.str(line);
        ss >> n >> p;
        ss.clear();

        if(n == 0 || p == 0){
            break;
        }

        for (int i = 0; i < n; i++)
        {
            string currentReq;

            getline(cin, line);
            ss.str(line);
            ss >> currentReq;
            ss.clear();
            req.push_back(currentReq);
        }

        for (int i = 0; i < p; i++)
        {
            string currentProp;
            float currentPrice;
            int currentReqMet;

            getline(cin, line);
            ss.str(line);
            ss >> currentProp;
            ss.clear();

            prop.push_back(currentProp);

            getline(cin, line);
            ss.str(line);
            ss >> currentPrice >> currentReqMet;
            ss.clear();

            price.push_back(currentPrice);
            reqMet.push_back(currentReqMet);

            for (int j = 0; j < currentReqMet; j++)
            {
                getline(cin, line);
            }

            compliance.push_back(currentReqMet/(float)n);
        }

        float highestCompliance = *max_element(compliance.begin(), compliance.end());
        vector<int> complianceIndexes = findValues(compliance, highestCompliance);

        cout << "RFP #" << propNumber << endl;
        propNumber++;
        if (complianceIndexes.size() > 1)
        {

            vector<float> reducedPrices;
            for (int i = 0; i < complianceIndexes.size(); i++)
            {
                reducedPrices.push_back(price[complianceIndexes[i]]);
            }
            

            float lowestPrice = *min_element(reducedPrices.begin(), reducedPrices.end());
            vector<int> priceIndexes = findValuesInVectors(price, complianceIndexes, lowestPrice);

            if (priceIndexes.size() > 1)
            {
                cout << prop[complianceIndexes[0]] << endl;
            }
            else
            {
                cout << prop[priceIndexes[0]] << endl;
            }
        }
        else
        {
            cout << prop[complianceIndexes[0]] << endl;
        }
    }

    return EXIT_SUCCESS;
}
